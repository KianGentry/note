#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

const char* VERSION = "pre-release";
const char* homeDir = std::getenv("HOME");

std::string getConfigValue(const std::string key, const std::string defaultValue) {
    if (!homeDir) return defaultValue;

    std::string configPath = std::string(homeDir) + "/.config/noterc";
    std::ifstream configFile(configPath);
    if (!configFile.is_open()) return defaultValue;

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string k;
        std::string value;
        if (std::getline(iss, k, '=') && std::getline(iss, value)) {
            if (k == key) {
                return value;
            }
        }
    }
    return defaultValue;
}

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

std::string getMostRecentNote() {
    std::string cmd = "ls -t /tmp | grep note_ | head -n 1";
    std::ifstream infile("/tmp/.noterecent");
    std::string recentNote;
    infile >> recentNote;
    return recentNote;
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

std::string newUnnamedNoteName() {
    int latestIndex = returnLatestUnnamedNoteIndex();
    return "/tmp/note_" + std::to_string(latestIndex + 1) + ".txt";
}

void newNote(const std::string& noteName) {
    std::string editor = getConfigValue("textEditor", "nano");
    if (!noteName.empty()) {
        std::system((editor + " /tmp/note_" + noteName + ".txt").c_str());
    }
    else {
        std::system((editor + " " + newUnnamedNoteName()).c_str());
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