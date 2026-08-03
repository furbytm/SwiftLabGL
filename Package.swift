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
    .executable(name: "LabGLExample", targets: ["LabGLExample"]),
  ],
  dependencies: [
    .package(url: "https://github.com/the-swift-collective/imgui.git", from: "1.91.5"),
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
      exclude: ["LabGL/src/backend/metal/labgl_window_metal.mm"],
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
  ],
  cxxLanguageStandard: .gnucxx20
)
