# Environment Variables

Environment variables are another way for users to provide input to programs, similar to command line arguments. However, while command line arguments can be any string and appear in any format or order, environment variables always have a name and a value. For example, the values `123`, `41/23-A`, `--discount-applied`, `--destination=Kochi`, `-p 80:8080` are all valid command line arguments. Unlike command line arguments, which you specify each time you run a program, environment variables are often set once at the operating system/shell level and are available to all processes globally. [Do you know the difference between a program and a process?](https://www.youtube.com/watch?v=7ge7u5VUSbE&ab_channel=CoreDumped "A PROGRAM is not a PROCESS. (YouTube)"). The OS or shell also provides many useful environment variables by default, making it easier for programs to access important configuration and user information like `PATH`, `HOME`, `USER`, `SHELL`.

You can view all environment variables in a terminal with:
```bash
printenv
# or
env
```

## Accessing Environment Variables in C++

You can access environment variables in C++ using the `getenv` function from `<cstdlib>`.

### Example 1: Print the value of the HOME variable
```cpp
#include <iostream>
#include <cstdlib>

int main() {
    const char* home = std::getenv("HOME");
    if (home) {
        std::cout << "Your HOME directory is: " << home << std::endl;
    } else {
        std::cout << "HOME variable is not set." << std::endl;
    }
    return 0;
}
```

### Example 2: Print all environment variables
You can use the `environ` global variable (POSIX) to access all environment variables:
```cpp
#include <iostream>

extern char **environ;

int main() {
    for (char **env = environ; *env != nullptr; ++env) {
        std::cout << *env << std::endl;
    }
    return 0;
}
```

### Example 3: Setting an Environment Variable (in the shell)
You cannot set environment variables for the parent process from C++, but you can set them before running your program:
```bash
export MYNAME=arun
./myprogram
```
And in C++:
```cpp
#include <iostream>
#include <cstdlib>

int main() {
    const char* myname = std::getenv("MYNAME");
    if (myname) {
        std::cout << "MYNAME is: " << myname << std::endl;
    } else {
        std::cout << "MYNAME is not set." << std::endl;
    }
    return 0;
}
```

## Summary
- Use `getenv` to read environment variables in C++.
- Use `environ` to loop through all environment variables.
- Set variables in the shell before running your program.

**Tip:** Environment variables are inherited by child processes, so any program you launch from your shell will see the variables you set.
