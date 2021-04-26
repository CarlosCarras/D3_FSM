cmake_minimum_required(VERSION 3.12)
project(D3_FSM)

set(CMAKE_CXX_STANDARD 14)

add_executable(D3_FSM main.cpp D3State.h D3.cpp D3.h StateDefinitions.h)