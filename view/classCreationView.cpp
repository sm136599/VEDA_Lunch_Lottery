#include "classCreationView.h"

void ClassCreationView::display(const Community* comm) {
    string title = "반 생성";
    vector<string> options = {"기수", "반", "종료"};
    IView::displayMenu(title, options, comm);
}

