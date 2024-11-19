#ifndef FILE_FINDER_H
#define FILE_FINDER_H

#include <string>
#include <vector>

class FileFinder {
public:
    FileFinder(const std::string &searchPath, bool recursive, bool caseInsensitive);
    
    std::vector<std::string> findFiles(const std::string &fileName) const;

private:
    std::string searchPath;
    bool recursive;
    bool caseInsensitive;
};

#endif // FILE_FINDER_H
