#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <string>
#include <vector>

class ProcessManager {
public:
    ProcessManager(const std::vector<std::string> &fileNames, const std::string &searchPath, bool recursive, bool caseInsensitive);
    
    void run();

private:
    void forkChildProcess(const std::string &fileName);
    void handleChildProcess(const std::string &fileName);
    void waitForChildren();
    
    std::vector<std::string> fileNames;
    std::string searchPath;
    bool recursive;
    bool caseInsensitive;
};

#endif // PROCESS_MANAGER_H
