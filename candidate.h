#pragma once
#include "party.h"
#include "city.h"


class Candidate : public Party, public City
{
private:
	int candidateID, seats;
	char candidateName[25], candidatePost[30], gender;

public:

    Candidate();
    void getCandidateInfo();
	inline const char *getCandidateDesignation() const { return candidatePost; }
	inline std::string getCandidateName() const { return candidateName; }
	inline int getCandidateID() const { return candidateID; }
	inline int getSeats() const { return seats; }
	inline int getCandidateVotes() const { return getVotes(); }
	inline void setCandidateVotes(int n) { setVotes(n); }
	inline void setCandidateName(const char *newName) { strcpy(candidateName, newName); }
	inline void setCandidatePost(const char *newPost) { strcpy(candidatePost, newPost); }
	inline void setSeats(int n) { seats = n; }

	void storeCandidate();
	void getCandidate(int x);
};
