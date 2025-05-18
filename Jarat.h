#ifndef JARAT_H
#define JARAT_H
#include "Vonat.h"
#include "Menetrend.h"
#include <string>
class Jarat
{
    std::string JNev;
    Vonat *JVonat;
    Menetrend *MenetRendArray; // Linked list

public:
    Jarat(std::string Nev,Vonat *JVonat = nullptr, Menetrend *ElsoAllomas = nullptr) : JNev(Nev), JVonat(JVonat), MenetRendArray(ElsoAllomas) {};
    ~Jarat();
    std::string getJaratName();
    void PrintJarat() const;
    void setJVonat(Vonat *sVonat);
    Vonat *getJVonat();
    void setFirstMenetrend(Menetrend *sFirstMenetrend);
    Menetrend *getFirstMenetrend();
};

#endif