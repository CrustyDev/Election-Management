#pragma once
#include "city.h"

class Voter : public City
{
private:
    int voterID, partyId, age;
    char voterName[25], partyName[50], gender, password[10];

public:
    Voter();
    void getVoterInfo();

    inline std::string getVoterPartyName() const { return partyName; }
    inline std::string getVoterName() const { return voterName; }
    inline int getVoterID() const { return voterID; }
    inline int getVoterAge() const { return age; }
    inline char getVoterGender() const { return gender; }
    inline int getVoterPartyId() const { return partyId; }
    inline std::string getPassword() const { return password; }

    inline void setVoterName(const char *newName) { strcpy(voterName, newName); }
    inline void setPartyName(const char *newParty) { strcpy(partyName, newParty); }
    inline void setPartyId(int n) { partyId = n; }
    inline void setAge(int n) { age = n; }
    inline void setPassword(const char *password) { strcpy(this->password, password); }

    void storeVoter();
    void getVoter(int x);
};
