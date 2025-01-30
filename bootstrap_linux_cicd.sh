#!/bin/sh
vcpkg install --triplet=x64-linux
mkdir cmake-build-debug
cd cmake-build-debug
cmake .. --preset=conan-debug -DUSE_VCPKG=ON