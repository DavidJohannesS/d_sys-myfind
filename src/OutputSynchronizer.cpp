#include "../include/OutputSynchronizer.h"
#include <iostream>
#include <mutex>

std::mutex OutputSynchronizer::outputMutex;

void OutputSynchronizer::printOutput(pid_t pid, const std::string &fileName, const std::string &result) {
    std::lock_guard<std::mutex> lock(outputMutex);
    std::cout << "[PID: " << pid << "] File: " << fileName << " -> " << result << std::endl;
}
