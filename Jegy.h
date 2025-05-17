#ifndef JEGY_H
#define JEGY_H
#include "Jarat.h"
#include "Allomas.h"
class Jegy
{
    Jarat *JJarat;
    Allomas *ElsoAllomas;
    Allomas *VegAllomas;
    int Jegyar;

public:
    Jegy(Jarat *FelJarat = nullptr, Allomas *Elso = nullptr, Allomas *Utolso = nullptr, int Ar = -1) : JJarat(FelJarat), ElsoAllomas(Elso), VegAllomas(Utolso), Jegyar(Ar) {};
    Jegy(Jegy* CopyJegy);
    virtual ~Jegy() = default;
    Jarat* getJarat();
    Allomas* getElsoAllomas();
    Allomas* getVegAllomas();
    int getJegyAr() const;
    virtual void PrintJegy() const;
};
#endif // JEGY_H
