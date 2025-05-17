#include "HelyJegy.h"
#include <iostream>
#include <string>




int HelyJegy::getUlesSzam() const {
    return UlesSzam;
}

void HelyJegy::PrintJegy() const {
    Jegy::PrintJegy();
    std::cout << "Ulesszam: " << std::to_string(this->getUlesSzam()) << std::endl;
}
