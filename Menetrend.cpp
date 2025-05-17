#include "Menetrend.h"
#include <iostream>

Menetrend::Menetrend(const Allomas *MAlomas, int ID, Ido *ErkIdo, Ido *IndIdo) {
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

Menetrend *Menetrend::getNextNode()
{
    return nextNode;
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