#include <unistd.h>
#include <string>
#include <iostream>
#include <cstring>

int main()
{
    char buffer[256];
    int age;

    // Demonstrate stdin (standard input)
    const char* promptName = "Enter your name: ";
    write(1, promptName, strlen(promptName)); // Write to stdout using file descriptor 1

    ssize_t bytesRead = read(0, buffer, sizeof(buffer) - 1); // Read from stdin using file descriptor 0
    if (bytesRead <= 0) {
        const char* errorMsg = "Error reading name.\n";
        write(2, errorMsg, strlen(errorMsg)); // Write to stderr using file descriptor 2
        return 1;
    }
    buffer[bytesRead - 1] = '\0'; // Remove newline character

    // Demonstrate stdout (standard output)
    const char* promptAge = "Hello, ";
    write(1, promptAge, strlen(promptAge));
    write(1, buffer, strlen(buffer));
    const char* askAge = "! Enter your age: ";
    write(1, askAge, strlen(askAge));

    bytesRead = read(0, buffer, sizeof(buffer) - 1);
    if (bytesRead <= 0) {
        const char* errorMsg = "Error reading age.\n";
        write(2, errorMsg, strlen(errorMsg));
        return 1;
    }
    buffer[bytesRead - 1] = '\0'; // Remove newline character
    age = std::stoi(buffer);

    if (age < 0) {
        // Demonstrate stderr (standard error)
        const char* errorMsg = "Error: Age cannot be negative!\n";
        write(2, errorMsg, strlen(errorMsg));
        return 1;
    }

    const char* ageMsg = "You are ";
    write(1, ageMsg, strlen(ageMsg));
    snprintf(buffer, sizeof(buffer), "%d", age);
    write(1, buffer, strlen(buffer));
    const char* yearsOld = " years old.\n";
    write(1, yearsOld, strlen(yearsOld));

    return 0;
}