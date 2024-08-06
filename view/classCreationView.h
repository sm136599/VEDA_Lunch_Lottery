#ifndef _CLASSCREATIONVIEW_H
#define _CLASSCREATIONVIEW_H

#include "iView.h"

class ClassCreationView : public IView {
public:
    virtual void display(const Community* comm) override;
};

#endif