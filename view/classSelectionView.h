#ifndef _CLASSSELCTIONVIEW_H
#define _CLASSSELCTIONVIEW_H

#include "iView.h"

class ClassSelectionView : public IView {
public:
    virtual void display(const Community* comm) override;
};

#endif