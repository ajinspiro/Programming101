
# Step-by-Step: How a C++ Program Gets Compiled (Beginner Friendly)

Let's see how your C++ code (main.cpp) is turned into something your computer can run, using clang++. We'll break it down into simple steps.

---

Save the below code as `main.cpp`.
```cpp
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello, C++" << std::endl;
    return 0;
}
```

## 1. Preprocessing

The first step is to run the preprocessor. This expands all the `#include` and `#define` statements in your code.

**Command:**
```bash
clang++ --preprocess main.cpp -o main.ii
```
**What happens?**
- This creates a file called `main.ii`.
- `main.ii` is just your code with all the includes and macros expanded. It still looks like C++ code, but much longer!

---

## 2. Compiling to Assembly

Next, we turn the preprocessed code into assembly language, which is a low-level language closer to what the computer understands.

**Command:**
```bash
clang++ --assemble main.ii -o main.s
```
**What happens?**
- This creates a file called `main.s`.
- `main.s` is written in assembly language. It's not easy to read unless you know assembly, but it's still text.

---

## 3. Assembling to Object Code

Now, we turn the assembly code into machine code (object file). This is what the computer actually understands, but it's not yet a full program.

**Command:**
```bash
clang++ --compile main.s -o main.o
```
**What happens?**
- This creates a file called `main.o`.
- `main.o` is a binary file (not human-readable). It contains your code in machine language, but it can't run by itself yet.

---

## 4. Linking

The last step is to link your object file with the C++ standard library. This adds all the code needed for things like `std::cout` and `std::cin` to work.

**Command:**
```bash
clang++ main.o -o hello
```
**What happens?**
- This creates an executable file called `hello`.
- Now your program knows how to print to the screen and read from the keyboard, because it has all the necessary code from the standard library.

---

## 5. Run Your Program

**Command:**
```bash
./hello
```
You should see your program's output!

---

**Summary:**
1. Preprocess: `main.cpp` → `main.ii`
2. Compile: `main.ii` → `main.s`
3. Assemble: `main.s` → `main.o`
4. Link: `main.o` + standard library → `hello`
5. Run: `./hello`

You can do all these steps in one go with just:
```bash
clang++ main.cpp -o hello
```
But breaking it down helps you understand what happens at each stage!