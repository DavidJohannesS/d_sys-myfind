#include "../include/ArgumentParser.h"
#include "../include/ProcessManager.h"
#include <iostream>

int main(int argc, char *argv[]) {
    // Create an instance of ArgumentParser
    ArgumentParser argumentParser(argc, argv);

    // Retrieve parsed arguments
    bool recursive = argumentParser.isRecursive();
    bool caseInsensitive = argumentParser.isCaseInsensitive();
    std::string searchPath = argumentParser.getSearchPath();
    std::vector<std::string> fileNames = argumentParser.getFileNames();

    // Print parsed arguments (for debugging purposes)
    std::cout << "Recursive: " << (recursive ? "true" : "false") << std::endl;
    std::cout << "Case Insensitive: " << (caseInsensitive ? "true" : "false") << std::endl;
    std::cout << "Search Path: " << searchPath << std::endl;
    std::cout << "File Names: ";
    for (const auto& fileName : fileNames) {
        std::cout << fileName << " ";
    }
    std::cout << std::endl;

    // Create an instance of ProcessManager and run the process
    ProcessManager processManager(fileNames, searchPath, recursive, caseInsensitive);
    processManager.run();

    return 0;
}
