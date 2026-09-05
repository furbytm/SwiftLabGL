// swift-tools-version:6.0
import PackageDescription

let package = Package(
  name: "SwiftLabGL",
  platforms: [
    .macOS(.v15),
    .visionOS(.v1),
    .iOS(.v17),
    .tvOS(.v17)
  ],
  products: [
    .library(name: "LabGL", targets: ["LabGL"]),
    .library(name: "LabFX", targets: ["LabFX"]),
    .library(name: "LabFXShaders", targets: ["LabFXShaders"]),
    .library(name: "LabFXParser", targets: ["LabFXParser"]),
    .library(name: "LabText", targets: ["LabText"]),
    .executable(name: "LabGLExample", targets: ["LabGLExample"]),
  ],
  dependencies: [
    .package(url: "https://github.com/the-swift-collective/imgui.git", from: "1.92.0"),
  ],
  targets: [
    .executableTarget(
      name: "LabGLExample",
      dependencies: ["LabGL"],
      swiftSettings: [
        .interoperabilityMode(.Cxx)
      ]
    ),

    .target(
      name: "CNanocolor",
      path: "Nanocolor",
      exclude: ["cmake", "CMakeLists.txt", "Nanocolor-Introduction.pdf"],
      sources: ["nanocolor.c", "nanocolorUtils.c"],
      publicHeadersPath: "."
    ),

    .target(
      name: "LabGL",
      dependencies: [
        .target(name: "CNanocolor"),
        .product(name: "ImGui", package: "imgui"),
      ],
      path: ".",
      exclude: [
        "LabGL/build"
      ],
      sources: [
        "LabGL/src/core",
        "LabGL/src/backend/metal",
        "LabGL/src/capture/labgl_capture.cpp",
        "LabGL/src/capture/labgl_image_metal.mm",
        "LabGL/src/labgl_sysinfo.cpp",
      ],
      publicHeadersPath: "include",
      cxxSettings: [
        .define("BUILDING_LABGL"),
        .headerSearchPath("LabGL/src/core"),
        .headerSearchPath("LabGL/src/backend/metal"),
        .headerSearchPath("LabGL/src/capture"),
        .headerSearchPath("LabGL/src"),
        .headerSearchPath("LabGL/vendor"),
        .headerSearchPath("LabGL/support"),
        .headerSearchPath("LabGL/include"),
        .headerSearchPath("."),
      ],
      linkerSettings: [
        .linkedFramework("Metal"),
        .linkedFramework("QuartzCore"),
        .linkedFramework("Cocoa"),
      ]
    ),

    .target(
      name: "LabFX",
      dependencies: [
        .target(name: "LabGL"),
        .target(name: "LabFXParser"),
        .target(name: "LabFXShaders"),
      ],
      path: ".",
      exclude: [
        "LabGL/build"
      ],
      sources: [
        "LabGL/showcase/labfx/labfx_runtime.cpp",
      ],
      publicHeadersPath: "include/labfx",
      cxxSettings: [
        .headerSearchPath("LabGL/showcase/labfx"),
        .headerSearchPath("."),
      ]
    ),

    .target(
      name: "LabFXShaders",
      dependencies: [
        .target(name: "LabFXParser"),
      ],
      path: "LabGL/showcase/labfx/shaders",
      sources: [
        "labfx_shaders_tonemap.cpp",
        "labfx_shaders_sky.cpp",
        "labfx_shaders_sky_data.cpp",
        "labfx_shaders_ibl.cpp",
      ],
      publicHeadersPath: "."
    ),
    
    .target(
      name: "LabFXParser",
      dependencies: [
        .target(name: "LabText"),
      ],
      path: "LabFXParser"
    ),

    .target(
      name: "LabText",
      path: "LabText",
      cxxSettings: [
        .define("LABTEXT_ODR")
      ]
    ),
  ],
  cxxLanguageStandard: .gnucxx20
)
