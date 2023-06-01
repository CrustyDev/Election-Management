#include "candidate.h"
#include <fstream>

using std::ifstream;
using std::ios;
using std::ofstream;

extern void GetCandidateId();
extern void setCandidateId();
extern int candidateId;
extern void GetStateCount();
extern int stateCount;
extern int countDigits(int a);
extern void GetCityCount();
extern void SetPartyIdNo();
extern void GetPartyIdNo();
extern int cityCount;
extern int partyId;
extern void funHeading(const std::string &heading);

Candidate::Candidate() {
  setPartyId(0);
  setMembers(0);
  setVotes(0);
  seats = 0;
  setPartyName("NoName");
  setHeadName("NoName");
  setPassword("1234");
  setstateId(0);
  setCityId(0);
  setstateName("NoName");
  setcityName("NoName");
}

void Candidate::getCandidateInfo() {
  GetCandidateId();
  candidateID = ++candidateId;
  std::cout << "\n\n   Your Id :  " << candidateID;
  setCandidateId();
  std::cin.ignore();
  std::cout << "\n\n   Enter Your Name            :  ";
  std::cin.getline(candidateName, 24);
  std::cout << "\n   Enter Your Designation     :  ";
  std::cin.getline(candidatePost, 29);
  std::cout << "\n   Enter Your Gender(M/F)     :  ";
  std::cin >> gender;

  GetStateCount();
  int sr;
  State bs1[stateCount];
  do {
    funHeading("Creating Candidate Account : ");
    std::cout << "\n\n   Your Id : " << candidateID;
    std::cout << "\n\n   Enter Your Name            :  " << candidateName;
    std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
    std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender << "\n\n";
    std::cout << std::endl << "   S.No.  State\n\n";
    for (int i = 0; i < stateCount; i++) {
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
      std::cout << "\n   Invalid Choice!";
  } while (sr <= 0 || sr > stateCount);
  setstateId(bs1[sr - 1].getstateId());
  setstateName(bs1[sr - 1].getstateName().c_str());

  GetCityCount();
  City cs1[cityCount];
  do {
    funHeading("Creating Candidate Account : ");
    std::cout << "\n\n   Your Id : " << candidateID;
    std::cout << "\n\n   Enter Your Name            :  " << candidateName;
    std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
    std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
    std::cout << "\n\n   Select Your State          :  " << getstateName()
              << "\n\n";
    std::cout << std::endl << "   S.No.  City\n\n";
    for (int i = 0; i < cityCount; i++) {
      cs1[i].getCity(i);
      if (cs1[i].getstateId() == getstateId()) {
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
      std::cout << "\n   Invalid Choice!";
  } while (sr <= 0 || sr > cityCount);
  setCityId(cs1[sr - 1].getcityId());
  setcityName(cs1[sr - 1].getcityName().c_str());

  Party ps1[partyId];
  do {
    funHeading("Creating Candidate Account : ");
    std::cout << "\n\n   Your Id : " << candidateID;
    std::cout << "\n\n   Enter Your Name            :  " << candidateName;
    std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
    std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
    std::cout << "\n\n   Select Your State          :  " << getstateName();
    std::cout << "\n\n   Select Your City          :  " << getcityName()
              << "\n\n";
    GetPartyIdNo();
    std::cout << std::endl << "   S.No.  Party\n\n";
    for (int i = 0; i < partyId; i++) {
      ps1[i].getParty(i);
      std::cout << "   " << i + 1 << ".";
      int j = countDigits(i + 1);
      for (int k = j; k < 8; k++)
        std::cout << " ";
      std::cout << ps1[i].getPartyName() << std::endl;
    }
    std::cout << "\n   Choose Your Party (S.No) : ";
    std::cin >> sr;
    if (sr <= 0 || sr > partyId)
      std::cout << "\n   Invalid Choice!";
  } while (sr <= 0 || sr > partyId);
  setPartyId(ps1[sr - 1].getPartyId());
  setPartyName(ps1[sr - 1].getPartyName().c_str());
  setHeadName(ps1[sr - 1].getHeadName().c_str());

  int m = ps1[sr - 1].getMembers();
  ps1[sr - 1].setMembers(m + 1);
  SetPartyIdNo();
  remove("Party.txt");
  for (int i = 0; i < partyId; i++) {
    ps1[i].storeParty();
  }

  funHeading("Creating Candidate Account : ");
  std::cout << "\n\n   Your Id : " << candidateID;
  std::cout << "\n\n   Enter Your Name            :  " << candidateName;
  std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
  std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
  std::cout << "\n\n   Select Your State          :  " << getstateName();
  std::cout << "\n\n   Select Your City           :  " << getcityName();
  std::cout << "\n\n   Choose Your Party          :  " << getPartyName()
            << "\n\n";

  setMembers(1);
  setVotes(0);
  seats = 0;
  setLeadCandidateId(0);

  std::cout << "\n   Enter Your Password: ";
  std::string password;
  do {
    std::getline(std::cin >> std::ws, password);
    if (password.length() > 10) {
      std::cout << "Password length cannot be more than 10." << std::endl;
      std::cout << "Press Any key to retry." << std::endl;
    }
  } while (password.length() > 10);
  setPassword(password.c_str());
}

void Candidate::getCandidate(int x) {
  int i = 0;
  ifstream finCandidateRecord;
  finCandidateRecord.open("candidates.txt", ios::in | ios::binary);
  if (!finCandidateRecord) {
    std::cout << "\n   File not Found";
  } else {
    while (!finCandidateRecord.eof() && i != x + 1) {
      finCandidateRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
      i++;
    }
  }
}

void Candidate::storeCandidate() {
  ofstream foutCandidate;
  foutCandidate.open("candidates.txt", ios::app | ios::binary);
  foutCandidate.write(reinterpret_cast<char *>(this), sizeof(*this));
  foutCandidate.close();
}
