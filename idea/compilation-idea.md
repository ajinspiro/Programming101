https://clang.llvm.org/docs/ClangCommandLineReference.html#preprocessor-options

Prepare the main.cpp from 01.
Then run the below command. It runs the preprocessor only and outputs the result to main.ii.

```bash
clang++ --preprocess main.cpp -o main.ii
```
From the docs:
-E, --preprocess
Only run the preprocessor

The output is main.ii. This file contains all the declarations of iostream. Means, now the main method we wrote "knows how to call/use" the std::cout and std::cin. But it cannot do those operations yet.

Now run the command to create assembly source code file.
```bash
clang++ --assemble main.ii -o main.s
```
From the docs:
-S, --assemble
Only run preprocess and compilation steps

The output is main.s. This file is just like the main.cpp we wrote. main.cpp was source code for clang++, and this main.s file is source for something called the "assembler". The assembler can take in english like source code written in assembly and produce binary files that can be understood by machines. For obvious reasons, its not human readable and you need a hex editor to inspect the contents of this file. The main method we wrote is now converted into assembly. It still only knows that 2 things named cout and cin exists, and still our assembly code does not know how to perform those actions, i.e, how to take data from keyboard keystrokes and how to send "Hello, C++" to screen.


Now we will compile the assembly source file using the assembler that comes with clang++.
```bash
clang++ --compile main.s -o main.o
```
From the docs:
-c, --compile
Only run preprocess, compile, and assemble steps

This step will produce main.o. Its no longer human readable in any manner. You cannot open this file in notepad or vscode. To open this you need special tool called hex editor. Microsoft has one available in the vscode marketplace so that you can open files like main.o in vscode itself. You can try it. Even though main.o is machine code, it still does not know how to performs the actions std::cout and std::cin yet. And because of that, we cannot execute it yet.


Now the last step - Linking. We will take the standard library and link it with our main.o using the linker that comes with clang++.
```bash
clang++ main.o -o hello
```

The binary instructions machines use to print to screen and read from keyboard are available in standard library in ready to use form. This command takes that ready to use instructions and add it to our main.o, giving it the capabilities to write to screen and read from keyboard. Our program is now ready for execution.

```bash
./hello
```