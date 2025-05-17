#include "JaratWrapper.h"
#include <string>
#include <fstream>
#include <sstream>

JaratWrapper::~JaratWrapper() {
    if (nextNode != nullptr) {
        delete nextNode;
    }
    delete this;
}

Jarat * JaratWrapper::getJarat() {
    return currJarat;
}

JaratWrapper * JaratWrapper::getNextNode() {
    return nextNode;
}

JaratWrapper * JaratWrapper::JaratWrapperInit(Allomas* FirstAllomas, Vonat** VonatArray) {
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
                MenetrendID = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 2) {
                if (MenetrendID == 0) {
                    AllomasNev = tmp;
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 1) {
                    ErkezOra = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 2) {
                    ErkezPerc = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 3) {
                    IndulOra = std::stoi(tmp);
                    MenetrendReadIncrement++;
                } else if (MenetrendReadIncrement == 4) {
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

    }
    if (!ElsoJaratWrapperExists) {
        Jarat * JaratToAdd = new Jarat(JaratNev,Vonat::FindVonatByNumber(VonatArray, VonatSzam));
        ElsoJaratWrapper = new JaratWrapper(JaratToAdd);
        ElsoJaratWrapperExists = true;
    } else if (ElsoJaratWrapperExists) {
        Jarat * JaratToAdd = new Jarat(JaratNev,Vonat::FindVonatByNumber(VonatArray, VonatSzam));
        JaratWrapper* NextJaratWrapper = new JaratWrapper(JaratToAdd);
        ElsoJaratWrapper->operator+(NextJaratWrapper);
    }
    return ElsoJaratWrapper;
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

