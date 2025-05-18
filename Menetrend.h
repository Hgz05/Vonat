#ifndef MENETREND_H
#define MENETREND_H
#include "Allomas.h"
#include "Ido.h"
class Menetrend
{
    Menetrend *nextNode = nullptr;
    Allomas *CurrAllomas;
    int MenetrendID;
    Ido *ErkezoIdo;
    Ido *InduloIdo;
    Ido *EredErkezoIdo;
    Ido *EredInduloIdo;

public:
    explicit Menetrend(Allomas *MAllomas = nullptr, int ID = -1 ,Ido *ErkIdo = nullptr, Ido *IndIdo = nullptr);
    Ido getErkezoIdo() const;
    Ido getInduloIdo() const;
    Allomas *getAllomas() const;
    void printKeses();
    void setKeses(int Perc);
    void setKesesToALl(int Perc);
    void printInfo();
    void printAllInfo();
    Menetrend *getNextNode();
    Allomas* FindAllomasByName(const std::string &Name);
    void operator+(Menetrend *newMenetrend);
    void deleteElement(Menetrend *curr);
    ~Menetrend();
};

#endif