#!/bin/sh
conan install . --output-folder=cmake-build-debug --build=missing --profile:h=debugprofile_linux.txt --profile:b=debugprofile_linux.txt -c tools.system.package_manager:mode=install
cd cmake-build-debug
cmake .. --preset=conan-debug