cmake_minimum_required(VERSION 3.20)

project("ElectionManagement")

add_executable(${PROJECT_NAME} main.cpp candidate.h candidate.cpp city.h city.cpp party.h party.cpp state.h state.cpp voter.h voter.cpp logic.h logic.cpp)
