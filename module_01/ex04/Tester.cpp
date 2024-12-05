#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>  // For opendir(), readdir(), closedir()
#include <cstring>   // For strcmp()
#include <unistd.h>  // For chdir() (Unix-like systems)

bool compareFiles(std::string programOutput, std::string expectedOutput) {
    std::ifstream f1(programOutput), f2(expectedOutput);
    if (!f1 || !f2) return false;  // Check if files were opened successfully
    std::string line1, line2;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) return false;  // If any line doesn't match, return false
    }
    return f1.eof() && f2.eof();  // Ensure both files are at EOF at the same time
}

void executeTest(std::string file_path, std::string s1,
                 std::string expected_file, std::string s2) {
    std::string newFile = file_path + ".reeplace";  // Use + instead of append
    std::string cmd = "./a.out " + file_path + " \"" + s1 + "\" \"" + s2 + "\"";

    int result = system(cmd.c_str());
    if (result != 0) {
        std::cerr << "Command execution failed with error code: " << result << std::endl;
        return;
    }
    if (compareFiles(newFile, expected_file) == false) {
        std::cout << "Test failed!" << std::endl;
    } else {
        std::cout << "Test passed!" << std::endl;
    }
}

int main(void) {
    const char* testFolder = "./Tests";
    const char* args = "./args";

    std::ifstream arguments(args);
    if (!arguments.is_open()) {
        std::cerr << "Error opening arguments file." << std::endl;
        return 1;
    }
    DIR* dir = opendir(testFolder);
    if (dir == NULL) {
        std::cerr << "Error opening directory: " << testFolder << std::endl;
        return 1;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string str(entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || str.find(".replace") != std::string::npos) {
            continue;
        }
        std::string file_path = std::string(testFolder) + "/" + entry->d_name;
        std::string s1, s2;
        if (!std::getline(arguments, s1) || !std::getline(arguments, s2)) {
            std::cerr << "Error reading arguments from file." << std::endl;
            break;
        }
        std::string expected_file_path = file_path + ".replace";
        executeTest(file_path, s1, expected_file_path, s2);
    }

    // Close the directory and file streams
    closedir(dir);
    arguments.close();

    return 0;
}
