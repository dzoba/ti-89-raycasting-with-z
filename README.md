# TI-89 Height-Mapped Raycaster

A custom height-mapped raycasting engine and dungeon crawler game for the TI-89 graphing calculator, built on top of the 2002 FAT Engine. Renders textured walls, stair geometry, billboard enemy sprites, and procedurally generated dungeons on a 10MHz Motorola 68000 with a 160x100 4-shade grayscale LCD.

https://github.com/dzoba/ti-89-raycasting-with-z/raw/main/ti-89-dungeon-with-stairs.mp4

## What's here

**Descend** (`fatd_dungeon.c`) is a procedural dungeon crawler with:
- Height-mapped raycaster with per-tile floor elevations and stair-step rendering
- Textured walls and doors using the FAT Engine's texture system
- Billboard enemy sprites with mask-based transparency and per-column Z-buffer occlusion
- Procedural level generation (rooms, L-shaped corridors, triangle-wave staircases)
- Bump-to-attack combat, HP/level tracking, blinking minimap
- Smooth Z interpolation when walking up and down stairs

**Also included:**
- `fatd_stairs.c` -- standalone height-mapped raycaster demo with textured walls
- `fatd_hw4.c` -- fully self-contained version that runs on HW4 Titanium (no FAT Engine dependency)
- `fatd_life.c` -- Conway's Game of Life with bitwise parallel neighbor counting (50-100x faster than scalar)
- `fatd_plasma.c` -- real-time grayscale plasma effect
- `ti_send.c` / `ti_dbus_send.c` -- USB transfer tools for DUSB (Titanium) and DBUS (SilverLink) protocols

## Running on hardware

### You need
- A TI-89 (standard HW2 recommended) or TI-89 Titanium
- A USB cable: SilverLink (TI-GRAPH LINK) for standard TI-89, or direct USB for Titanium
- `libusb` installed (`brew install libusb` on macOS)

### Transfer prebuilt binaries

Prebuilt `.89y` and `.89z` files are in `output/`.

For a standard TI-89 with SilverLink cable:
```bash
# Build the transfer tool
cc -o ti_dbus_send tools/ti_dbus_send.c -lusb-1.0

# Send the FAT Engine runtime, textures, launcher, and dungeon game
./ti_dbus_send output/fatlib.89y output/fatdtx.89y output/fatload.89z output/fatddung.89y
```

For a TI-89 Titanium with direct USB:
```bash
cc -o ti_send tools/ti_send.c -lusb-1.0
./ti_send output/fatlib.89y output/fatdtx.89y output/fatload.89z output/fatddung.89y
```

On the calculator, run `fatload()` from the home screen.

**Note:** On the standard TI-89, archive `fatlib` and `fatdtx` to Flash ROM via VAR-LINK to free enough RAM for the engine to load.

**Note:** The full FAT Engine (textured walls, sprites) only works on standard TI-89 (HW1/HW2). The Titanium HW4 blocks heap code execution. Use `descend.89z` (the standalone flat-shaded version) on Titanium:
```bash
./ti_send output/descend.89z
# Then run descend() on the calculator
```

### Controls
- Arrow keys: move forward/backward, turn left/right
- ESC: quit

## Building from source

### Prerequisites
- Docker (for the GCC4TI cross-compiler)
- Python 3 (for .89g packaging)

### Build the Docker image (once)
```bash
docker build -t gcc4ti-builder .
```

### Build the dungeon crawler
```bash
cd tools
DRY_RUN=1 bash build_dungeon.sh
```

This compiles `src/fatd_dungeon.c` with GCC4TI inside Docker, exePack compresses it, and packages a `.89g` group file in `output/`.

Drop `DRY_RUN=1` to also launch TiEmu (requires a patched TiEmu build and a TI-89 ROM image).

## Project structure

```
src/              Source code for all demos and the dungeon crawler
src/includes/     FAT Engine header (fat.h)
tools/            Build scripts, packaging tools, USB transfer tools
output/           Prebuilt binaries ready to send to a calculator
fat-sdk/          Original 2002 FAT Engine SDK (engine, textures, examples)
Dockerfile        GCC4TI cross-compiler build environment
```

## About the FAT Engine

The [FAT Engine](http://tict.ticalc.org/) ("Fixed Angle Texturing") is a Wolfenstein 3D-style raycasting engine for TI-89/TI-92+ calculators, written by Thomas Nussbaumer and released in 2002 by the TiCT team. It renders 3D environments at 560-825 frames per minute on the 10MHz Motorola 68000.

The FAT Engine SDK is included in `fat-sdk/` for build purposes. The original SDK was distributed freely for TI calculator development but has no explicit open-source license. The SDK source, examples, and texture data are copyright Thomas Nussbaumer / TiCT. If you are the original author and have concerns, please open an issue.

## License

The custom source code in `src/` and `tools/` is released under the MIT License. The FAT Engine SDK in `fat-sdk/` retains its original copyright (see above).
