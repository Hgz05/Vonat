#include "Vonat.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int Vonat::VonatArraySize = 0;


Vonat::Vonat(Vonat *VonatCopy) {
    VonatTipus =VonatCopy->VonatTipus;
    VonatSzam = VonatCopy->VonatSzam;
    MaxSeb = VonatCopy->MaxSeb;
    Kor = VonatCopy->Kor;
    KocsiDarab = VonatCopy->KocsiDarab;
    KocsiArray = copyKocsiArray(VonatCopy->KocsiArray);

}

Kocsi * Vonat::copyKocsiArray(Kocsi *NextNode) {
    if (NextNode->getNextNode() != nullptr) {
        NextNode->setNextNode(copyKocsiArray(NextNode->getNextNode()));
    }
    Kocsi* NewKocsi = new Kocsi(NextNode); //This may not work
    return NewKocsi;
}

Vonat::~Vonat() {
    DeleteKocsiArray(KocsiArray);
}

void Vonat::DeleteKocsiArray(Kocsi *ArrayElement) {
    if (ArrayElement->getNextNode() != nullptr) {
        DeleteKocsiArray(ArrayElement->getNextNode());
    }
    delete ArrayElement;
}

eVonatTipus Vonat::getVonatTipus() const
{
    return VonatTipus;
}

eVonatTipus Vonat::stringToVonatTipus(std::string VonatTipus) {
    if (VonatTipus == "InterCity") {
        return InterCity;
    } else if (VonatTipus == "Gyors") {
        return Gyors;
    } else if (VonatTipus == "Zonazo") {
        return Zonazo;
    } else if (VonatTipus == "Szemelyi") {
        return Szemelyi;
    }
    throw "Invalid String Input To VonatTipus!";
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
    std::cout << "\nA vonat tipusa:\n\n";
    std::cout << enumToString(getVonatTipus());
    std::cout << "\n\nMaximalis sebesseg:\n";
    std::cout <<  std::to_string(getMaxSeb());
    std::cout << "\n\nVonat kora:\n";
    std::cout <<  std::to_string(getKor());
    std::cout <<   "\n\nKocsik szama:\n";
    std::cout <<  std::to_string(getKocsiDarab()) << std::endl;
    std::cout << "\nKocsik:\n";
    KocsiArray->PrintKocsik();

}

Kocsi * Vonat::FindKocsiBySzam(int KocsiSzam) {
    Kocsi* tmp = KocsiArray;
    while (tmp->getNextNode() != nullptr && tmp->getKocsiSzam() != KocsiSzam) {
        tmp = tmp->getNextNode();
    }
    if (tmp->getKocsiSzam() != KocsiSzam) {
        throw "Kocsi with this KocsiSzam does not exsit!";
    }
    return tmp;
}

Vonat** Vonat::InitVonat() {

    bool FirstVonatExists = false;
    Vonat** VonatArray = new Vonat *[1];
    VonatArray[0] = nullptr;

    std::string VonatTipus;
    int VonatSzam;
    int MaxSeb;
    int Kor;
    int KocsiDarab;


    int KocsiSzam;
    std::string KocsiTipus;

    std::ifstream file("Vonat.dat");
    if (!file.is_open()) {
        throw "Vonat file could not be opened!";
    }
    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {
        int ReadIncrement = 0;
        int KocsiReadIncrement = 0;
        bool FirstKocsiExists = false;
        Kocsi* ElsoKocsi =nullptr;
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
                        if (ElsoKocsi == nullptr) {
                            throw "Elso Kocsi Is Null!";
                        }
                        Kocsi* NextKocsi = new Kocsi(KocsiSzam, Kocsi::stringToKocsiTipus(KocsiTipus));
                        ElsoKocsi->operator+(NextKocsi);
                    }
                    KocsiReadIncrement = 0;
                }
            }

        }
        if (!FirstVonatExists) {
            VonatArray[0] = new Vonat(stringToVonatTipus(VonatTipus),VonatSzam,ElsoKocsi, MaxSeb, KocsiDarab, Kor);
            FirstVonatExists = true;
            VonatArraySize = 1;
        }else if (FirstVonatExists) {
            Vonat* NextVonat = new Vonat(stringToVonatTipus(VonatTipus),VonatSzam, ElsoKocsi, MaxSeb, KocsiDarab, Kor);
            VonatArray = AddToVonatArray(VonatArray, NextVonat);
        }

        //Vonat add to array and kocsi link to vonat
    }
    file.close();
    return VonatArray;
}

void Vonat::SaveVonat(Vonat **VonatArray) {
}

Vonat ** Vonat::AddToVonatArray(Vonat **VonatArray, Vonat *VonatToAdd) {
    if (VonatArray == nullptr || VonatToAdd == nullptr) {
        throw "VonatArray or VonatToAdd does not exist!";
    }
    VonatArraySize++;
    Vonat** NewVonatArray = new Vonat *[VonatArraySize];
    for (int i = 0; i < VonatArraySize-1; i++) {
        NewVonatArray[i] = new Vonat(VonatArray[i]);// The delete deletes the nextNode
    }
    delete[] VonatArray;
    NewVonatArray[VonatArraySize-1] = VonatToAdd;
    return NewVonatArray;
}

Vonat ** Vonat::RemoveFromVonatArray(Vonat **VonatArray, Vonat *VonatToRemove) {
    if (VonatArray == nullptr || VonatToRemove == nullptr) {
        throw "VonatArray or VonatToRemove does not exist!";
    }
    VonatArraySize--;
    if (VonatArraySize == 0) {
        for (int i = 0; i < VonatArraySize+1; i++) {
            delete VonatArray[i];
        }
        delete VonatArray;
        return nullptr;
    }
    int j = 0;
    Vonat** NewVonatArray = new Vonat *[VonatArraySize];
    for (int i = 0; i < VonatArraySize-1; i++) {
        if (VonatArray[i] != VonatToRemove) {
            NewVonatArray[j] = new Vonat(VonatArray[i]);
            j++;
        }
    }
    delete[] VonatArray;
    return NewVonatArray;

}

Vonat * Vonat::FindVonatByNumber(Vonat **VonatArray, int VonatNumber) {
    for (int i = 0; i < VonatArraySize; i++) {
         if (VonatArray[i]->getVonatSzam() == VonatNumber) {
             return VonatArray[i];
         }
    }
    throw "Vonat with this number does not exist!";
}
