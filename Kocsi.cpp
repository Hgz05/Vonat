#include "Kocsi.h"
#include <iostream>
#include <string>

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

Kocsi::Kocsi(Kocsi *KocsiCopy) {
    nextNode = KocsiCopy->nextNode;
    KocsiSzam = KocsiCopy->KocsiSzam;
    KocsiTipus = KocsiCopy->KocsiTipus;
    UlesArray = new Ules *[60];
    for (int i = 0; i<60; i++) {
        UlesArray[i] = new Ules(KocsiCopy->UlesArray[i]);
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

Ules * Kocsi::FindUlesBySzam(int UlesSzam) {
    return UlesArray[(UlesSzam - 1)-((KocsiSzam-1)*60)];
}

void Kocsi::PrintKocsik(){
    Kocsi* tmp = this;
    while (tmp != nullptr) {
        std::cout <<"Kocsiszam:\n";
        std::cout << tmp->getKocsiSzam();
        std::cout << "\n\nKocsitipus:\n";
        std::cout << this->enumToString(KocsiTipus) << std::endl;
        tmp = tmp->nextNode;
    }

}

std::string Kocsi::KocsiToFile() {
    Kocsi* tmp = this;
    std::string ToReturn = "";
    while (tmp != nullptr) {
        if (tmp->nextNode != nullptr) {
            ToReturn = ToReturn+std::to_string(tmp->getKocsiSzam())+";"+tmp->enumToString(tmp->getKocsiTipus())+";";
        } else {
            ToReturn = ToReturn+std::to_string(tmp->getKocsiSzam())+";"+tmp->enumToString(tmp->getKocsiTipus());
        }
        tmp = tmp->nextNode;
    }
    return ToReturn;
}

std::string Kocsi::enumToString(eKocsiTipus KocsiTipus) {
    if (KocsiTipus == Elso) {
        return "Elso";
    }
    if (KocsiTipus == Masod) {
        return "Masod";
    }
    if (KocsiTipus == Alvo) {
        return "Alvo";
    }
    throw "Invalid enum to string";
}

eKocsiTipus Kocsi::stringToKocsiTipus(const std::string KocsiTipus) {
    if (KocsiTipus == "Elso") {
        return Elso;
    } else if (KocsiTipus == "Masod") {
        return Masod;
    } else if (KocsiTipus == "Alvo") {
        return Alvo;
    }
    throw "Invalid String To Kocsitipus.";
}

Kocsi *Kocsi::getNextNode()
{
    return nextNode;
}

void Kocsi::setNextNode(Kocsi *nextPtr) {
    nextNode = nextPtr;
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
