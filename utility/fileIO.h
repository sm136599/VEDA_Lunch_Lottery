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
#include <algorithm>

using namespace std;

template <class T>
unique_ptr< vector< vector<T> > > readFile(string filePath, char delimiter) {   //filepath : "file이름" , delimiter : '\t' <-탭 
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

//벡터 시프트 (->)
template <class T>
void shiftRight(vector<T>& row, int shift){
    int size=row.size();
    if(shift==0) return;    //shift가 0일때
    shift %= size;          //shift가 row벡터 크기보다 큰 경우
    rotate(row.begin(), row.end() - shift, row.end());
    
}

template <class T>
void writeFile(string filePath, char delimiter, vector< vector<T> > data) {
    ofstream fout(filePath);

    if (!fout) throw runtime_error("Error opening file for writing.\n");

    for (const auto& row : data) {
        for (const auto& item : row) {
            fout << item << delimiter;
        }
        fout << '\n';
    }

    fout.close();
}

#endif // FILEIO_H