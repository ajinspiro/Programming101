#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // Demonstrate stdin (standard input)
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

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
