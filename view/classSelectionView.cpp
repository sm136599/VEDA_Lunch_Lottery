#include "classSelectionView.h"

void ClassSelectionView::display(const Community* comm) {
    string title = "반 선택";
    vector<string> options = readFileNames("./data");
    options.push_back("종료");
    //vector<string> options = {"종료"};
    IView::displayMenu(title, options, comm);
}