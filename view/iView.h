#ifndef _IVIEW_H
#define _IVIEW_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

#include "../community/communityHeader.h"

#define cls system("cls")
#define pause system("pause")

class IView {
public:
    void displayMenu(const string& title, const vector<string>& options, const Community* comm);
    virtual void display(const Community* comm) = 0;
};

#endif