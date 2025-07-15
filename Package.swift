
// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.


import PackageDescription

let package = Package(
    name: "FSPlayerLib",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "FSPlayerLib",
            targets: ["FSPlayerLib","FSPlayer"]),
    ],
    dependencies: [
        .package(url: "https://github.com/apple/swift-protobuf.git", from: "1.28.2"),
        .package(url: "https://github.com/1024jp/GzipSwift", from: "6.0.0"),
    ],
    targets: [
        
        .binaryTarget(name: "FSPlayer", path: "FSPlayer.xcframework"),
        .target(name: "FSPlayerLib",dependencies: [
            "FSPlayer",
            .product(name: "SwiftProtobuf", package: "swift-protobuf"),
            .product(name: "Gzip", package: "GzipSwift"),
        ]),
          
    ],
    swiftLanguageVersions: [.v5]

)
