#include "../include/ProcessManager.h"
#include "../include/FileFinder.h" 
#include "../include/OutputSynchronizer.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

ProcessManager::ProcessManager(const std::vector<std::string> &fileNames, const std::string &searchPath, bool recursive, bool caseInsensitive)
    : fileNames(fileNames), searchPath(searchPath), recursive(recursive), caseInsensitive(caseInsensitive) {}

void ProcessManager::run() {
    for (const auto &fileName : fileNames) {
        forkChildProcess(fileName);
    }
    waitForChildren();
}

void ProcessManager::forkChildProcess(const std::string &fileName) {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Fork failed for file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        handleChildProcess(fileName);
        exit(EXIT_SUCCESS);
    }
    // Parent process continues to fork other children
}

void ProcessManager::handleChildProcess(const std::string &fileName) {
    FileFinder fileFinder(searchPath, recursive, caseInsensitive);
    std::vector<std::string> results = fileFinder.findFiles(fileName);
    
    pid_t pid = getpid();
    for (const auto &result : results) {
        OutputSynchronizer::printOutput(pid, fileName, result);
    }
}

void ProcessManager::waitForChildren() {
    int status;
    while (wait(&status) > 0);
}
