#include "controller.h"

Controller::Controller() {
    this->community = new Community();
    mainMenuView = new MainMenuView();
    classCreationView = new ClassCreationView();
    classSelectionView = new ClassSelectionView();
    shuffleView = new ShuffleView();
}
Controller::Controller(Community* comm) {
    this->community = comm;
    mainMenuView = new MainMenuView();
    classCreationView = new ClassCreationView();
    classSelectionView = new ClassSelectionView();
    shuffleView = new ShuffleView();
}
void Controller::run() {
    setView(mainMenuView);
    while (true) { 
        processInput();
    }
}
void Controller::setView(IView* view) {
    currentView = view;
    currentView->display(this->community);
}
void Controller::processInput() {
    if (dynamic_cast<MainMenuView*>(currentView)) {
        processMainMenu();
    }
    else if (dynamic_cast<ClassCreationView*>(currentView)) {
        processClassCreation();
    }
    else if (dynamic_cast<ClassSelectionView*>(currentView)) {
        processClassSelection();
    }
    else if (dynamic_cast<ShuffleView*>(currentView)) {
        processShuffle();
    }
}
void Controller::processMainMenu() {
    cout << "메인메뉴 실행" << endl;
    int cmd;
    cin >> cmd;
    fflush(stdin);
    if (cin.fail()) cout << "다시 입력해주세요" << endl;
    switch (cmd)
    {
    case 1:
        setView(classSelectionView);
        break;
    case 2:
        setView(classCreationView);
        break;
    case 3:
        setView(shuffleView);
        break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }
}
void Controller::processClassCreation() {
    cout << "반 생성 실행" << endl;
    int cmd;
    cin >> cmd;
    fflush(stdin);
    if (cin.fail()) cout << "다시 입력해주세요" << endl;
    switch (cmd)
    {
    case 1: {
            // 기수 입력
            cout << "기수 입력 >> ";
            string cohort; cin >> cohort;
            // community.setCohort(cohort);
            setView(classCreationView);
            break;
        }
    case 2: {
            // 반 입력
            cout << "반 입력 >> ";
            string group; cin >> group;
            // community.setGroup(group);
            setView(classCreationView);
            break;
        }
    case 3: {
            // 기수_반.csv 파일 형식으로 data폴더 안에 저장하기
            string fileName = "./data/" + community->getCohort() + "_" + community->getGroup() + ".csv";
            ofstream fout; 
            fout.open(fileName);
            fout << "# 데이터 입력 (지우고 작성해주세요)" << endl;
            fout.close();
            cout << fileName << " 생성 완료" << endl;
            pause;
            // 메인 화면 돌아가기
            setView(mainMenuView);
            break;
        }
    default:
        break;
    }
}
void Controller::processClassSelection() {
    cout << "반 선택 실행" << endl;
    int cmd;
    cin >> cmd;
    fflush(stdin);
    if (cin.fail()) cout << "다시 입력해주세요" << endl;
    // 파일 이름: 기수_반.csv
    //vector<string> files = getFileNames("./data");
    vector<string> files;
    if (cmd == files.size() + 1) setView(mainMenuView);
    else {
        // community 멤버 변수에 기수, 반 입력
        string fileName = files[cmd-1];
        fileName = fileName.substr(0, fileName.find('.'));
        string cohort, group;
        cohort = fileName.substr(0, fileName.find('_'));
        group = fileName.substr(fileName.find('_') + 1);
        // community.setCohort(cohort);
        // community.setGroup(group);
        // community->loadStudents();
        setView(classSelectionView);
    }

}
void Controller::processShuffle() {
    cout << "섞기 실행" << endl;
    // community->makeParty();
    // 만들어진 파티 보여주기
    // community->showParty();
    pause;
    setView(mainMenuView);
}