# Hello World

Let's learn how to make a computer say hello! We'll do this in two ways: using C++ and using a shell script (bash).

---

## 1. C++ Program

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

## 2. Bash Script

Bash is a simple way to tell your computer what to do using commands. The `echo` command prints text to the screen.

Try this in your terminal:
```bash
echo "Hello, bash"
```
You should see `Hello, bash` printed out.

Now, save this line in a file called `hello.sh`.

**Try to run it:**
```bash
./hello.sh
```
You might see an error: `Permission denied`. That's normal!

---

### How to Run Scripts in Linux

Linux doesn't run scripts just because they end with `.sh`. You need to do one of these:

1. Run it with bash:
   ```bash
   bash ./hello.sh
   ```
2. Make it executable:
   - Add this as the first line in `hello.sh`:
     ```bash
     #!/bin/bash
     ```
   - Give it permission to execute:
     ```bash
     chmod +x ./hello.sh
     ```
   - Now execute it:
     ```bash
     ./hello.sh
     ```

You should see the output now!

---

Feel free to ask questions or search online if you're curious about anything, like what "shebang" means.

Happy coding!