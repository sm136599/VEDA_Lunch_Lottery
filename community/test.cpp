#include <iostream>
#include "community.h"
#include "../utility/fileIO.h"

using namespace std;

int main() {
    // Community 객체 생성
    Community community;

    // 학생 데이터를 불러오고 출력
    cout << "학생 데이터를 불러옵니다..." << endl;
    auto studentsData = community.loadStudents();

    cout << "불러온 학생 데이터:" << endl;
    for (const auto& row : *studentsData) {
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }

    // 랜덤 파티 생성 및 출력
    cout << "랜덤 파티를 생성합니다..." << endl;
    vector<vector<string>> party = community.makeParty();

    // 생성된 파티를 파일에 저장
    cout << "파티 결과를 파일에 저장합니다..." << endl;
    community.saveParty();

    return 0;
}

//g++ -g -std=c++17 -o test.exe test.cpp community.h community.cpp  <- 컴파일할때 이걸로!