#include "HelyJegy.h"
#include <iostream>
#include <string>


Jegy * HelyJegy::Clone() {
    return new HelyJegy(this);
}

std::string HelyJegy::FileToWrite() {
    std::string JaratNev = this->getJarat()->getJaratName();
    std::string ElsoAll = this->getElsoAllomas()->getAllomasNev();
    std::string VegAll = this->getVegAllomas()->getAllomasNev();
    std::string JegyAr = std::to_string(this->getJegyAr());
    std::string UlesSz = std::to_string(UlesSzam);
    std::string ToReturn =JaratNev+";"+ElsoAll+";"+VegAll+";"+JegyAr+";"+"1"+";"+UlesSz;
    return ToReturn;
}


int HelyJegy::getUlesSzam() const {
    return UlesSzam;
}


void HelyJegy::PrintJegy() const {
    Jegy::PrintJegy();
    std::cout << "Ulesszam: " << std::to_string(this->getUlesSzam()) << std::endl;
}
