#ifndef _COMMUNITY_H
#define _COMMUNITY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#include "../headers.h"
#include "../utility/fileIO.h"

class Community {
private:
    string cohort;  // 기수
    string group;   // 반  
    //unique_ptr< vector< vector<string> > > originalData;  //함수에서 직접 선언
    vector<vector<string>> groupedData;
    //vector<string> students;            //파일입출력으로 불러올거   
    //vector<vector<string>> prevParty;   //불러온거를 다시 쪼개서 넣을거?
public:
    Community();
    // 파일에서 데이터 불러오기
    unique_ptr< vector< vector<string> > > loadStudents();
    // 랜덤 파티 생성
    vector<vector<string>> makeParty();
    // 파티 저장
    void saveParty();

    string getCohort() const;
    string getGroup() const;
};

#endif