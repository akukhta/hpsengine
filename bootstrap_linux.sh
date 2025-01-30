#!/bin/sh
sudo conan install . --output-folder=cmake-build-debug --build=missing --profile:h=debugprofile_linux.txt --profile:b=debugprofile_linux.txt
cd cmake-build-debug
cmake .. --preset=conan-debug