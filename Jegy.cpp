#include "Jegy.h"
#include <iostream>


Jegy::Jegy(Jegy *CopyJegy) {
    JJarat = CopyJegy->getJarat();
    ElsoAllomas = CopyJegy->getElsoAllomas();
    VegAllomas = CopyJegy->getVegAllomas();
    Jegyar = CopyJegy->getJegyAr();
}

Jegy * Jegy::Clone() {
    return new Jegy(this);
}

Jarat * Jegy::getJarat() {
    return JJarat;
}

std::string Jegy::FileToWrite() {
    std::string JaratNev = JJarat->getJaratName();
    std::string ElsoAll = ElsoAllomas->getAllomasNev();
    std::string VegAll = VegAllomas->getAllomasNev();
    std::string JegyAr = std::to_string(Jegyar);
    std::string ToReturn =JaratNev+";"+ElsoAll+";"+VegAll+";"+JegyAr+";"+"0";
    return ToReturn;
}

Allomas * Jegy::getElsoAllomas() {
    return ElsoAllomas;
}

Allomas * Jegy::getVegAllomas() {
    return VegAllomas;
}

int Jegy::getJegyAr() const {
    return Jegyar;
}

void Jegy::PrintJegy() const {
    std::cout << "\nJegyInfo:\n\n";
    std::cout << "Jarat neve: ";
    std::cout<< JJarat->getJaratName();
    std::cout <<"\n" <<ElsoAllomas->getAllomasNev() << " Allomastol\n";
    std::cout << VegAllomas->getAllomasNev() << " Allomasig\n";
    std::cout << "Jegyar: ";
    std::cout << std::to_string(this->getJegyAr()) << "\n\n";
}
