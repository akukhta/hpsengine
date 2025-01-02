#!/bin/sh
conan install . --output-folder=bin --build=missing
cd bin
cmake .. --preset=conan-release
#cmake --build
