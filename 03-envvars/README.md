TODO:

explain environment variables.
explain export command to set env vars, echo command with $ for printing env vars and unset for removing env vars. 
    echo $GREETING
    export GREETING="hello c++"
    export GREETING=$GREETING,"Hola C++" #appending existing variable
    unset GREETING

C++ program

```cpp
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    const char* username = std::getenv("MYTAXI_USER");
    const char* pickup_location = std::getenv("MYTAXI_PICKUP_LOCATION");
    const char* destination_location = std::getenv("MYTAXI_DESTINATION_LOCATION");

    if (username) {
        std::cout << "User : " << username << std::endl;
    } else {
        std::cout << "Couldn't get your identity. Environment variable MYTAXI_USER not set." << std::endl;
    }

    if (pickup_location) {
        std::cout << "Pickup at : " << pickup_location << std::endl;
    } else {
        std::cout << "Couldn't get your location. Environment variable MYTAXI_PICKUP_LOCATION not set." << std::endl;
    }
 
    if (destination_location) {
        std::cout << "Drop off at : " << destination_location << std::endl;
    } else {
        std::cout << "Couldn't get your destination. Environment variable MYTAXI_DESTINATION_LOCATION not set." << std::endl;
    }

    return 0;
}
```

Give compilation of the command as an exercise. (Try compiling the above source yourself. Output program should be `onlinetaxi_env`)
execute the program 
1. with only MYTAXI_USER set, 
1. with only MYTAXI_PICKUP_LOCATION set,
1. with only MYTAXI_DESTINATION_LOCATION,
1. with all three set,
1. with none of these 3 set
 
explain shell sessions, ~/.bashrc and /etc/environment

explain system environment variables ,USER,HOSTNAME,UID,PATH,LD_LIBRARY_PATH,HOME,SHELL,LANG,PWD
explain export PATH=$PATH:.