#!/bin/sh
vcpkg install --triplet=x64-linux
mkdir cmake-build-debug
cd cmake-build-debug
cmake .. -DUSE_VCPKG=ON