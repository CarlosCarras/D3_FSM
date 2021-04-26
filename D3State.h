#ifndef D3_FSM_H
#define D3_FSM_H

#include <iostream>

class State {
public:
    bool moveToNext = false;

    virtual void enter(State* currentState) = 0;
    virtual void loop(State* currentState) = 0;
    virtual void exit(State *currentState) = 0;
    virtual ~State() = default;
};

#endif //D3_FSM_H
