#include "Jarat.h"

Jarat::~Jarat()
{
    delete MenetRendArray;
}

std::string Jarat::getJaratName() {
    return JNev;
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
