LD_LIBRARY_PATH
create a demo function, make library and put the containing folder in LD_LIBRARY_PATH. Then demonstrate the compiler failing before setting the LD_LIBRARY_PATH and succeeding after setting LD_LIBRARY_PATH.

explain static linking and dynamic linking.
explain using `ldd` output
explain the difference in addressing. fixed position instructions vs position independent instructions.


There are two main types:

1. Static relocation: Done by the linker when creating the final executable. All addresses are fixed before the program runs.
2. Dynamic relocation: Done by the loader at runtime, especially for shared libraries. The loader updates addresses so the program and libraries can coexist in memory, even if loaded at different locations each time.

TODO: relocation_demo.md

`readelf` is a command-line tool on Linux used to display information about ELF (Executable and Linkable Format) files, such as executables, object files, and shared libraries. It can show headers, sections, symbols, relocation entries, and more, helping you inspect how binaries are structured and linked.
Example usage: 
clang++ hello.cpp -o hello
readelf -h hello           # ELF header
readelf -S hello           # Section headers
readelf -l hello           # Program headers
readelf -s hello | grep main  # Locate the main symbol
readelf -r main.o    # Show relocation entries