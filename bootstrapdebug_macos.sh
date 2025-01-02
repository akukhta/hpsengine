#!/bin/sh
conan install . --output-folder=cmake-build-debug --build=missing --profile:h=debugprofile_macos.txt --profile:b=debugprofile_macos.txt
cd bin
cmake .. -DCMAKE_BUILD_TYPE=Debug --preset=conan-debug
