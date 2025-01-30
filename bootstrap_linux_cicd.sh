#!/bin/sh
mkdir cmake-build-debug
cd cmake-build-debug
cmake .. -DUSE_VCPKG=ON
cmake --build .