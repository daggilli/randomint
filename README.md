# RANDOMINT

### Introduction

This is a very simple C++ class to provide a source of pseudorandom integers in a given range. The goal is for its usage to be a simple as possible. It is a header-only package.

### Requirements

A reasonably modern C++ compiler (C++17 or later).

### Installation

Clone the package, type `./CMAKE` in the project root and then `./INSTALL`. The header file, `randomint.hpp` will be installed in `/usr/local/include`.

### Usage

Include the header file

```c++
#include <tandomint.hpp>
```

Declare a generator

```c++
auto generator = RandomInt::RandomUint16Generator(1024,4096);
std::cout << generator() << "\n";
```

A very brief example of the salient points of usage is found in `src/test/main.cpp`.
