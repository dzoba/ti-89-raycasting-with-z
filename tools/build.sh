#!/bin/bash
# Build the stairs demo, package, and launch in TiEmu
set -eu

TOOLS_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR="$(cd "$TOOLS_DIR/.." && pwd)"
FAT_ENGINE_DIR="${FAT_ENGINE_DIR:-$REPO_DIR/../fat-engine}"
TIEMU_BIN="${TIEMU_BIN:-$FAT_ENGINE_DIR/tiemu/repo/tiemu/trunk/src/tiemu}"
TIEMU_DYLD_LIBRARY_PATH="${TIEMU_DYLD_LIBRARY_PATH:-/opt/homebrew/lib}"

DEFAULT_ROM=""
for candidate in \
  "$HOME/.tiemu/images/ti89_2.09.img" \
  "$HOME/.tiemu/images/TI89Titanium_OS.img"
do
  if [[ -f "$candidate" ]]; then
    DEFAULT_ROM="$candidate"
    break
  fi
done
ROM="${ROM:-$DEFAULT_ROM}"

if [[ -z "$ROM" || ! -f "$ROM" ]]; then
  echo "ROM image not found. Set ROM=/path/to/tiemu.img" >&2
  exit 1
fi

echo "=== Step 1: Build stairs demo in Docker ==="
docker run --platform linux/amd64 --rm \
  -v "$REPO_DIR:/build/repo" \
  gcc4ti-builder bash -c '
    export TIGCC=/usr/local/share/gcc4ti
    export PATH=$TIGCC/bin:$PATH
    cd /build/repo
    echo "=== Compiling fatd_stairs ==="
    tigcc -O3 -fomit-frame-pointer -Wall -W -Wwrite-strings -I includes src/fatd_stairs.c -pack fatdspk
    echo "=== Build complete ==="
    mv fatdspk.89y output/ 2>/dev/null || true
    mv fatd_stairs.89y output/ 2>/dev/null || true
    mv fatd_stairs.89z output/ 2>/dev/null || true
    ls -la output/fatdspk.89y 2>/dev/null || ls -la output/fatd_stairs.89y 2>/dev/null || echo "Looking for output..."
    ls -la output/*.89y output/*.89z 2>/dev/null || true
  '

# Find the packed output
DEMO_FILE=""
if [[ -f "$REPO_DIR/output/fatdspk.89y" ]]; then
  DEMO_FILE="$REPO_DIR/output/fatdspk.89y"
elif [[ -f "$REPO_DIR/output/fatd_stairs.89y" ]]; then
  DEMO_FILE="$REPO_DIR/output/fatd_stairs.89y"
fi

if [[ -z "$DEMO_FILE" ]]; then
  echo "ERROR: Build produced no output file" >&2
  ls -la "$REPO_DIR/output"/*.89y "$REPO_DIR/output"/*.89z 2>/dev/null
  exit 1
fi

echo ""
echo "=== Step 2: Package group file ==="
python3 "$TOOLS_DIR/make89g.py" "$REPO_DIR/output/stairs.89g" \
  "$REPO_DIR/output/fatlib.89y" \
  "$REPO_DIR/output/fatdtx.89y" \
  "$REPO_DIR/output/fatload.89z" \
  "$DEMO_FILE"

if [[ "${DRY_RUN:-0}" == "1" ]]; then
  echo "DRY_RUN=1, stopping after packaging."
  exit 0
fi

echo ""
echo "=== Step 3: Launch TiEmu ==="
pkill -f tiemu 2>/dev/null || true
sleep 1

DYLD_LIBRARY_PATH="$TIEMU_DYLD_LIBRARY_PATH" "$TIEMU_BIN" "$ROM" \
  "-send=$REPO_DIR/output/stairs.89g" \
  "-exec=fatload()" \
  "-hwprot=0" &
echo "TiEmu PID: $!"
echo ""
echo "Done! TiEmu will auto-send files and run fatload() after boot."
