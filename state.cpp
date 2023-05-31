#include "state.h"
#include <fstream>

extern int stateCount;
extern int stateIdNo;
extern void GetStateIdNo();
extern void SetStateIdNo();

State::State()
{
    stateId = 0;
    seats = 0;
    strcpy(stateName, "NoName");
}

State::State(const char *sName)
{
    stateCount++;
    stateId = stateCount;
    seats = 0;
    strcpy(stateName, sName);
}

void State::getStateInfo()
{
    std::cout << "Enter the Name : ";
    std::cin.getline(stateName, 24);
    GetStateIdNo();
    stateId = ++stateIdNo;
    SetStateIdNo();
    stateCount++;
    seats = 0;
}

void State::getStates(int x)
{
    int i = 0;
    std::ifstream finStateRecord;
    finStateRecord.open("States.bin", std::ios::in | std::ios::binary);
    if (!finStateRecord)
    {
        std::cout << "\n   File not Found";
    }
    else
    {
        while (!finStateRecord.eof() && i != x + 1)
        {
            finStateRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
            i++;
        }
    }
}

void State::storeState()
{
    std::ofstream foutState;
    foutState.open("States.bin", std::ios::app | std::ios::binary);
    foutState.write((char *)this, sizeof(*this));
    foutState.close();
}
