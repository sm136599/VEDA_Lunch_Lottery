//
// Created by u-keun song on 2024. 8. 3..
//
#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>

using namespace std;

template <class T>
unique_ptr< vector<T> > readFile(string filePath, char delimiter) {
    ifstream fin;
    fin.open(filePath);

    if (!fin) throw runtime_error("There is no such file.\n");

    auto result = make_unique< vector<T> >();

    // 입력이 한 줄로 되어 있다고 가정
    string token;
    while (getline(fin, token, delimiter)) {
        if constexpr (is_same_v<T, string>) {
            (*result).push_back(token);
        } else {
            stringstream tokenStream(token);
            T value;
            tokenStream >> value;
            if (tokenStream.fail()) {
                throw runtime_error("Failed to convert token to the specified type.\n");
            }
            result.push_back(value);
        }
    }

    fin.close();

    return result;
}

#endif // FILEIO_H