#include <iostream>
#include <string>
#include "D3.h"

int main() {
    D3 d3;

    while(true) {
        if (d3.getState()->moveToNext) d3.nextState();
        d3.loop();
    }
}