# Demonstrating Relocation with Code

This example shows how relocation works in C programs using object files and the linker.

## Source Files

**foo.c**
```c
int foo() {
    return 42;
}
```

**main.c**
```c
#include <stdio.h>

int foo(); // Declaration

int main() {
    printf("%d\n", foo());
    return 0;
}
```

## Steps to Observe Relocation

1. **Compile without linking:**
   ```bash
   gcc -c foo.c   # produces foo.o
   gcc -c main.c  # produces main.o
   ```

2. **Check relocation entries:**
   ```bash
   readelf -r main.o
   ```
   You will see entries showing that the address of `foo` is not yet resolved (relocation entries).

3. **Link the object files:**
   ```bash
   gcc main.o foo.o -o main
   ```

4. **Check the executable:**
   Now, all addresses are resolved. The linker has relocated the references to `foo` in `main.o` to the actual address in the final executable.

## Summary
- Before linking, references to external functions are placeholders (relocation entries).
- After linking, these are replaced with real addresses, allowing the program to run.

You can use `readelf -r` or `objdump -r` to inspect relocation entries in object files before linking.
