#ifndef STATEDEFINITIONS_H
#define STATEDEFINITIONS_H

#include <chrono>
#include <thread>
#include "D3State.h"


#define STATE_INITIALIZE    0
#define STATE_DETUMBLE      1
#define STATE_LINK          2
#define STATE_GTRACK        3
#define NUM_STATES          4


class Detumble : public State {
private:
    Detumble() = default;
    int cnt = 0;

public:
    unsigned long id = STATE_DETUMBLE;

    void enter(State* currentState) override {
        std::cout << "Entered Detumbling State!" << std::endl;
        moveToNext = false;
    }

    void loop(State* currentState) override {
        std::cout << "Detumbling..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if (cnt++ > 5) moveToNext = true;
    }

    void exit(State* currentState) override {
        std::cout << "Exiting Detumbling State!" << std::endl;
    }

    static State &getInstance() {
        static Detumble singleton;
        return singleton;
    }
};

class Initialize : public State {
private:
    Initialize() = default;

public:
    unsigned long id = STATE_INITIALIZE;

    void enter(State* currentState) override {
        std::cout << "Entering Initialize State!" << std::endl;
        moveToNext = true;
    }

    void loop(State* currentState) override {}

    void exit(State* currentState) override {
        std::cout << "Exiting Initialize State!" << std::endl;
    }

    static State &getInstance() {
        static Initialize singleton;
        return singleton;
    }
};

#endif //STATEDEFINITIONS_H
