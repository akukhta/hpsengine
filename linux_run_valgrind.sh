#!/bin/sh
cd cmake-build-debug/build/Debug
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --xml=yes --xml-file=../../../valgrind_report.xml ./sdlplgrd