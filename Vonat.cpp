#include "Vonat.h"
#include <iostream>
#include <string>
eVonatTipus Vonat::getVonatTipus() const
{
    return VonatTipus;
}

std::string Vonat::enumToString(eVonatTipus type) const
{
    switch (type)
    {
    case 0:
        return "InterCity";
        break;
    case 1:
        return "Gyors";
        break;
    case 2:
        return "Zonazo";
        break;
    case 3:
        return "Szemelyi";
        break;
    default:
        "Szemelyi";
        break;
    }
    throw "Enum to String Error!"; // Look at it later
}

int Vonat::getVonatSzam() const
{
    return VonatSzam;
}

Kocsi *Vonat::getKocsi()
{
    return KocsiArray;
}

int Vonat::getMaxSeb() const
{
    return MaxSeb;
}

int Vonat::getMaxKocsi() const
{
    return MaxKocsi;
}

int Vonat::getKor() const
{
    return Kor;
}

void Vonat::printVonatStat() const
{
    std::cout << "A vonat tipusa:\t Maximalis sebesseg:\t Vonat kora:\t Max kocsik szama:" << std::endl;
    std::cout << enumToString(getVonatTipus());
    std::cout << "\t" << std::to_string(getMaxSeb());
    std::cout << "\t" << std::to_string(getKor());
    std::cout << "\t" << std::to_string(getMaxKocsi()) << std::endl;
}
