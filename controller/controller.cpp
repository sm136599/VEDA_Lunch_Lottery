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
bool Controller::getIntCommand(int& cmd) {
    cout << ">> ";
    cin >> cmd;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "다시 입력해주세요." << endl;
        return false;
    }
    return true;
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
    int cmd;
    if (!getIntCommand(cmd)) {
        return;
    }
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
    int cmd;
    if (!getIntCommand(cmd)) {
        return;
    }
    switch (cmd)
    {
    case 1: {
            // 기수 입력
            cout << "기수 입력 >> ";
            string cohort; cin >> cohort;
            community->setCohort(cohort);
            setView(classCreationView);
            break;
        }
    case 2: {
            // 반 입력
            cout << "반 입력 >> ";
            string group; cin >> group;
            community->setGroup(group);
            setView(classCreationView);
            break;
        }
    case 3: {
            // 기수_반.csv 파일 형식으로 data폴더 안에 저장하기
            // 기수와 반이 없으면 어떻게 하지?
            if (community->getCohort() == "" || community->getGroup() == "") {
                cout << "기수와 반 모두 입력해주세요" << endl;
                return;
            }
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
    case 4: {
        community->setCohort("");
        community->setGroup("");
        setView(mainMenuView);
        return;
    }
    default:
        break;
    }
}
void Controller::processClassSelection() {
    int cmd;
    if (!getIntCommand(cmd)) {
        return;
    }
    // 파일 이름: 기수_반.csv
    vector<string> files = readFileNames("./data");

    if (!(1 <= cmd && cmd <= files.size() + 1)) {
        cout << "번호를 다시 입력해주세요" << endl;
        return; 
    }
    if (cmd == files.size() + 1) setView(mainMenuView);
    else {
        // community 멤버 변수에 기수, 반 입력
        string fileName = files[cmd-1];
        fileName = fileName.substr(0, fileName.find('.'));
        string cohort, group;
        cohort = fileName.substr(0, fileName.find('_'));
        group = fileName.substr(fileName.find('_') + 1);
        community->setCohort(cohort);
        community->setGroup(group);
        community->loadStudents();
        setView(mainMenuView);
    }

}
void Controller::processShuffle() {
    community->makeParty();
    // 만들어진 파티 보여주기
    vector< vector<string> > party = community->getParty();
    cout << "==========지난 주==========" << endl;
    for (int i = 0;i < party.size(); i++) {
        cout << i + 1 << "조 : ";
        for (const auto& person : party[i]) {
            cout << person << ", ";
        }
        cout << endl;
    }
    cout << "==========이번 주==========" << endl;
    party = community->getNextParty();
    for (int i = 0;i < party.size(); i++) {
        cout << i + 1 << "조 : ";
        for (const auto& person : party[i]) {
            cout << person << ", ";
        }
        cout << endl;
    }
    cout << "위의 이번 주 조합이 저장됩니다. 지난 주 기록은 사라집니다." << endl;
    pause;
    writeFile(("./data/" + community->getCohort() + "_" + community->getGroup() + ".csv").c_str(), ',', community->getNextParty());
    community->loadStudents();
    setView(mainMenuView);
}