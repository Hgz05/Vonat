#include "Ules.h"


int Ules::getUlesSzam() const
{
    return UlesSzam;
}

bool Ules::getAblakMel() const
{
    return AblakMel;
}

bool Ules::getSzabad() const
{
    return Szabad;
}

void Ules::setSzabad()
{
    Szabad = false;
}

void Ules::setUlesSzam(const int szam)
{
    UlesSzam = szam;
}

void Ules::setAblakmel(const bool ablak)
{
    AblakMel = ablak;
}
