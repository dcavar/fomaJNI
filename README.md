# fomaJNI

Copyright 2018 by [Damir Cavar](http://damir.cavar.me/) <dcavar@indiana.edu>


Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.


## Introduction

The purpose of this code is to provide a C++ wrapper and a Java JNI interface to the binary [foma](https://fomafst.github.io) library. As the description of [foma](https://fomafst.github.io) says: "Foma is a compiler, programming language, and C library for constructing finite-state automata and transducers for various uses.", and in our case in particular for Natural Language Processing (NLP).

[Foma](https://fomafst.github.io) is very efficient and fast as a morphological analyzer and there are numerous morphologies or grammars publicly available for many languages.

I provide a simple binary English Finite State Transducer (eng.fst) in the example for the use with Foma. See details about how this loads in the Java and C++ code.

I have tested the code on Linux (Fedora 28) and Mac OSX. The C++ code should work with any C++11 compatible compiler. The Java code was compiled and tested with the current Oracle Java 10 release.

You will need to have:

- a Java SDK
- a C++ compiler
- Foma installed, including .h include files and libraries, you can tweak CMakeLists.txt to adapt to static or dynamic linking of those
- CMake

Follow the documentation of all these packages to learn more about their use, setup, configuration.


## Instructions

To build the system on Linux or MacOS, run the build.sh script.

These are the individual steps:

To compile the C++ components into the target library run:

	cmake .
	make

To generate the test binary:

	g++ -std=c++11  -L"/usr/local/lib" -L. -lfoma -lz -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" test.c FomaWrapper.cpp -o test

To generate the header and class file, assuming you use Java 8 or newer:

   javac -h include foma/App.java

Then check App.c and run on Mac:

  g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -dynamiclib -o libfomaJNI.dylib App.cpp FomaWrapper.cpp

On Linux do this:

  g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libfomaJNI.so App.cpp FomaWrapper.cpp

Run the app now with:

  java -Djava.library.path=. foma.App

