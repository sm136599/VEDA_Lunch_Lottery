#ifndef _IVIEW_H
#define _IVIEW_H

class IView {
public:
    virtual void display() = 0;
    virtual ~IView();
};

#endif