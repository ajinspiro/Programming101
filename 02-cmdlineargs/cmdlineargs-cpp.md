# Command line arguments

Programs like the "hello world" example we compiled earlier are simple and useful, but they don't let the user give any input. Most real programs become more helpful when they can take information from the user, do something with it, and then show a result. For example, Uber asks for your account info and location to find a taxi nearby.

There are different ways a program can get input from the user. In this lesson, we'll learn about command line arguments.

Below is a simple C++ program that parses command line arguments and prints them. We will use the argc (argument count) and argv (argument vector) parameters of the main method for this. Save it as `main.cpp`:

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Argument count: " << argc << std::endl;
    std::cout << "Program name: " << argv[0] << std::endl;
    if (argc < 2)
    {
        std::cout << "No additional arguments provided." << std::endl;
        return 0;
    }
    std::cout << "Arguments:" << std::endl;
    for (int i = 1; i < argc; ++i)
    {
        std::cout << '\t' << argv[i] << std::endl;
    }
    return 0;
}
```

**To compile:**
```bash
clang++ main.cpp -o cmdlineargs
```

**To run the program:**
```bash
./cmdlineargs
```
```bash
./cmdlineargs 123
```
```bash
./cmdlineargs arg1 arg2
```

### Parsing Specific Command Line Arguments

Below is source for a C++ program that takes input for an online taxi service like Uber. It parses and prints the values of `MYTAXI_USER` (for identifying which user is calling taxi), `MYTAXI_PICKUP_LOCATION` (where to send the taxi to pickup user), and `MYTAXI_DESTINATION_LOCATION` (where to drop the user off) from the command line arguments:

```cpp
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: ./cmdlineargs --MYTAXI_USER=<user> --MYTAXI_PICKUP_LOCATION=<pickup> --MYTAXI_DESTINATION_LOCATION=<destination>\n";
        return 1;
    }

    std::string user, hire_location, destination_location;
    std::string argname_user = "--MYTAXI_USER=", argname_pickup = "--MYTAXI_PICKUP_LOCATION=", argname_destination = "--MYTAXI_DESTINATION_LOCATION=";

    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.find(argname_user) == 0)
        {
            user = arg.substr(argname_user.length());
        }
        else if (arg.find(argname_pickup) == 0)
        {
            hire_location = arg.substr(argname_pickup.length());
        }
        else if (arg.find(argname_destination) == 0)
        {
            destination_location = arg.substr(argname_destination.length());
        }
    }

    std::cout << "User: " << (user.empty() ? "not set" : user) << std::endl;
    std::cout << "Pickup location: " << (hire_location.empty() ? "not set" : hire_location) << std::endl;
    std::cout << "Destination: " << (destination_location.empty() ? "not set" : destination_location) << std::endl;

    return 0;
}
``` 

This time try compiling the above source yourself. Output program should be `onlinetaxi`

**To run the program:**
```bash
./onlinetaxi --MYTAXI_USER=ARUN --MYTAXI_PICKUP_LOCATION=LuluMall --MYTAXI_DESTINATION_LOCATION=Airport
```


**Usage example:**
```sh
./mytaxi --MYTAXI_USERNAME=arun --MYTAXI_LOCATION=bangalore
```

Happy coding!