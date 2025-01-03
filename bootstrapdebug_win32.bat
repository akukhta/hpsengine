conan install . --output-folder=build --build=missing --profile:h=debugprofile_win32.txt --profile:b=debugprofile_win32.txt
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug --preset=conan-default
