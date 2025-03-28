#!/bin/bash
set -e  # Exit immediately if a command fails

BUILD_DIR="build"

# Clean previous build artifacts
echo "🧹 Cleaning previous build..."
rm -rf $BUILD_DIR
rm -rf CMakeFiles

# Install dependencies with Conan
echo "📦 Installing dependencies with Conan..."
conan install . --output-folder=$BUILD_DIR --build=missing

# Run CMake to configure the project
echo "⚙️ Running CMake..."
cmake -S . -B $BUILD_DIR -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# Build the project
echo "🔨 Building project..."
cmake --build $BUILD_DIR --target CppLearn

echo "✅ Build completed!"
