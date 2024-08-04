#include "classCreationView.h"

void ClassCreationView::display(const Community* comm) {
    string title = "반 생성";
    vector<string> options = {"기수 " + comm->getCohort(), "반 " + comm->getGroup(), "완료"};
    IView::displayMenu(title, options, comm);
}

