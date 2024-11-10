#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <vector>
#include <string>

class ArgumentParser {
public:
    ArgumentParser(int argc, char *argv[]);
    
    bool isRecursive() const;
    bool isCaseInsensitive() const;
    std::string getSearchPath() const;
    std::vector<std::string> getFileNames() const;

private:
    void parseArguments();
    
    bool recursive;
    bool caseInsensitive;
    std::string searchPath;
    std::vector<std::string> fileNames;
    int argc;
    char **argv;
};

#endif
