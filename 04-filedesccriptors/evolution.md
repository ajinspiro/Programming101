🕰️ 1. C-style File I/O (from C, inherited into C++)
a. fopen and fgets — C89 / ANSI C

FILE* file = fopen("example.txt", "r");
char buffer[256];
while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
}
fclose(file);

b. fgetc — C89

FILE* file = fopen("example.txt", "r");
int ch;
while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
}
fclose(file);

🕰️ 2. C++ Standard Library (fstream) — C++98
a. std::ifstream with line-by-line reading

std::ifstream file("example.txt");
std::string line;
while (std::getline(file, line)) {
    std::cout << line << '\n';
}

b. Character-by-character with get()

std::ifstream file("example.txt");
char ch;
while (file.get(ch)) {
    std::cout << ch;
}

🕰️ 3. POSIX Low-level File I/O — UNIX Tradition (pre-C++)

int fd = open("example.txt", O_RDONLY);
char buffer[128];
ssize_t bytes;
while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
    write(STDOUT_FILENO, buffer, bytes);
}
close(fd);

🕰️ 4. Memory-mapped Files — 1970s onward, platform-specific

    mmap on UNIX

    CreateFileMapping on Windows

    (Not shown here fully due to OS specificity)

🕰️ 5. Boost Libraries — 2003+
a. boost::filesystem or generic ifstream + stringstream

std::ifstream file("example.txt");
std::stringstream buffer;
buffer << file.rdbuf();
std::string content = buffer.str();

b. boost::iostreams::mapped_file_source

boost::iostreams::mapped_file_source file("example.txt");
std::cout << file.data();
file.close();

🕰️ 6. C++11 — Range-based, Efficient Reading

std::ifstream file("example.txt");
std::string content((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

🕰️ 7. C++17 — std::filesystem

namespace fs = std::filesystem;
if (fs::exists("example.txt")) {
    std::ifstream file("example.txt");
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
}

🕰️ 8. C++20 — std::ranges (Experimental)

for (char c : std::ifstream{"example.txt"} | std::views::all) {
    std::cout << c;
}

🕰️ 9. Custom Utility Functions — Any Era

User-defined helpers wrapping any of the above:

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    return { std::istreambuf_iterator<char>(file), {} };
}