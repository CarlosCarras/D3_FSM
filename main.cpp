#include <iostream>
#include <fstream>
#include <string>
#include "d3_fsm.h"


State current = ;

void setState(State& newState)
{
    current->exit(this);  // do stuff before we change state
    current = &newState;  // change state
    current->enter(this); // do stuff after we change state
}

void getState() {

}

void setStateAtRestart() {
    int potentialState;
    std::string line;
    std::ifstream file("state.d3fsm");

    if (file.is_open()) {
        getline(file, line);
        potentialState = std::stoi(line);

        if (potentialState == )
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}