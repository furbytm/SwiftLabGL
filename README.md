# SwiftPM mirror of https://codeberg.org/meshula/LabGL

This project starts from the idea of creating a fantasy graphics platform in the same spirit as QuadPlay and PICO-8. The fantasy is this:

> What if GL 1.1 was the best version of OpenGL ever created?

LabGL is an immediate-mode graphics library with a classic GL 1 API surface — `glBegin` / `glEnd`, `glVertex`, `glColor`, `glMatrix` — reimagined over modern OpenGL and Metal. The same GL code compiles to either backend without changes.

The dispatch layer is a thin macro shim: every `glFoo(...)` call expands to`LABGLDISPATCH_glFoo(...)`, which the active backend implements. The original idea for the structure is due to **Eric Johnston** at *LucasArts*. He created a library called LecGL during the development of *Star Wars Episode 1 Racer*, for Nintendo 64. The library functioned as a portability layer, allowing prototyping on *Silicon Graphics* hardware, and deployment on shipping console hardware.

LabGL therefore originated as a recreation of the general concept but geared towards rapid and fun prototyping today. It's subsequently grown with features such as text rendering, things that I always wished graphics APIs just provided straight out of the box without fuss. It is a fantasy graphics platform after all!

---

## Showcase

### Font Demo — Slug GPU font rendering + LaTeX math

Something I always wish for in every graphics API is straight forward text rendering, so I imagined my dream text render as if it was part of GL 1.1.

LabGL renders text directly from TrueType/OpenType outlines on the GPU using Eric Lengyel's [Slug algorithm](https://sluglibrary.com/). Rather than using pre-rasterized atlases, Slug saves a texture of curve crossings that allow a shader to render fonts on the GPU. The result is sub-pixel quality antialiased type at any size. The demo implements full OpenType shaping for complex scripts, including bidirectional scripts.

It also incorporates a LaTeX math renderer.

![Font Demo Screenshot](https://codeberg.org/meshula/LabGL/media/branch/dev/assets/17743234161064.jpg)

The screenshot illustrates:

- **Multi-font rendering** — CascadiaMono (monospace), Latin Modern Roman (serif), and STIX (Math) in a single frame
- **Stateful pen API** — `glFont()` + `glText()` + `glTextAt()` + `glTextAdvanceEm()` for mid-line font and color switches
- **Animated size** — point size driven by `sin(t)` each frame
- **Per-character color** — animated rainbow cycling across a full alphabet
- **OpenType shaping** — Devanagari Heart Sutra with conjunct consonants via kb_text_shape
- **LaTeX math** — featureful inline math renderer: fractions, radicals, integrals, matrices, set theory

---

### Tron Demo — "This is Unix!" filesystem visualizer

A perspective 3D view of your filesystem rendered as a glowing green vector city, inspired by the Jurassic Park / Tron aesthetic. It's not terribly useful, and the camera controls are terrible. It is fun to just knock things out with this olden API though.

![Tron Demo Visualizer](https://codeberg.org/meshula/LabGL/media/branch/dev/assets/17743239344716.jpg)

- **Streets** = directories (flat ground plane, path label on pavement)
- **Buildings** = files (wireframe box; height ∝ log(size))
- **Filenames** = Slug text labels above each building
- **Boids** = Reynolds' boid flock flying overhead, just because
- **Data clouds** = floating wireframe tori for other mounted volumes

Controls: `ESC`/`Q` quit · mouse drag orbit · scroll zoom · `Space` pause · `R` re-scan

---

### Panel Viewer — Clay UI + LabLayout declarative panels

A three-panel application layout built with [Clay](https://github.com/nicbarker/clay) and driven by a declarative LabLayout spec string. Demonstrates embedding a 3D L-system viewport inside 2D UI chrome.

![L-System Viewer](https://codeberg.org/meshula/LabGL/media/branch/dev/assets/17743241129720.jpg)

- Toolbar, left inspector, main 3D viewport, right panel
- Layout declared as a YAML-like DSL parsed once at startup
- Clay handles all 2D hit-testing and hover highlighting
- VoxTree L-system renders live inside the `Viewport` element

---

## Capture and Playback

LabGL has a built-in call-capture system. Every `LABGLDISPATCH_*` call can be recorded into a **`.lglcap`** text file alongside a binary **`.lglblob`** sidecar. Captures are human-readable, diffable, and suitable for unit tests or QA hand-off.

### What gets captured

- **Immediate-mode draw calls** — `glBegin`/`glEnd`, vertex/color/normal/texcoord
- **State changes** — enable/disable, blend, depth, cull, scissor, viewport
- **Matrix operations** — push/pop, translate, rotate, scale, frustum, ortho, lookAt
- **Lighting and materials** — per-light parameters, global ambient, material properties, color material mode
- **Font/text** — `glFont`/`glText` calls (Slug GPU text)
- **Vertex array draws** — `glDrawElements`/`glDrawArrays` geometry stored in the `.lglblob` sidecar with hash-based deduplication (instanced meshes stored once)
- **Texture uploads** — `glTexImage2D` pixel data stored in the `.lglblob` with dedup

And so on; everything should be covered; if not, that's a bug.

### State preamble

A capture begins with a full snapshot of `g_labglState` — all enable bits,
lighting, materials, viewport, depth, blend, etc. — decomposed into equivalent
GL text commands. This ensures captures are self-contained and replay correctly
regardless of the GL context they were recorded from.

### Usage

Record a single frame:

```c
labgl_captureStart(buf);
labgl_captureEmitPreamble();   // snapshot current state
// ... render frame ...
labgl_captureStop();
labgl_captureSave(buf, "frame.lglcap");
```

Play it back with the `playback` / `playback_metal` sample programs:

```sh
./build/playback_metal frame.lglcap
```

See **[docs/capture-system.md](https://codeberg.org/meshula/LabGL/src/branch/dev/docs/capture-system.md)** for the full API
reference, file format details, and using captures as a performance tool
(memoizing procedural generation, offline baking, future optimization passes).

See **[docs/debugging-facilities.md](https://codeberg.org/meshula/LabGL/src/branch/dev/docs/debugging-facilities.md)** for
annotations, hazard detection, state dumps, breakpoint hooks, and capture
stats.

See **[docs/quickstart.md](https://codeberg.org/meshula/LabGL/src/branch/dev/docs/quickstart.md)** for a full project overview,
architecture walkthrough, and context reload.

---

## Building

### Linux prerequisites (Ubuntu / Debian)

```sh
sudo apt install build-essential cmake libx11-dev libxrandr-dev libxcursor-dev libxi-dev libgl-dev zlib1g-dev
```

### Desktop Build

```sh
git clone https://codeberg.org/meshula/LabGL.git
cd LabGL
cmake -B build
cmake --build build
```

### iOS Build

To configure:
```sh
  cd build-ios
  cmake .. \
    -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_SYSROOT=iphoneos \
    -DCMAKE_OSX_ARCHITECTURES=arm64 \
    -DCMAKE_OSX_DEPLOYMENT_TARGET=16.0 \
    -DLABGL_BUILD_VOXTREE=OFF \
    -DLABGL_ENABLE_IMGUI=OFF
```

To build:
```sh
cmake -B build-ios
cmake --build build-ios
```

Dependencies (FreeType, GLM, LabText, LabCamera — plus OpenVDB + TBB for the optional voxtree build) are resolved `find_package`-first, so an installed copy is used when available; CMake `FetchContent` is the automatic fallback when one isn't found.

Certain third-party libraries are vendored in `vendor/`: Clay, RGFW, glad.

To build the `voxtree` CLI (L-System to OpenVDB voxelizer), enable the optional OpenVDB + TBB dependencies:

```sh
cmake -B build -DLABGL_BUILD_VOXTREE=ON
```

### Targets

| Target | Description |
|---|---|
| `hello_triangle` / `hello_triangle_metal` | Minimal immediate-mode example |
| `tex_demo` / `tex_demo_metal` | Procedural texture + UV mapping example |
| `font_demo` / `font_demo_metal` | Font + math showcase |
| `tron_demo` / `tron_demo_metal` | Filesystem visualizer |
| `panel_viewer` / `panel_viewer_metal` | Clay UI panel layout |
| `playback` / `playback_metal` | Replay a `.lglcap` capture file |
| `voxtree` | L-System → OpenVDB CLI tool (requires `-DLABGL_BUILD_VOXTREE=ON`) |
| `voxtree_viewer` / `voxtree_viewer_metal` | Interactive VoxTree viewer |

There are a lot more examples in both the `examples` and `showcase` directories.

Metal targets are macOS-only. All OpenGL targets work on macOS and Linux.

### Testing

LabGL ships a small [ctest](https://cmake.org/cmake/help/latest/manual/ctest.1.html)-based unit suite under `tests/`.

```sh
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Configure with `-DLABGL_BUILD_TESTS=OFF` to skip building the suite. Add a new test by dropping a `.cpp` into `tests/` and registering it in `tests/CMakeLists.txt` via the `labgl_add_test()` helper.

---

## License

All files copyright (c) 2026 Nick Porcino, and released under a BSD 3-clause license. Certain files as noted are covered by their own licenses.


## Thanks

Special thanks to **Eric Lengyel** for teaching us the Slug technique and releasing a reference HLSL shader.
Special thanks to **Michael Nicolella** and **Patrick Doane** for brainstorming and helpful suggestions.

LabGL builds on the following third-party libraries and fonts.

### Rendering algorithms

**Slug** — GPU font rendering algorithm by Eric Lengyel
Reference shaders: https://github.com/EricLengyel/Slug
Paper: https://jcgt.org/published/0006/02/02/ (JCGT 2017)
License: dual MIT / Apache 2.0. The patent has been dedicated to the public domain.
Credit is required if the code is distributed.

### Text shaping

**kb_text_shape** — single-header Unicode text segmentation and OpenType shaping, by Jimmy Lefevre
https://github.com/jlefevre/kb (part of the `kb` single-header library collection)
License: zlib

**FreeType** — font loading and outline extraction
https://freetype.org
License: FreeType License (BSD-style) / GPLv2

### UI and windowing

**Clay** — immediate-mode UI layout library by Nic Barker
https://github.com/nicbarker/clay
License: zlib

**RGFW** — single-header cross-platform windowing by ColleagueRiley
https://github.com/ColleagueRiley/RGFW
License: zlib

**glad2** — GL loader generator
https://github.com/Dav1dde/glad
License: generated code is WTFPL / CC0; loader itself is Apache 2.0

### Math and geometry

**GLM** — OpenGL Mathematics library
https://github.com/g-truc/glm
License: MIT

**par_shapes** — triangle mesh generation, by Philip Rideout
https://github.com/prideout/par
License: MIT

**LabCamera** — interactive camera controller, by Nick Porcino
https://github.com/meshula/LabCamera
License: MIT

**LabText** — text utilities, by Nick Porcino
https://github.com/meshula/LabText
License: MIT

**OpenVDB** — sparse volumetric data structure (used by the VoxTree demo)
https://www.openvdb.org
License: MPL 2.0

**oneTBB** — Intel Threading Building Blocks (OpenVDB dependency)
https://github.com/oneapi-src/oneTBB
License: Apache 2.0

### Fonts

**Cascadia Mono** — monospace programming font by Microsoft
https://github.com/microsoft/cascadia-code
License: SIL Open Font License 1.1

**Latin Modern** — TeX math serif family, derived from Computer Modern, by B. Jackowski & J.M. Nowacki / GUST
https://www.gust.org.pl/projects/e-foundry/latin-modern
License: GUST Font License (permissive, similar to LPPL)

**STIX Two Math** — mathematical OpenType font by the STIX Fonts Project
https://github.com/stipub/stixfonts
License: SIL Open Font License 1.1

**Noto Sans Devanagari** — Devanagari script font by Google
https://github.com/google/fonts/tree/main/ofl/notosansdevanagari
License: SIL Open Font License 1.1
