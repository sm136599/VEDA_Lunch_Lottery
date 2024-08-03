//
// Created by u-keun song on 2024. 8. 3..
//
#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>

using namespace std;

template <class T>
unique_ptr< vector< vector<T> > > readFile(string filePath, char delimiter) {
    ifstream fin;
    fin.open(filePath);

    if (!fin) throw runtime_error("There is no such file.\n");

    auto result = make_unique< vector< vector<T> > >();

    string line, token;
    int idx = 0;
    while (getline(fin, line)) {
        stringstream lineStream(line);
        vector<T> row;
        while (getline(lineStream, token, delimiter)) {
            if constexpr (is_same_v<T, string>) {
                row.push_back(token);
            } else {
                stringstream tokenStream(token);
                T value;
                tokenStream >> value;
                if (tokenStream.fail()) throw runtime_error("failed to convert token to the specified type.\n");
                row.push_back(value);
            }
        }
        result->push_back(row);
    }

    fin.close();

    return result;
}

#endif // FILEIO_H