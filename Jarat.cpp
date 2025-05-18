#include "Jarat.h"
#include <iostream>
#include <bits/ostream.tcc>
#include <utility>


Jarat::Jarat(std::string Nev, Vonat *JVonat, Menetrend *ElsoAllomas): JNev(std::move(Nev)), JVonat(JVonat), MenetRendArray(ElsoAllomas) {}

Jarat::~Jarat()
{
    delete MenetRendArray;
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
