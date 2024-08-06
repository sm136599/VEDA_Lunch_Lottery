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
1. 실행 파일 `main.exe` 파일을 실행합니다. (주의 : `main.exe` 파일과 `data` 폴더는 같은 폴더 내에 있어야 합니다.) 프로그램을 실행하면 아래와 같은 화면을 볼 수 있습니다.
<p align="center">
  <img width="319" alt="스크린샷 2024-08-06 오후 6 57 09" src="https://github.com/user-attachments/assets/99798bef-00e3-448b-9bd2-901c460090c7">
</p>

2. 명령줄에 `1`을 입력하면(`1` 입력 후 엔터) 조를 섞을 반을 선택할 수 있습니다.(기존의 정보는 미리 저장해 두었습니다.)
<p align="center">
  <img width="314" alt="스크린샷 2024-08-06 오후 7 00 20" src="https://github.com/user-attachments/assets/fe03e41b-e4df-4bfb-99f3-f346a9be2c06">
</p>
&emsp;&emsp;위의 화면은 `data` 폴더에 어떤 반의 정보가 저장되었는지 보여주는 화면입니다. 파일 이름은 `{기수}_{반}` 형식으로 되어 있습니다.

3. 반을 선택하면 선택한 반으로 설정이 되고, 메인 화면으로 돌아갑니다.(위의 사진에서는 명령줄에 `1` 또는 `2`를 입력하는 것으로 선택할 수 있습니다.)
<p align="center">
  <img width="313" alt="스크린샷 2024-08-06 오후 7 06 56" src="https://github.com/user-attachments/assets/db962b12-3656-4b7d-84a4-ffa798d4aa2f">
</p>

4. 명령줄에 `3`을 입력하면(`3` 입력 후 엔터) 현재 설정된 반의 '랜밥' 조를 섞을 수 있습니다.
<p align="center">
  <img width="361" alt="스크린샷 2024-08-06 오후 7 08 25" src="https://github.com/user-attachments/assets/d7e2b85b-4971-406f-a2d4-76c4d9bda0d8">
</p>

- 데이터를 수정할 수 있습니다.
  - `data` 폴더의 `*.txt` 파일을 수정하면 조를 변경할 수 있지만, 권장하지 않습니다.

## 조 구성 정보

- 그룹 크기: 6명
- 총 그룹 수: 5개

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
