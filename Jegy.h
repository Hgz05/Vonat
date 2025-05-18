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
    explicit Jegy(Jarat *FelJarat = nullptr, Allomas *Elso = nullptr, Allomas *Utolso = nullptr, int Ar = -1) : JJarat(FelJarat), ElsoAllomas(Elso), VegAllomas(Utolso), Jegyar(Ar) {};
    explicit Jegy(Jegy* CopyJegy);
    virtual Jegy* Clone();
    virtual ~Jegy() = default;
    Jarat* getJarat();
    virtual std::string FileToWrite();
    Allomas* getElsoAllomas();
    Allomas* getVegAllomas();
    int getJegyAr() const;
    virtual void PrintJegy() const;
};
#endif // JEGY_H
