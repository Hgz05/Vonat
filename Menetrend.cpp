#include "Menetrend.h"
#include <iostream>


Menetrend::Menetrend( Allomas *MAlomas, int ID, Ido *ErkIdo, Ido *IndIdo) {
    MenetrendID = ID;
    CurrAllomas = MAlomas;
    ErkezoIdo = ErkIdo;
    InduloIdo = IndIdo;
    EredErkezoIdo = new Ido(ErkIdo);
    EredInduloIdo = new Ido(IndIdo);


}
Ido Menetrend::getErkezoIdo() const
{
    return *ErkezoIdo;
}

Ido Menetrend::getInduloIdo() const
{
    return *InduloIdo;
}

Allomas * Menetrend::getAllomas() const {
    return CurrAllomas;
}

void Menetrend::printKeses()
{
    Ido Keses = *InduloIdo - *EredInduloIdo;
    Keses.printTime();
}

void Menetrend::setKeses(int Perc)
{
    InduloIdo->operator+(Perc);
    ErkezoIdo->operator+(Perc);
}

void Menetrend::setKesesToALl(int Perc) {
    Menetrend* tmp = this;
    while (tmp != nullptr) {
        tmp->setKeses(Perc);
        tmp = tmp->getNextNode();
    }
}

void Menetrend::printInfo()
{

    std::cout << "Allomas:\t" << CurrAllomas->getAllomasNev();
    std::cout << "\nTervezett erkezes:\n";
    EredErkezoIdo->printTime();
    std::cout << "\nJelenlegi erkezes:\n";
    ErkezoIdo->printTime();
    std::cout << "\nTervezett indulas:\n";
    EredInduloIdo->printTime();
    std::cout << "\nJelenelegi indulas:\n";
    InduloIdo->printTime();
    std::cout << "\nKeses:\t";
    printKeses();
    std::cout << std::endl;
}

void Menetrend::printAllInfo() {
    Menetrend* tmp = this;
    while (tmp != nullptr) {
        tmp->printInfo();
        tmp = tmp->nextNode;
    }
}

Menetrend *Menetrend::getNextNode()
{
    return nextNode;
}

Allomas* Menetrend::FindAllomasByName(std::string Name) {
    Menetrend* tmp = this;
    while (tmp->nextNode != nullptr && tmp->getAllomas()->getAllomasNev() != Name ) {
        tmp = tmp->getNextNode();
    }
    if (tmp->getAllomas()->getAllomasNev() != Name) {
        throw "Allomas by this name does not exist.";
    }
    return tmp->getAllomas();


}

void Menetrend::operator+(Menetrend *newMenetrend)
{
    if (this == nullptr || newMenetrend == nullptr)
        throw "Previous or new Menetrend does not exist";

    Menetrend *tmp = this;
    while (tmp->getNextNode() != nullptr)
    {
        tmp = tmp->getNextNode();
    }
    tmp->nextNode = newMenetrend;
}

void Menetrend::deleteElement(Menetrend *curr)
{
    if (curr == nullptr)
        return;
    deleteElement(curr->nextNode);
    delete curr;
}
Menetrend::~Menetrend()
{
    deleteElement(this);
}