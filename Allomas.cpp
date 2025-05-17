#include "Allomas.h"

#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string Allomas::getAllomasNev() const
{
    return Nev;
}

double Allomas::getX() const
{
    return Szelesseg;
}

double Allomas::getY() const
{
    return Magassag;
};

bool Allomas::getWc() const
{
    return Wc;
};

bool Allomas::getBufe() const
{
    return Bufe;
}
Allomas *Allomas::getNextNode() const
{
    return nextNode;
}
void Allomas::operator+(Allomas *newAllomas)
{
    if (this == nullptr || newAllomas == nullptr)
        throw "Previous or new Allomas does not exist";

    Allomas *tmp = this;
    while (tmp->getNextNode() != nullptr)
    {
        tmp = tmp->getNextNode();
    }
    tmp->nextNode = newAllomas;
}
Allomas* Allomas::AllomasRead() {
    int ReadIncrement = 0;
    std::string Name;
    double Szelesseg;
    double Magassag;
    bool Wc;
    bool Bufe;
    bool FirstAllomasExists = false;
    Allomas* FirstAllomas = nullptr; //Temporary Allomas object
    std::ifstream file("Allomas.dat");
    if (!file.is_open()) {
        throw "File could not be opened!";
    }
    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, tmp, ';')) {
            if (ReadIncrement == 0) {
                Name = tmp;
                ReadIncrement++;
            }else if (ReadIncrement == 1) {
                Szelesseg = std::stod(tmp);
                ReadIncrement++;
            }else if (ReadIncrement == 2) {
                Magassag = std::stod(tmp);
                ReadIncrement++;
            }else if (ReadIncrement == 3) {
                Wc = std::stoi(tmp) == 1;
                ReadIncrement++;
            }else if (ReadIncrement == 4) {
                Bufe = std::stoi(tmp) == 1;
                ReadIncrement = 0;
            }
        }
        if (!FirstAllomasExists) {
            FirstAllomas = new Allomas(Name,Szelesseg,Magassag,Wc,Bufe);
            FirstAllomasExists = true;
        } else {
            Allomas* NextAllomas = new Allomas(Name,Szelesseg,Magassag,Wc,Bufe);
            FirstAllomas->operator+(NextAllomas);
        }
    }
    if (FirstAllomas == nullptr) {
        throw "FirstAllomas was not initialised!";
    }
    return FirstAllomas;

}