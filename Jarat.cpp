#include "Jarat.h"
#include <iostream>
#include "memtrace.h"


Jarat::~Jarat()
{
    MenetRendArray->deleteElement(MenetRendArray);
}

std::string Jarat::getJaratName() {
    return JNev;
}

void Jarat::PrintJarat() const {
    std::cout << "\n\n\n";
    std::cout <<JNev << std::endl << std::endl;

}

void Jarat::setJVonat(Vonat *sVonat)
{
    JVonat = sVonat;
}

Vonat *Jarat::getJVonat()
{
    return JVonat;
}

void Jarat::setFirstMenetrend(Menetrend *sFirstMenetrend)
{
    delete MenetRendArray;
    MenetRendArray = sFirstMenetrend;
}

Menetrend *Jarat::getFirstMenetrend()
{
    return MenetRendArray;
}
