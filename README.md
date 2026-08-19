# C++ Modules Project

This repository contains a series of C++ exercises organized by module, from `cpp00` through `cpp09`. Each folder is an independent project with its own `Makefile`, source files, and exercise-specific implementation.

## Project structure

- `cpp00` — basics of C++ syntax, I/O, classes, and introductory exercises
- `cpp01` — memory allocation, references, and zombie management
- `cpp02` — fixed-point numbers and operator overloading
- `cpp03` — inheritance and polymorphism
- `cpp04` — abstract classes, interfaces, and deep copies
- `cpp05` — exceptions and nested classes
- `cpp06` — casts and type reinterpretation
- `cpp07` — templates and generic programming
- `cpp08` — STL containers and algorithms
- `cpp09` — advanced C++ and templates

## Requirements

- A C++ compiler such as `g++`
- `make`
- A Unix-like environment (Linux/macOS)

## Build and run

Each exercise is built independently.

Example:

```bash
cd cpp00/ex00
make
./megaphone
```

Or for another module:

```bash
cd cpp02/ex00
make
./Fixed
```

## Common Make targets

Most projects support the following commands:

```bash
make        # compile the program
make clean  # remove object files
make fclean # remove object files and binary
make re     # rebuild from scratch
```

## Notes

- The project targets C++98 compatibility (`-std=c++98` in the Makefiles).
- Each exercise is self-contained and can be compiled from its own directory.
- This is a learning-focused project intended to practice object-oriented programming, memory management, and modern C++ fundamentals.

## License

This project is for educational purposes and is part of the C++ learning curriculum.
