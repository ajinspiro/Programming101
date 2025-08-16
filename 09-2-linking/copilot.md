# Static Linking vs Dynamic Linking in C++

This guide explains the difference between static and dynamic linking in C++, with code examples and commands.

---

## Static Linking

With static linking, all the code your program needs (including libraries) is combined into a single executable at compile time. The executable does not need external library files at runtime.

### Example

Suppose you have a simple library (`libdemo.cpp`):

```cpp
#include <iostream>
void hello() {
    std::cout << "Hello from library!\n";
}
```

Compile it to a static library:

```bash
clang++ -c libdemo.cpp -o libdemo.o
ar rcs libdemo.a libdemo.o # creating archive
```

Your main program (`main.cpp`):

```cpp
void hello();
int main() {
    hello();
    return 0;
}
```

Compile and link statically:

```bash
clang++ main.cpp -L. -ldemo -static -o statically_linked
```

Now, `./statically_linked` will run without needing any external `.so` or `.dll` files.

---

## Dynamic Linking

With dynamic linking, your program uses external shared libraries (`.so` on Linux, `.dll` on Windows) at runtime. The executable is smaller, but the library must be available when you run the program.

### Example

Compile `libdemo.cpp` as a shared library:

```bash
clang++ -fPIC -shared libdemo.cpp -o libdemo.so
```

Compile and link `main.cpp` dynamically:

```bash
clang++ main.cpp -L. -ldemo -o dynamically_linked
```

To run the program, set `LD_LIBRARY_PATH` to include the directory with `libdemo.so`:

```bash
LD_LIBRARY_PATH=. ./dynamically_linked
```

TODO: Remove the export command from above and instruct the student to append a period(.) to the end of LD_LIBRARY_PATH.
They are supposed to use `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.`

If you do not set `LD_LIBRARY_PATH`, the program will fail to run because it cannot find the shared library.

---

## Summary

- **Static linking:** All code is included in the executable; no external libraries needed at runtime.
- **Dynamic linking:** Executable is smaller; needs shared libraries at runtime.