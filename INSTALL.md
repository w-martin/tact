Installation instructions for mewt
==================================

## Disclaimer
This program is written in C++, and built using CMake.  
To build, you will need to have the following utilities and libraries 
installed: 
* A C compiler such as gcc or clang.
* A C++ compiler such a g++ or clang.
* Boost libraries (http://www.boost.org/) version 1.49.0 or higher.
* CMake (http://www.cmake.org/cmake/resources/software.html) build utility.
* A Python interpreter (http://www.python.org/) version 2.7.0 or higher.  

Please note that utilities and libraries with lower version numbers may work, 
but we cannot guarantee their compatibility.

## Building

1. Run "mkdir build"
2. Run "cd build"
3. Run "cmake .." to create the Makefile.
4. Run "make" to build.

## Installation

Once built: 
* Run "make install" to install.

## Testing

1. Run "mkdir build"
2. Run "cd build"
3. Run "cmake -D TESTING=FAST .." to create the Makefile with most tests enabled, or run "cmake -D TESTING=ALL .." to enable integration tests as well.
4. Run "make" to build.
5. Run "make test" to run tests.

## Running

Run "./mewt" to run the program from within the build directory, 
or if installed, just run "mewt".
