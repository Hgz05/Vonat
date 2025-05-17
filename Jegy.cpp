#include "Jegy.h"
#include <iostream>

Jarat * Jegy::getJarat() {
    return JJarat;
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
    std::cout << std::to_string(this->getJegyAr()) << "\n";
}
