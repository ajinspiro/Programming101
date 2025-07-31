# Hello World

Let's learn how to make a computer say hello! We'll do this in two ways: using C++ and using a shell script (bash).

---

## 1. C++ Program

A C++ program is written as text (called source code). Computers can't run this text directly. We need a special tool called a **compiler** to turn our code into a program the computer can run.

Here's a simple C++ program. Save it as `main.cpp`:

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

If you want to name your program something else, use the `-o` option:
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
   - Give it permission to run:
     ```bash
     chmod +x ./hello.sh
     ```
   - Now run it:
     ```bash
     ./hello.sh
     ```

You should see the output now!

---

Feel free to ask questions or search online if you're curious about anything, like what "shebang" means.

Happy coding!