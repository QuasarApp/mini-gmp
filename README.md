
# ![QtBigInt Logo](res/png/QtBigIntLogo2.png)

**QtBigInt** - Arbitrary-sized integer class for C++ and build system of Qt (qmake). Power by minigmp.


# Features
* No additional dependencies other than the standard library.
* Support for all arithmetic operators, which allows you to easily integrate the library into any of your algorithms.
* Based on the minigmp 6.1.2 library that provides high performance.

# Build


 * git clone https://github.com/QuasarApp/QtBigInt.git
 * cd QtBigInt
 * qmake -r 
 * make -j8
 * make test #(for testing)

# Include

## For qmake projects 

 * cd yourRepo
 * git submodule add https://github.com/QuasarApp/QtBigInt.git # add the repository of Qt-Secret into your repo like submodule
 * git submodule update --init --update
 * Include in your pro file the pri file of Qt-Secret library
  >> include($$PWD/QtBigInt/GMP.pri)
 * Rebuild yuor project

## For other build system
 
 * cd yourRepo
 * git submodule add https://github.com/QuasarApp/QtBigInt.git # add the repository of Qt-Secret into your repo like submodule
 * git submodule update --init --update
 * Add the rule for build Qt-Secret
 * Add INCLUDEPATH and LIBS for your build system 
 * Rebuild yuor project


# Usage
Create objects of the BigInt class, and do what you got to do!

``` cpp
#include <bigint.h>

BigInt big1 = 1234567890, big2;
big2 = "9876543210123456789098765432101234567890";

std::cout << (big1 * big2 * 123456).getSring() << "\n";
// Output: 1505331490682966620443288524512589666204282352096057600
```
