#include "candidate.h"
#include "city.h"
#include <algorithm>
#include <unordered_map>

extern int cityCount;
extern int candidateId;
extern int stateCount;
extern void GetCandidateId();
extern void setCandidateId();
extern void GetCityCount();
extern void SetCityCount();
extern void GetStateCount();
extern void SetStateCount();

void getStateResult(const State &state) {
  GetStateCount();
  GetCityCount();
  State states[stateCount];
  for (int i = 0; i < stateCount; i++)
    states[i].getStates(i);

  City cities[cityCount];
  for (int i = 0; i < cityCount; i++)
    cities[i].getCity(i);

  std::unordered_map<int, float> parties;
  int seats = 0;

  for (int i = 0; i < cityCount; i++) {
    if (cities[i].getstateId() == state.getstateId()) {
      if (cities[i].getLeadCandidateId()) {
        Candidate cand;
        seats += 1;
        cand.getCandidate(cities[i].getLeadCandidateId() - 1);
        if (!parties.extract(cand.getPartyId()))
          parties.insert({cand.getPartyId(), 1});
        else
          parties[cand.getPartyId()]++;
      } else {
        std::cout << "No votes from city " << cities[i].getcityName()
                  << std::endl;
        std::cout << "Cannot give result." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
      }
    }
  }

  if (!parties.empty()) {
    const auto maxId =
        std::max_element(parties.begin(), parties.end(),
                         [](const auto &first, const auto &second) {
                           return first.second < second.second;
                         });
    float majority_percent = (maxId->second / seats) * 100;
    if (majority_percent > 50.0f)
      std::cout << states[maxId->first - 1].getstateName()
                << " wins with majority of " << majority_percent << "%"
                << std::endl;
    else
      std::cout << "No clear majority but "
                << states[maxId->first - 1].getstateName() << " leads with "
                << majority_percent << "%" << std::endl;
  } else {
  }
  std::cin.ignore();
  std::cin.get();
}
