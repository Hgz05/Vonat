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
    Kocsi* NewKocsi = new Kocsi(NextNode);
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

eVonatTipus Vonat::stringToVonatTipus(const std::string& VonatTipus) {
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


std::string Vonat::enumToString(eVonatTipus type) {
    switch (type)
    {
    case 0:
        return "InterCity";
    case 1:
        return "Gyors";
    case 2:
        return "Zonazo";
    case 3:
        return "Szemelyi";
    default:
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

Vonat** Vonat::CreateNewVonat(Vonat **VonatArray) {
    std::string VTipus;
    std::cout << "Vonat Tipusa (InterCity, Gyors, Zonazo, Szemelyi)\n";
    std::cin >> VTipus;
    if (VTipus != "InterCity" && VTipus != "Gyors" && VTipus != "Zonazo" && VTipus != "Szemelyi") {
        throw "Invalid VonatTipus!\n";
    }
    std::string VNev;
    std::cout << "\n\nVonat neve:\n";
    std::cin >> VNev;
    std::string VSzamS;
    std::cout << "\n\nVonat Szama\n";
    std::cin >> VSzamS;
    if(CheckStringInt(VSzamS)) {
        throw "Invalid input!\n";
    }
    int VSzam = std::stoi(VSzamS);
    std::string VMaxSebS;
    std::cout << "\n\nMaximalis Sebesseg:\n";
    std::cin >> VMaxSebS;
    if(CheckStringInt(VMaxSebS)) {
        throw "Invalid input!\n";
    }
    int VMaxSeb = std::stoi(VMaxSebS);
    std::cout << "\n\nVonat Kora:\n";
    std::string VKorS;
    std::cin >> VKorS;
    if (CheckStringInt(VKorS)) {
        throw "Invalid input!";
    }
    int VKor = std::stoi(VKorS);
    std::cout << "\n\nKocsik Szama:\n";
    std::string VKocsiDbS;
    std::cin >> VKocsiDbS;
    if (CheckStringInt(VKocsiDbS)) {
        throw "Invalid input!";
    }
    int VKocsiDb = std::stoi(VKocsiDbS);
    std::string *TipusArray = new std::string[VKocsiDb];
    for (int i = 0; i < VKocsiDb; i++) {
        std::cout << i+1 <<". Kocsi Tipusa (Elso,Masod,Alvo)\n";
        std::cin >> TipusArray[i];
        if (TipusArray[i] != "Elso" && TipusArray[i] != "Masod" && TipusArray[i] != "Alvo" ) {
            throw "Invalid KocsiTipus!";
        }
    }
    bool FirsKocsiExists = false;
    Kocsi* FirstKocsi = nullptr;
    for (int i = 0; i < VKocsiDb; i++) {
        if (!FirsKocsiExists) {
                FirstKocsi = new Kocsi(i+1, Kocsi::stringToKocsiTipus(TipusArray[i]));
                FirsKocsiExists = true;
        } else if (FirstKocsi != nullptr) {
            Kocsi* NextKocsi = new Kocsi(i+1, Kocsi::stringToKocsiTipus(TipusArray[i]));
            FirstKocsi->operator+(NextKocsi);
        }
    }
    Vonat *VonatToAdd = new Vonat(stringToVonatTipus(VTipus),VSzam,FirstKocsi,VMaxSeb,VKocsiDb,VKor);
    VonatArray = AddToVonatArray(VonatArray, VonatToAdd);
    delete[] TipusArray;
    return VonatArray;
}

int Vonat::CheckStringInt(const std::string &VString) {
    for (char i : VString) {
        if (isalpha(i)) {
            return 1;
        }
    }
    return 0;
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
                    } else {
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
        }else{
            Vonat* NextVonat = new Vonat(stringToVonatTipus(VonatTipus),VonatSzam, ElsoKocsi, MaxSeb, KocsiDarab, Kor);
            VonatArray = AddToVonatArray(VonatArray, NextVonat);
        }

    }
    file.close();
    return VonatArray;
}

void Vonat::SaveVonat(Vonat **VonatArray) {
    std::ofstream file("Vonat.dat");
    if (!file.is_open()) {
        throw "Vonat file could not be opened!";
    }
    for (int i = 0; i<VonatArraySize; i++) {
        if (VonatArraySize-i == 1) {
            std::string VonatTipus = Vonat::enumToString(VonatArray[i]->getVonatTipus());
            std::string VonatSzam = std::to_string(VonatArray[i]->getVonatSzam());
            std::string MaxSeb = std::to_string(VonatArray[i]->getMaxSeb());
            std::string Kor = std::to_string(VonatArray[i]->getKor());
            std::string KocsiDarab = std::to_string(VonatArray[i]->getKocsiDarab());
            file << VonatTipus <<";"<< VonatSzam<<";"<< MaxSeb<<";"<< Kor<<";"<< KocsiDarab<<";"<< VonatArray[i]->getKocsi()->KocsiToFile();
        } else{
            std::string VonatTipus = Vonat::enumToString(VonatArray[i]->getVonatTipus());
            std::string VonatSzam = std::to_string(VonatArray[i]->getVonatSzam());
            std::string MaxSeb = std::to_string(VonatArray[i]->getMaxSeb());
            std::string Kor = std::to_string(VonatArray[i]->getKor());
            std::string KocsiDarab = std::to_string(VonatArray[i]->getKocsiDarab());
            file << VonatTipus <<";"<< VonatSzam<<";"<< MaxSeb<<";"<< Kor<<";"<< KocsiDarab<<";"<< VonatArray[i]->getKocsi()->KocsiToFile()+"\n";
        }


    }
    delete[] VonatArray;
    file.close();

}

Vonat ** Vonat::AddToVonatArray(Vonat **VonatArray, Vonat *VonatToAdd) {
    if (VonatArray == nullptr || VonatToAdd == nullptr) {
        throw "VonatArray or VonatToAdd does not exist!";
    }
    VonatArraySize++;
    Vonat** NewVonatArray = new Vonat *[VonatArraySize];
    for (int i = 0; i < VonatArraySize-1; i++) {
        NewVonatArray[i] = new Vonat(VonatArray[i]);
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
