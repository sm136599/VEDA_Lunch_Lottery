#include "shuffleView.h"

void ShuffleView::display(const Community* comm) {
    string title = "섞기";
    vector<string> options = {};
    IView::displayMenu(title, options, comm);
}
