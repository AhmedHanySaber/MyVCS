#include <iostream>
#include <fstream>
#include <filesystem> // Ensure this header is included
#include <set>
#include <string>
#include <ctime>

std::set<std::string> trackedFiles;

void init() {
    if (std::filesystem::create_directory(".myvcs")) {
        std::filesystem::create_directory(".myvcs/commits");
        std::cout << "Initialized empty VCS repository in .myvcs\n";
    } else {
        std::cout << "Repository already exists\n";
    }
}

void addFile(const std::string& filename) {
    trackedFiles.insert(filename);
    std::ofstream outFile(".myvcs/tracked_files.txt", std::ios::app);
    outFile << filename << "\n";
    std::cout << "Added " << filename << " to tracking\n";
}

void commit(const std::string& message) {
    std::time_t now = std::time(nullptr);
    std::string timestamp = std::to_string(now);
    std::string commitDir = ".myvcs/commits/" + timestamp;

    std::filesystem::create_directory(commitDir);

    for (const auto& file : trackedFiles) {
        std::filesystem::copy(file, commitDir + "/" + file);
    }

    std::ofstream logFile(".myvcs/log.txt", std::ios::app);
    logFile << timestamp << " " << message << "\n";

    std::cout << "Committed changes with message: " << message << "\n";
}

void log() {
    std::ifstream logFile(".myvcs/log.txt");
    std::string line;
    while (std::getline(logFile, line)) {
        std::cout << line << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: myvcs <command> [<args>]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "init") {
        init();
    } else if (command == "add") {
        if (argc < 3) {
            std::cerr << "Usage: myvcs add <filename>\n";
            return 1;
        }
        addFile(argv[2]);
    } else if (command == "commit") {
        if (argc < 3) {
            std::cerr << "Usage: myvcs commit <message>\n";
            return 1;
        }
        commit(argv[2]);
    } else if (command == "log") {
        log();
    } else {
        std::cerr << "Unknown command: " << command << "\n";
        return 1;
    }

    return 0;
}
