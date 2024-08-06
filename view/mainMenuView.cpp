#include "mainMenuView.h"

void MainMenuView::display(const Community* comm) {
    string title = "메인 메뉴";
    vector<string> options = {"반 선택", "반 생성", "섞기", "종료"};
    IView::displayMenu(title, options, comm);
}
