#!/bin/bash
set -e  # Exit immediately if a command fails

BUILD_DIR="cmake-build-debug"

echo "Deleting the old stuff"
rm -rf cmake-build-debug

echo "📦 Installing dependencies with Conan..."
conan install . --output-folder=$BUILD_DIR --build=missing

echo "⚙️ Running CMake with Unix Makefiles..."
cmake -S . -B $BUILD_DIR -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

echo "🔨 Building project..."
cmake --build $BUILD_DIR

echo "✅ Build completed!"
