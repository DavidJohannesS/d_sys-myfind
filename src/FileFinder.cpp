#include "../include/FileFinder.h"
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

FileFinder::FileFinder(const std::string &searchPath, bool recursive, bool caseInsensitive)
    : searchPath(searchPath), recursive(recursive), caseInsensitive(caseInsensitive) {}

std::vector<std::string> FileFinder::findFiles(const std::string &fileName) const {
    std::vector<std::string> results;

    auto searchFunc = [&](const fs::path &path) {
        std::string pathString = path.filename().string();
        std::string searchFileName = fileName;
        
        if (caseInsensitive) {
            std::transform(pathString.begin(), pathString.end(), pathString.begin(), ::tolower);
            std::transform(searchFileName.begin(), searchFileName.end(), searchFileName.begin(), ::tolower);
        }

        if (pathString == searchFileName) {
            results.push_back(path.string());
        }
    };

    if (recursive) {
        for (const auto &entry : fs::recursive_directory_iterator(searchPath)) {
            if (entry.is_regular_file()) {
                searchFunc(entry.path());
            }
        }
    } else {
        for (const auto &entry : fs::directory_iterator(searchPath)) {
            if (entry.is_regular_file()) {
                searchFunc(entry.path());
            }
        }
    }

    return results;
}
