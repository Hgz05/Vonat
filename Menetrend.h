#ifndef MENETREND_H
#define MENETREND_H
#include "Allomas.h"
#include "Ido.h"
class Menetrend
{
    Menetrend *nextNode = nullptr;
    const Allomas *CurrAllomas;
    Ido *ErkezoIdo;
    Ido *InduloIdo;
    Ido *EredErkezoIdo;
    Ido *EredInduloIdo;

public:
    Menetrend(const Allomas *MAllomas = nullptr, Ido *ErkIdo = nullptr, Ido *IndIdo = nullptr);
    Ido getErkezoIdo() const;
    Ido getInduloIdo() const;
    void printKeses();
    void setKeses(int Perc);
    void printInfo();
    Menetrend *getNextNode();
    void operator+(Menetrend *newMenetrend);
    void deleteElement(Menetrend *curr);
    ~Menetrend();
};

#endif