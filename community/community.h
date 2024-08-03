#ifndef _COMMUNITY_H
#define _COMMUNITY_H

class Community {
private:
    vector<string> students;
public:
    // 파일에서 데이터 불러오기
    void loadStudents();
    // 랜덤 파티 생성
    void makeParty();
    // 파티 저장
    void saveParty();
};

#endif