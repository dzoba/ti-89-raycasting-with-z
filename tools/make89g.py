#!/usr/bin/env python3
"""Combine multiple TI-89 files (.89y/.89z) into a single group file (.89g)."""

import os
import struct
import sys

ARCHIVED_ATTR = 0x40

def read_ti89_file(filepath, archive=True):
    """Read a .89y/.89z file and extract variable name, type, attribute, and data."""
    with open(filepath, 'rb') as f:
        data = f.read()

    # Verify signature
    assert data[:8] == b'**TI89**', f"Bad signature in {filepath}"

    # Entry count at 0x3A (should be 1 for single-var files)
    entry_count = struct.unpack_from('<H', data, 0x3A)[0]
    assert entry_count == 1, f"Expected 1 entry, got {entry_count} in {filepath}"

    # Variable entry at 0x3C (16 bytes)
    data_offset = struct.unpack_from('<I', data, 0x3C)[0]
    var_name = data[0x40:0x48]
    var_type = data[0x48]
    var_attr = data[0x49]
    if archive:
        var_attr |= ARCHIVED_ATTR

    # Variable data starts at the offset specified in the entry
    var_data = data[data_offset:]

    return var_name, var_type, var_attr, var_data


def make_group(input_files, output_file, folder=b'main', archive=True):
    """Create a .89g group file from multiple .89y/.89z files."""
    variables = []
    for f in input_files:
        name, vtype, attr, data = read_ti89_file(f, archive=archive)
        variables.append((name, vtype, attr, data))

    # Number of entries: 1 folder + N variables
    num_entries = 1 + len(variables)

    # Calculate where data section starts
    # Header: 58 bytes (0x00-0x39) + 2 bytes entry count
    # Entry table: num_entries * 16 bytes
    # Offset marker: 4 bytes + terminator: 2 bytes
    entry_table_start = 0x3C
    data_section_start = entry_table_start + num_entries * 16 + 4 + 2

    # Build entry table and calculate data offsets
    entries = []
    current_data_offset = data_section_start

    # Folder entry (type 0x1F, no data)
    folder_name = folder.ljust(8, b'\x00')[:8]
    entries.append(struct.pack('<I', current_data_offset) + folder_name +
                   bytes([0x1F, 0x00]) + b'\x00\x00')

    # Variable entries
    data_blocks = []
    for name, vtype, attr, data in variables:
        entries.append(struct.pack('<I', current_data_offset) + name +
                       bytes([vtype, attr]) + b'\x00\x00')
        data_blocks.append(data)
        current_data_offset += len(data)

    # Build the file
    out = bytearray()

    # Header
    out += b'**TI89**'
    out += struct.pack('<H', 0x0001)
    out += folder_name  # default folder
    out += b'\x00' * 40  # comment
    out += struct.pack('<H', num_entries)

    # Entry table
    for entry in entries:
        out += entry

    # Offset marker (points past all data) and terminator
    out += struct.pack('<I', current_data_offset)
    out += struct.pack('>H', 0xA55A)

    # Data blocks
    for block in data_blocks:
        out += block

    with open(output_file, 'wb') as f:
        f.write(bytes(out))

    print(f"Created {output_file} ({len(out)} bytes, {len(variables)} variables)")


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} output.89g input1.89y [input2.89y ...]")
        sys.exit(1)

    archive = os.environ.get("MAKE89G_ARCHIVE", "1") != "0"
    output = sys.argv[1]
    inputs = sys.argv[2:]
    make_group(inputs, output, archive=archive)
