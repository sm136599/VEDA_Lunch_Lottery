#ifndef _COMMUNITY_H
#define _COMMUNITY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#include "../headers.h"
#include "../utility/fileIO.h"

#define FILEPATH "./data/" + this->cohort + "_" + this->group + ".csv"
#define DELIMITER ','

class Community {
private:
    string cohort;  // 기수
    string group;   // 반 
    vector< vector<string> > party;  
    vector< vector<string> > nextParty;

    void shiftRight(vector<string>& row, int shift);
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
    void setCohort(string cohort) {
        this->cohort = cohort;
    };
    void setGroup(string group) {
        this->group = group;
    };
    vector< vector<string> > getParty() const {
        return party;
    }
    vector< vector<string> > getNextParty() const {
        return nextParty;
    }
};

#endif