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


/*************************************** GTrack ***************************************/

class GTrack : public State {
private:
    GTrack() = default;
    int cnt = 0;

public:
    void enter() override {
        std::cout << "Entered GTrack State!" << std::endl;
        moveToNext = false;
    }

    void loop() override {
        std::cout << "Tracking..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if (cnt++ > 5) moveToNext = true;
    }

    void exit() override {
        std::cout << "Exiting GTrack State!" << std::endl;
    }

    static State &getInstance() {
        static GTrack singleton;
        return singleton;
    }
};

/**************************************** Link ****************************************/

class Link : public State {
private:
    Link() = default;
    int cnt = 0;

public:
    void enter() override {
        std::cout << "Entered Linking State!" << std::endl;
        moveToNext = false;
    }

    void loop() override {
        std::cout << "Linking..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if (cnt++ > 5) moveToNext = true;
    }

    void exit() override {
        std::cout << "Exiting Linking State!" << std::endl;
    }

    static State &getInstance() {
        static Link singleton;
        return singleton;
    }
};

/************************************** DETUMBLE **************************************/

class Detumble : public State {
private:
    Detumble() = default;
    int cnt = 0;

public:
    void enter() override {
        std::cout << "Entered Detumbling State!" << std::endl;
        moveToNext = false;
    }

    void loop() override {
        std::cout << "Detumbling..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if (cnt++ > 5) moveToNext = true;
    }

    void exit() override {
        std::cout << "Exiting Detumbling State!" << std::endl;
    }

    static State &getInstance() {
        static Detumble singleton;
        return singleton;
    }
};

/************************************* Initialize *************************************/

class Initialize : public State {
private:
    Initialize() = default;

public:
    void enter() override {
        std::cout << "Entering Initialize State!" << std::endl;
        moveToNext = true;
    }

    void loop() override {}

    void exit() override {
        std::cout << "Exiting Initialize State!" << std::endl;
    }

    static State &getInstance() {
        static Initialize singleton;
        return singleton;
    }
};

#endif //STATEDEFINITIONS_H
