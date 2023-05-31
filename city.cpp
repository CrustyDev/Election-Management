#include "city.h"
#include <fstream>

extern void GetCityIdNo();
extern void SetCityIdNo();
extern int cityIdNo;
extern int cityCount;

City::City()
{
    setstateId(0);
    setSeats(0);
    LeadcandidateId = 0;
    setstateName("NoName");
    strcpy(cityName, "NoName");
    cityId = 0;
}

int City::getCityInfo(int sId, const char *sName)
{
    setstateId(sId);
    setstateName(sName);
    std::cout << "Enter the Name : ";
    std::cin.getline(cityName, 24);
    cityCount++;
    int s = 1;
    setSeats(s);
    GetCityIdNo();
    cityId = ++cityIdNo;
    SetCityIdNo();
    LeadcandidateId = 0;
    return s;
}

void City::getCity(int x)
{
    int i = 0;
    std::ifstream finCityRecord;
    finCityRecord.open("Cities.txt", std::ios::in | std::ios::binary);
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
    std::ofstream foutCity;
    foutCity.open("Cities.txt", std::ios::app | std::ios::binary);
    foutCity.write(reinterpret_cast<char *>(this), sizeof(*this));
    foutCity.close();
}
