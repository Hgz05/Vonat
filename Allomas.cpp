#include "Allomas.h"
#include <iostream>
#include <string>

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

void Allomas::set_nev(const std::string nev) {
    Nev = nev;
}

void Allomas::set_szelesseg(const double szelesseg) {
    Szelesseg = szelesseg;
}

void Allomas::set_magassag(const double magassag) {
    Magassag = magassag;
}

void Allomas::set_wc(const bool wc) {
    Wc = wc;
}

void Allomas::set_bufe(const bool bufe) {
    Bufe = bufe;
};
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
