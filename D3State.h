#ifndef D3_FSM_H
#define D3_FSM_H

#include <iostream>

class State {
public:
    bool moveToNext = false;

    virtual void enter() = 0;
    virtual void loop() = 0;
    virtual void exit() = 0;
    virtual ~State() = default;
};

#endif //D3_FSM_H
