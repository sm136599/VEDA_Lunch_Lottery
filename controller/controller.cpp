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
    while (true) { 
        setView(mainMenuView);
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
    string cmd;
    cin >> cmd;
    if (cmd == "4") {
        exit(0);
    }
}
void Controller::processClassCreation() {
    cout << "반 생성 실행" << endl;
    string cmd;
    cin >> cmd;  
}
void Controller::processClassSelection() {
    cout << "반 선택 실행" << endl;
    string cmd;
    cin >> cmd;
}
void Controller::processShuffle() {
    cout << "섞기 실행" << endl;
    string cmd;
    cin >> cmd;
}