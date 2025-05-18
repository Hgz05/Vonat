#include "JaratWrapper.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

JaratWrapper::~JaratWrapper() {
    if (nextNode != nullptr) {
        delete nextNode;
    }
    delete this;
}

void JaratWrapper::PrintJarat() const{
    std::cout << "Printing Jarat's\n";
}

Jarat * JaratWrapper::getJarat() {
    return currJarat;
}

JaratWrapper * JaratWrapper::getNextNode() {
    return nextNode;
}

JaratWrapper * JaratWrapper::InitJaratWrapper(Allomas* FirstAllomas, Vonat** VonatArray) {
    JaratWrapper* ElsoJaratWrapper = nullptr;
    bool ElsoJaratWrapperExists = false;
    std::string JaratNev;
    int VonatSzam;
    int MenetrendID;
    std::string AllomasNev;
    int ErkezOra;
    int ErkezPerc;
    int IndulOra;
    int IndulPerc;


    bool ElsoMenetrendExist = false;
    int MenetrendReadIncrement = 0;
    std::ifstream file("JaratWrapper.dat");
    if (!file.is_open()) {
        throw "JaratWrapper file could not be opened!";
    }
    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {

        Menetrend* ELsoMenetrend;
        int ReadIncrement = 0;
        std::stringstream ss(line);
        while (getline(ss, tmp, ';')) {
            if (ReadIncrement == 0) {
                JaratNev = tmp;
                ReadIncrement++;
            } else if (ReadIncrement == 1) {
                VonatSzam = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 2) {
                if (MenetrendReadIncrement == 0) {
                    MenetrendID = std::stoi(tmp);
                    MenetrendReadIncrement++;
                }else if (MenetrendReadIncrement == 1) {
                    AllomasNev = tmp;
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 2) {
                    ErkezOra = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 3) {
                    ErkezPerc = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 4) {
                    IndulOra = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 5) {
                    IndulPerc = std::stoi(tmp);
                    if (!ElsoMenetrendExist) {
                        Ido *ErkezIdo = new Ido(ErkezOra,ErkezPerc);
                        Ido *IndulIdo = new Ido(IndulOra,IndulPerc);
                        ELsoMenetrend = new Menetrend(FirstAllomas->FindAllomasByName(AllomasNev),MenetrendID,ErkezIdo, IndulIdo);
                        ElsoMenetrendExist = true;
                    } else if (ElsoMenetrendExist) {
                        Ido *ErkezIdo = new Ido(ErkezOra,ErkezPerc);
                        Ido *IndulIdo = new Ido(IndulOra,IndulPerc);
                        Menetrend* NextMenetrend = new Menetrend(FirstAllomas->FindAllomasByName(AllomasNev),MenetrendID,ErkezIdo, IndulIdo);
                        ELsoMenetrend->operator+(NextMenetrend);

                    }
                    MenetrendReadIncrement = 0;
                }
            }
        }
        if (!ElsoJaratWrapperExists) {
            Jarat * JaratToAdd = new Jarat(JaratNev,Vonat::FindVonatByNumber(VonatArray, VonatSzam),ELsoMenetrend);
            ElsoJaratWrapper = new JaratWrapper(JaratToAdd);
            ElsoJaratWrapperExists = true;
        } else if (ElsoJaratWrapperExists) {
            Jarat * JaratToAdd = new Jarat(JaratNev,Vonat::FindVonatByNumber(VonatArray, VonatSzam), ELsoMenetrend);
            JaratWrapper* NextJaratWrapper = new JaratWrapper(JaratToAdd);
            ElsoJaratWrapper->operator+(NextJaratWrapper);

        }
        ElsoMenetrendExist = false;
    }
    file.close();
    return ElsoJaratWrapper;
}

void JaratWrapper::SaveJaratWrapper(JaratWrapper* FistJarat) {
}

void JaratWrapper::operator+(JaratWrapper *newJaratWrapper) {
        if (this == nullptr || newJaratWrapper == nullptr)
            throw "Previous or new JaratWrapper does not exist";
        JaratWrapper *tmp = this;
        while (tmp->getNextNode() != nullptr)
        {
            tmp = tmp->getNextNode();
        }
        tmp->nextNode = newJaratWrapper;
}
Jarat * JaratWrapper::FindJaratByName(const std::string &Nev) {
    JaratWrapper* tmp = this;
    while (tmp != nullptr) {
        if (tmp->getJarat()->getJaratName() == Nev) {
            return tmp->getJarat();
        }
        tmp = tmp->getNextNode();
    }
    throw "Jarat with that Name does not exist!";
}
