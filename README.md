Challenge Problems
==================
These are my solutions to problems from various programming challenge problem sites. At the moment it only includes problems from [Project Euler](ProjectEuler.net). In the future I plan to add the [Matasano Crypto Challenges](http://cryptopals.com/).

Feel free to look around, but if you just blindly use these answers, you're a bad person.

Dependencies
------------
* A recent C++ compiler. I use these problems to experiment with the new standards.
* CMake
* [GMP](http://gmplib.org)
* Python3
* Doxygen

Build
-----
Should be straight forward if the dependencies are installed. Depending on what you want it can be as simple as:

```
cmake path/to/src
make -j 7
make test
```

If you want clang + ninja, that first line could then be

```
CPP=clang++ CC=clang cmake -GNinja path/to/src
```

Executables created
-------------------
The *Tests executables are unit tests corresponding to each library inside the lib directory.

`pe` runs Project Euler solutions. Without argument it runs all problems, but if a number is specified as the first argument it will solve only that problem.

Other build targets
-------------------
In addition to the default all target and test target, there are the following:
* `docs` - Runs Doxygen
* `check-format` - Runs clang-format over the source tree reporting differences
