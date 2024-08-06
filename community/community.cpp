#include "community.h"
using namespace std;

Community::Community() {
    cohort = "";    // 
    group = "";     // 
}

void Community::shiftRight(vector<string>& row, int shift){
    int size=row.size();
    if(shift==0) return;    
    shift %= size;    
    rotate(row.begin(), row.end() - shift, row.end());
}

//학생 파일 불러오기
void Community::loadStudents() {
    party = *readFile<string>((FILEPATH).c_str(), DELIMITER);    //이차원 벡터 data에 파일 내용 넣기, readfile은 포인터니까 *붙여주자
}

// 랜덤 파티 생성
void Community::makeParty() {
    size_t numRows = 5;
    size_t numCols = 6;
    vector<vector<string>> shiftedData = party;
    for(size_t i = 0 ; i < shiftedData.size(); i++){
        shiftRight(shiftedData[i], i + 1);  //각 행에 대해서 i만큼 시프트
    }

    nextParty = vector< vector<string> > (numRows, vector<string>(numCols, ""));
    // 각 열에 대해 행의 요소들을 모아 새로운 행벡터에 저장하고 그 행벡터는 새로운 2차원 벡터에 저장
    for (size_t row = 0; row < numRows; row++) {
        for (size_t col = 0; col < numRows; col++) {

            nextParty[col][row] = shiftedData[row][col];
        }
    }
    for (size_t row = 0; row < numRows; row++) {
        nextParty[row][numCols - 1] = shiftedData[row][numCols - 1];
    }
}
// 파티 저장
void Community::saveParty() {
    writeFile<string>((FILEPATH).c_str(), DELIMITER, nextParty); 
}

string Community::getCohort() const {
    return cohort;
}
string Community::getGroup() const {
    return group;
}