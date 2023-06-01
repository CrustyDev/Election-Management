#pragma once
#include "state.h"

class City : public State {
private:
  int cityId, LeadcandidateId;
  char cityName[25];

public:
  City();

  int getCityInfo(int sId, const char *sName);
  void showCityInfo() const { std::cout << cityName << std::endl; }

  int getcityId() const { return cityId; }
  std::string getcityName() const { return cityName; }
  int getLeadCandidateId() const { return LeadcandidateId; }

  void setCityId(int n) { cityId = n; }
  void setcityName(const char *name) { strcpy(cityName, name); }
  void storeCity();
  void getCity(int x);
  void setLeadCandidateId(int n) { LeadcandidateId = n; }
};
