#include "Vonat.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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

int Vonat::getKocsiDarab() const
{
    return KocsiDarab;
}

int Vonat::getKor() const
{
    return Kor;
}

void Vonat::printVonatStat() const
{
    std::cout << "A vonat tipusa:\t Maximalis sebesseg:\t Vonat kora:\t Kocsik szama:" << std::endl;
    std::cout << enumToString(getVonatTipus());
    std::cout << "\t" << std::to_string(getMaxSeb());
    std::cout << "\t" << std::to_string(getKor());
    std::cout << "\t" << std::to_string(getKocsiDarab()) << std::endl;
}

Vonat** Vonat::InitVonat() {
    int ReadIncrement = 0;
    int KocsiReadIncrement = 0;
    bool FirstKocsiExists = false;

    std::string VonatTipus;
    int VonatSzam;
    int MaxSeb;
    int Kor;
    int KocsiDarab;


    int KocsiSzam;
    std::string KocsiTipus;

    std::ifstream file("Vonat.dat");
    if (!file.is_open()) {
        throw "Allomas file could not be opened!";
    }
    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {
        Kocsi* ElsoKocsi;
        std::stringstream ss(line);
        while (std::getline(ss, tmp, ';')) {
            if (ReadIncrement == 0) {
                VonatTipus = tmp;
                ReadIncrement++;
            } else if (ReadIncrement == 1) {
                VonatSzam = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 2) {
                MaxSeb = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 3) {
                Kor = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 4) {
                KocsiDarab = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 5) {
                if (KocsiReadIncrement == 0) {
                    KocsiSzam = std::stoi(tmp);
                    KocsiReadIncrement++;
                }else if (KocsiReadIncrement == 1) {
                    KocsiTipus = tmp;
                    if (!FirstKocsiExists) {
                        ElsoKocsi = new Kocsi(KocsiSzam, Kocsi::stringToKocsiTipus(KocsiTipus));
                        FirstKocsiExists = true;
                    } else if (FirstKocsiExists) {
                        Kocsi* NextKocsi = new Kocsi(KocsiSzam, Kocsi::stringToKocsiTipus(KocsiTipus));
                        ElsoKocsi->operator+(NextKocsi);
                    }

                    KocsiReadIncrement = 0;
                }
            }

        }
        
    }
}
