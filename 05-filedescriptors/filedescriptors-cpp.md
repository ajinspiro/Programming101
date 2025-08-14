# File Descriptors in C++

File descriptors are low-level integer handles used by the operating system to access files and I/O resources. In C++, especially when using POSIX APIs, file descriptors provide a way to interact directly with files, sockets, and other resources.

## Basics

- **0**: Standard Input (`stdin`)
- **1**: Standard Output (`stdout`)
- **2**: Standard Error (`stderr`)

When you open a file using system calls like `open()`, the OS returns a file descriptor.

## Example: Using File Descriptors

```cpp
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    const char* msg = "Hello, file descriptors!\n";
    write(fd, msg, 25); // Write to the file using the descriptor

    close(fd); // Always close when done
    return 0;
}
```

## Notes

- File descriptors are not the same as C++ file streams (`std::ifstream`, `std::ofstream`).
- Use `open()`, `read()`, `write()`, and `close()` for file descriptor operations.
- Always close file descriptors to avoid resource leaks.

File descriptors are essential for low-level file and device I/O in C++ on Unix-like systems.