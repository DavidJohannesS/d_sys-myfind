#ifndef OUTPUT_SYNCHRONIZER_H
#define OUTPUT_SYNCHRONIZER_H

#include <string>
#include <mutex>

class OutputSynchronizer {
public:
    static void printOutput(pid_t pid, const std::string &fileName, const std::string &result);

private:
    static std::mutex outputMutex;
};

#endif // OUTPUT_SYNCHRONIZER_H
