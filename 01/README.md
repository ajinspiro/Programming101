# Hello world program

In this chapter, we will print a greeting in screen. Save the following source code as `main.cpp`. A source code is human readable text or string. It can be opened using notepad and read by a human because its just text. Source codes are NOT programs. Our laptops or smartphones cannot execute them. Special programs called `compilers` create programs from source code. The output of compilers are executables which can be executed by out laptops and smartphones, and they cannot be opened using notepad. (To read the contents of a program, you need to use something called `hex editor`). The process of creating a program from source code is called `compilation`.

```cpp
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello, C++" << std::endl;
    return 0;
}
```

To compile: `$ clang++ main.cpp`

This will compile `main.cpp` and creates a program in the same directory. By default the filename of the program will be `a.out`.

To execute: `$ ./a.out`

We can tell the compiler to give a custom name to our program using the `-o` flag.

Compile again: `$ clang++ main.cpp -o hello`

Execute: `$ ./hello`


TODO: echo "Hello, bash"