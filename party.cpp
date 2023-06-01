#include "party.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ios;
using std::ofstream;

extern void GetPartyIdNo();
extern void SetPartyIdNo();
extern int partyId;

Party::Party()
{
    PartyID = 0;
    votes = 0;
    Members = 0;
    seats = 0;
    strcpy(partyName, "NoName");
    strcpy(headName, "NoName");
    setPassword("1234");
}

void Party::getPartyInfo()
{
    GetPartyIdNo();
    PartyID = ++partyId;
    SetPartyIdNo();
    // partyCount++;
    votes = 0;
    seats = 0;
    Members = 1;
    std::cin.ignore();
    std::cout << "Enter the PartyName : ";
    std::cin.getline(partyName, 49);

    std::cout << "\n   Enter the HeadName : ";
    std::cin.getline(headName, 24);
    char arr[10], cr;
    std::cout << "\n   Enter the Password : ";
    std::string password;
    do
    {
        // std::cin.ignore();
        std::getline(std::cin >> std::ws, password);
        if (password.length() > 10)
        {
            std::cout << "Password length cannot be more than 10." << std::endl;
        }
    } while (password.length() > 10);
    setPassword(password.c_str());
}

void Party::getParty(int x)
{
    int i = 0;
    ifstream finPartyRecord;
    finPartyRecord.open("Party.txt", ios::in | ios::binary);
    if (!finPartyRecord)
    {
        std::cout << "\n   File not Found";
    }
    else
    {
        while (!finPartyRecord.eof() && i != x + 1)
        {
            finPartyRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
            i++;
        }
    }
}

void Party::storeParty()
{
    ofstream foutParty;
    foutParty.open("Party.txt", ios::app | ios::binary);
    foutParty.write(reinterpret_cast<char *>(this), sizeof(*this));
    foutParty.close();
}
