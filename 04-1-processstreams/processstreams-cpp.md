# Understanding stdin, stdout, and stderr in C++

When writing console applications, you often need to interact with users or other programs. C++ provides three standard streams for this purpose:

* **stdin** (standard input): For reading input.
* **stdout** (standard output): For writing normal output.
* **stderr** (standard error): For writing error messages.

Let’s explore these concepts using the following C++ program:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // Demonstrate stdin (standard input)
    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // Reads the entire line, including spaces

    // Demonstrate stdout (standard output)
    std::cout << "Hello, " << name << "! Enter your age: ";
    std::cin >> age;

    if (age < 0) {
        // Demonstrate stderr (standard error)
        std::cerr << "Error: Age cannot be negative!\n";
        return 1;
    }

    std::cout << "You are " << age << " years old.\n";
    return 0;
}
```

1. **stdin** – Standard Input
* **What is it?**

    `stdin` is the default stream from which your program reads input. In C++, this is represented by `std::cin`.

* **How is it used?**
    In the program, `std::getline(std::cin, name);` reads a full line of text (including spaces) from the user. Later, `std::cin >> age;` reads an integer from the user.

2. **stdout** – Standard Output
* **What is it?**
    
    `stdout` is the default stream where your program writes its normal output. In C++, this is `std::cout`.
* **How is it used?**
    The program uses `std::cout` to prompt the user and display results:
    * `std::cout << "Enter your name: ";`
    * `std::cout << "Hello, " << name << "! Enter your age: ";`
    * `std::cout << "You are " << age << " years old.\n";`

3. **stderr** – Standard Error
* **What is it?**
    * `stderr` is a separate output stream for error messages. In C++, this is `std::cerr`.
* **Why is it useful?**
    * Error messages sent to stderr can be separated from normal output, which is helpful for debugging or when redirecting output in scripts.
* **How is it used?**
    * If the user enters a negative age, the program writes an error message to stderr:
    * `std::cerr << "Error: Age cannot be negative!\n";`

## Why Separate Streams?
* **Redirection:**
    You can redirect **stdout** and **stderr** separately in the terminal. For example, you might want to save normal output to a file but still see errors on the screen.
* **Clarity:**
    Keeping errors separate from normal output makes it easier to debug and process program output.

