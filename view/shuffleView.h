#ifndef _SHUFFLEVIEW_H
#define _SHUFFLEVIEW_H

#include "iView.h"

class ShuffleView : public IView {
public:
    virtual void display(const Community* comm) override;
};

#endif