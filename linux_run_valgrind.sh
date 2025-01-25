#!/bin/sh
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --xml=yes --xml-file=valgrind_report.xml ./sdlplgrd