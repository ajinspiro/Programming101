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

Give compilation of the command as an exercise. 
execute the program 
    with only MYTAXI_USER set, 
    with only MYTAXI_PICKUP_LOCATION set,
    with only MYTAXI_DESTINATION_LOCATION,
    with all three set,
    with none of these 3 set
 
explain shell sessions, ~/.bashrc and /etc/environment

explain system environment variables PATH,LD_LIBRARY_PATH,HOME,SHELL,LANG,PWD,USER,HOSTNAME,UID
explain export PATH=$PATH:.
TODO: https://chatgpt.com/share/68881a30-652c-8002-b5b9-5bb04e824fb2

TODO: use echo command to print env variable

TODO: test the following cpp code

