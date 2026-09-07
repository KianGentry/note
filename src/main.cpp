#include <iostream>

const char* VERSION = "1";
std::string tmp_name = "/tmp/note_";

void print_help() {
    std::cout << "Usage: program [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version information\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        print_help();
    }
    else if (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version") {
        std::cout << "Program version " << VERSION << "\n";
    } 
    else {
        std::cout << "Unknown option: " << argv[1] << "\n";
        print_help();
    }
    return 0;
}