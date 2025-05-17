#include "Kocsi.h"
#include <iostream>

Kocsi::Kocsi(const int KocsiSzam, eKocsiTipus KocsiTipus) : KocsiSzam(KocsiSzam), KocsiTipus(KocsiTipus)
{
    UlesArray = new Ules *[60];
    for (int i = 0; i < 60; i++)
    {
        UlesArray[i] = new Ules();
        UlesArray[i]->setUlesSzam(((KocsiSzam - 1) * 60) + i + 1);
        if ((i + 1) % 2 == 1)
        {
            UlesArray[i]->setAblakmel(true);
        }
        else
        {
            UlesArray[i]->setAblakmel(false);
        }
    }
}
Kocsi::~Kocsi()
{
    {
        for (int i = 0; i < 60; i++)
        {
            delete UlesArray[i];
        }
        delete[] UlesArray;
    }
}
int Kocsi::getKocsiSzam()
{
    return KocsiSzam;
}

eKocsiTipus Kocsi::getKocsiTipus()
{
    return KocsiTipus;
}

eKocsiTipus Kocsi::stringToKocsiTipus(const std::string KocsiTipus) {
    switch (KocsiTipus) {
        case "Elso":
            return Elso;
            break;
            case "Masod":
            return Masod;
            break;
            case "Alvo":
            return Alvo;
            break;
            default:
            throw "Invalid String Input To KocsiTipus!";
    }
}

Kocsi *Kocsi::getNextNode()
{
    return nextNode;
}

void Kocsi::operator+(Kocsi *newKocsi)
{
    if (this == nullptr || newKocsi == nullptr)
        throw "New or previous Kocsi does not exist.";
    Kocsi *tmp = this;
    while (tmp->getNextNode() != nullptr)
    {
        tmp = tmp->getNextNode();
    }
    tmp->nextNode = newKocsi;
}
