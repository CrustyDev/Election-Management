#include "voter.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ios;
using std::ofstream;

extern void GetVoterId();
extern int voterId;
extern int stateCount;
extern void funHeading(const std::string& heading);
extern void GetStateCount();
extern int countDigits(int a);
extern int cityCount;
extern void GetCityCount();
extern void setVoterId();

Voter::Voter()
{
    partyId = 0;
    age = 18;
    voterID = 0;
    strcpy(partyName, "null");
    strcpy(voterName, "null");
    setPassword("1234");
    setstateId(0);
    setCityId(0);
    setstateName("NoName");
    setcityName("NoName");
}

void Voter::getVoterInfo()
{
    GetVoterId();
    voterID = ++voterId;
    std::cout << "\n\n   Your Id :  " << voterID;

    std::cin.ignore();
    std::cout << "\n\n   Enter Your Name            :  ";
    std::cin.getline(voterName, 24);
    std::cout << "\n   Enter Your Age             :  ";
    std::cin >> age;
    std::cout << "\n   Enter Your Gender(M/F)     :  ";
    std::cin >> gender;

    int sr;
    State bs1[stateCount];
    do
    {
        funHeading("Creating Voter Account : ");
        std::cout << "\n\n   Your Id : " << voterID;
        std::cout << "\n\n   Enter Your Name            :  " << voterName;
        std::cout << "\n\n   Enter Your Age             :  " << age;
        std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender << "\n\n";
        GetStateCount();
        std::cout << std::endl
                  << "   S.No.  State\n\n";
        for (int i = 0; i < stateCount; i++)
        {
            bs1[i].getStates(i);
            std::cout << "   " << i + 1 << ".";
            int j = countDigits(i + 1);
            for (int k = j; k < 8; k++)
                std::cout << " ";
            bs1[i].showStateInfo();
        }
        std::cout << "\n   Choose Your State (S.No) : ";
        std::cin >> sr;
        if (sr <= 0 || sr > stateCount)
        {
            std::cout << "\n   Invalid Choice!";
        }
    } while (sr <= 0 || sr > stateCount);

    setstateId(bs1[sr - 1].getstateId());
    setstateName(bs1[sr - 1].getstateName().c_str());

    City cs1[cityCount];
    do
    {
        funHeading("Creating Voter Account : ");
        std::cout << "\n\n   Your Id : " << voterID;
        std::cout << "\n\n   Enter Your Name            :  " << voterName;
        std::cout << "\n\n   Enter Your Age             :  " << age;
        std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
        std::cout << "\n\n   Select Your State          :  " << getstateName() << "\n\n";
        GetCityCount();
        std::cout << std::endl
                  << "   S.No.  City\n\n";
        for (int i = 0; i < cityCount; i++)
        {
            cs1[i].getCity(i);
            if (cs1[i].getstateId() == getstateId())
            {
                std::cout << "   " << i + 1 << ".";
                int j = countDigits(i + 1);
                for (int k = j; k < 8; k++)
                    std::cout << " ";
                cs1[i].showCityInfo();
            }
        }
        std::cout << "\n   Choose Your City (S.No) : ";
        std::cin >> sr;
        if (sr <= 0 || sr > cityCount)
        {
            std::cout << "\n   Invalid Choice!";
        }
    } while (sr <= 0 || sr > cityCount);

    setCityId(cs1[sr - 1].getcityId());
    setcityName(cs1[sr - 1].getcityName().c_str());

    funHeading("Creating Voter Account : ");
    std::cout << "\n\n   Your Id : " << voterID;
    std::cout << "\n\n   Enter Your Name            :  " << voterName;
    std::cout << "\n\n   Enter Your Age             :  " << age;
    std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
    std::cout << "\n\n   Select Your State          :  " << getstateName();
    std::cout << "\n\n   Select Your City           :  " << getcityName() << "\n\n";

    partyId = 0;
    strcpy(partyName, "null");
    setLeadCandidateId(0);
    char arr[10], cr;
    std::cout << "\n   Enter the Password : ";
    std::cout << "\n   Enter the Password : ";
    std::string password;
    do
    {
        std::getline(std::cin >> std::ws, password);
        if (password.length() > 10)
        {
            std::cout << "Password Length cannot be more than 10." << std::endl;
            std::cout << "Press Any Key to retry." << std::endl;
        }
    } while (password.length() > 10);
    setPassword(password.c_str());
    setVoterId();
}

void Voter::getVoter(int x)
{
    int i = 0;
    ifstream finVoterRecord;
    finVoterRecord.open("voter.txt", ios::in | ios::binary);
    if (!finVoterRecord)
    {
        std::cout << "\n   File not Found";
    }
    else
    {
        while (!finVoterRecord.eof() && i != x + 1)
        {
            finVoterRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
            i++;
        }
    }
}

void Voter::storeVoter()
{
    ofstream foutVoter;
    foutVoter.open("voter.txt", ios::app | ios::binary);
    foutVoter.write(reinterpret_cast<char *>(this), sizeof(*this));
    foutVoter.close();
}