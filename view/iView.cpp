#include "iView.h"

void IView::displayMenu(const string& title, const vector<string>& options, const Community* comm) {
    cls;
    cout << "============" << title << "============" << endl;
    cout << "선택된 반: ";
    if (comm->getCohort() == "" || comm->getGroup() == "") {
        cout << "없음" << endl;
    }
    else {
        cout << comm->getCohort() << "기 " << comm->getGroup() << "반" << endl;
    }
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}