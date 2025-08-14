#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "turing_award_winners.txt";
    std::string content, line;

    // Read the file and print its contents.
    // This line invokes the constructor of the class std::ifstream.
    // "new" keyword is not used here, as std::ifstream is a stack-allocated object.
    // Prompt about stack vs heap allocation in C++ if you are still confused.
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Could not open file for reading.\n";
        return 1;
    }
    std::cout << "Current contents of the file:\n";
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
        content += line + "\n";
    }
    infile.close();

    // Add a new entry to the content
    content += "2030: A J Arun Kumar\n";

    std::cout << "\n\nModified the content. Added a new entry.\n";
    // Save the modified content back to the file
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Could not open file for writing.\n";
        return 1;
    }
    outfile << content;
    outfile.close();

    std::cout << "New content saved.\n";
    return 0;
}