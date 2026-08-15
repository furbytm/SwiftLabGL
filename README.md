# SwiftPM mirror of https://codeberg.org/meshula/LabGL

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

### Tonemap operators

**AgX** — filmic tone mapping algorithm, by Troy Sobotka and EaryChow's AgXBaseRec2020
matrices, used as the default view transform in Blender and adapted from Google Filament's
minimal AgX implementation.
Reference shaders: https://github.com/google/filament/blob/main/filament/src/ToneMapper.cpp
Original AgX: https://github.com/sobotka/AgX
EaryChow's AgX: https://github.com/EaryChow/AgX_LUT_Gen
Blender: https://www.blender.org
License: Apache 2.0
Credit is required if the code is distributed.

**ACES** — ACES RRT+ODT tone mapping is adapted from Filament's ACES implementation, by Google
Reference shaders: https://github.com/google/filament/blob/main/filament/src/ToneMapper.cpp
ACES: https://github.com/aces-aswf/aces-core
License: Apache 2.0
Credit is required if the code is distributed.

**Guy ACES, Hill ACES, Narkowicz ACES** — additional ACES curve fits, by Tizian Zeltner
https://github.com/tizian/tonemapper
License: MIT

**Filmic Tonemap Operators** — filmic tonemapping operators, by Tizian Zeltner
https://github.com/tizian/tonemapper
License: MIT

**Khronos PBR Neutral** — neutral tone mapper, by the Khronos Group
Reference shaders: https://github.com/KhronosGroup/ToneMapping/tree/main/PBR_Neutral
License: Apache 2.0
Credit is required if the code is distributed.

### Text shaping

**kb_text_shape** — single-header Unicode text segmentation and OpenType shaping, by Jimmy Lefevre
https://github.com/JimmyLefevre/kb (part of the `kb` single-header library collection)
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
