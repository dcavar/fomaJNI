#!/bin/sh
javac -h include foma/App.java
cmake .
make
g++ -std=c++11  -L"/usr/local/lib" -L. -lfoma -lz -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" test.c FomaWrapper.cpp -o test

