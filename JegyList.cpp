#include "JegyList.h"
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>

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
        if (typeid(JegyArray[i]) == typeid(HelyJegy)) {
            NewJegyArray[i] = new Jegy(JegyArray[i]); //HelyJegy copy
        } else {
            NewJegyArray[i] = new Jegy(JegyArray[i]);
        }
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
            if (typeid(JegyArray[i]) == typeid(HelyJegy))
            NewJegyArray[j] = new Jegy(JegyArray[i]); //Helyjegy Copy
            j++;
        } else {
            NewJegyArray[j] = new Jegy(JegyArray[i]);
            j++;
        }
    }
    setJegyListSize(getJegyListSize() - 1);
    delete[] JegyArray;
    JegyArray = NewJegyArray;
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
                    } else if (FirstJegyExists == true){
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
                } else if (FirstJegyExists == true){
                    Jegy* JegyToAdd = new HelyJegy(FirstJarat->FindJaratByName(JaratName),FirstAllomas->FindAllomasByName(ELsoAllomasName),FirstAllomas->FindAllomasByName(VegAllomasName), Jegyar, UlesSzam);
                    JegyArray->AddToJEgyArray(JegyToAdd);
                }
                ReadIncrement = 0;
            }
        }

    }
    return JegyArray;
}

void JegyList::SaveJegyList(JegyList* JegyList) {
}
