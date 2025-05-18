#include "JegyList.h"

#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "HelyJegy.h"

JegyList::JegyList(Jegy *FirstJegy) {
    if (FirstJegy == nullptr) {
        throw "FirstJegy is null!";
    }
    JegyArray = new Jegy*[1];
    JegyArray[0] = FirstJegy;
    JegyArraySize = 1;
    // Fix this constructor
}
JegyList::JegyList(HelyJegy *FirstHelyJegy) {
    if (FirstHelyJegy == nullptr) {
        throw "FirstHelyJegy is null!";
    }
    JegyArray = new Jegy*[1];
    JegyArray[0] = FirstHelyJegy;
    JegyArraySize = 1;
    // Fix this constructor
}

JegyList::~JegyList() {
    delete[] JegyArray;
    delete this;
}

void JegyList::setJegyListSize(int size) {
    JegyArraySize = size;
}

int JegyList::getJegyListSize() const {
    return JegyArraySize;
}

void JegyList::AddToJEgyArray(Jegy *JegyToAdd) {
    if (JegyToAdd == nullptr) {
        throw "JegyToAdd is null!";
    }
    Jegy** NewJegyArray = new Jegy*[JegyArraySize+1];
    for (int i = 0; i < JegyArraySize; i++) {
        NewJegyArray[i] = JegyArray[i]->Clone();
    }
    delete[] JegyArray;
    NewJegyArray[JegyArraySize] = JegyToAdd;
    setJegyListSize(getJegyListSize() + 1);
    JegyArray = NewJegyArray;
}

void JegyList::DeleteFromJEgyArray(Jegy *JegyToRemove) {
    if (JegyToRemove == nullptr) {
        throw "JegyToRemove is null!";
    }
    int j = 0;
    Jegy** NewJegyArray = new Jegy*[JegyArraySize-1];
    for (int i = 0; i < JegyArraySize; i++) {
        if (JegyArray[i] != JegyToRemove) {

            NewJegyArray[j] = JegyArray[i]->Clone();
            j++;
        }
    }
    setJegyListSize(getJegyListSize() - 1);
    delete[] JegyArray;
    JegyArray = NewJegyArray;
}

void JegyList::BuyJegy(JaratWrapper* FirstJarat) {
    std::string JaratNev;
    Jarat* JaratToAssign = nullptr;
    Allomas* FelAllomas =nullptr;
    Allomas* LeAllomas =nullptr;
    bool Helyjegy = false;
    int Jegyar;

    std::cout << "Jarat neve?\n";
    try {
        std::cin >> JaratNev;
        JaratToAssign = FirstJarat->FindJaratByName(JaratNev);
    } catch (const char* e) {
        std::cout << e;
        return;
    }
    std::cout << "Hol szall fel?\n";
    std::string FelSzal;
    try {
        std::cin >> FelSzal;
        FelAllomas = FirstJarat->FindJaratByName(JaratNev)->getFirstMenetrend()->FindAllomasByName(FelSzal);
    }catch (const char* e) {
        std::cout << e;
        return;
    }
    std::cout << "Hol szall le?\n";
    std::string LeSzal;
    try {
        std::cin >> LeSzal;
        LeAllomas = FirstJarat->FindJaratByName(JaratNev)->getFirstMenetrend()->FindAllomasByName(LeSzal);
    }catch (const char* e) {
        std::cout << e;
        return;
    }
    if (JaratToAssign->getJVonat()->getVonatTipus() == InterCity) {
        double UlesSzam;
        std::cout << "Jegy Kivalasztasa:\n1. Manualis\n2. Ablak Melle\n";
        std::string Input;
        std::cin >> Input;
        if (Input.length() > 1) {
            std::cout << "Invalid input!\n";
            return;
        }
        char InputChar = Input[0];
        if (isalpha(InputChar)) {
            std::cout << "Invalid input!\n";
            return;
        }
        int InputInt = InputChar - '0';
        if (InputInt != 1 && InputInt != 2) {
            std::cout << "Invalid input!\n";
            return;
        }
        bool UlesSzabad = false;
        if (InputInt == 1) {
            std::cin >> UlesSzam;
            try {
                UlesSzabad = JaratToAssign->getJVonat()->FindKocsiBySzam(std::ceil(UlesSzam/60))->FindUlesBySzam(UlesSzam)->getSzabad();
            }catch (const char* e) {
                std::cout << e;
                return;
            }
            if (UlesSzabad) {
                JaratToAssign->getJVonat()->FindKocsiBySzam(std::ceil(UlesSzam/60))->FindUlesBySzam(UlesSzam)->setSzabad();
            } else {
                std::cout << "Ez az ules nem szabad!";
                return;
            }
        } else if (InputInt == 2) {
            UlesSzam = 2;
            do {
                UlesSzabad = JaratToAssign->getJVonat()->FindKocsiBySzam(std::ceil(UlesSzam/60))->FindUlesBySzam(UlesSzam)->getUlesSzam();
                if (UlesSzam == 60*JaratToAssign->getJVonat()->getKocsiDarab() && !UlesSzabad) {
                    std::cout<< "Nincs szabad ules!";
                    return;
                }
            }while (UlesSzabad == false);
            JaratToAssign->getJVonat()->FindKocsiBySzam(std::ceil(UlesSzam/60))->FindUlesBySzam(UlesSzam)->setSzabad();
        }
        Jegy* NewJegy = new HelyJegy(JaratToAssign,FelAllomas,LeAllomas, 2800, UlesSzam);
        this->AddToJEgyArray(NewJegy);
    } else {
        Jegy* NewJegy = new Jegy(JaratToAssign,FelAllomas,LeAllomas, 1800);
        this->AddToJEgyArray(NewJegy);
    }

}

void JegyList::PrintJegyList() const {
    for (int i = 0;i<JegyArraySize;i++) {
        JegyArray[i]->PrintJegy();
    }
}

JegyList* JegyList::InitJegyList(JaratWrapper* FirstJarat, Allomas* FirstAllomas) {
    std::fstream file("JegyList.dat");
    if (!file.is_open()) {
        throw "JegyList file could not be opened!";
    }
    std::string JaratName;
    std::string ELsoAllomasName;
    std::string VegAllomasName;
    int Jegyar;
    int UlesSzam;
    bool FirstJegyExists = false;
    JegyList* JegyArray;

    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {
        int ReadIncrement = 0;
        std::stringstream ss(line);
        while (std::getline(ss, tmp, ';')) {
            if (ReadIncrement == 0) {
                JaratName = tmp;
                ReadIncrement++;
            } else if (ReadIncrement == 1) {
                ELsoAllomasName = tmp;
                ReadIncrement++;
            } else if (ReadIncrement == 2) {
                VegAllomasName = tmp;
                ReadIncrement++;
            } else if (ReadIncrement == 3) {
               Jegyar = std::stoi(tmp);
                ReadIncrement++;
            } else if (ReadIncrement == 4) {
                if (std::stoi(tmp) == 1) {
                    ReadIncrement++;
                } else {
                    if (!FirstJegyExists) {
                        Jegy* FirstJegy = new Jegy(FirstJarat->FindJaratByName(JaratName),FirstAllomas->FindAllomasByName(ELsoAllomasName),FirstAllomas->FindAllomasByName(VegAllomasName), Jegyar);
                        JegyArray = new JegyList(FirstJegy);
                        FirstJegyExists = true;
                    } else if (FirstJegyExists){
                        Jegy* JegyToAdd = new Jegy(FirstJarat->FindJaratByName(JaratName),FirstAllomas->FindAllomasByName(ELsoAllomasName),FirstAllomas->FindAllomasByName(VegAllomasName), Jegyar);
                        JegyArray->AddToJEgyArray(JegyToAdd);
                    }
                    ReadIncrement = 0;

                }
            } else if (ReadIncrement == 5) {
                UlesSzam = std::stoi(tmp);
                if (!FirstJegyExists) {
                    Jegy* FirstJegy = new HelyJegy(FirstJarat->FindJaratByName(JaratName),FirstAllomas->FindAllomasByName(ELsoAllomasName),FirstAllomas->FindAllomasByName(VegAllomasName),Jegyar, UlesSzam);
                    JegyArray = new JegyList(FirstJegy);
                    FirstJegyExists = true;
                } else if (FirstJegyExists){
                    Jegy* JegyToAdd = new HelyJegy(FirstJarat->FindJaratByName(JaratName),FirstAllomas->FindAllomasByName(ELsoAllomasName),FirstAllomas->FindAllomasByName(VegAllomasName), Jegyar, UlesSzam);
                    JegyArray->AddToJEgyArray(JegyToAdd);
                }
                ReadIncrement = 0;
            }
        }

    }
    file.close();
    return JegyArray;
}

void JegyList::SaveJegyList(JegyList* JegyList) {
    std::ofstream file("JegyList.dat");
    if (!file.is_open()) {
        throw "File could not be opened!";
    }
    for (int i = 0; i< JegyList->JegyArraySize; i++) {
        if (JegyList->JegyArraySize-i == 1) {
            file << JegyList->JegyArray[i]->FileToWrite();
        }
        file << JegyList->JegyArray[i]->FileToWrite()+"\n";
    }
    file.close();
}

