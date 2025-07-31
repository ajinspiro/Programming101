
TODO: 
./printEnv
This program should print environment variable "arun" and "number". Use std::getenv function in c++ to do that. When the env variables are not available, print a "hello not set" and "number not set" message.
export hello="hello c++"
export number=323
 
explain ~/.bashrc and /etc/environment

explain system environment variable PATH
explain export PATH=$PATH:.
TODO: https://chatgpt.com/share/68881a30-652c-8002-b5b9-5bb04e824fb2

TODO: use echo command to print env variable



```cpp
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    const char* location = std::getenv("MYTAXI_LOCATION");
    const char* username = std::getenv("MYTAXI_USERNAME");

    if (location) {
        std::cout << "MYTAXI_LOCATION (Taxi will be sent here): " << location << std::endl;
    } else {
        std::cout << "Oops. Couldn't get your location. Environment variable MYTAXI_LOCATION not set." << std::endl;
    }

    if (username) {
        std::cout << "MYTAXI_USERNAME (To identify which user booked the taxi):" << username << std::endl;
    } else {
        std::cout << "Oops. Couldn't identify you. Environment variable MYTAXI_USERNAME not set" << std::endl;
    }

    return 0;
}
```