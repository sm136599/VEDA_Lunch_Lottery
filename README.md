# VEDA_Lunch_Lottery (랜밥 - 랜덤밥먹기)

VEDA_Lunch_Lottery는 그룹 내에서 무작위로 식사 조를 만들어주는 C++ 프로그램입니다. 

## 프로젝트 개요

이 프로그램은 정기적으로 무작위 식사 그룹을 만들어 조직 내 소통을 증진시키고, 새로운 관계를 형성할 기회를 제공합니다.
프로그램의 주요한 목적은, 전 주에 함께 '랜밥'을 한 인원이 다음주에 최소한으로 만나도록 조를 구성하는 것입니다.

### 주요 특징

- 무작위 조 편성: 매주 새로운 조합의 식사 그룹 생성
- (비밀) 영혼의 듀오가 한 쌍 있습니다..!

[//]: # (- 유연한 설정: 그룹 크기와 총 그룹 수 조정 가능)
[//]: # (- 공정한 분배: 모든 참가자가 고르게 다양한 그룹에 배정되도록 보장)

## 사용 방법

1. 프로그램을 실행합니다.
2. 참가자 명단을 입력하거나 파일에서 불러옵니다.
3. 프로그램이 자동으로 무작위 그룹을 생성합니다.
4. 결과를 화면에 표시하고, 선택적으로 파일로 저장할 수 있습니다.

[//]: # (3. 원하는 그룹 크기와 총 그룹 수를 설정합니다.)



## 설정 예시

- 그룹 크기: 6명
- 총 그룹 수: 5개
- 주기: 매주 화요일
- 기간: 총 10주

## 커스터마이징

이 프로그램은 다양한 상황에 맞게 조정할 수 있습니다:
- 학교 수업의 그룹 프로젝트
- 회사 내 팀 빌딩 활동
- 대규모 컨퍼런스나 워크숍의 네트워킹 세션
- 동아리나 소셜 그룹의 활동 조직

## 프로젝트 구조
```
project_root/
├── main.cpp
├── headers.h
├── community/
│   ├── community.cpp
│   ├── community.h
│   └── communityHeader.h
├── controller/
│   ├── controller.cpp
│   ├── controller.h
│   └── controllerHeader.h
├── utility/
│   ├── fileIO.cpp
│   ├── fileIO.h
│   └── fileIOHeader.h
└── view/
    ├── classCreationView.cpp
    ├── classCreationView.h
    ├── classSelectionView.cpp
    ├── classSelectionView.h
    ├── iView.cpp
    ├── iView.h
    ├── mainMenuView.cpp   
    ├── mainMenuView.h
    ├── shuffleView.cpp   
    ├── shuffleView.h
    └── viewHeader.h
```
