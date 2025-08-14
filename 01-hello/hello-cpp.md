# Hello World

Let's learn how to make a computer say hello! We'll do this using C++.

---

A C++ program starts as **source code**, which is plain text that humans can write and read using editors like Notepad. This source code describes what we want the computer to do, but computers can't run it directly. To make it runnable, we use a **compiler** to convert the source code into a **program**—a binary file that only machines can read and execute. Humans can't easily understand these binary files; to view or edit them, you'd need a special tool like a hex editor.

Here's the source code for a simple C++ program. Save it as `main.cpp`:

```cpp
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello, C++" << std::endl;
    return 0;
}
```

**To compile:**
```bash
clang++ main.cpp
```
This makes a program called `a.out` in the same folder.

**To run the program:**
```bash
./a.out
```
You should see `Hello, C++` on the screen!

We can tell the compiler to give a custom name other than `a.out` to our program using the `-o` flag.
```bash
clang++ main.cpp -o hello
./hello
```

---
Happy coding!