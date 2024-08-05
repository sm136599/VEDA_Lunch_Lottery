#ifndef _IVIEW_H
#define _IVIEW_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <conio.h>
#endif

using namespace std;

#include "../community/communityHeader.h"

#ifdef _WIN32
#define cls system("cls")
#define pause system("pause")
#else
#define cls system("clear")
#define pause system("read -n 1 -s -p \"Press any key to continue...\"; echo")
#endif

class IView {
public:
    void displayMenu(const string& title, const vector<string>& options, const Community* comm);
    virtual void display(const Community* comm) = 0;
};

#endif