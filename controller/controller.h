#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "../headers.h"

class Controller {
    IView* currentView;
    Community* community;
    MainMenuView* mainMenuView;
    ClassCreationView* classCreationView;
    ClassSelectionView* classSelectionView;
    ShuffleView* shuffleView;
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