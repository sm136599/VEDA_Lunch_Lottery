//
// Created by u-keun song on 2024. 8. 4..
//
#include <filesystem>
#include "fileIO.h"

vector<string> readFileNames(const char* directoryPath) {
    vector<string> fileNames;

    for (const auto& file : filesystem::directory_iterator(directoryPath)) {
        if (filesystem::is_regular_file(file.status())) {
            fileNames.push_back(file.path().filename().string());
        }
    }

    return fileNames;
}
