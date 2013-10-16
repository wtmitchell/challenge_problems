Project Euler
=============

These are my solutions to problems found on ProjectEuler.net.

Feel free to look around, but if you just blindly use these answers, you're a bad person.

Dependencies
------------
* A recent C++ compiler
* CMake
* [GMP](http://gmplib.org)
* Python3
* Doxygen

Build
-----
Should be straight forward if the dependencies are installed.

    cmake path/to/src
    make -j 7
    make test

Executables created
-------------------
The *Tests executables are unit tests corresponding to each library inside the
lib directory.

pe runs either all problems or the problem number specified as the first argument.

Other build targets
-------------------
In addition to the default all target and test target, there are the following:
* docs - Runs Doxygen
* check-format - Runs clang-format over the source tree reporting differences
