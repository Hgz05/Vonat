#include "Ido.h"
#include <iostream>
Ido Ido::operator-(Ido const &Alapido) const
{
    Ido tmp;
    if (this->ora == Alapido.ora && this->perc == Alapido.perc) {
        tmp.ora = 0;
        tmp.perc = 0;
    }
    else if (this->perc > Alapido.perc)
    {
        tmp.ora = Alapido.ora - this->ora;
        tmp.perc = this->perc - Alapido.perc;
    }
    else
    {
        tmp.ora = Alapido.ora + 1 - this->ora;
        tmp.perc = Alapido.perc - this->perc;
    }
    return tmp;
}
bool Ido::operator==(Ido const &Alapido) const
{
    if (this->ora == Alapido.ora && this->perc == Alapido.perc)
    {
        return true;
    }
    return false;
}

void Ido::operator+(int min)
{
    int plusHour;
    perc += min;
    if (perc <= 60)
    {
        plusHour = this->perc / 60;
        perc = perc % 60;
    }
    ora += plusHour;
}

void Ido::printTime() const {
    std::cout <<std::to_string(ora) << " Ora\t" <<std::to_string(perc) << " Perc\n";
}
