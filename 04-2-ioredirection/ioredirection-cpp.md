# Bash I/O Redirection with C++

Explore how Bash redirects input and output streams—**stdin**, **stdout**, and **stderr**—using a simple C++ demo.

## Demo: Streams in C++

1. Save the below file as `main.cpp`.
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
2. Compile:
    ```bash
    clang++ streams_demo.cpp -o streams_demo
    ```
3. Run:
    ```bash
    ./streams_demo
    ```

## Common Redirection Examples

- Overwrite **stdout**:
  ```bash
  ./streams_demo > output.txt
  ```
- Append **stdout**:
  ```bash
  ./streams_demo >> output.txt
  ```
- Redirect **stderr**:
  ```bash
  ./streams_demo 2> error.txt
  ```
- Redirect both **stdout** and **stderr**:
  ```bash
  ./streams_demo &> all_output.txt
  ```
- Use file as **stdin**:
  ```bash
  ./streams_demo < input.txt
  ```
- Separate **stdout** and **stderr**:
  ```bash
  ./streams_demo > out.txt 2> err.txt
  ```

## Combined Redirection Example

Save the below source as `main.cpp`.
```cpp
#include <stdio.h>
#include <ctype.h>
int main(){
    int c;
    while ( ( c = getchar() ) != EOF )
    putchar(toupper(c));
    return 0;
}
```

Compile:
```bash
clang++ main.cpp -o upper
```
Run `upper` program with redirected input and output:
```bash
./upper < input.txt > output.txt
```
