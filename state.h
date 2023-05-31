#pragma once
#include <cstring>
#include <fstream>
#include <iostream>

class State
{
private:
    int stateId, seats;
    char stateName[25];

public:
    State();
    State(const char *sName);

    void getStateInfo();
    void showStateInfo() const { std::cout << stateName << std::endl; }

    int getSeats() const { return seats; }
    void setSeats(int x) { seats = x; }

    int getstateId() const { return stateId; }
    void setstateId(int id) { stateId = id; }

    std::string getstateName() const { return stateName; }
    void setstateName(const char *sName) { strcpy(stateName, sName); }

    void storeState();
    void getStates(int x);
};
