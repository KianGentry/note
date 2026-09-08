#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

const char* VERSION = "pre-release";

void printVersion() {
    std::cout << "Program version " << VERSION << "\n";
}

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

int returnLatestUnnamedNoteIndex() {
    std::system("ls -a /tmp | grep note_ | tail -n 1 | cut -d '_' -f 2 | cut -d '.' -f1 > /tmp/.noteindex");
    int index = 0;
    std::ifstream infile("/tmp/.noteindex");
    infile >> index;
    return index;
}

std::string newNoteName() {
    int latestIndex = returnLatestUnnamedNoteIndex();
    return "/tmp/note_" + std::to_string(latestIndex + 1) + ".txt";
}

void newNote(const std::string& noteName) {
    if (!noteName.empty()) {
        std::system(("nano /tmp/note_" + noteName + ".txt").c_str());
    }
    else {
        std::system(("nano " + newNoteName()).c_str());
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        newNote("");
    }
    else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "help") {
        printHelp();
    }
    else if (std::string(argv[1]) == "-v" || std::string(argv[1]) == "version") {
        printVersion();
    } 
    else if (std::string(argv[1]) == "-l" || std::string(argv[1]) == "list") {
        listNotes();
    }
    else {
        newNote(std::string(argv[1]));
    }
    return 0;
}