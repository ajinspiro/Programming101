# Using `dlopen` to Load and Use Dynamic Libraries at Runtime in C/C++

Dynamic loading of libraries at runtime is a powerful feature in Unix-like systems, allowing programs to load, link, and use shared libraries as needed, rather than at compile time. This is especially useful for plugins, modular applications, or when you want to reduce memory usage by loading code only when required.

This article demonstrates how to use the `dlopen`, `dlsym`, and `dlclose` functions from `<dlfcn.h>` to load and use a dynamic library at runtime in C/C++.

## 1. Creating a Simple Dynamic Library

Let's create a simple shared library that provides a function to add two integers.

**File: `mylib.c`**
```c
// mylib.c
int add(int a, int b) {
    return a + b;
}
```


Compile this file into a shared library using `clang++`:
```bash
clang++ -fPIC -shared -o libmylib.so mylib.c
```

## 2. Writing a Program to Load the Library at Runtime

Now, let's write a program that loads this library at runtime, finds the `add` function, and uses it.

**File: `main.c`**
```c
#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add_func)(int, int);
    char *error;

    // Load the shared library
    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Clear any existing error
    dlerror();

    // Get a pointer to the 'add' function
    *(void **) (&add_func) = dlsym(handle, "add");
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    // Use the function
    int result = add_func(2, 3);
    printf("2 + 3 = %d\n", result);

    // Close the library
    dlclose(handle);
    return 0;
}
```

## 3. Compiling and Running the Program


Compile the main program, linking with the dynamic linking library using `clang++`:
```bash
clang++ -o main main.c -ldl
```

Make sure `libmylib.so` is in the current directory or in your `LD_LIBRARY_PATH`.

Run the program:
```bash
./main
```
Output:
```
2 + 3 = 5
```

## 4. Explanation
- `dlopen`: Loads the shared library into memory.
- `dlsym`: Looks up the address of the symbol (function) in the loaded library.
- `dlclose`: Unloads the library.
- `-ldl`: Links the program with the dynamic linking loader library.

## 5. Use Cases
- Plugin systems (load plugins at runtime)
- Optional features (load only if needed)
- Reducing memory footprint

## 6. Error Handling
Always check the return values of `dlopen` and `dlsym`, and use `dlerror()` to get error messages.

---

This approach allows you to build flexible and modular applications that can load and use code dynamically at runtime.
