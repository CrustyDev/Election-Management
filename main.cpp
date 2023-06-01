#include "candidate.h"
#include "city.h"
#include "logic.h"
#include "party.h"
#include "state.h"
#include "voter.h"
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;
int stateCount = 0;
int cityCount = 0;
int stateIdNo = 0;
int cityIdNo = 0;
int partyId = 0;
int candidateId = 0;
int voterId = 0;
int resultId = 0;

void GetStateCount() {
  ifstream finStateCount;
  finStateCount.open("stateCount.txt");
  if (!finStateCount) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finStateCount >> stateCount;
  finStateCount.close();
}

void GetCityCount() {
  ifstream finCityCount;
  finCityCount.open("cityCount.txt");
  if (!finCityCount) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finCityCount >> cityCount;
  finCityCount.close();
}

void GetStateIdNo() {
  ifstream finStateIdNo;
  finStateIdNo.open("stateIdNo.txt");
  if (!finStateIdNo) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finStateIdNo >> stateIdNo;
  finStateIdNo.close();
}

void GetCityIdNo() {
  ifstream finCityIdNo;
  finCityIdNo.open("cityIdNo.txt");
  if (!finCityIdNo) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finCityIdNo >> cityIdNo;
  finCityIdNo.close();
}

void GetPartyIdNo() {
  ifstream finPartyIdNo;
  finPartyIdNo.open("partyIdNo.txt");
  if (!finPartyIdNo) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finPartyIdNo >> partyId;
  finPartyIdNo.close();
}

void GetCandidateId() {
  ifstream finCandidateId;
  finCandidateId.open("candidateId.txt");
  if (!finCandidateId) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finCandidateId >> candidateId;
  finCandidateId.close();
}

void GetVoterId() {
  ifstream finVoterId;
  finVoterId.open("voterId.txt");
  if (!finVoterId) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finVoterId >> voterId;
  finVoterId.close();
}

void GetResultId() {
  ifstream finResultId;
  finResultId.open("resultId.txt");
  if (!finResultId) {
    std::cout << "\n   File not Exists\n";
    return;
  }
  finResultId >> resultId;
  finResultId.close();
}

void SetStateCount() {
  ofstream foutStateCount;
  foutStateCount.open("stateCount.txt");
  foutStateCount << stateCount;
  foutStateCount.close();
}

void SetCityCount() {
  ofstream foutCityCount;
  foutCityCount.open("cityCount.txt");
  foutCityCount << cityCount;
  foutCityCount.close();
}

void SetStateIdNo() {
  ofstream foutStateIdNo;
  foutStateIdNo.open("stateIdNo.txt");
  foutStateIdNo << stateIdNo;
  foutStateIdNo.close();
}

void SetCityIdNo() {
  ofstream foutCityIdNo;
  foutCityIdNo.open("cityIdNo.txt");
  foutCityIdNo << cityIdNo;
  foutCityIdNo.close();
}

void SetPartyIdNo() {
  ofstream foutPartyIdNo;
  foutPartyIdNo.open("partyIdNo.txt");
  foutPartyIdNo << partyId;
  foutPartyIdNo.close();
}

void setCandidateId() {
  ofstream foutCandidateId;
  foutCandidateId.open("candidateId.txt");
  foutCandidateId << candidateId;
  foutCandidateId.close();
}

void setVoterId() {
  ofstream foutVoterId;
  foutVoterId.open("voterId.txt");
  foutVoterId << voterId;
  foutVoterId.close();
}

void setResultId() {
  ofstream foutResultId;
  foutResultId.open("resultId.txt");
  foutResultId << resultId;
  foutResultId.close();
}

void funFrontPage() {
#if defined _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void funHeading(const std::string &heading) {
  funFrontPage();

  std::cout << "   " << heading << "\n";
}

int countDigits(int a) {
  int i = 0;
  while (a > 0) {
    i++;
    a /= 10;
  }
  return i;
}

int choiceAdmin(int a) {
  int x;
  if (a == 0) {
    funHeading("Options : ");
    std::cout << "\n   1. Voter Login" << std::endl;
    std::cout << "   2. Candidate Login" << std::endl;
    std::cout << "   3. Party Login" << std::endl;
    std::cout << "   4. Create Account/Party" << std::endl;
    std::cout << "   5. View Result(s)" << std::endl;
    std::cout << "   6. Admin Side" << std::endl;
    std::cout << "   7. Exit" << std::endl;
  } else if (a == 1) {
    funHeading("Maintain Record : ");
    std::cout << "\n   0. GoBack" << std::endl;
    std::cout << "\n   1. View Voter Record" << std::endl;
    std::cout << "   2. View Candidate Record" << std::endl;
    std::cout << "   3. View Party Record" << std::endl;
    std::cout << "   4. Reset All Votes and Seats" << std::endl;
  } else if (a == 2) {
    funHeading("Admin Side Features : ");
    std::cout << "\n   0. GoBack" << std::endl;
    std::cout << "\n   1. Alter State Record" << std::endl;
    std::cout << "   2. Alter District Record" << std::endl;
    std::cout << "   3. Maintain Data" << std::endl;
    std::cout << "   4. Set Result Record" << std::endl;
  } else if (a == 3) {
    funHeading("Altering State Record : ");
    std::cout << "\n   0.GoBack" << std::endl;
    std::cout << "\n   1.Add State Record" << std::endl;
    std::cout << "   2.Show State Record" << std::endl;
    std::cout << "   3.Delete State Record" << std::endl;
    std::cout << "   4.Update State Record" << std::endl;
  } else if (a == 4) {
    funHeading("Altering City Record : ");
    std::cout << "\n   0.GoBack" << std::endl;
    std::cout << "\n   1.Add City Record" << std::endl;
    std::cout << "   2.Show City Record" << std::endl;
    std::cout << "   3.Delete City Record" << std::endl;
    std::cout << "   4.Update City Record" << std::endl;
  } else if (a == 5) {
    funHeading("Creating an Account : ");
    std::cout << "\n   0.GoBack" << std::endl;
    std::cout << "\n   1.Voter Account" << std::endl;
    std::cout << "   2.Candidate Account" << std::endl;
    std::cout << "   3.Create A Party" << std::endl;
  } else if (a == 6) {
    // funHeading("Options : ");
    std::cout << "\n\n   Options : - ";
    std::cout << "\n\n   0.LogOut" << std::endl;
    std::cout << "   1.View Members List" << std::endl;
    std::cout << "   2.Update Data" << std::endl;
  } else if (a == 7) {
    // funHeading("Options : ");
    std::cout << "\n\n   Options : - ";
    std::cout << "\n\n   0.LogOut" << std::endl;
    std::cout << "   1.View Other Members List" << std::endl;
    std::cout << "   2.Update Data" << std::endl;
  } else if (a == 8) {
    // funHeading("Options : ");
    std::cout << "\n\n   Options : - ";
    std::cout << "\n\n   0.LogOut" << std::endl;
    std::cout << "   1.Do Vote" << std::endl;
    std::cout << "   2.Update Data" << std::endl;
  } else if (a == 9) {
    funHeading("Showing the Result(s) : ");
    std::cout << "\n   0.GoBack" << std::endl;
    std::cout << "\n   1.OverAll Result" << std::endl;
    std::cout << "   2.Result in a Specific State" << std::endl;
    std::cout << "   3.Result in a Specific District" << std::endl;
    std::cout << "   4.List of Results for an Interval" << std::endl;
  }
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

void funStateInput(State *bs1, int x) {
  int y = x + stateCount;
  for (int i = stateCount, k = 0; i < y; i++, k++) {
    State obj;
    if (x > 1) {
      std::cout << "\n   Enter State " << k + 1 << "\n";
    } else {
      std::cout << "\n";
    }
    std::cout << "   ";
    obj.getStateInfo();
    std::string objName = obj.getstateName();
    for (int j = stateCount; j > 0; j--) {
      std::string cmpName = bs1[j - 1].getstateName();
      int k = cmpName.compare(objName);
      if (!k) {
        GetStateIdNo();
        stateIdNo--;
        SetStateIdNo();
        stateCount--;
        return;
      }
    }
    obj.storeState();
    bs1[stateCount - 1] = obj;
  }
}

void insertNewState() {
  int x;
  GetStateCount();
  std::cout << "\n   Enter the No. of State's you want to Insert: ";
  std::cin >> x;
  std::cin.ignore();
  if (x == 0) {
    return;
  }
  State *bs1 = new State[stateCount + x];
  funHeading("Inserting State's Record: ");
  std::cout << std::endl << "   S.No.  StateName\n\n";
  for (int i = 0; i < stateCount; i++) {
    bs1[i].getStates(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    for (int k = j; k < 8; k++)
      std::cout << " ";
    bs1[i].showStateInfo();
  }
  funStateInput(bs1, x);
  SetStateCount();
  std::cout
      << "\n\n   Record Inserted\n\n   Press any Key To Update The Record";
  std::cin.ignore();
  std::cin.get();
  delete[] bs1;
}

int inputDeleteChoices() {
  int x;
  std::cout << "   1.Delete Via SerialNumber(*Convenient)" << std::endl;
  std::cout << "   2.Delete Via StateName" << std::endl;
  std::cout << "   3.Go Back" << std::endl;
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

void deleteState() {
  GetStateCount();
  if (stateCount == 0) {
    std::cout << "\n   No Record Exists";
    return;
  }
  State bs1[stateCount];
  for (int i = 0; i < stateCount; i++) {
    bs1[i].getStates(i);
  }
  while (true) {
    funHeading("Deleting A State Record : ");
    std::cout << std::endl << "   S.No.  StateName\n\n";
    for (int i = 0; i < stateCount; i++) {
      std::cout << "   " << i + 1 << ".";
      int j = countDigits(i + 1);
      for (int k = j; k < 8; k++)
        std::cout << " ";
      bs1[i].showStateInfo();
    }
    std::cout << "\n\n";
    int ch = inputDeleteChoices();
    if (ch == 1) {
      int sr;
      std::cout << "\n   Enter the S.No. : ";
      std::cin >> sr;
      if (sr <= 0 || sr > stateCount) {
        std::cout << "\n   Invalid No!";
        continue;
      }
      std::cin.ignore();
      char cnfm;
      std::cout << "\n   Are you Sure to Delete Record "
                << bs1[sr - 1].getstateName() << " (y/n) : ";
      // cnfm = std::cout<<cnfm;
      std::cin >> cnfm;
      if (cnfm == 'y' || cnfm == 'Y') {
        for (int i = sr - 1; i < stateCount; i++) {
          bs1[i] = bs1[i + 1];
        }
        stateCount--;
        std::cout
            << "\n\n   Record Deleted\n\n   Press any Key to Update Record";
        std::cin.ignore();
        std::cin.get();
      }
    }
    if (ch == 2) {
      int sr;
      char sName[25];
      std::cout << "\n   Enter the StateName : ";
      std::cin.ignore();
      std::cin.getline(sName, 19);
      bool f = false;
      for (int i = 0; i < stateCount; i++) {
        std::string stName = bs1[i].getstateName();
        int match = stName.compare(sName);
        if (!match) {
          f = true;
          sr = i + 1;
          break;
        }
      }
      if (f != 1) {
        std::cout << "\n\n   Record Does not exist\n\n   Press any Key";
        std::cin.ignore();
        std::cin.get();
        continue;
      }
      char cnfm;
      std::cout << "\n   Are you Sure to Delete Record "
                << bs1[sr - 1].getstateName() << " (y/n) : ";
      std::cin >> cnfm; // cnfm = std::cout<<cnfm;
      if (cnfm == 'y' || cnfm == 'Y') {
        for (int i = sr - 1; i < stateCount; i++) {
          bs1[i] = bs1[i + 1];
        }
        stateCount--;
        std::cout
            << "\n\n   Record Deleted\n\n   Press any Key to Update Record";
        std::cin.ignore();
        std::cin.get();
      }
    }
    if (ch == 3) {
      SetStateCount();
      remove("States.bin");
      for (int i = 0; i < stateCount; i++) {
        bs1[i].storeState();
      }
      return;
    }
    std::cout << "\n   Enter the Correct Choice!";
  }
}

int inputUpdateChoices() {
  int x;
  std::cout << "   1.Update Via SerialNumber(*Convenient)" << std::endl;
  std::cout << "   2.Update Via StationName" << std::endl;
  std::cout << "   3.Go Back" << std::endl;
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

void updateState() {
  GetStateCount();
  if (stateCount == 0) {
    std::cout << "\n   No Record Exists";
    return;
  }
  State bs1[stateCount];
  for (int i = 0; i < stateCount; i++) {
    bs1[i].getStates(i);
  }
  while (true) {
    funHeading("Updating A State Record : ");
    std::cout << std::endl << "   S.No.  StateName\n\n";
    for (int i = 0; i < stateCount; i++) {
      std::cout << "   " << i + 1 << ".";
      int j = countDigits(i + 1);
      for (int k = j; k < 8; k++)
        std::cout << " ";
      bs1[i].showStateInfo();
    }
    std::cout << "\n\n";
    char newName[25];
    int ch = inputUpdateChoices();
    if (ch == 1) {
      int sr;
      std::cout << "\n   Enter the S.No. : ";
      std::cin >> sr;
      if (sr <= 0 || sr > stateCount) {
        std::cout << "\n   Invalid No!";
        continue;
      }
      std::cin.ignore();
      std::cout << "\n   Enter New StateName forState ("
                << bs1[sr - 1].getstateName() << ") : ";
      std::cin.getline(newName, 24);
      char cnfm;
      std::cout << "\n   Are you Sure to Update the Record to " << newName
                << " (y/n) : ";
      std::cin >> cnfm;
      if (cnfm == 'y' || cnfm == 'Y') {
        for (int i = sr - 1; i < stateCount; i++) {
          bs1[i] = bs1[i + 1];
        }
        stateCount--;
        State obj(newName);
        int j;
        for (j = stateCount - 1; j > 0; j--) {
          std::string cmpName = bs1[j - 1].getstateName();
          int k = cmpName.compare(newName);
          if (k < 0) {
            bs1[j] = bs1[j - 1];
          } else {
            break;
          }
        }
        bs1[j] = obj;
        std::cout
            << "\n\n   Record Updated\n\n   Press any Key to Update Record";
        std::cin.ignore();
        std::cin.get();
      }
    }
    if (ch == 2) {
      int sr;
      char sName[25];
      std::cout << "\n   Enter the StateName : ";
      std::cin.ignore();
      std::cin.getline(sName, 24);
      bool f = false;
      for (int i = 0; i < stateCount; i++) {
        std::string stName = bs1[i].getstateName();
        int match = stName.compare(sName);
        if (!match) {
          f = true;
          sr = i + 1;
          break;
        }
      }
      if (f != 1) {
        std::cout << "\n\n   No Record Found\n\n   Press any Key";
        std::cin.ignore();
        std::cin.get();
        continue;
      }
      std::cout << "\n   Enter New StateName forState ("
                << bs1[sr - 1].getstateName() << ") : ";
      std::cin.getline(newName, 24);
      char cnfm;
      std::cout << "\n   Are you Sure to Update the Record to " << newName
                << " (y/n) : ";
      // cnfm = std::cout<<cnfm;
      std::cin >> cnfm;
      if (cnfm == 'y' || cnfm == 'Y') {
        for (int i = sr - 1; i < stateCount; i++) {
          bs1[i] = bs1[i + 1];
        }
        stateCount--;
        State obj(newName);
        int j;
        for (j = stateCount - 1; j > 0; j--) {
          std::string cmpName = bs1[j - 1].getstateName();
          int k = cmpName.compare(newName);
          if (k < 0) {
            bs1[j] = bs1[j - 1];
          } else {
            break;
          }
        }
        bs1[j] = obj;
        std::cout
            << "\n\n   Record Updated\n\n   Press any Key to Update Record";
        std::cin.ignore();
        std::cin.get();
      }
    }
    if (ch == 3) {
      SetStateCount();
      remove("States.bin");
      for (int i = 0; i < stateCount; i++) {
        bs1[i].storeState();
      }
      return;
    }
    std::cout << "\n   Enter the Correct Choice!";
  }
}

void viewStateRecord() {
  GetStateCount();
  if (stateCount == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  std::cout << std::endl << "   S.No.  StateName    Seats\n\n";
  for (int i = 0; i < stateCount; i++) {
    State obj;
    obj.getStates(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    std::cout << std::string(8 - j, ' ');
    std::cout << obj.getstateName();
    std::cout << std::string(20 - obj.getstateName().length(), ' ');
    std::cout << obj.getSeats() << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}

int funCityInput(int stateId, const char *stateName, City *b, int x) {
  int y = x + cityCount, stateSeats = 0;
  City obj;
  for (int i = cityCount, k = 0; i < y; i++, k++) {
    if (x > 1) {
      std::cout << "\n   Enter City " << k + 1 << "\n";
    } else {
      std::cout << "\n";
    }
    std::cout << "   ";
    stateSeats = stateSeats + obj.getCityInfo(stateId, stateName);

    std::string objState = obj.getstateName();
    int j;
    for (j = cityCount - 1; j > 0; j--) {
      std::string cmpState = b[j - 1].getstateName();
      int k = cmpState.compare(objState);
      if (k < 0) {
        b[j] = b[j - 1];
      } else if (!k) {
        std::string objCity = obj.getcityName();
        std::string cmpCity = b[j - 1].getcityName();
        int k = cmpCity.compare(objCity);
        if (k < 0) {
          b[j] = b[j - 1];
        } else {
          break;
        }
      } else {
        break;
      }
    }
    b[j] = obj;
  }
  return stateSeats;
}

void insertNewCity() {
  int x;
  GetCityCount();
  GetStateCount();
  State bs1[stateCount];
  funHeading("Inserting City's Record: ");
  std::cout << std::endl << "   S.No.  StateName\n\n";
  for (int i = 0; i < stateCount; i++) {
    bs1[i].getStates(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    for (int k = j; k < 8; k++)
      std::cout << " ";
    bs1[i].showStateInfo();
  }
  int st;
  std::cout << "\n   Select the State via serialNo. : ";
  std::cin >> st;
  std::cin.ignore();
  std::cout << "\n   Enter the No. of Cities you want to Insert: ";
  std::cin >> x;
  std::cin.ignore();
  if (x == 0) {
    return;
  }

  City c[cityCount + x];
  // funHeading("Inserting State's Record: ");
  std::cout << std::endl << "\n\n   S.No.  CityName    Seats\n\n";
  char *cName;
  for (int i = 0; i < cityCount; i++) {
    c[i].getCity(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    for (int k = j; k < 8; k++)
      std::cout << " ";
    std::cout << c[i].getcityName();
    std::cout << std::string(14 - c[i].getcityName().length(), ' ');
    std::cout << c[i].getSeats() << std::endl;
    // std::cout<<"   "<<c[i].getstateId()<<" "<<c[i].getstateName()<<std::endl;
  }
  int seatsCount = funCityInput(bs1[st - 1].getstateId(),
                                bs1[st - 1].getstateName().c_str(), c, x);
  seatsCount = seatsCount + bs1[st - 1].getSeats();
  bs1[st - 1].setSeats(seatsCount);
  SetCityCount();
  remove("States.bin");
  for (int i = 0; i < stateCount; i++) {
    bs1[i].storeState();
  }
  remove("Cities.txt");
  for (int i = 0; i < cityCount; i++) {
    c[i].storeCity();
  }
  std::cout
      << "\n\n   Record Inserted\n\n   Press any Key To Update The Record";
  std::cin.ignore();
  std::cin.get();
}

/*int inputDeleteChoices(){
   int x;
   std::cout<<"   1.Delete Via SerialNumber(*Convenient)"<<std::endl;
   std::cout<<"   2.Delete Via StateName"<<std::endl;
   std::cout<<"   3.Go Back"<<std::endl;
   std::cout<<"\n   Enter your Choice : ";
   std::cin>>x;
   return x;
}*/
void deleteCity() {
  /*getStateCount();
  if(stateCount==0){std::cout<<"\n   No Record Exists";return;}
  State bs1[stateCount];
  for(int i=0;i<stateCount;i++){bs1[i].getStates(i);}
  redo:;*/
  funHeading("Deleting A State Record : ");
  std::cout << "   Available Soon";

  /*std::cout<<std::endl<<"   S.No.  StateName\n\n";
  for(int i=0;i<stateCount;i++){
     std::cout<<"   "<<i+1<<".";
     int j = countDigits(i+1);
     for(int k = j;k<8;k++) std::cout<<" ";
     bs1[i].showStateInfo();
  }
  std::cout<<"\n\n";
  int ch = inputDeleteChoices();
  if(ch == 1){
     int sr;
     std::cout<<"\n   Enter the S.No. : ";std::cin>>sr;
     if(sr<=0||sr>stateCount){std::cout<<"\n   Invalid No!";goto redo;}
     std::cin.ignore();
     char cnfm;
     std::cout<<"\n   Are you Sure to Delete Record
  "<<bs1[sr-1].getstateName()<<" (y/n) : ";
     //cnfm = std::cout<<cnfm;
     std::cin>>cnfm;
     if(cnfm == 'y'||cnfm == 'Y'){
            for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
            stateCount--;
            std::cout<<"\n\n   Record Deleted\n\n   Press any Key to Update
  Record";
     }
     goto redo;
  }
  else if(ch==2){
     int sr;char sName[25];
     std::cout<<"\n   Enter the StateName : ";
     std::cin.ignore();std::cin.getline(sName,19);
     bool f=0;
     for(int i=0;i<stateCount;i++){
            std::string stName = bs1[i].getstateName();
            int match = std::stringMatch(stName,sName);
            if(match==1){f=1;sr=i+1;break;}
     }
     if(f!=1){std::cout<<"\n\n   Record Already Not Exists\n\n   Press any
  Key";goto redo;} char cnfm; std::cout<<"\n   Are you Sure to Delete Record
  "<<bs1[sr-1].getstateName()<<" (y/n) : ";std::cin>>cnfm;//cnfm =
  std::cout<<cnfm; if(cnfm == 'y'||cnfm == 'Y'){ for(int
  i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];} stateCount--; std::cout<<"\n\n
  Record Deleted\n\n   Press any Key to Update Record";
     }
     goto redo;
  }
  else if (ch==3){
     setStateCount();
     remove("States.bin");
     for(int i=0;i<stateCount;i++){bs1[i].storeState();}
     return;
  }
  else{std::cout<<"\n   Enter the Correct Choice!";goto redo;}*/
}

/*int inputUpdateChoices(){
   int x;
   std::cout<<"   1.Update Via SerialNumber(*Convenient)"<<std::endl;
   std::cout<<"   2.Update Via StationName"<<std::endl;
   std::cout<<"   3.Go Back"<<std::endl;
   std::cout<<"\n   Enter your Choice : ";
   std::cin>>x;
   return x;
}*/
void updateCity() {
  funHeading("Updating A State Record : ");
  std::cout << "   Available Soon";
}

void viewCityRecord() {
  GetCityCount();
  if (cityCount == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  City bs1[cityCount];
  std::cout << std::endl << "   S.No.  State Name    CityName    Seats\n\n";
  char *sName;
  for (int i = 0; i < cityCount; i++) {
    bs1[i].getCity(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    std::cout << std::string(6 - j, ' ');
    std::cout << bs1[i].getstateName();
    std::cout << std::string(20 - bs1[i].getstateName().length(), ' ');
    std::cout << bs1[i].getcityName()
              << std::string(15 - bs1[i].getcityName().length(), ' ');
    std::cout << bs1[i].getSeats() << std::endl;
  }
  std::cout << "Press ANY Key to contunue.";
  std::cin.ignore();
  std::cin.get();
}

int funPartyInput(Party *bs1, int x) {
  Party obj;
  std::cout << "   ";
  obj.getPartyInfo();
  bs1[partyId - 1] = obj;

  return obj.getPartyId();
}

int insertNewParty() {
  int Id = 0;
  GetPartyIdNo();
  funHeading("Inserting Party Record: \n");
  Party obj;
  obj.getPartyInfo();
  Id = obj.getPartyId();
  SetPartyIdNo();
  obj.storeParty();
  std::cout
      << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
  std::cin.get();

  return Id;
}

int partyLogin() {
  GetPartyIdNo();
  if (partyId == 0) {
    std::cout << "\n   No Record Found";
    return 0;
  }
  Party bs1[partyId];
  funHeading("Party Login Page: ");
  std::cout << std::endl << "   S.No.   PartyName\n\n";
  for (int i = 0; i < partyId; i++) {
    bs1[i].getParty(i);
    std::cout << "   " << i + 1 << ".";
    int j = countDigits(i + 1);
    for (int k = j; k < 8; k++)
      std::cout << " ";
    std::cout << bs1[i].getPartyName() << std::endl;
  }
  int x;
  std::cout << "\n   Select the Party via S.No. : ";
  std::cin >> x;
  std::cin.ignore();
  char paswrd[10], cr;
  std::string cmpPaswrd = bs1[x - 1].getPassword();
  std::cout << "\n   Enter Your Password: ";
  std::string password;
  do {
    // std::cin.ignore();
    std::getline(std::cin >> std::ws, password);
    if (password.length() > 10) {
      std::cout << "Password length cannot be more than 10." << std::endl;
    }
  } while (password.length() > 10);

  int match = password.compare(cmpPaswrd);
  if (!match) {
    return bs1[x - 1].getPartyId();
  }
  std::cout << "\n   Wrong Password!";

  return 0;
}

int inputPartyUpdateChoice() {
  int x;
  std::cout << "   1.Change HeadName" << std::endl;
  std::cout << "   2.Change Password" << std::endl;
  std::cout << "   3.Go Back" << std::endl;
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

int confirm() {
  char x;
  std::cout << "\n   Are You Sure (y/n) : ";
  std::cin >> x;
  // x = std::cout<<x;
  if (x == 'y' || x == 'Y')
    return 1;
  return 0;
}

void displayCandidateInfo(Candidate obj) {
  int c = 0;
  c = countDigits(obj.getCandidateID());
  std::cout << "   " << obj.getCandidateID();
  for (int i = c; i < 7; i++)
    std::cout << " ";
  std::cout << obj.getCandidateName();
  std::cout << std::string(25 - obj.getCandidateName().length(), ' ');
  std::cout << obj.getstateName()
            << std::string(20 - obj.getstateName().length(), ' ');
  std::cout << obj.getcityName()
            << std::string(20 - obj.getcityName().length(), ' ');
  c = countDigits(obj.getVotes());
  std::cout << obj.getVotes();
}

void viewPartyInfo(int Id) {
  GetPartyIdNo();
  if (partyId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Party bs1[partyId], obj;
  GetCandidateId();
  Candidate cs1[candidateId];

  int sIndex = Id - 1;
  for (int i = 0; i < partyId; i++) {
    bs1[i].getParty(i);
  }

  obj = bs1[sIndex];
  obj.setSeats(0);
  obj.setVotes(0);
  for (int i = 0; i < candidateId; i++) {
    cs1[i].getCandidate(i);
    if (cs1[i].getPartyId() == obj.getPartyId()) {
      int pseats = obj.getSeats();
      pseats = pseats + cs1[i].getSeats();
      obj.setSeats(pseats);
      int pVotes = obj.getVotes();
      pVotes = pVotes + cs1[i].getCandidateVotes();
      obj.setVotes(pVotes);
    }
  }
  while (true) {
    funHeading("");
    std::cout << "\n   PartyName : " << obj.getPartyName();
    std::cout << "\n   Head      : " << obj.getHeadName();
    std::cout << "\n   Members   : " << obj.getMembers();
    std::cout << "\n   Seats     : " << obj.getSeats();
    std::cout << "\n   Votes     : " << obj.getVotes();
    int ch = choiceAdmin(6);
    switch (ch) {
    case 1:
      funHeading("List Of Members : -");
      std::cout << "\n   PartyName : " << obj.getPartyName();
      std::cout << "       Head : " << obj.getHeadName();
      std::cout << "       Members : " << obj.getMembers();
      std::cout << "\n\n\n   ID         Name                  State            "
                   "   City            Votes\n";
      for (int i = 0; i < candidateId; i++) {
        if (cs1[i].getPartyId() == obj.getPartyId()) {
          displayCandidateInfo(cs1[i]);
          std::cout << "\n";
        }
      }
      std::cin.ignore();
      std::cin.get();
      break;
    case 2: {
      std::cout << "\n\n";
      int ch3 = inputPartyUpdateChoice();
      std::cin.ignore();
      if (ch3 == 1) {
        char newName[25];
        std::cout << "\n   Enter the New HeadName : ";
        std::cin.getline(newName, 24);
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setHeadName(newName);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
      }
      if (ch3 == 2) {
        char newPassword[10], cr;
        std::cout << "\n   Enter the New Password : ";
        for (int i = 0; i < 10; i++) {
          cr = getchar();
          if (cr != '\r') {
            newPassword[i] = cr;
            std::cout << "*";
          } else {
            newPassword[i] = '\0';
            break;
          }
        }
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setPassword(newPassword);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
          break;
        }
      }
      if (ch3 == 3) {
        break;
      }
      std::cout << "Invalid Choice" << std::endl;
      break;
    }
    case 0:
      // bs1[sIndex].setMembers(3);
      SetPartyIdNo();
      remove("Party.txt");
      for (int i = 0; i < partyId; i++) {
        bs1[i].storeParty();
      }
      return;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  }
}

int funCandidateInput(Candidate *bs1, int x) {
  Candidate obj;
  std::cout << "   ";
  obj.getCandidateInfo();

  bs1[candidateId - 1] = obj;

  return obj.getCandidateID();
}

int insertNewCandidate() {
  int x = 1, Id = 0;
  GetCandidateId();
  if (x == 0) {
    return Id;
  }
  Candidate bs1[candidateId + x];

  funHeading("Creating Candidate Account : \n");
  for (int i = 0; i < candidateId; i++) {
    bs1[i].getCandidate(i);
  }
  Id = funCandidateInput(bs1, x);
  setCandidateId();
  remove("candidates.txt");
  for (int i = 0; i < candidateId; i++) {
    bs1[i].storeCandidate();
  }
  std::cout
      << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
  std::cin.ignore();
  std::cin.get();

  return Id;
}

int CandidateLogin() {
  GetCandidateId();
  if (candidateId == 0) {
    std::cout << "\n   No Record Found";
    return 0;
  }
  Candidate bs1[candidateId];
  for (int i = 0; i < candidateId; i++) {
    bs1[i].getCandidate(i);
  }
redo:;
  funHeading("Candidate Login Page: ");

  int Id;
  std::cout << "\n   Enter Your Id : ";
  std::cin >> Id;
  std::cin.ignore();
  bool f = false;
  int index = Id - 1;
  if (Id == bs1[index].getCandidateID()) {
    f = true;
  }

  if (!f) {
    std::cout << "\n   No Account exists with this Id!";
    goto redo;
  }

  std::string cmpPaswrd = bs1[index].getPassword();
  std::cout << "\n   Enter Your Password: ";
  std::string password;

  do {
    std::getline(std::cin >> std::ws, password);
    if (password.length() > 10) {
      std::cout << "Password cannot be greater than 10 letters" << std::endl;
    }
  } while (password.length() > 10);

  int match = password.compare(cmpPaswrd);
  if (!match) {
    return bs1[index].getCandidateID();
  }
  std::cout << "\n   Wrong Password!";
  return 0;
}

int inputCandidateUpdateChoice() {
  int x;
  std::cout << "   1.Change Name" << std::endl;
  std::cout << "   2.Change Password" << std::endl;
  std::cout << "   3.Change Description" << std::endl;
  std::cout << "   4.Go Back" << std::endl;
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

void viewCandidateInfo(int Id) {
  GetCandidateId();
  if (candidateId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Candidate bs1[candidateId], obj;
  int sIndex = Id - 1;
  for (int i = 0; i < candidateId; i++) {
    bs1[i].getCandidate(i);
    /*if(bs1[i].getCandidateID()==Id){
    sIndex = i;
    }*/
  }
  while (true) {
    obj = bs1[sIndex];
    funHeading("Welcome : ");
    std::cout << "\n   PartyName  : " << obj.getPartyName();
    std::cout << "        Head  : " << obj.getHeadName();
    std::cout << "\n\n   Name         : " << obj.getCandidateName();
    std::cout << "\n   Designation  : " << obj.getCandidateDesignation();
    std::cout << "\n   State        : " << obj.getstateName();
    std::cout << "\n   City         : " << obj.getcityName();
    std::cout << "\n   Votes        : " << obj.getVotes();
    std::cout << "\n   Seats        : " << obj.getSeats();

    int ch = choiceAdmin(7);
    switch (ch) {
    case 1: {
      funHeading("List Of Other Members : -");
      std::cout << "\n   PartyName : " << obj.getPartyName();
      std::cout << "       Head : " << obj.getHeadName();

      std::cout << "\n\n\n   ID         Name                  State            "
                   "   City            Votes\n";
      for (int i = 0; i < candidateId; i++) {
        if (bs1[i].getPartyId() == obj.getPartyId() &&
            bs1[i].getCandidateID() != obj.getCandidateID()) {
          displayCandidateInfo(bs1[i]);
          std::cout << "\n";
        }
      }
      break;
    }
    case 2: {
      std::cout << "\n\n";
      int ch3 = inputCandidateUpdateChoice();
      std::cin.ignore();
      if (ch3 == 1) {
        char newName[25];
        std::cout << "\n   Enter the New HeadName : ";
        std::cin.getline(newName, 24);
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setCandidateName(newName);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
      } else if (ch3 == 2) {
        char newPassword[10], cr;
        std::cout << "\n   Enter the New Password : ";
        for (int i = 0; i < 10; i++) {
          cr = getchar();
          if (cr != '\r') {
            newPassword[i] = cr;
            std::cout << "*";
          } else {
            newPassword[i] = '\0';
            break;
          }
        }
        std::cout << "\n";
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setPassword(newPassword);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
      } else if (ch3 == 3) {
        char newDescription[25];
        std::cout << "\n   Enter the New Description : ";
        std::cin.getline(newDescription, 24);
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setCandidatePost(newDescription);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
      } else if (ch3 == 4) {
        continue;
      } else {
        std::cout << "\n   Enter the Correct Choice!";
      }
      break;
    }
    case 0:
      /*setPartyCount();*/
      remove("candidates.txt");
      for (int i = 0; i < candidateId; i++) {
        bs1[i].storeCandidate();
      }
      return;
    default:
      std::cout << "\n   Enter the Correct Choice!";
    }
  }
}

int funVoterInput(Voter *b, int x) {
  Voter obj;
  std::cout << "   ";
  obj.getVoterInfo();

  b[voterId - 1] = obj;

  return obj.getVoterID();
}

int insertNewVoter() {
  int x = 1, Id = 0;
  GetVoterId();
  if (x == 0) {
    return Id;
  }
  Voter bs1[voterId + x];

  funHeading("Creating Voter Account : \n");
  for (int i = 0; i < voterId; i++) {
    bs1[i].getVoter(i);
  }
  Id = funVoterInput(bs1, x);
  setVoterId();
  remove("voter.txt");
  for (int i = 0; i < voterId; i++) {
    bs1[i].storeVoter();
  }
  std::cout
      << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
  std::cin.ignore();
  std::cin.get();

  return Id;
}

int VoterLogin() {
  GetVoterId();
  if (voterId == 0) {
    std::cout << "\n   No Record Found";
    return 0;
  }
  Voter bs1[voterId];
  for (int i = 0; i < voterId; i++) {
    bs1[i].getVoter(i);
  }

  bool f = false;
  int Id;
  int index;
  do {
    // funHeading("Voter Login Page: ");

    std::cout << "\n   Enter Your Id : ";
    std::cin.ignore();
    std::cin >> Id;

    index = Id - 1;
    if (Id == bs1[index].getVoterID()) {
      f = true;
    }

    if (!f) {
      std::cout << "\n   No Account exists with this Id!";
      continue;
    }
  } while (!f);

  std::string cmpPaswrd = bs1[index].getPassword();
  std::string password;
  std::cout << "\n   Enter Your Password: ";

  do {
    std::getline(std::cin >> std::ws, password);
    if (password.length() > 10) {
      std::cout << "Password cannot be longer than 10 characters" << std::endl;
    }
  } while (password.length() > 10);
  int match = password.compare(cmpPaswrd);
  if (!match)
    return Id;
  std::cout << "\n   Wrong Password!";
  return 0;
}

int inputVoterUpdateChoice() {
  int x;
  std::cout << "   1.Change Name" << std::endl;
  std::cout << "   2.Change Age" << std::endl;
  std::cout << "   3.Change Password" << std::endl;
  std::cout << "   4.Go Back" << std::endl;
  std::cout << "\n   Enter your Choice : ";
  std::cin >> x;
  return x;
}

void displayCandidateForVote(Candidate obj) {
  int c = 0;
  c = countDigits(obj.getCandidateID());
  std::cout << "   " << obj.getCandidateID();
  for (int i = c; i < 7; i++)
    std::cout << " ";
  std::cout << obj.getCandidateName()
            << std::string(25 - obj.getCandidateName().length(), ' ');
  std::cout << obj.getPartyName();
}

void voterMakeVote(Voter &vs1) {
  GetCandidateId();
  Candidate candidates[candidateId];
  GetCityCount();
  City city1[cityCount];
  int cindex;
  int vCityId = vs1.getcityId();
  for (int i = 0; i < cityCount; i++) {
    city1[i].getCity(i);
    if (city1[i].getcityId() == vCityId) {
      cindex = i;
    }
  }

  funHeading("Making A Vote : \n");
  std::cout << "   State : " << vs1.getstateName()
            << "        City : " << vs1.getcityName();
  std::cout << "\n\n\n   ID      CandidateName                  Party\n";
  for (int i = 0; i < candidateId; i++) {
    candidates[i].getCandidate(i);
    if (candidates[i].getcityId() == vCityId) {
      displayCandidateForVote(candidates[i]);
      std::cout << "\n";
    }
  }
  int selectedId;
  std::cout << "\n\n   Select via Id whom you want to vote :  ";
  std::cin >> selectedId;
  char ays;
  std::cout << "\n   Are you sure to vote for "
            << candidates[selectedId - 1].getCandidateName() << " ( "
            << candidates[selectedId - 1].getPartyName() << " ) (y/n):";
  std::cin >> ays;
  if (ays == 'y' || ays == 'Y') {
    int vote = candidates[selectedId - 1].getCandidateVotes();
    candidates[selectedId - 1].setCandidateVotes(vote + 1);
    vs1.setPartyId(candidates[selectedId - 1].getCandidateID());
    vs1.setPartyName(candidates[selectedId - 1].getPartyName().c_str());
    int leadingCandidate = city1[cindex].getLeadCandidateId();
    if (!leadingCandidate) {
      int maxvotes = candidates[leadingCandidate - 1].getCandidateVotes();
      if (vote > maxvotes) {
        city1[cindex].setLeadCandidateId(selectedId);
      }
    } else {
      int maxvotes = INT8_MIN;
      for (int i = 0; i < candidateId; i++) {
        if (candidates[i].getcityId() == vCityId) {
          if (candidates[i].getCandidateVotes() > maxvotes) {
            maxvotes = candidates[i].getCandidateVotes();
            city1[cindex].setLeadCandidateId(candidates[i].getCandidateID());
          }
        }
      }
    }
    for (int i = 0; i < candidateId; i++) {
      if (candidates[i].getcityId() == vCityId) {
        if (candidates[i].getCandidateID() ==
            city1[cindex].getLeadCandidateId()) {
          candidates[i].setSeats(1);
        } else {
          candidates[i].setSeats(0);
        }
      }
    }
    remove("Cities.txt");
    for (int i = 0; i < cityCount; i++) {
      city1[i].storeCity();
    }
    remove("candidates.txt");
    for (int i = 0; i < candidateId; i++) {
      candidates[i].storeCandidate();
    }

    std::cout << "\n   Voted Successfully\n\n   Press any Key To Update Data";
    std::cin.ignore();
    std::cin.get();
  }
}

void viewVoterInfo(int Id) {
  GetVoterId();
  if (voterId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Voter bs1[voterId], obj;
  int sIndex = Id - 1;
  for (int i = 0; i < voterId; i++) {
    bs1[i].getVoter(i);
  }
  while (true) {
    obj = bs1[sIndex];
    funHeading("Welcome : ");
    std::cout << "\n   Name   : " << obj.getVoterName();
    std::cout << "          VotedToParty : " << obj.getVoterPartyName();
    std::cout << "\n   Age    : " << obj.getVoterAge();
    std::cout << "\n   Gender : " << obj.getVoterGender();
    std::cout << "\n   State  : " << obj.getstateName();
    std::cout << "\n   City   : " << obj.getcityName();
    int ch = choiceAdmin(8);
    int able;
    switch (ch) {
    case 1:
      able = obj.getVoterPartyId();
      if (able == 0) {
        voterMakeVote(bs1[Id - 1]);
      } else {
        std::cout
            << "\n   You have already voted.Now you can't change your vote";
      }
      break;
    case 2: {
      std::cout << "\n\n";
      int ch3 = inputVoterUpdateChoice();
      std::cin.ignore();
      if (ch3 == 1) {
        char newName[25];
        std::cout << "\n   Enter the New Name : ";
        std::cin.getline(newName, 24);
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setVoterName(newName);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
      }
      if (ch3 == 2) {
        int newAge;
        std::cout << "\n   Enter the New Age : ";
        std::cin >> newAge;
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setAge(newAge);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
        break;
      }
      if (ch3 == 3) {
        char newPassword[10], cr;
        std::cout << "\n   Enter the New Password : ";
        std::string password;
        do {
          std::getline(std::cin >> std::ws, password);
          if (password.length() > 10) {
            std::cout << "Password cannot be greater than 10 characters"
                      << std::endl;
          }
        } while (password.length() > 10);
        int y = confirm();
        if (y == 1) {
          bs1[sIndex].setPassword(newPassword);
          std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
          std::cin.ignore();
          std::cin.get();
        }
        break;
      }
      if (ch3 == 4) {
        break;
      }
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
    case 0:
      remove("voter.txt");
      for (int i = 0; i < voterId; i++) {
        bs1[i].storeVoter();
      }
      return;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  }
}

void displayVoterRecord(Voter bs1[], int vId) {
  funHeading("Voter's Record : ");

  std::cout << "\n   ID     NAME               AGE   GENDER   STATE          "
               "CITY     Vote-STATUS\n\n";

  for (int i = 0; i < vId; i++) {
    int c = 0;
    c = countDigits(bs1[i].getVoterID());
    std::cout << "   " << bs1[i].getVoterID();
    std::cout << std::string(7 - c, ' ');
    std::cout << bs1[i].getVoterName()
              << std::string(20 - bs1[i].getVoterName().length(), ' ');
    c = countDigits(bs1[i].getVoterAge());
    std::cout << bs1[i].getVoterAge();
    std::cout << std::string(7 - c, ' ');

    std::cout << bs1[i].getVoterGender();
    std::cout << std::string(6, ' ');

    std::cout << bs1[i].getstateName();
    std::cout << std::string(15 - bs1[i].getstateName().length(), ' ');
    std::cout << bs1[i].getcityName();
    std::cout << std::string(15 - bs1[i].getcityName().length(), ' ');
    c = bs1[i].getVoterPartyId();
    std::cout << (c ? "1" : "0") << std::endl;
  }
}

void viewVoterRecord() {
  GetVoterId();
  if (voterId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Voter bs1[voterId];
  for (int i = 0; i < voterId; i++) {
    bs1[i].getVoter(i);
  }

  displayVoterRecord(bs1, voterId);
redo:;
  std::cout << "\n\n   0.GoBack";
  std::cout << "\n   1.Apply Filter (Sort/OrderBy (State,City))";
  int ch;
  std::cout << "\n\n   Enter Your Choice : ";
  std::cin >> ch;
  if (ch == 0) {
    return;
  }
  Voter bs2[voterId], obj;
  int id = 0;
  for (int i = 0; i < voterId; i++) {
    obj = bs1[i];
    std::string objState = obj.getstateName();
    int j;
    for (j = id; j > 0; j--) {
      std::string cmpState = bs2[j - 1].getstateName();
      int k = cmpState.compare(objState);
      if (k < 0) {
        bs2[j] = bs2[j - 1];
      } else if (!k) {
        std::string objCity = obj.getcityName();
        std::string cmpCity = bs2[j - 1].getcityName();
        int k = cmpCity.compare(objCity);
        if (k < 0) {
          bs2[j] = bs2[j - 1];
        } else {
          goto in;
        }
      } else {
        break;
      }
    }
  in:;
    id++;
    bs2[j] = obj;
  }
  displayVoterRecord(bs2, voterId);
  goto redo;
}

void displayCandidateRecord(Candidate bs1[], int cId) {
  funHeading("Candidate's Record : ");

  std::cout << "\n   ID     NAME                     PARTYNAME                 "
               "   STATE           CITY         VOTES  SEATS\n\n";
  for (int i = 0; i < cId; i++) {
    int c = 0;
    c = countDigits(bs1[i].getCandidateID());
    std::cout << "   " << bs1[i].getCandidateID();
    for (int i = c; i < 7; i++)
      std::cout << " ";
    std::cout << bs1[i].getCandidateName();
    std::cout << std::string(25 - bs1[i].getCandidateName().length(), ' ');
    c = strlen(bs1[i].getPartyName().c_str());
    std::cout << bs1[i].getPartyName();
    for (int i = c; i < 30; i++)
      std::cout << " ";
    std::cout << bs1[i].getstateName();
    std::cout << std::string(15 - bs1[i].getstateName().length(), ' ');
    std::cout << bs1[i].getcityName();
    std::cout << std::string(15 - bs1[i].getcityName().length(), ' ');
    c = countDigits(bs1[i].getCandidateVotes());
    std::cout << bs1[i].getCandidateVotes();
    for (int i = c; i < 7; i++)
      std::cout << " ";
    std::cout << bs1[i].getSeats() << "\n";
  }
}

void viewCandidateRecord() {
  GetCandidateId();
  if (candidateId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Candidate bs1[candidateId];

  for (int i = 0; i < candidateId; i++) {
    bs1[i].getCandidate(i);
  }
  displayCandidateRecord(bs1, candidateId);
redo:;
  std::cout << "\n\n   0.GoBack";
  std::cout << "\n   1.Apply Filter";
  int ch;
  std::cout << "\n\n   Enter Your Choice : ";
  std::cin >> ch;
  if (ch != 1) {
    return;
  }
  Candidate bs2[candidateId], obj;
  int id = 0;
  std::cout << "\n   0.GoBack";
  std::cout << "\n   1.Sort/OrderBy(Id)";
  std::cout << "\n   2.Sort/OrderBy(State,City,PartyName)";
  std::cout << "\n   3.Sort/OrderBy(PartyName,State,City)";
  std::cout << "\n\n   Enter Your Choice : ";
  std::cin >> ch;
  if (ch == 2) {
    for (int i = 0; i < candidateId; i++) {
      obj = bs1[i];
      std::string objState = obj.getstateName();
      int j;
      for (j = id; j > 0; j--) {
        std::string cmpState = bs2[j - 1].getstateName();
        int k = cmpState.compare(objState);
        if (k < 0) {
          bs2[j] = bs2[j - 1];
        } else if (!k) {
          std::string objCity = obj.getcityName();
          std::string cmpCity = bs2[j - 1].getcityName();
          int k = cmpCity.compare(objCity);
          if (k < 0) {
            bs2[j] = bs2[j - 1];
          } else if (!k) {
            std::string objParty = obj.getPartyName();
            std::string cmpParty = bs2[j - 1].getPartyName();
            int k = cmpParty.compare(objParty);
            if (k < 0) {
              bs2[j] = bs2[j - 1];
            } else {
              goto in;
            }
          } else {
            goto in;
          }
        } else {
          break;
        }
      }
    in:;
      id++;
      bs2[j] = obj;
    }
    displayCandidateRecord(bs2, candidateId);
    goto redo;
  }
  if (ch == 3) {
    for (int i = 0; i < candidateId; i++) {
      obj = bs1[i];
      std::string objParty = obj.getPartyName();
      int j;
      for (j = id; j > 0; j--) {
        std::string cmpParty = bs2[j - 1].getPartyName();
        int k = cmpParty.compare(objParty);
        if (k < 0) {
          bs2[j] = bs2[j - 1];
        } else if (!k) {
          std::string objState = obj.getstateName();
          std::string cmpState = bs2[j - 1].getstateName();
          int k = cmpState.compare(objState);
          if (k < 0) {
            bs2[j] = bs2[j - 1];
          } else if (!k) {
            std::string objCity = obj.getcityName();
            std::string cmpCity = bs2[j - 1].getcityName();
            int k = cmpCity.compare(objCity);
            if (k < 0) {
              bs2[j] = bs2[j - 1];
            } else {
              goto in2;
            }
          } else {
            goto in2;
          }
        } else {
          break;
        }
      }
    in2:;
      id++;
      bs2[j] = obj;
    }
    displayCandidateRecord(bs2, candidateId);
    goto redo;
  }
  displayCandidateRecord(bs1, candidateId);
  goto redo;
}

void viewPartyRecord() {
  GetPartyIdNo();
  if (partyId == 0) {
    std::cout << "\n   No Record Found";
    return;
  }
  Party bs1[partyId];

  funHeading("Party's Record : ");

  std::cout << "\n   ID     NAME                          HEAD             "
               "MEMBERS\n\n";
  for (int i = 0; i < partyId; i++) {
    bs1[i].getParty(i);
    int c = 0;
    c = countDigits(bs1[i].getPartyId());
    std::cout << "   " << bs1[i].getPartyId();
    for (int i = c; i < 7; i++)
      std::cout << " ";
    std::cout << bs1[i].getPartyName();
    std::cout << std::string(30 - bs1[i].getPartyName().length(), ' ');
    std::cout << bs1[i].getHeadName();
    std::cout << std::string(20 - bs1[i].getHeadName().length(), ' ');
    std::cout << bs1[i].getMembers() << "\n";
  }

  std::cout << "\n\n   Press Any Key To Go Back";
  std::cin.ignore();
  std::cin.get();
}

void ResetVotes() {
  funHeading("Reseting the Record in DataBase : ");
  std::cout << "\n\n   1.Reset Voter's Record\n";
  std::cout << "   2.Reset Party/Candidate's Record";
  std::cout << "\n\n   Enter Your Choice : ";
  int ch;
  std::cin >> ch;
  char c;
  std::cout << "\n   Are you sure to reset the Record (y/n) :";
  std::cin >> c;
  if (c == 'y' || c == 'Y') {
    if (ch == 1) {
      GetVoterId();
      if (voterId != 0) {
        Voter vs1[voterId];
        for (int i = 0; i < voterId; i++) {
          vs1[i].getVoter(i);
          vs1[i].setPartyId(0);
          vs1[i].setPartyName("null");
        }
        remove("voter.txt");
        for (int i = 0; i < voterId; i++) {
          vs1[i].storeVoter();
        }
      }
    }
    if (ch == 2) {
      GetCandidateId();
      if (candidateId != 0) {
        Candidate cs1[candidateId];
        for (int i = 0; i < candidateId; i++) {
          cs1[i].getCandidate(i);
          cs1[i].setCandidateVotes(0);
          cs1[i].setSeats(0);
        }
        remove("candidates.txt");
        for (int i = 0; i < candidateId; i++) {
          cs1[i].storeCandidate();
        }
      }
    }

    std::cout << "\n\n   Record has been reset. Press any Key to Go Back";
    std::cin.ignore();
    std::cin.get();
  } else
    return;
}

void CreateAccount() {
  int ch, Id;
  do {
    ch = choiceAdmin(5);
    switch (ch) {
    case 1:
      Id = insertNewVoter();
      if (Id) {
        viewVoterInfo(Id);
      }
      break;
    case 2:
      Id = insertNewCandidate();
      if (Id) {
        viewCandidateInfo(Id);
      }
      break;
    case 3:
      Id = insertNewParty();
      if (Id) {
        viewPartyInfo(Id);
      }
      break;
    case 0:
      break;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  } while (ch);
}

void AlterState() {
  int ch;
  do {
    ch = choiceAdmin(3);
    switch (ch) {
    case 0:
      break;
    case 1:
      insertNewState();
      break;
    case 2:
      viewStateRecord();
      break;
    case 3:
      deleteState();
      break;
    case 4:
      updateState();
      break;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  } while (ch);
}

void AlterCity() {
  int ch;
  do {
    ch = choiceAdmin(4);
    switch (ch) {
    case 0:
      break;
    case 1:
      insertNewCity();
      break;
    case 2:
      viewCityRecord();
      break;
    case 3:
      deleteCity();
      break;
    case 4:
      updateCity();
      break;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  } while (ch);
}

void MaintainRecords() {
  int ch;
  do {
    ch = choiceAdmin(1);
    switch (ch) {
    case 1:
      viewVoterRecord();
      break;
    case 2:
      viewCandidateRecord();
      break;
    case 3:
      viewPartyRecord();
      break;
    case 4:
      ResetVotes();
      break;

    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  } while (ch);
}

int main() {
  funFrontPage();
  int ch, Id = 0;
  do {
    ch = choiceAdmin(0);
    switch (ch) {
    case 1:
      Id = VoterLogin();
      if (Id) {
        viewVoterInfo(Id);
      }
      break;
    case 2:
      Id = CandidateLogin();
      if (Id) {
        viewCandidateInfo(Id);
      }
      break;
    case 3:
      Id = partyLogin();
      if (Id) {
        viewPartyInfo(Id);
      }
      break;
    case 4:
      CreateAccount();
      break;
    case 5:
      // showResults();
      {
        State st;
        int id;
        std::cout << "Enter the id of the state: ";
        std::cin >> id;
        st.getStates(id - 1);
        getStateResult(st);
      }
      break;
    case 6: {
      int ch;
      do {
        ch = choiceAdmin(2);
        switch (ch) {
        case 0:
          break;
        case 1:
          AlterState();
          break;
        case 2:
          AlterCity();
          break;
        case 3:
          MaintainRecords();
          break;
        case 4:
          // setResultRecord();
          break;
        default:
          std::cout << "\n   Enter the Correct Choice!";
          break;
        }
      } while (ch != 0);
    } break;
    case 7:
      break;
    default:
      std::cout << "\n   Enter the Correct Choice!";
      break;
    }
  } while (ch != 7);

  return 0;
}
