#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>

int main() {
    const char* filename = "turing_award_winners.txt";
    const char* new_entry = "2030: A J Arun Kumar\n";
    const size_t bufsize = 4096;
    char buffer[bufsize + 1];
    ssize_t bytes_read;

    // Open file for reading
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        std::cerr << "Could not open file for reading.\n";
        return 1;
    }
    std::cout << "Current contents of the file:\n";
    std::string content;
    while ((bytes_read = read(fd, buffer, bufsize)) > 0) {
        buffer[bytes_read] = '\0';
        std::cout << buffer;
        content += buffer;
    }
    close(fd);

    // Modify the content
    content += new_entry;
    std::cout << "\n\nModified the content. Added a new entry.\n";

    // Open file for writing (truncate)
    fd = open(filename, O_WRONLY | O_TRUNC);
    if (fd == -1) {
        std::cerr << "Could not open file for writing.\n";
        return 1;
    }
    ssize_t bytes_written = write(fd, content.c_str(), content.size());
    if (bytes_written != (ssize_t)content.size()) {
        std::cerr << "Error writing to file.\n";
        close(fd);
        return 1;
    }
    close(fd);
    std::cout << "New content saved.\n";
    return 0;
}
