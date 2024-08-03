#ifndef _MAINMENUVIEW_H
#define _MAINMENUVIEW_H

#include "iView.h"

class MainMenuView : public IView {
public:
    virtual void display(const Community* comm) override;
};

#endif