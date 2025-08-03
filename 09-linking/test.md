# Difference between --static and --fPIC Flags

## --static
- The `--static` flag is used to create a static library (`.a` file).
- Static libraries are archives of object files. When you link a program with a static library, all necessary code from the library is copied into the executable at compile time.
- The resulting executable is self-contained and does not require the library at runtime.

**Example:**
```bash
gcc -c foo.c -o foo.o
ar rcs libfoo.a foo.o   # Create static library
gcc main.c -L. -lfoo -o main_static --static
```

## --fPIC
- The `--fPIC` (Position Independent Code) flag is used when compiling source files to generate code that can be loaded at any memory address.
- This is required for creating shared libraries (`.so` files), which are loaded at runtime by programs.
- Shared libraries save memory and disk space, as multiple programs can use the same library code.

**Example:**
```bash
gcc -fPIC -c foo.c -o foo.o
gcc -shared -o libfoo.so foo.o   # Create shared library
gcc main.c -L. -lfoo -o main_shared
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./main_shared
```

## Summary Table

| Flag      | Library Type   | Linking Time | Memory Usage | Use Case                |
|-----------|---------------|--------------|--------------|-------------------------|
| --static  | Static (.a)   | Compile time | Higher       | Standalone executables  |
| --fPIC    | Shared (.so)  | Run time     | Lower        | Shared libraries (.so)  |
