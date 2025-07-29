# Pre-requisites

1. Visual Studio Code (and the following extensions)
    1. C/C++ (by Microsoft)
    2. Remote - SSH (by Microsoft)
    3. ~~CMake tools (by Microsoft)~~
2. WSL (Open a command prompt and type `wsl --install`)
3. WSL Ubuntu (latest LTS). Available in Microsoft store.
4. clang
    1. Open a WSL Ubuntu terminal and run the following commands. PS: These must be run in WSL Ubuntu bash, NOT in Windows command prompt.
    2. `sudo apt update`
    3. `sudo apt upgrade`
    4. `sudo apt install clang`
5. ~~CMake `sudo apt install cmake`~~

You can run `sudo usermod -aG sudo arun` to add `arun` to super user list. This is only for your WSL/Laptop Ubuntu. Do NOT do this for production systems because this is security bad practise. 