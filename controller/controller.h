#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "../community/community.h"
#include "../view/iView.h"
#include "../view/mainMenuView.h"
#include "../view/classCreationView.h"
#include "../view/classSelectionView.h"
#include "../view/shuffleView.h"

class Controller {
    IView* currentView;
    Community* community;
    MainMenuView* mainMenuView;
    ClassCreationView* classCreationView;
    ClassSelectionView* classSelectionView;
    ShuffleView* shuffleView;
    bool getIntCommand(int& cmd);
public:
    Controller();
    Controller(Community* comm);
    void run();
    void setView(IView* view);
    void processInput();
    void processMainMenu();
    void processClassCreation();
    void processClassSelection();
    void processShuffle();
};

#endif