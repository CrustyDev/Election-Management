#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int stateCount = 0;
int cityCount = 0;
int stateIdNo = 0;
int cityIdNo = 0;
int partyId = 0;
int candidateId = 0;
int voterId = 0;
int resultId = 0;
int a[100005], seg[4 * 100005];

void GetStateCount()
{
	ifstream finStateCount;
	finStateCount.open("stateCount.txt");
	if (!finStateCount)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finStateCount >> stateCount;
	finStateCount.close();
}

void GetCityCount()
{
	ifstream finCityCount;
	finCityCount.open("cityCount.txt");
	if (!finCityCount)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finCityCount >> cityCount;
	finCityCount.close();
}

void GetStateIdNo()
{
	ifstream finStateIdNo;
	finStateIdNo.open("stateIdNo.txt");
	if (!finStateIdNo)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finStateIdNo >> stateIdNo;
	finStateIdNo.close();
}

void GetCityIdNo()
{
	ifstream finCityIdNo;
	finCityIdNo.open("cityIdNo.txt");
	if (!finCityIdNo)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finCityIdNo >> cityIdNo;
	finCityIdNo.close();
}

void GetPartyIdNo()
{
	ifstream finPartyIdNo;
	finPartyIdNo.open("partyIdNo.txt");
	if (!finPartyIdNo)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finPartyIdNo >> partyId;
	finPartyIdNo.close();
}

void GetCandidateId()
{
	ifstream finCandidateId;
	finCandidateId.open("candidateId.txt");
	if (!finCandidateId)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finCandidateId >> candidateId;
	finCandidateId.close();
}

void GetVoterId()
{
	ifstream finVoterId;
	finVoterId.open("voterId.txt");
	if (!finVoterId)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finVoterId >> voterId;
	finVoterId.close();
}

void GetResultId()
{
	ifstream finResultId;
	finResultId.open("resultId.txt");
	if (!finResultId)
	{
		std::cout << "\n   File not Exists\n";
		return;
	}
	finResultId >> resultId;
	finResultId.close();
}

void SetStateCount()
{
	ofstream foutStateCount;
	foutStateCount.open("stateCount.txt");
	foutStateCount << stateCount;
	foutStateCount.close();
}

void SetCityCount()
{
	ofstream foutCityCount;
	foutCityCount.open("cityCount.txt");
	foutCityCount << cityCount;
	foutCityCount.close();
}

void SetStateIdNo()
{
	ofstream foutStateIdNo;
	foutStateIdNo.open("stateIdNo.txt");
	foutStateIdNo << stateIdNo;
	foutStateIdNo.close();
}

void SetCityIdNo()
{
	ofstream foutCityIdNo;
	foutCityIdNo.open("cityIdNo.txt");
	foutCityIdNo << cityIdNo;
	foutCityIdNo.close();
}

void SetPartyIdNo()
{
	ofstream foutPartyIdNo;
	foutPartyIdNo.open("partyIdNo.txt");
	foutPartyIdNo << partyId;
	foutPartyIdNo.close();
}

void setCandidateId()
{
	ofstream foutCandidateId;
	foutCandidateId.open("candidateId.txt");
	foutCandidateId << candidateId;
	foutCandidateId.close();
}

void setVoterId()
{
	ofstream foutVoterId;
	foutVoterId.open("voterId.txt");
	foutVoterId << voterId;
	foutVoterId.close();
}

void setResultId()
{
	ofstream foutResultId;
	foutResultId.open("resultId.txt");
	foutResultId << resultId;
	foutResultId.close();
}

void funFrontPage()
{
#if defined _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void funHeading(std::string Heading)
{
	funFrontPage();

	std::cout << "   " << Heading << "\n";
}

int countDigits(int a)
{
	int i = 0;
	while (a > 0)
	{
		i++;
		a /= 10;
	}
	return i;
}

int choiceAdmin(int a)
{
	int x;
	if (a == 0)
	{
		funHeading("Options : ");
		std::cout << "\n   1. Voter Login" << std::endl;
		std::cout << "   2. Candidate Login" << std::endl;
		std::cout << "   3. Party Login" << std::endl;
		std::cout << "   4. Create Account/Party" << std::endl;
		std::cout << "   5. View Result(s)" << std::endl;
		std::cout << "   6. Admin Side" << std::endl;
		std::cout << "   7. Exit" << std::endl;
	}
	else if (a == 1)
	{
		funHeading("Maintain Record : ");
		std::cout << "\n   0. GoBack" << std::endl;
		std::cout << "\n   1. View Voter Record" << std::endl;
		std::cout << "   2. View Candidate Record" << std::endl;
		std::cout << "   3. View Party Record" << std::endl;
		std::cout << "   4. Reset All Votes and Seats" << std::endl;
	}
	else if (a == 2)
	{
		funHeading("Admin Side Features : ");
		std::cout << "\n   0. GoBack" << std::endl;
		std::cout << "\n   1. Alter State Record" << std::endl;
		std::cout << "   2. Alter District Record" << std::endl;
		std::cout << "   3. Maintain Data" << std::endl;
		std::cout << "   4. Set Result Record" << std::endl;
	}
	else if (a == 3)
	{
		funHeading("Altering State Record : ");
		std::cout << "\n   0.GoBack" << std::endl;
		std::cout << "\n   1.Add State Record" << std::endl;
		std::cout << "   2.Show State Record" << std::endl;
		std::cout << "   3.Delete State Record" << std::endl;
		std::cout << "   4.Update State Record" << std::endl;
	}
	else if (a == 4)
	{
		funHeading("Altering City Record : ");
		std::cout << "\n   0.GoBack" << std::endl;
		std::cout << "\n   1.Add City Record" << std::endl;
		std::cout << "   2.Show City Record" << std::endl;
		std::cout << "   3.Delete City Record" << std::endl;
		std::cout << "   4.Update City Record" << std::endl;
	}
	else if (a == 5)
	{
		funHeading("Creating an Account : ");
		std::cout << "\n   0.GoBack" << std::endl;
		std::cout << "\n   1.Voter Account" << std::endl;
		std::cout << "   2.Candidate Account" << std::endl;
		std::cout << "   3.Create A Party" << std::endl;
	}
	else if (a == 6)
	{
		// funHeading("Options : ");
		std::cout << "\n\n   Options : - ";
		std::cout << "\n\n   0.LogOut" << std::endl;
		std::cout << "   1.View Members List" << std::endl;
		std::cout << "   2.Update Data" << std::endl;
	}
	else if (a == 7)
	{
		// funHeading("Options : ");
		std::cout << "\n\n   Options : - ";
		std::cout << "\n\n   0.LogOut" << std::endl;
		std::cout << "   1.View Other Members List" << std::endl;
		std::cout << "   2.Update Data" << std::endl;
	}
	else if (a == 8)
	{
		// funHeading("Options : ");
		std::cout << "\n\n   Options : - ";
		std::cout << "\n\n   0.LogOut" << std::endl;
		std::cout << "   1.Do Vote" << std::endl;
		std::cout << "   2.Update Data" << std::endl;
	}
	else if (a == 9)
	{
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

class State
{
private:
	int stateId, seats;
	char stateName[25];

public:
	State()
	{
		stateId = 0;
		seats = 0;
		strcpy(stateName, "NoName");
	}

	State(const char *sName)
	{
		stateCount++;
		stateId = stateCount;
		seats = 0;
		strcpy(stateName, sName);
	}

	void getStateInfo()
	{
		std::cout << "Enter the Name : ";
		std::cin.getline(stateName, 24);
		GetStateIdNo();
		stateId = ++stateIdNo;
		SetStateIdNo();
		stateCount++;
		seats = 0;
	}

	void showStateInfo()
	{
		std::cout << stateName << std::endl;
	}

	int getSeats() { return seats; }
	void setSeats(int x) { seats = x; }

	int getstateId() { return stateId; }
	void setstateId(int id) { stateId = id; }

	std::string getstateName() const { return stateName; }
	void setstateName(const char *sName) { strcpy(stateName, sName); }

	void storeState();
	void getStates(int x);
};

void State::getStates(int x)
{
	int i = 0;
	ifstream finStateRecord;
	finStateRecord.open("States.bin", ios::in | ios::binary);
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
	ofstream foutState;
	foutState.open("States.bin", ios::app | ios::binary);
	foutState.write((char *)this, sizeof(*this));
	foutState.close();
}

void funStateInput(State *bs1, int x)
{
	int y = x + stateCount;
	for (int i = stateCount, k = 0; i < y; i++, k++)
	{
		State obj;
		if (x > 1)
		{
			std::cout << "\n   Enter State " << k + 1 << "\n";
		}
		else
		{
			std::cout << "\n";
		}
		std::cout << "   ";
		obj.getStateInfo();
		std::string objName = obj.getstateName();
		for (int j = stateCount; j > 0; j--)
		{
			std::string cmpName = bs1[j - 1].getstateName();
			int k = cmpName.compare(objName);
			if (!k)
			{
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

void insertNewState()
{
	int x;
	GetStateCount();
	std::cout << "\n   Enter the No. of State's you want to Insert: ";
	std::cin >> x;
	std::cin.ignore();
	if (x == 0)
	{
		return;
	}
	State *bs1 = new State[stateCount + x];
	funHeading("Inserting State's Record: ");
	std::cout << std::endl
			  << "   S.No.  StateName\n\n";
	for (int i = 0; i < stateCount; i++)
	{
		bs1[i].getStates(i);
		std::cout << "   " << i + 1 << ".";
		int j = countDigits(i + 1);
		for (int k = j; k < 8; k++)
			std::cout << " ";
		bs1[i].showStateInfo();
	}
	funStateInput(bs1, x);
	SetStateCount();
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Update The Record";
	std::cin.ignore();
	std::cin.get();
	delete[] bs1;
}

int inputDeleteChoices()
{
	int x;
	std::cout << "   1.Delete Via SerialNumber(*Convenient)" << std::endl;
	std::cout << "   2.Delete Via StateName" << std::endl;
	std::cout << "   3.Go Back" << std::endl;
	std::cout << "\n   Enter your Choice : ";
	std::cin >> x;
	return x;
}

void deleteState()
{
	GetStateCount();
	if (stateCount == 0)
	{
		std::cout << "\n   No Record Exists";
		return;
	}
	State bs1[stateCount];
	for (int i = 0; i < stateCount; i++)
	{
		bs1[i].getStates(i);
	}
	while (true)
	{
		funHeading("Deleting A State Record : ");
		std::cout << std::endl
				  << "   S.No.  StateName\n\n";
		for (int i = 0; i < stateCount; i++)
		{
			std::cout << "   " << i + 1 << ".";
			int j = countDigits(i + 1);
			for (int k = j; k < 8; k++)
				std::cout << " ";
			bs1[i].showStateInfo();
		}
		std::cout << "\n\n";
		int ch = inputDeleteChoices();
		if (ch == 1)
		{
			int sr;
			std::cout << "\n   Enter the S.No. : ";
			std::cin >> sr;
			if (sr <= 0 || sr > stateCount)
			{
				std::cout << "\n   Invalid No!";
				continue;
			}
			std::cin.ignore();
			char cnfm;
			std::cout << "\n   Are you Sure to Delete Record " << bs1[sr - 1].getstateName() << " (y/n) : ";
			// cnfm = std::cout<<cnfm;
			std::cin >> cnfm;
			if (cnfm == 'y' || cnfm == 'Y')
			{
				for (int i = sr - 1; i < stateCount; i++)
				{
					bs1[i] = bs1[i + 1];
				}
				stateCount--;
				std::cout << "\n\n   Record Deleted\n\n   Press any Key to Update Record";
				std::cin.ignore();
				std::cin.get();
			}
		}
		if (ch == 2)
		{
			int sr;
			char sName[25];
			std::cout << "\n   Enter the StateName : ";
			std::cin.ignore();
			std::cin.getline(sName, 19);
			bool f = false;
			for (int i = 0; i < stateCount; i++)
			{
				std::string stName = bs1[i].getstateName();
				int match = stName.compare(sName);
				if (!match)
				{
					f = true;
					sr = i + 1;
					break;
				}
			}
			if (f != 1)
			{
				std::cout << "\n\n   Record Does not exist\n\n   Press any Key";
				std::cin.ignore();
				std::cin.get();
				continue;
			}
			char cnfm;
			std::cout << "\n   Are you Sure to Delete Record " << bs1[sr - 1].getstateName() << " (y/n) : ";
			std::cin >> cnfm; // cnfm = std::cout<<cnfm;
			if (cnfm == 'y' || cnfm == 'Y')
			{
				for (int i = sr - 1; i < stateCount; i++)
				{
					bs1[i] = bs1[i + 1];
				}
				stateCount--;
				std::cout << "\n\n   Record Deleted\n\n   Press any Key to Update Record";
				std::cin.ignore();
				std::cin.get();
			}
		}
		if (ch == 3)
		{
			SetStateCount();
			remove("States.bin");
			for (int i = 0; i < stateCount; i++)
			{
				bs1[i].storeState();
			}
			return;
		}
		std::cout << "\n   Enter the Correct Choice!";
	}
}

int inputUpdateChoices()
{
	int x;
	std::cout << "   1.Update Via SerialNumber(*Convenient)" << std::endl;
	std::cout << "   2.Update Via StationName" << std::endl;
	std::cout << "   3.Go Back" << std::endl;
	std::cout << "\n   Enter your Choice : ";
	std::cin >> x;
	return x;
}

void updateState()
{
	GetStateCount();
	if (stateCount == 0)
	{
		std::cout << "\n   No Record Exists";
		return;
	}
	State bs1[stateCount];
	for (int i = 0; i < stateCount; i++)
	{
		bs1[i].getStates(i);
	}
	while (true)
	{
		funHeading("Updating A State Record : ");
		std::cout << std::endl
				  << "   S.No.  StateName\n\n";
		for (int i = 0; i < stateCount; i++)
		{
			std::cout << "   " << i + 1 << ".";
			int j = countDigits(i + 1);
			for (int k = j; k < 8; k++)
				std::cout << " ";
			bs1[i].showStateInfo();
		}
		std::cout << "\n\n";
		char newName[25];
		int ch = inputUpdateChoices();
		if (ch == 1)
		{
			int sr;
			std::cout << "\n   Enter the S.No. : ";
			std::cin >> sr;
			if (sr <= 0 || sr > stateCount)
			{
				std::cout << "\n   Invalid No!";
				continue;
			}
			std::cin.ignore();
			std::cout << "\n   Enter New StateName forState (" << bs1[sr - 1].getstateName() << ") : ";
			std::cin.getline(newName, 24);
			char cnfm;
			std::cout << "\n   Are you Sure to Update the Record to " << newName << " (y/n) : ";
			std::cin >> cnfm;
			// cnfm =
			// std::cout<<cnfm;
			if (cnfm == 'y' || cnfm == 'Y')
			{
				for (int i = sr - 1; i < stateCount; i++)
				{
					bs1[i] = bs1[i + 1];
				}
				stateCount--;
				State obj(newName);
				int j;
				for (j = stateCount - 1; j > 0; j--)
				{
					std::string cmpName = bs1[j - 1].getstateName();
					int k = cmpName.compare(newName);
					if (k < 0)
					{
						bs1[j] = bs1[j - 1];
					}
					else
					{
						break;
					}
				}
				bs1[j] = obj;
				std::cout << "\n\n   Record Updated\n\n   Press any Key to Update Record";
				std::cin.ignore();
				std::cin.get();
			}
		}
		if (ch == 2)
		{
			int sr;
			char sName[25];
			std::cout << "\n   Enter the StateName : ";
			std::cin.ignore();
			std::cin.getline(sName, 24);
			bool f = false;
			for (int i = 0; i < stateCount; i++)
			{
				std::string stName = bs1[i].getstateName();
				int match = stName.compare(sName);
				if (!match)
				{
					f = true;
					sr = i + 1;
					break;
				}
			}
			if (f != 1)
			{
				std::cout << "\n\n   No Record Found\n\n   Press any Key";
				std::cin.ignore();
				std::cin.get();
				continue;
			}
			std::cout << "\n   Enter New StateName forState (" << bs1[sr - 1].getstateName() << ") : ";
			std::cin.getline(newName, 24);
			char cnfm;
			std::cout << "\n   Are you Sure to Update the Record to " << newName << " (y/n) : ";
			// cnfm = std::cout<<cnfm;
			std::cin >> cnfm;
			if (cnfm == 'y' || cnfm == 'Y')
			{
				for (int i = sr - 1; i < stateCount; i++)
				{
					bs1[i] = bs1[i + 1];
				}
				stateCount--;
				State obj(newName);
				int j;
				for (j = stateCount - 1; j > 0; j--)
				{
					std::string cmpName = bs1[j - 1].getstateName();
					int k = cmpName.compare(newName);
					if (k < 0)
					{
						bs1[j] = bs1[j - 1];
					}
					else
					{
						break;
					}
				}
				bs1[j] = obj;
				std::cout << "\n\n   Record Updated\n\n   Press any Key to Update Record";
				std::cin.ignore();
				std::cin.get();
			}
		}
		if (ch == 3)
		{
			SetStateCount();
			remove("States.bin");
			for (int i = 0; i < stateCount; i++)
			{
				bs1[i].storeState();
			}
			return;
		}
		std::cout << "\n   Enter the Correct Choice!";
	}
}

void viewStateRecord()
{
	GetStateCount();
	if (stateCount == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	std::cout << std::endl
			  << "   S.No.  StateName    Seats\n\n";
	for (int i = 0; i < stateCount; i++)
	{
		State obj;
		obj.getStates(i);
		std::cout << "   " << i + 1 << ".";
		int j = countDigits(i + 1);
		std::cout << std::string(8 - j, ' ');
		std::cout << obj.getstateName();
		std::cout << std::string(14 - obj.getstateName().length(), ' ');
		std::cout << obj.getSeats() << std::endl;
	}
	std::cin.ignore();
	std::cin.get();
}

class City : public State
{
private:
	int cityId, LeadcandidateId;
	char cityName[25];

public:
	City()
	{
		setstateId(0);
		setSeats(0);
		LeadcandidateId = 0;
		setstateName("NoName");
		strcpy(cityName, "NoName");
		cityId = 0;
	}

	int getCityInfo(int sId, const char *sName)
	{
		setstateId(sId);
		setstateName(sName);
		std::cout << "Enter the Name : ";
		std::cin.getline(cityName, 24);
		cityCount++;
		int s = 1;
		/*std::cout<<"   Enter the No. of Seats : ";
		std::cin>>s;std::cin.ignore();*/
		setSeats(s);
		GetCityIdNo();
		cityId = ++cityIdNo;
		SetCityIdNo();
		LeadcandidateId = 0;
		return s;
	}

	void showCityInfo()
	{
		std::cout << cityName << std::endl;
	}

	// int getSeats(){return seats;}
	// void setSeats(int x){seats = seats + x;}
	int getcityId() { return cityId; }
	std::string getcityName() const { return cityName; }
	int getLeadCandidateId() { return LeadcandidateId; }

	void setCityId(int n) { cityId = n; }
	void setcityName(const char *name) { strcpy(cityName, name); }
	void storeCity();
	int getCity(int x);
	void setLeadCandidateId(int n) { LeadcandidateId = n; }
};

int City::getCity(int x)
{
	int i = 0;
	ifstream finCityRecord;
	finCityRecord.open("Cities.txt", ios::in | ios::binary);
	if (!finCityRecord)
	{
		std::cout << "\n   File not Found";
	}
	else
	{
		while (!finCityRecord.eof() && i != x + 1)
		{
			finCityRecord.read((char *)this, sizeof(*this));
			i++;
		}
	}
}

void City::storeCity()
{
	ofstream foutCity;
	foutCity.open("Cities.txt", ios::app | ios::binary);
	foutCity.write((char *)this, sizeof(*this));
	foutCity.close();
}

int funCityInput(int stateId, const char *stateName, City *b, int x)
{
	int y = x + cityCount, stateSeats = 0;
	City obj;
	for (int i = cityCount, k = 0; i < y; i++, k++)
	{
		if (x > 1)
		{
			std::cout << "\n   Enter City " << k + 1 << "\n";
		}
		else
		{
			std::cout << "\n";
		}
		std::cout << "   ";
		stateSeats = stateSeats + obj.getCityInfo(stateId, stateName);

		std::string objState = obj.getstateName();
		int j;
		for (j = cityCount - 1; j > 0; j--)
		{
			std::string cmpState = b[j - 1].getstateName();
			int k = cmpState.compare(objState);
			if (k < 0)
			{
				b[j] = b[j - 1];
			}
			else if (!k)
			{
				std::string objCity = obj.getcityName();
				std::string cmpCity = b[j - 1].getcityName();
				int k = cmpCity.compare(objCity);
				if (k < 0)
				{
					b[j] = b[j - 1];
				}
				else
				{
					goto in;
				}
			}
			else
			{
				break;
			}
		}
	in:;
		b[j] = obj;
	}
	return stateSeats;
}

void insertNewCity()
{
	int x;
	GetCityCount();
	GetStateCount();
	State bs1[stateCount];
	funHeading("Inserting City's Record: ");
	std::cout << std::endl
			  << "   S.No.  StateName\n\n";
	for (int i = 0; i < stateCount; i++)
	{
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
	if (x == 0)
	{
		return;
	}

	City c[cityCount + x];
	// funHeading("Inserting State's Record: ");
	std::cout << std::endl
			  << "\n\n   S.No.  CityName    Seats\n\n";
	char *cName;
	for (int i = 0; i < cityCount; i++)
	{
		c[i].getCity(i);
		std::cout << "   " << i + 1 << ".";
		int j = countDigits(i + 1);
		for (int k = j; k < 8; k++)
			std::cout << " ";
		std::cout << c[i].getcityName();
		std::cout << std::string(14 - c[i].getcityName().length(), ' ');
		std::cout << c[i].getSeats() << std::endl;
		// std::cout<<"   "<<c[i].getstateId()<<"  "<<c[i].getstateName()<<std::endl;
	}
	int seatsCount = funCityInput(bs1[st - 1].getstateId(), bs1[st - 1].getstateName().c_str(), c, x);
	seatsCount = seatsCount + bs1[st - 1].getSeats();
	bs1[st - 1].setSeats(seatsCount);
	SetCityCount();
	remove("States.bin");
	for (int i = 0; i < stateCount; i++)
	{
		bs1[i].storeState();
	}
	remove("Cities.txt");
	for (int i = 0; i < cityCount; i++)
	{
		c[i].storeCity();
	}
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Update The Record";
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
void deleteCity()
{
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
	   std::cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";
	   //cnfm = std::cout<<cnfm;
	   std::cin>>cnfm;
	   if(cnfm == 'y'||cnfm == 'Y'){
		  for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
		  stateCount--;
		  std::cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";
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
	   if(f!=1){std::cout<<"\n\n   Record Already Not Exists\n\n   Press any Key";goto redo;}
	   char cnfm;
	   std::cout<<"\n   Are you Sure to Delete Record "<<bs1[sr-1].getstateName()<<" (y/n) : ";std::cin>>cnfm;//cnfm = std::cout<<cnfm;
	   if(cnfm == 'y'||cnfm == 'Y'){
		  for(int i=sr-1;i<stateCount;i++){bs1[i]=bs1[i+1];}
		  stateCount--;
		  std::cout<<"\n\n   Record Deleted\n\n   Press any Key to Update Record";
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
void updateCity()
{
	funHeading("Updating A State Record : ");
	std::cout << "   Available Soon";
}

void viewCityRecord()
{
	GetCityCount();
	if (cityCount == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	City bs1[cityCount];
	std::cout << std::endl
			  << "   S.No.  StateName    CityName    Seats\n\n";
	char *sName;
	for (int i = 0; i < cityCount; i++)
	{
		bs1[i].getCity(i);
		std::cout << "   " << i + 1 << ".";
		int j = countDigits(i + 1);
		for (int k = j; k < 8; k++)
			std::cout << " ";
		std::cout << bs1[i].getstateName();
		std::cout << std::string(12 - bs1[i].getstateName().length(), ' ');
		std::cout << bs1[i].getcityName() << std::string(14 - bs1[i].getcityName().length(), ' ');
		std::cout << bs1[i].getSeats() << std::endl;

		// std::cout<<"   "<<bs1[i].getLeadCandidateId()<<std::endl;
	}
}

/*void setCityLeadCandidate(){
   getCityCount();
   City bs1[cityCount];
   for(int i=0;i<cityCount;i++){
	  bs1[i].getCity(i);
	  bs1[i].setLeadCandidateId(0);
   }


   remove("Cities.txt");
   for(int i=0;i<cityCount;i++){bs1[i].storeCity();}
   std::cout<<"\n\n   Record Inserted\n\n   Press any Key To Update The Record";

}*/
class Party
{
private:
	int PartyID, votes, Members, seats;
	char partyName[50], headName[25], password[10];

public:
	Party()
	{
		PartyID = 0;
		votes = 0;
		Members = 0;
		seats = 0;
		strcpy(partyName, "NoName");
		strcpy(headName, "NoName");
		setPassword("1234");
	}

	void getPartyInfo()
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
				std::cout << "Press Any key to retry." << std::endl;
			}
		} while (password.length() > 10);
		setPassword(password.c_str());
		// std::cout<<"\n\nPassword : "<<arr;
	}

	std::string getPartyName() const { return partyName; }
	std::string getHeadName() const { return headName; }

	int getPartyId() { return PartyID; }
	int getVotes() { return votes; }
	int getMembers() { return Members; }
	int getSeats() { return seats; }
	std::string getPassword() const { return password; }

	void setPartyName(const char *newName) { strcpy(partyName, newName); }
	void setHeadName(const char *newName) { strcpy(headName, newName); }
	void setVotes(int n) { votes = n; }
	void setPartyId(int n) { PartyID = n; }
	void setMembers(int n) { Members = n; }
	void setSeats(int n) { seats = n; }
	void setPassword(const char *password) { strcpy(this->password, password); }

	void storeParty();
	int getParty(int x);
};

class Candidate : public Party, public City
{
private:
	int candidateID, seats;
	char candidateName[25], candidatePost[30], gender;

public:
	Candidate()
	{
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

	void getCandidateInfo()
	{
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

	redo1:;
		funHeading("Creating Candidate Account : ");
		std::cout << "\n\n   Your Id : " << candidateID;
		std::cout << "\n\n   Enter Your Name            :  " << candidateName;
		std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
		std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender << "\n\n";
		GetStateCount();
		State bs1[stateCount];
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
		int sr;
		std::cout << "\n   Choose Your State (S.No) : ";
		std::cin >> sr;
		if (sr <= 0 || sr > stateCount)
		{
			std::cout << "\n   Invalid Choice!";
			goto redo1;
		}
		setstateId(bs1[sr - 1].getstateId());
		setstateName(bs1[sr - 1].getstateName().c_str());

	redo2:;
		funHeading("Creating Candidate Account : ");
		std::cout << "\n\n   Your Id : " << candidateID;
		std::cout << "\n\n   Enter Your Name            :  " << candidateName;
		std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
		std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
		std::cout << "\n\n   Select Your State          :  " << getstateName() << "\n\n";
		GetCityCount();
		City cs1[cityCount];
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
			goto redo2;
		}
		setCityId(cs1[sr - 1].getcityId());
		setcityName(cs1[sr - 1].getcityName().c_str());

	redo3:;
		funHeading("Creating Candidate Account : ");
		std::cout << "\n\n   Your Id : " << candidateID;
		std::cout << "\n\n   Enter Your Name            :  " << candidateName;
		std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
		std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
		std::cout << "\n\n   Select Your State          :  " << getstateName();
		std::cout << "\n\n   Select Your City          :  " << getcityName() << "\n\n";
		GetPartyIdNo();
		Party ps1[partyId];
		std::cout << std::endl
				  << "   S.No.  Party\n\n";
		for (int i = 0; i < partyId; i++)
		{
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
		{
			std::cout << "\n   Invalid Choice!";
			goto redo3;
		}
		setPartyId(ps1[sr - 1].getPartyId());
		setPartyName(ps1[sr - 1].getPartyName().c_str());
		setHeadName(ps1[sr - 1].getHeadName().c_str());
		int m = ps1[sr - 1].getMembers();
		ps1[sr - 1].setMembers(m + 1);
		SetPartyIdNo();
		remove("Party.txt");
		for (int i = 0; i < partyId; i++)
		{
			ps1[i].storeParty();
		}

		funHeading("Creating Candidate Account : ");
		std::cout << "\n\n   Your Id : " << candidateID;
		std::cout << "\n\n   Enter Your Name            :  " << candidateName;
		std::cout << "\n\n   Enter Your Designation     :  " << candidatePost;
		std::cout << "\n\n   Enter Your Gender(M/F)     :  " << gender;
		std::cout << "\n\n   Select Your State          :  " << getstateName();
		std::cout << "\n\n   Select Your City           :  " << getcityName();
		std::cout << "\n\n   Choose Your Party          :  " << getPartyName() << "\n\n";

		setMembers(1);
		setVotes(0);
		seats = 0;
		setLeadCandidateId(0);

		std::cout << "\n   Enter Your Password: ";
		std::string password;
		do
		{
			// std::cin.ignore();
			std::getline(std::cin >> std::ws, password);
			if (password.length() > 10)
			{
				std::cout << "Password length cannot be more than 10." << std::endl;
				std::cout << "Press Any key to retry." << std::endl;
			}
		} while (password.length() > 10);
		setPassword(password.c_str());

		// std::cout<<"\n\nPassword : "<<arr;
	}

	char *getCandidateDesignation() { return candidatePost; }
	std::string getCandidateName() const { return candidateName; }
	int getCandidateID() { return candidateID; }
	int getSeats() { return seats; }
	int getCandidateVotes() { return getVotes(); }

	void setCandidateVotes(int n) { setVotes(n); }
	void setCandidateName(const char *newName) { strcpy(candidateName, newName); }
	void setCandidatePost(const char *newPost) { strcpy(candidatePost, newPost); }
	void setSeats(int n) { seats = n; }

	void storeCandidate();
	int getCandidate(int x);
};

int Party::getParty(int x)
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

int funPartyInput(Party *bs1, int x)
{
	Party obj;
	std::cout << "   ";
	obj.getPartyInfo();
	bs1[partyId - 1] = obj;

	return obj.getPartyId();
}

int insertNewParty()
{
	int Id = 0;
	GetPartyIdNo();
	funHeading("Inserting Party Record: \n");
	Party obj;
	obj.getPartyInfo();
	Id = obj.getPartyId();
	SetPartyIdNo();
	obj.storeParty();
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
	std::cin.get();

	return Id;
}

int partyLogin()
{
	GetPartyIdNo();
	if (partyId == 0)
	{
		std::cout << "\n   No Record Found";
		return 0;
	}
	Party bs1[partyId];
	funHeading("Party Login Page: ");
	std::cout << std::endl
			  << "   S.No.   PartyName\n\n";
	for (int i = 0; i < partyId; i++)
	{
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
	do
	{
		// std::cin.ignore();
		std::getline(std::cin >> std::ws, password);
		if (password.length() > 10)
		{
			std::cout << "Password length cannot be more than 10." << std::endl;
			std::cout << "Press Any key to retry." << std::endl;
		}
	} while (password.length() > 10);

	int match = password.compare(cmpPaswrd);
	if (!match)
	{
		return bs1[x - 1].getPartyId();
	}
	std::cout << "\n   Wrong Password!";

	return 0;
}

int inputPartyUpdateChoice()
{
	int x;
	std::cout << "   1.Change HeadName" << std::endl;
	std::cout << "   2.Change Password" << std::endl;
	std::cout << "   3.Go Back" << std::endl;
	std::cout << "\n   Enter your Choice : ";
	std::cin >> x;
	return x;
}

int confirm()
{
	char x;
	std::cout << "\n   Are You Sure (y/n) : ";
	std::cin >> x;
	// x = std::cout<<x;
	if (x == 'y' || x == 'Y')
		return 1;
	return 0;
}

void displayCandidateInfo(Candidate obj)
{
	int c = 0;
	c = countDigits(obj.getCandidateID());
	std::cout << "   " << obj.getCandidateID();
	for (int i = c; i < 7; i++)
		std::cout << " ";
	std::cout << obj.getCandidateName();
	std::cout << std::string(25 - obj.getCandidateName().length(), ' ');
	std::cout << obj.getstateName() << std::string(20 - obj.getstateName().length(), ' ');
	std::cout << obj.getcityName() << std::string(20 - obj.getcityName().length(), ' ');
	c = countDigits(obj.getVotes());
	std::cout << obj.getVotes();
}

void viewPartyInfo(int Id)
{
	GetPartyIdNo();
	if (partyId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Party bs1[partyId], obj;
	GetCandidateId();
	Candidate cs1[candidateId];

	int sIndex = Id - 1;
	for (int i = 0; i < partyId; i++)
	{
		bs1[i].getParty(i);
	}

	obj = bs1[sIndex];
	obj.setSeats(0);
	obj.setVotes(0);
	for (int i = 0; i < candidateId; i++)
	{
		cs1[i].getCandidate(i);
		if (cs1[i].getPartyId() == obj.getPartyId())
		{
			int pseats = obj.getSeats();
			pseats = pseats + cs1[i].getSeats();
			obj.setSeats(pseats);
			int pVotes = obj.getVotes();
			pVotes = pVotes + cs1[i].getCandidateVotes();
			obj.setVotes(pVotes);
		}
	}
	while (true)
	{
		funHeading("");
		std::cout << "\n   PartyName : " << obj.getPartyName();
		std::cout << "\n   Head      : " << obj.getHeadName();
		std::cout << "\n   Members   : " << obj.getMembers();
		std::cout << "\n   Seats     : " << obj.getSeats();
		std::cout << "\n   Votes     : " << obj.getVotes();
		int ch = choiceAdmin(6);
		switch (ch)
		{
		case 1:
			funHeading("List Of Members : -");
			std::cout << "\n   PartyName : " << obj.getPartyName();
			std::cout << "       Head : " << obj.getHeadName();
			std::cout << "       Members : " << obj.getMembers();
			std::cout << "\n\n\n   ID         Name                  State               City            Votes\n";
			for (int i = 0; i < candidateId; i++)
			{
				// cs1[i].getCandidate(i);
				if (cs1[i].getPartyId() == obj.getPartyId())
				{
					displayCandidateInfo(cs1[i]);
					std::cout << "\n";
				}
			}
			break;
		case 2:
		{
			std::cout << "\n\n";
			int ch3 = inputPartyUpdateChoice();
			std::cin.ignore();
			if (ch3 == 1)
			{
				char newName[25];
				std::cout << "\n   Enter the New HeadName : ";
				std::cin.getline(newName, 24);
				int y = confirm();
				if (y == 1)
				{
					bs1[sIndex].setHeadName(newName);
					std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
					std::cin.ignore();
					std::cin.get();
				}
			}
			if (ch3 == 2)
			{
				char newPassword[10], cr;
				std::cout << "\n   Enter the New Password : ";
				for (int i = 0; i < 10; i++)
				{
					cr = getchar();
					if (cr != '\r')
					{
						newPassword[i] = cr;
						std::cout << "*";
					}
					else
					{
						newPassword[i] = '\0';
						break;
					}
				}
				int y = confirm();
				if (y == 1)
				{
					bs1[sIndex].setPassword(newPassword);
					std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
					std::cin.ignore();
					std::cin.get();
					break;
				}
			}
			if (ch3 == 3)
			{
				break;
			}
			std::cout << "Invalid Choice" << std::endl;
			break;
		}
		case 0:
			// bs1[sIndex].setMembers(3);
			SetPartyIdNo();
			remove("Party.txt");
			for (int i = 0; i < partyId; i++)
			{
				bs1[i].storeParty();
			}
			return;
		default:
			std::cout << "\n   Enter the Correct Choice!";
			break;
		}
	}
}

int Candidate::getCandidate(int x)
{
	int i = 0;
	ifstream finCandidateRecord;
	finCandidateRecord.open("candidates.txt", ios::in | ios::binary);
	if (!finCandidateRecord)
	{
		std::cout << "\n   File not Found";
	}
	else
	{
		while (!finCandidateRecord.eof() && i != x + 1)
		{
			finCandidateRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
			i++;
		}
	}
}

void Candidate::storeCandidate()
{
	ofstream foutCandidate;
	foutCandidate.open("candidates.txt", ios::app | ios::binary);
	foutCandidate.write(reinterpret_cast<char *>(this), sizeof(*this));
	foutCandidate.close();
}

int funCandidateInput(Candidate *bs1, int x)
{
	Candidate obj;
	std::cout << "   ";
	obj.getCandidateInfo();

	bs1[candidateId - 1] = obj;

	return obj.getCandidateID();
}

int insertNewCandidate()
{
	int x = 1, Id = 0;
	GetCandidateId();
	if (x == 0)
	{
		return Id;
	}
	Candidate bs1[candidateId + x];

	funHeading("Creating Candidate Account : \n");
	for (int i = 0; i < candidateId; i++)
	{
		bs1[i].getCandidate(i);
	}
	Id = funCandidateInput(bs1, x);
	setCandidateId();
	remove("candidates.txt");
	for (int i = 0; i < candidateId; i++)
	{
		bs1[i].storeCandidate();
	}
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
	std::cin.ignore();
	std::cin.get();

	return Id;
}

int CandidateLogin()
{
	GetCandidateId();
	if (candidateId == 0)
	{
		std::cout << "\n   No Record Found";
		return 0;
	}
	Candidate bs1[candidateId];
	for (int i = 0; i < candidateId; i++)
	{
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
	if (Id == bs1[index].getCandidateID())
	{
		f = true;
	}
	/*for(int i=0;i<candidateId;i++){
	   if(Id == bs1[i].getCandidateID()){
		  index = i;
		  f=1;
		  break;
	   }
	}*/
	if (f != 1)
	{
		std::cout << "\n   No Account exists with this Id!";
		goto redo;
	}

	char paswrd[10], cr;
	std::string cmpPaswrd = bs1[index].getPassword();
	std::cout << "\n   Enter Your Password: ";
	for (int i = 0; i < 10; i++)
	{
		cr = getchar();
		if (cr != '\r')
		{
			paswrd[i] = cr;
			std::cout << "*";
		}
		else
		{
			paswrd[i] = '\0';
			break;
		}
	}
	// std::cout<<"\n\nPassword : "<<paswrd;
	// std::cout<<"\n\nCmpPassword : "<<cmpPaswrd;
	int match = strcmp(paswrd, cmpPaswrd.c_str());
	if (!match)
	{
		return bs1[index].getCandidateID();
	}
	std::cout << "\n   Wrong Password!";
	return 0;
}

int inputCandidateUpdateChoice()
{
	int x;
	std::cout << "   1.Change Name" << std::endl;
	std::cout << "   2.Change Password" << std::endl;
	std::cout << "   3.Change Description" << std::endl;
	std::cout << "   4.Go Back" << std::endl;
	std::cout << "\n   Enter your Choice : ";
	std::cin >> x;
	return x;
}

void viewCandidateInfo(int Id)
{
	GetCandidateId();
	if (candidateId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Candidate bs1[candidateId], obj;
	int sIndex = Id - 1;
	for (int i = 0; i < candidateId; i++)
	{
		bs1[i].getCandidate(i);
		/*if(bs1[i].getCandidateID()==Id){
		sIndex = i;
		}*/
	}
	while (true)
	{
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
		switch (ch)
		{
		case 1:
		{
			funHeading("List Of Other Members : -");
			std::cout << "\n   PartyName : " << obj.getPartyName();
			std::cout << "       Head : " << obj.getHeadName();

			std::cout << "\n\n\n   ID         Name                  State               City            Votes\n";
			for (int i = 0; i < candidateId; i++)
			{
				if (bs1[i].getPartyId() == obj.getPartyId() && bs1[i].getCandidateID() != obj.getCandidateID())
				{
					displayCandidateInfo(bs1[i]);
					std::cout << "\n";
				}
			}
			break;
		}
		case 2:
		{
			std::cout << "\n\n";
			int ch3 = inputCandidateUpdateChoice();
			std::cin.ignore();
			if (ch3 == 1)
			{
				char newName[25];
				std::cout << "\n   Enter the New HeadName : ";
				std::cin.getline(newName, 24);
				int y = confirm();
				if (y == 1)
				{
					bs1[sIndex].setCandidateName(newName);
					std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
					std::cin.ignore();
					std::cin.get();
				}
			}
			else if (ch3 == 2)
			{
				char newPassword[10], cr;
				std::cout << "\n   Enter the New Password : ";
				for (int i = 0; i < 10; i++)
				{
					cr = getchar();
					if (cr != '\r')
					{
						newPassword[i] = cr;
						std::cout << "*";
					}
					else
					{
						newPassword[i] = '\0';
						break;
					}
				}
				std::cout << "\n";
				int y = confirm();
				if (y == 1)
				{
					bs1[sIndex].setPassword(newPassword);
					std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
					std::cin.ignore();
					std::cin.get();
				}
			}
			else if (ch3 == 3)
			{
				char newDescription[25];
				std::cout << "\n   Enter the New Description : ";
				std::cin.getline(newDescription, 24);
				int y = confirm();
				if (y == 1)
				{
					bs1[sIndex].setCandidatePost(newDescription);
					std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
					std::cin.ignore();
					std::cin.get();
				}
			}
			else if (ch3 == 4)
			{
				continue;
			}
			else
			{
				std::cout << "\n   Enter the Correct Choice!";
			}
			break;
		}
		case 0:
			/*setPartyCount();*/
			remove("candidates.txt");
			for (int i = 0; i < candidateId; i++)
			{
				bs1[i].storeCandidate();
			}
			return;
		default:
			std::cout << "\n   Enter the Correct Choice!";
		}
	}
}

class Voter : public City
{
private:
	int voterID, partyId, age;
	char voterName[25], partyName[50], gender, password[10];

public:
	Voter()
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

	void getVoterInfo()
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

	std::string getVoterPartyName() const { return partyName; }
	std::string getVoterName() const { return voterName; }
	int getVoterID() { return voterID; }
	int getVoterAge() { return age; }
	char getVoterGender() { return gender; }
	int getVoterPartyId() { return partyId; }
	std::string getPassword() { return password; }

	void setVoterName(const char *newName) { strcpy(voterName, newName); }
	void setPartyName(const char *newParty) { strcpy(partyName, newParty); }
	void setPartyId(int n) { partyId = n; }
	void setAge(int n) { age = n; }
	void setPassword(const char *password) { strcpy(this->password, password); }

	void storeVoter();
	int getVoter(int x);
};

int Voter::getVoter(int x)
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

int funVoterInput(Voter *b, int x)
{
	Voter obj;
	std::cout << "   ";
	obj.getVoterInfo();

	b[voterId - 1] = obj;

	return obj.getVoterID();
}

int insertNewVoter()
{
	int x = 1, Id = 0;
	GetVoterId();
	if (x == 0)
	{
		return Id;
	}
	Voter bs1[voterId + x];

	funHeading("Creating Voter Account : \n");
	for (int i = 0; i < voterId; i++)
	{
		bs1[i].getVoter(i);
	}
	Id = funVoterInput(bs1, x);
	setVoterId();
	remove("voter.txt");
	for (int i = 0; i < voterId; i++)
	{
		bs1[i].storeVoter();
	}
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
	std::cin.ignore();
	std::cin.get();

	return Id;
}

int VoterLogin()
{
	GetVoterId();
	if (voterId == 0)
	{
		std::cout << "\n   No Record Found";
		return 0;
	}
	Voter bs1[voterId];
	for (int i = 0; i < voterId; i++)
	{
		bs1[i].getVoter(i);
	}
redo:;
	funHeading("Voter Login Page: ");

	int Id;
	std::cout << "\n   Enter Your Id : ";
	std::cin >> Id;
	std::cin.ignore();
	bool f = false;
	int index = Id - 1;
	// std::cout<<bs1[index].getVoterID();
	if (Id == bs1[index].getVoterID())
	{
		f = true;
	}
	/*for(int i=0;i<voterId;i++){
	   if(Id == bs1[i].getVoterID()){
		  index = i;
		  f=1;
		  break;
	   }
	}*/
	if (f != 1)
	{
		std::cout << "\n   No Account exists with this Id!";
		goto redo;
	}

	char paswrd[10], cr;
	std::string cmpPaswrd = bs1[index].getPassword();
	std::cout << "\n   Enter Your Password: ";
	for (int i = 0; i < 10; i++)
	{
		cr = getchar();
		if (cr != '\r')
		{
			paswrd[i] = cr;
			std::cout << "*";
		}
		else
		{
			paswrd[i] = '\0';
			break;
		}
	}
	// std::cout<<"\n\nPassword : "<<paswrd;
	// std::cout<<"\n\nCmpPassword : "<<cmpPaswrd;
	int match = strcmp(paswrd, cmpPaswrd.c_str());
	if (!match)
	{
		return Id;
	}
	std::cout << "\n   Wrong Password!";
	return 0;
}

int inputVoterUpdateChoice()
{
	int x;
	std::cout << "   1.Change Name" << std::endl;
	std::cout << "   2.Change Age" << std::endl;
	std::cout << "   3.Change Password" << std::endl;
	std::cout << "   4.Go Back" << std::endl;
	std::cout << "\n   Enter your Choice : ";
	std::cin >> x;
	return x;
}

void displayCandidateForVote(Candidate obj)
{
	int c = 0;
	c = countDigits(obj.getCandidateID());
	std::cout << "   " << obj.getCandidateID();
	for (int i = c; i < 7; i++)
		std::cout << " ";
	std::cout << obj.getCandidateName() << std::string(25 - obj.getCandidateName().length(), ' ');
	/*c=strlen(obj.getstateName());
	std::cout<<obj.getstateName();
	for(int i=c;i<20;i++) std::cout<<" ";
	c=strlen(obj.getcityName());
	std::cout<<obj.getcityName();
	for(int i=c;i<20;i++) std::cout<<" ";*/
	std::cout << obj.getPartyName();
}

void voterMakeVote(Voter *vs1, int Id)
{
	GetCandidateId();
	Candidate cs1[candidateId];
	GetCityCount();
	City city1[cityCount];
	int cindex;
	int vCityId = vs1[Id - 1].getcityId();
	for (int i = 0; i < cityCount; i++)
	{
		city1[i].getCity(i);
		if (city1[i].getcityId() == vCityId)
		{
			cindex = i;
		}
	}
	funHeading("Making A Vote : \n");
	std::cout << "   State : " << vs1[Id - 1].getstateName() << "        City : " << vs1[Id - 1].getcityName();
	std::cout << "\n\n\n   ID      CandidateName                  Party\n";
	for (int i = 0; i < candidateId; i++)
	{
		cs1[i].getCandidate(i);
		if (cs1[i].getcityId() == vCityId)
		{
			displayCandidateForVote(cs1[i]);
			std::cout << "\n";
		}
	}
	int selectedId;
	std::cout << "\n\n   Select via Id whom you want to vote :  ";
	std::cin >> selectedId;
	char ays;
	std::cout << "\n   Are you sure to vote for " << cs1[selectedId - 1].getCandidateName() << " ( " << cs1[selectedId - 1].getPartyName() << " ) (y/n):";
	std::cin >> ays;
	if (ays == 'y' || ays == 'Y')
	{
		int vote = cs1[selectedId - 1].getCandidateVotes();
		cs1[selectedId - 1].setCandidateVotes(vote + 1);
		vs1[Id - 1].setPartyId(cs1[selectedId - 1].getCandidateID());
		vs1[Id - 1].setPartyName(cs1[selectedId - 1].getPartyName().c_str());
		int leadingCandidate = city1[cindex].getLeadCandidateId();
		if (leadingCandidate != 0)
		{
			int maxvotes = cs1[leadingCandidate - 1].getCandidateVotes();
			if (vote > maxvotes)
			{
				city1[cindex].setLeadCandidateId(selectedId);
			}
		}
		else
		{
			int maxvotes = 0;
			for (int i = 0; i < candidateId; i++)
			{
				if (cs1[i].getcityId() == vCityId)
				{
					if (cs1[i].getCandidateVotes() > maxvotes)
					{
						maxvotes = cs1[i].getCandidateVotes();
						city1[cindex].setLeadCandidateId(cs1[i].getCandidateID());
					}
				}
			}
		}
		for (int i = 0; i < candidateId; i++)
		{
			if (cs1[i].getcityId() == vCityId)
			{
				if (cs1[i].getCandidateID() == city1[cindex].getLeadCandidateId())
				{
					cs1[i].setSeats(1);
				}
				else
				{
					cs1[i].setSeats(0);
				}
			}
		}
		remove("Cities.txt");
		for (int i = 0; i < cityCount; i++)
		{
			city1[i].storeCity();
		}
		remove("candidates.txt");
		for (int i = 0; i < candidateId; i++)
		{
			cs1[i].storeCandidate();
		}

		std::cout << "\n   Voted Successfully\n\n   Press any Key To Update Data";
		std::cin.ignore();
		std::cin.get();
	}
	else
		return;
}

void viewVoterInfo(int Id)
{
	GetVoterId();
	if (voterId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Voter bs1[voterId], obj;
	int sIndex = Id - 1;
	for (int i = 0; i < voterId; i++)
	{
		bs1[i].getVoter(i);
		/*if(bs1[i].getVoterID()==Id){
		sIndex = i;
		}*/
	}
redo:;
	obj = bs1[sIndex];
	funHeading("Welcome : ");
	std::cout << "\n   Name   : " << obj.getVoterName();
	std::cout << "          VotedToParty : " << obj.getVoterPartyName();
	std::cout << "\n   Age    : " << obj.getVoterAge();
	std::cout << "\n   Gender : " << obj.getVoterGender();
	std::cout << "\n   State  : " << obj.getstateName();
	std::cout << "\n   City   : " << obj.getcityName();
choice:;
	int ch = choiceAdmin(8), able;
	switch (ch)
	{
	case 1:
		able = obj.getVoterPartyId();
		// std::cout<<able;
		if (able == 0)
		{
			voterMakeVote(bs1, Id);
		}
		else
		{
			std::cout << "\n   You have already voted.Now you can't change your vote";
			// voterMakeVote(bs1,Id);
		}
		goto redo;
	case 2:
		goto choice2;
	case 0:
		/*setPartyCount();*/
		remove("voter.txt");
		for (int i = 0; i < voterId; i++)
		{
			bs1[i].storeVoter();
		}
		return;
	default:
		std::cout << "\n   Enter the Correct Choice!";

		goto redo;
	}
choice2:;

	std::cout << "\n\n";
	int ch3 = inputVoterUpdateChoice();
	std::cin.ignore();
	if (ch3 == 1)
	{
		char newName[25];
		std::cout << "\n   Enter the New Name : ";
		std::cin.getline(newName, 24);
		int y = confirm();
		if (y == 1)
		{
			bs1[sIndex].setVoterName(newName);
			std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
			std::cin.ignore();
			std::cin.get();
		}
		goto redo;
	}
	if (ch3 == 2)
	{
		int newAge;
		std::cout << "\n   Enter the New Age : ";
		std::cin >> newAge;
		int y = confirm();
		if (y == 1)
		{
			bs1[sIndex].setAge(newAge);
			std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
			std::cin.ignore();
			std::cin.get();
		}
		goto redo;
	}
	if (ch3 == 3)
	{
		char newPassword[10], cr;
		std::cout << "\n   Enter the New Password : ";
		for (int i = 0; i < 10; i++)
		{
			cr = getchar();
			if (cr != '\r')
			{
				newPassword[i] = cr;
				std::cout << "*";
			}
			else
			{
				newPassword[i] = '\0';
				break;
			}
		}
		std::cout << "\n";
		int y = confirm();
		if (y == 1)
		{
			bs1[sIndex].setPassword(newPassword);
			std::cout << "\n\n   Record Has Been Updated\n\n   Press Any Key";
			std::cin.ignore();
			std::cin.get();
		}
		goto redo;
	}
	if (ch3 == 4)
	{
		goto redo;
	}
	std::cout << "\n   Enter the Correct Choice!";
	goto redo;
}

class Interval
{
public:
	int low;
	int high;
	int PID;

	Interval()
	{
		low = 0;
		high = 0;
		PID = 0;
	}

	Interval(int l, int h, int p)
	{
		low = l;
		high = h;
		PID = p;
	}

	void getIntervalInfo()
	{
		std::cout << "\n   Enter Low : ";
		std::cin >> low;
		std::cout << "\n   Enter High : ";
		std::cin >> high;
		GetPartyIdNo();
		Party ps1[partyId];
		std::cout << std::endl
				  << "   ID  Party\n\n";
		for (int i = 0; i < partyId; i++)
		{
			ps1[i].getParty(i);
			std::cout << "   " << ps1[i].getPartyId() << ".";
			int j = countDigits(i + 1);
			for (int k = j; k < 8; k++)
				std::cout << " ";
			std::cout << ps1[i].getPartyName() << std::endl;
		}
		std::cout << "\n   Choose The Party (ID) : ";
		std::cin >> PID;
		resultId++;
	}

	int getLow() { return low; }
	int getHigh() { return high; }
	int getpId() { return PID; }

	void setLow(int l) { low = l; }
	void setHigh(int h) { high = h; }
	void setpId(int p) { PID = p; }

	void storeInterval();
	int getInterval(int x);
};

int Interval::getInterval(int x)
{
	int i = 0;
	ifstream finIntervalRecord;
	finIntervalRecord.open("Record.txt", ios::in | ios::binary);
	if (!finIntervalRecord)
	{
		std::cout << "\n   File not Found";
	}
	else
	{
		while (!finIntervalRecord.eof() && i != x + 1)
		{
			finIntervalRecord.read(reinterpret_cast<char *>(this), sizeof(*this));
			i++;
		}
	}
}

void Interval::storeInterval()
{
	ofstream foutInterval;
	foutInterval.open("Record.txt", ios::app | ios::binary);
	foutInterval.write(reinterpret_cast<char *>(this), sizeof(*this));
	foutInterval.close();
}

struct ITNode
{
	Interval *i;
	int max;
	ITNode *left, *right;
};

ITNode *newNode(Interval i)
{
	auto temp = new ITNode;
	temp->i = new Interval(i);
	temp->max = i.getHigh();
	temp->left = temp->right = nullptr;
	return temp;
}

ITNode *insert(ITNode *root, Interval i)
{
	if (root == nullptr)
		return newNode(i);

	int l = root->i->getLow();

	if (i.getLow() < l)
		root->left = insert(root->left, i);
	else
		root->right = insert(root->right, i);

	if (root->max < i.getHigh())
		root->max = i.getHigh();

	return root;
}

bool doOVerlap(Interval i1, Interval i2)
{
	if (i1.getLow() < i2.getHigh() && i2.getLow() < i1.getHigh())
		return true;
	return false;
}

void build(int ind, int low, int high)
{
	if (low == high)
	{
		seg[ind] = a[low];
		return;
	}
	int mid = (low + high) / 2;
	build(2 * ind + 1, low, mid);
	build(2 * ind + 2, mid + 1, high);
	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r)
{
	if (low >= l && high <= r)
	{
		return seg[ind];
	}
	if (high < l || low > r)
		return INT32_MIN;
	int mid = (low + high) / 2;
	int left = query(2 * ind + 1, low, mid, l, r);
	int right = query(2 * ind + 2, mid + 1, high, l, r);
	return max(left, right);
}

void update(int low, int high, int idx, int new_val, int ind)
{
	if (low == high)
	{
		a[idx] = new_val;
		seg[ind] == new_val;
		return;
	}
	int mid = (low + high) / 2;
	if (low <= idx && idx <= mid)
	{
		update(low, mid, idx, new_val, 2 * ind + 1);
	}
	else
	{
		update(mid + 1, high, idx, new_val, 2 * ind + 2);
	}
	seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// segment end
void displayResultRecord(ITNode *root)
{
	GetPartyIdNo();
	Party bs1[partyId];
	for (int i = 0; i < partyId; i++)
	{
		bs1[i].getParty(i);
	}
	int RpId = root->i->PID;
	int c = 0;
	// c=countDigits(obj.getCandidateID());
	std::cout << "   " << root->i->low << " - " << root->i->high;
	for (int i = 0; i < 7; i++)
		std::cout << " ";
	c = countDigits(bs1[RpId - 1].getPartyId());
	std::cout << bs1[RpId - 1].getPartyId();
	for (int i = c; i < 7; i++)
		std::cout << " ";
	c = strlen(bs1[RpId - 1].getPartyName().c_str());
	std::cout << bs1[RpId - 1].getPartyName() << std::string(c, ' ');
	std::cout << bs1[RpId - 1].getHeadName() << "\n";
}

Interval *overlapSearchAllSorted(ITNode *root, Interval i)
{
	if (root == nullptr)
		return nullptr;
	if (root->left != nullptr && root->left->max >= i.low)
		overlapSearchAllSorted(root->left, i);
	if (doOVerlap(*(root->i), i))
		displayResultRecord(root);
	// std::cout <<"\nOverlaps with [" << root->i->getLow()<<","<<root->i->getHigh()<<"]    PartyID : "<<root->i->getpId();
	overlapSearchAllSorted(root->right, i);
}

void inorder(ITNode *root)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	std::cout << "[" << root->i->getLow() << ", " << root->i->getHigh() << "]"
			  << " max = " << root->max << "PartyId = " << root->i->getpId() << std::endl;
	inorder(root->right);
}

void displayVoterRecord(Voter bs1[], int vId)
{
	funHeading("Voter's Record : ");

	std::cout << "\n   ID     NAME               AGE   GENDER   STATE          CITY     Vote-STATUS\n\n";

	for (int i = 0; i < vId; i++)
	{
		int c = 0;
		c = countDigits(bs1[i].getVoterID());
		std::cout << "   " << bs1[i].getVoterID();
		std::cout << std::string(7 - c, ' ');
		std::cout << bs1[i].getVoterName() << std::string(20 - bs1[i].getVoterName().length(), ' ');
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

void viewVoterRecord()
{
	GetVoterId();
	if (voterId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Voter bs1[voterId];
	for (int i = 0; i < voterId; i++)
	{
		bs1[i].getVoter(i);
	}

	displayVoterRecord(bs1, voterId);
redo:;
	std::cout << "\n\n   0.GoBack";
	std::cout << "\n   1.Apply Filter (Sort/OrderBy (State,City))";
	int ch;
	std::cout << "\n\n   Enter Your Choice : ";
	std::cin >> ch;
	if (ch == 0)
	{
		return;
	}
	Voter bs2[voterId], obj;
	int id = 0;
	for (int i = 0; i < voterId; i++)
	{
		obj = bs1[i];
		std::string objState = obj.getstateName();
		int j;
		for (j = id; j > 0; j--)
		{
			std::string cmpState = bs2[j - 1].getstateName();
			int k = cmpState.compare(objState);
			if (k < 0)
			{
				bs2[j] = bs2[j - 1];
			}
			else if (!k)
			{
				std::string objCity = obj.getcityName();
				std::string cmpCity = bs2[j - 1].getcityName();
				int k = cmpCity.compare(objCity);
				if (k < 0)
				{
					bs2[j] = bs2[j - 1];
				}
				else
				{
					goto in;
				}
			}
			else
			{
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

void displayCandidateRecord(Candidate bs1[], int cId)
{
	funHeading("Candidate's Record : ");

	std::cout << "\n   ID     NAME                     PARTYNAME                    STATE           CITY         VOTES  SEATS\n\n";
	for (int i = 0; i < cId; i++)
	{
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

void viewCandidateRecord()
{
	GetCandidateId();
	if (candidateId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Candidate bs1[candidateId];

	for (int i = 0; i < candidateId; i++)
	{
		bs1[i].getCandidate(i);
	}
	displayCandidateRecord(bs1, candidateId);
redo:;
	std::cout << "\n\n   0.GoBack";
	std::cout << "\n   1.Apply Filter";
	int ch;
	std::cout << "\n\n   Enter Your Choice : ";
	std::cin >> ch;
	if (ch != 1)
	{
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
	if (ch == 2)
	{
		for (int i = 0; i < candidateId; i++)
		{
			obj = bs1[i];
			std::string objState = obj.getstateName();
			int j;
			for (j = id; j > 0; j--)
			{
				std::string cmpState = bs2[j - 1].getstateName();
				int k = cmpState.compare(objState);
				if (k < 0)
				{
					bs2[j] = bs2[j - 1];
				}
				else if (!k)
				{
					std::string objCity = obj.getcityName();
					std::string cmpCity = bs2[j - 1].getcityName();
					int k = cmpCity.compare(objCity);
					if (k < 0)
					{
						bs2[j] = bs2[j - 1];
					}
					else if (!k)
					{
						std::string objParty = obj.getPartyName();
						std::string cmpParty = bs2[j - 1].getPartyName();
						int k = cmpParty.compare(objParty);
						if (k < 0)
						{
							bs2[j] = bs2[j - 1];
						}
						else
						{
							goto in;
						}
					}
					else
					{
						goto in;
					}
				}
				else
				{
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
	if (ch == 3)
	{
		for (int i = 0; i < candidateId; i++)
		{
			obj = bs1[i];
			std::string objParty = obj.getPartyName();
			int j;
			for (j = id; j > 0; j--)
			{
				std::string cmpParty = bs2[j - 1].getPartyName();
				int k = cmpParty.compare(objParty);
				if (k < 0)
				{
					bs2[j] = bs2[j - 1];
				}
				else if (!k)
				{
					std::string objState = obj.getstateName();
					std::string cmpState = bs2[j - 1].getstateName();
					int k = cmpState.compare(objState);
					if (k < 0)
					{
						bs2[j] = bs2[j - 1];
					}
					else if (!k)
					{
						std::string objCity = obj.getcityName();
						std::string cmpCity = bs2[j - 1].getcityName();
						int k = cmpCity.compare(objCity);
						if (k < 0)
						{
							bs2[j] = bs2[j - 1];
						}
						else
						{
							goto in2;
						}
					}
					else
					{
						goto in2;
					}
				}
				else
				{
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

void viewPartyRecord()
{
	GetPartyIdNo();
	if (partyId == 0)
	{
		std::cout << "\n   No Record Found";
		return;
	}
	Party bs1[partyId];

	funHeading("Party's Record : ");

	std::cout << "\n   ID     NAME                          HEAD             MEMBERS\n\n";
	for (int i = 0; i < partyId; i++)
	{
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

void ResetVotes()
{
	funHeading("Reseting the Record in DataBase : ");
	std::cout << "\n\n   1.Reset Voter's Record\n";
	std::cout << "   2.Reset Party/Candidate's Record";
	std::cout << "\n\n   Enter Your Choice : ";
	int ch;
	std::cin >> ch;
	char c;
	std::cout << "\n   Are you sure to reset the Record (y/n) :";
	std::cin >> c;
	if (c == 'y' || c == 'Y')
	{
		if (ch == 1)
		{
			GetVoterId();
			if (voterId != 0)
			{
				Voter vs1[voterId];
				for (int i = 0; i < voterId; i++)
				{
					vs1[i].getVoter(i);
					vs1[i].setPartyId(0);
					vs1[i].setPartyName("null");
				}
				remove("voter.txt");
				for (int i = 0; i < voterId; i++)
				{
					vs1[i].storeVoter();
				}
			}
		}
		if (ch == 2)
		{
			GetCandidateId();
			if (candidateId != 0)
			{
				Candidate cs1[candidateId];
				for (int i = 0; i < candidateId; i++)
				{
					cs1[i].getCandidate(i);
					cs1[i].setCandidateVotes(0);
					cs1[i].setSeats(0);
				}
				remove("candidates.txt");
				for (int i = 0; i < candidateId; i++)
				{
					cs1[i].storeCandidate();
				}
			}
		}

		std::cout << "\n\n   Record has been reset. Press any Key to Go Back";
		std::cin.ignore();
		std::cin.get();
	}
	else
		return;
}

void funIntervalInput(Interval *b)
{
	Interval obj;
	obj.getIntervalInfo();
	int objpID = obj.getpId();
	int j = resultId - 1;
	for (j = resultId - 1; j > 0; j--)
	{
		int cmppId = b[j - 1].getpId();
		if (objpID < cmppId)
		{
			b[j] = b[j - 1];
		}
		else
		{
			break;
		}
	}
	b[j] = obj;
}

void setResultRecord()
{
	GetResultId();
	Interval bs1[resultId + 1];

	funHeading("Inserting New Result Record : \n");
	for (int i = 0; i < resultId; i++)
	{
		bs1[i].getInterval(i);
		// std::cout<<"\n   "<<bs1[i].low<<" - "<<bs1[i].high<<"     PartyId: "<<bs1[i].PID;
	}
	funIntervalInput(bs1);
	setResultId();
	remove("Record.txt");
	for (int i = 0; i < resultId; i++)
	{
		bs1[i].storeInterval();
	}
	std::cout << "\n\n   Record Inserted\n\n   Press any Key To Insert The Record";
	std::cin.ignore();
	std::cin.get();
}

void showResult1()
{
redo:;
	funHeading("Showing OverAll Result");

	std::cout << "\n   PartyName                     HeadName               Votes     Seats\n\n";
	GetPartyIdNo();
	Party p1[partyId];
	GetCandidateId();
	Candidate c1[candidateId];
	for (int j = 0; j < partyId; j++)
	{
		p1[j].getParty(j);
		p1[j].setSeats(0);
		p1[j].setVotes(0);
	}
	for (int i = 0; i < candidateId; i++)
	{
		c1[i].getCandidate(i);
		int pId = c1[i].getPartyId();

		int pseats = p1[pId - 1].getSeats();
		pseats = pseats + c1[i].getSeats();
		p1[pId - 1].setSeats(pseats);
		int pVotes = p1[pId - 1].getVotes();
		pVotes = pVotes + c1[i].getCandidateVotes();
		p1[pId - 1].setVotes(pVotes);
	}
	for (int j = 0; j < partyId; j++)
	{
		int c = 0;
		c = strlen(p1[j].getPartyName().c_str());
		std::cout << "   " << p1[j].getPartyName();
		for (int k = c; k < 30; k++)
			std::cout << " ";
		c = strlen(p1[j].getHeadName().c_str());
		std::cout << p1[j].getHeadName();
		for (int k = c; k < 25; k++)
			std::cout << " ";
		c = countDigits(p1[j].getVotes());
		std::cout << p1[j].getVotes();
		for (int k = c; k < 10; k++)
			std::cout << " ";
		// c=countDigits(c1[i].getSeats());
		std::cout << p1[j].getSeats();
		std::cout << "\n";
	}
}

void showResult2()
{
redo:;
	funHeading("Showing result for a Specific State : ");
	GetStateCount();
	State bs1[stateCount];
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
	int sr;
	std::cout << "\n   Choose Your State (S.No) : ";
	std::cin >> sr;
	if (sr <= 0 || sr > stateCount)
	{
		std::cout << "\n   Invalid Choice!";
		goto redo;
	}

redo2:;
	funHeading("Showing result for a Specific State : ");
	std::cout << "\n\n   Selected State          :  " << bs1[sr - 1].getstateName() << " (" << bs1[sr - 1].getSeats() << ")"
			  << "\n\n";

	std::cout << "\n   PartyName                     HeadName               Votes     Seats\n\n";
	GetPartyIdNo();
	Party p1[partyId];
	GetCandidateId();
	Candidate c1[candidateId];

	for (int j = 0; j < partyId; j++)
	{
		p1[j].getParty(j);
		p1[j].setSeats(0);
		p1[j].setVotes(0);
		bool f = false;
		for (int i = 0; i < candidateId; i++)
		{
			c1[i].getCandidate(i);
			if (c1[i].getPartyId() == p1[j].getPartyId())
			{
				if (c1[i].getstateId() == bs1[sr - 1].getstateId())
				{
					f = true;
					int pseats = p1[j].getSeats();
					pseats = pseats + c1[i].getSeats();
					p1[j].setSeats(pseats);
					int pVotes = p1[j].getVotes();
					pVotes = pVotes + c1[i].getCandidateVotes();
					p1[j].setVotes(pVotes);
				}
			}
		}

		if (f == 1)
		{
			int c = 0;
			std::cout << "   " << p1[j].getPartyName();
			std::cout << std::string(30 - p1[j].getPartyName().length(), ' ');
			std::cout << p1[j].getHeadName();
			std::cout << std::string(25 - p1[j].getHeadName().length(), ' ');
			c = countDigits(p1[j].getVotes());
			std::cout << p1[j].getVotes();
			for (int k = c; k < 10; k++)
				std::cout << " ";
			// c=countDigits(c1[i].getSeats());
			std::cout << p1[j].getSeats();
			std::cout << "\n";
		}
	}
}

void showResult3()
{
redo:;
	funHeading("Showing result for a Specific District : ");
	GetStateCount();
	State bs1[stateCount]; // FIXME: try to cache this
	std::cout << std::endl
			  << "   S.No.  State\n\n";
	for (int i = 0; i < stateCount; i++)
	{
		bs1[i].getStates(i);
		std::cout << "   " << i + 1 << ".";
		int j = countDigits(i + 1);
		std::cout << std::string(j - 8, ' ');
		bs1[i].showStateInfo();
	}
	int sr;
	std::cout << "\n   Choose Your State (S.No) : ";
	std::cin >> sr;
	if (sr <= 0 || sr > stateCount)
	{
		std::cout << "\n   Invalid Choice!";
		goto redo;
	}

redo2:;
	funHeading("Showing result for a Specific District : ");
	std::cout << "\n\n   Select Your State          :  " << bs1[sr - 1].getstateName() << "\n\n";
	GetCityCount();
	City cs1[cityCount];
	std::cout << std::endl
			  << "   S.No.  City\n\n";
	for (int i = 0; i < cityCount; i++)
	{
		cs1[i].getCity(i);
		if (cs1[i].getstateId() == bs1[sr - 1].getstateId())
		{
			std::cout << "   " << i + 1 << ".";
			int j = countDigits(i + 1);
			for (int k = j; k < 8; k++)
				std::cout << " ";
			cs1[i].showCityInfo();
		}
	}
	int sr2;
	std::cout << "\n   Choose Your City (S.No) : ";
	std::cin >> sr2;
	if (sr <= 0 || sr > cityCount)
	{
		std::cout << "\n   Invalid Choice!";
		goto redo2;
	}

	funHeading("Showing result for a Specific District : ");
	std::cout << "\n\n   Selected State       :  " << bs1[sr - 1].getstateName();
	std::cout << "\n\n   Selected District    :  " << cs1[sr2 - 1].getcityName() << "\n\n";

	std::cout << "\n   PartyName                     HeadName                 CandidateName          Votes     Seats\n\n";
	GetCandidateId();
	Candidate c1[candidateId];
	for (int i = 0; i < candidateId; i++)
	{
		c1[i].getCandidate(i);
		if (c1[i].getcityId() == cs1[sr2 - 1].getcityId())
		{
			int c = 0;
			std::cout << "   " << c1[i].getPartyName();
			std::cout << std::string(30 - c1[i].getPartyName().length(), ' ');
			std::cout << c1[i].getHeadName();
			std::cout << std::string(25 - c1[i].getHeadName().length(), ' ');
			std::cout << c1[i].getCandidateName();
			std::cout << std::string(c1[i].getCandidateName().length(), ' ');
			c = countDigits(c1[i].getCandidateVotes());
			std::cout << c1[i].getCandidateVotes();
			for (int i = c; i < 10; i++)
				std::cout << " ";
			// c=countDigits(c1[i].getSeats());
			std::cout << c1[i].getSeats();
			std::cout << "\n";
		}
	}
}

void showResult4()
{
	GetResultId();
	Interval bs1[resultId + 1];
	ITNode *root = nullptr;
	funHeading("List of Record For Specific Interval : \n");
	for (int i = 0; i < resultId; i++)
	{
		bs1[i].getInterval(i);
		root = insert(root, bs1[i]);
	}
	int low, high;
	std::cout << "\n   Low : ";
	std::cin >> low;
	std::cout << "\n   High : ";
	std::cin >> high;
	auto x = Interval(low, high, 0);
	std::cout << "\n   Record for Interval [" << x.low << "," << x.high << "] : \n\n";
	std::cout << "   Interval          ID     PartyName                     HeadName\n\n";
	overlapSearchAllSorted(root, x);
}

void showResults()
{
	while (true)
	{
		int ch = choiceAdmin(9);
		switch (ch)
		{
		case 0:
			return;
		case 1:
			showResult1();
			break;
		case 2:
			showResult2();
			break;
		case 3:
			showResult3();
			break;
		case 4:
			showResult4();
			break;
		default:
			std::cout << "\n   Enter the Correct Choice!";
			break;
		}
	}
}

void CreateAccount()
{
	int ch, Id;
	do
	{
		ch = choiceAdmin(5);
		switch (ch)
		{
		case 1:
			Id = insertNewVoter();
			if (Id)
			{
				viewVoterInfo(Id);
			}
			break;
		case 2:
			Id = insertNewCandidate();
			if (Id)
			{
				viewCandidateInfo(Id);
			}
			break;
		case 3:
			Id = insertNewParty();
			if (Id)
			{
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

void AlterState()
{
	int ch;
	do
	{
		ch = choiceAdmin(3);
		switch (ch)
		{
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

void AlterCity()
{
	int ch;
	do
	{
		ch = choiceAdmin(4);
		switch (ch)
		{
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

void MaintainRecords()
{
	int ch;
	do
	{
		ch = choiceAdmin(1);
		switch (ch)
		{
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

int main()
{
	funFrontPage();
	int ch, Id = 0;
	do
	{
		ch = choiceAdmin(0);
		switch (ch)
		{
		case 1:
			Id = VoterLogin();
			if (Id)
			{
				viewVoterInfo(Id);
			}
			break;
		case 2:
			Id = CandidateLogin();
			if (Id)
			{
				viewCandidateInfo(Id);
			}
			break;
		case 3:
			Id = partyLogin();
			if (Id)
			{
				viewPartyInfo(Id);
			}
			break;
		case 4:
			CreateAccount();
			break;
		case 5:
			showResults();
			break;
		case 6:
		{
			int ch;
			do
			{
				ch = choiceAdmin(2);
				switch (ch)
				{
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
					setResultRecord();
					break;
					;
				default:
					std::cout << "\n   Enter the Correct Choice!";
					break;
				}
			} while (ch != 0);
		}
		case 7:
			break;
		default:
			std::cout << "\n   Enter the Correct Choice!";
			break;
		}
	} while (ch != 6);

	return 0;
}
