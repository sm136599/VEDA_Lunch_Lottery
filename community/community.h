#ifndef _COMMUNITY_H
#define _COMMUNITY_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Community {
private:
    string cohort;  // 기수
    string group;   // 반
    vector<string> students;            //파일입출력으로 불러올거   
    vector<vector<string>> prevParty;   //불러온거를 다시 쪼개서 넣을거?
public:
    Community();
    // 파일에서 데이터 불러오기
    void loadStudents();
    // 랜덤 파티 생성
    void makeParty();
    // 파티 저장
    void saveParty();

    string getCohort() const;
    string getGroup() const;
};

#endif