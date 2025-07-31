# Hello world
### C++ program

In this chapter, we will write C++ source code that prints a greeting in screen, compile the source code to create a program and then execute the program. Source code or code is human readable text. It can be opened using notepad and read by a human because its just text. Source codes are NOT programs. Our laptops or smartphones cannot execute source code. Special programs called `compilers` create programs from source code. The output of compilers are programs which can be executed by laptops and smartphones, and such compiled programs cannot be opened using notepad. (To read the contents of a program, you need to use something called `hex editor`). The process of creating a program from source code is called `compilation`.

Save the following source code as `main.cpp`. 
```cpp
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello, C++" << std::endl;
    return 0;
}
```

**To compile**: `$ clang++ main.cpp`

This will compile `main.cpp` and creates a program in the same directory. By default the filename of the program will be `a.out`.

**To execute**: `$ ./a.out`

We can tell the compiler to give a custom name to our program using the `-o` flag.

**Compile again**: `$ clang++ main.cpp -o hello`

**Execute**: `$ ./hello`

### Shell script

We will do the same using bash. In bash, the `echo` command helps us write text to the screen just like the C++ `cout` operator.

Execute the following command in bash shell.
```bash
$ echo "Hello, bash"
```

You should be able to see the `Hello, bash` written to the screen. 

Now save the above echo command as a text file with name `hello.sh`. Lets try executing it. 

**To execute**: `$ ./hello.sh`

You must be seeing an error `bash: ./hello.sh: Permission denied`.

#### Script execution in linux

Unlike in Windows, Linux does not allow a script to execute just because its file extension is `.sh` or `.py`. To execute a script, you need to take 1 of the following 2 steps. Try both for learning purposes.

1. Execute it with bash command. `$ bash ./hello.sh`
2. Add something called 'shebang' to the script, make the file executable and then execute it.
    1. Add `#!/bin/bash` as the first line of the `hello.sh`
    2. Give execute permission to `hello.sh` file by running `$ chmod +x ./hello.sh`
    3. Execute the script again `$ ./hello.sh`

You should be able to see the output now. We will learn about shebang in detail later. Feel free to prompt/search about it.