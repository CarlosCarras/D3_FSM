#ifndef D3_FSM_H
#define D3_FSM_H

#include <iostream>
                       // Detumble | Link | GTrack
#define FSM_DETUBLE    0b100
#define FSM_LINK       0b010
#define FSM_GTRACK     0b001


class State {
public:
    virtual void enter(State* currentState) = 0;
    virtual void loop(State* currentState) = 0;
    virtual void exit(State* currentState) = 0;
    virtual ~State() = default;
};

class Detumble : public State {
public:
    void enter(State* currentState) override {
        std::cout << "Entered Detumbling State!" << std::endl;
    }

    void exit(State* currentState) override {
        std::cout << "Exiting Detumbling State!" << std::endl;
    }
};

class D3 {
public:
    D3() = default;

    State* getCurrentState() const {
        return currentState;
    }

    void setState(State& newState) {
        currentState->exit(this);  // do stuff before we change state
        currentState = &newState;  // change state
        currentState->enter(this); // do stuff after we change state
    }

private:
    State* currentState;
};

#endif //D3_FSM_H
