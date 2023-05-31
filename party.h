#pragma once
#include <cstring>
#include <string>

class Party
{
private:
    int PartyID, votes, Members, seats;
    char partyName[50], headName[25], password[10];

public:
    Party();
    void getPartyInfo();

    inline std::string getPartyName() const { return partyName; }
    inline std::string getHeadName() const { return headName; }

    inline int getPartyId() const { return PartyID; }
    inline int getVotes() const { return votes; }
    inline int getMembers() const { return Members; }
    inline int getSeats() const { return seats; }
    inline std::string getPassword() const { return password; }

    inline void setPartyName(const char *newName) { strcpy(partyName, newName); }
    inline void setHeadName(const char *newName) { strcpy(headName, newName); }
    inline void setVotes(int n) { votes = n; }
    inline void setPartyId(int n) { PartyID = n; }
    inline void setMembers(int n) { Members = n; }
    inline void setSeats(int n) { seats = n; }
    inline void setPassword(const char *password) { strcpy(this->password, password); }

    void storeParty();
    void getParty(int x);
};