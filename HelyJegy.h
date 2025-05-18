#ifndef HELYJEGY_H
#define HELYJEGY_H
#include "Jegy.h"
class HelyJegy : public Jegy
{
    int UlesSzam;
    
public:
    HelyJegy(Jarat *FelJarat = nullptr, Allomas *Elso = nullptr, Allomas *Utolso = nullptr, int Ar = -1, int Ules = -1) : Jegy(FelJarat,Elso,Utolso,Ar), UlesSzam(Ules){};
    HelyJegy(HelyJegy* CopyHelyJegy): Jegy(CopyHelyJegy), UlesSzam(CopyHelyJegy->UlesSzam){};
    Jegy* Clone() override;
    std::string FileToWrite() override;
    int getUlesSzam() const;
    ~HelyJegy() =default;
    void PrintJegy() const override;

};
#endif // HELYJEGY_H
