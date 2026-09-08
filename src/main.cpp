#include <iostream>
#include <cstdlib>
#include <string>

const char* VERSION = "2";

void printHelp() {
    std::cout << "Usage: note [OPTION]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version information\n";
    std::cout << "  -l, --list     List all notes\n";
}

void listNotes() {
    std::system("ls -a /tmp | grep note_");
}

void returnLatestUnnamedNote() {
    std::system("ls -a /tmp | grep note_ | tail -n 1 | cut -d '_' -f 2 | cut -d '.' -f1");
}

void new_note() {
    returnLatestUnnamedNote();
    //std::string command = "nano /tmp/note_" + (std::to_string(return_latest_note() + 1));
    //std::system(command.c_str());
}

int main(int argc, char* argv[]) {
    if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        printHelp();
    }
    else if (std::string(argv[1]) == "-v" || std::string(argv[1]) == "--version") {
        std::cout << "Program version " << VERSION << "\n";
    } 
    else if (std::string(argv[1]) == "-l" || std::string(argv[1]) == "--list") {
        listNotes();
    }
    else if (std::string(argv[1]) == "-n" || std::string(argv[1]) == "--new" || argv[1] == nullptr) {
        new_note();
    }
    else {
        std::cout << "Unknown option: " << argv[1] << "\n";
        printHelp();
    }
    return 0;
}