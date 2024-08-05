#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "community.h"

Community::Community() {
    cohort = "";    // 
    group = "";     // 
}

//학생 파일 불러오기
unique_ptr< vector< vector<string> > > Community::loadStudents() {
    string filePath="names.txt";
    char delimiter=' ';
    unique_ptr< vector< vector<string> > > originalData = readFile<string>(filePath, delimiter);    //이차원 벡터 data에 파일 내용 넣기, readfile은 포인터니까 *붙여주자
    return originalData;
}

// 랜덤 파티 생성
vector<vector<string>> Community::makeParty() {
    auto data = loadStudents();
    vector<vector<string>> shiftedData;
    for(size_t i=0 ; i<data->size() ; i++){
        shiftRight((*data)[i], i);  //각 행에 대해서 i만큼 시프트
        shiftedData.push_back((*data)[i]);
    }

    size_t numRows = shiftedData.size();       //행
    size_t numCols = shiftedData[0].size();    //열

    //각 열에 대해 행의 요소들을 모아 새로운 행벡터에 저장하고 그 행벡터는 새로운 2차원 벡터에 저장
    for(size_t col = 0 ; col < numCols ; col++){     
        vector<string> newRows;
        for(size_t row = 0 ; row < numRows ; row++){  
            newRows.push_back(shiftedData[row][col]);
        }
        groupedData.push_back(newRows);
    }
    for(auto& row : groupedData){
        for(auto& item : row){
            cout << item << " ";
        }
        cout << endl;
    }
    return groupedData;
}
// 파티 저장
void Community::saveParty() {
    string filePath="random_lottery_result.txt";
    char delimiter=' ';
    writeFile(filePath, delimiter, groupedData); 
}

string Community::getCohort() const {
    return cohort;
}
string Community::getGroup() const {
    return group;
}