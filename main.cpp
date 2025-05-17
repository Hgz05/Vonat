
#include "Jarat.h"
#include "Jegy.h"
#include "HelyJegy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Allomas* AllomasRead() {
    int ReadIncrement = 0;
    std::string Name;
    double Szelesseg;
    double Magassag;
    bool Wc;
    bool Bufe;
    bool FirstAllomasExists = false;
    Allomas* FirstAllomas = nullptr; //Temporary Allomas object
    std::ifstream file("Allomas.dat");
    if (!file.is_open()) {
        throw "File could not be opened!";
    }
    std::string line;
    std::string tmp;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, tmp, ';')) {
            if (ReadIncrement == 0) {
                Name = tmp;
                ReadIncrement++;
            }else if (ReadIncrement == 1) {
                Szelesseg = std::stod(tmp);
                ReadIncrement++;
            }else if (ReadIncrement == 2) {
                Magassag = std::stod(tmp);
                ReadIncrement++;
            }else if (ReadIncrement == 3) {
                Wc = std::stoi(tmp) == 1;
                ReadIncrement++;
            }else if (ReadIncrement == 4) {
                Bufe = std::stoi(tmp) == 1;
                ReadIncrement = 0;
            }
        }
        if (!FirstAllomasExists) {
            FirstAllomas = new Allomas(Name,Szelesseg,Magassag,Wc,Bufe);
            FirstAllomasExists = true;
        } else {
            Allomas* NextAllomas = new Allomas(Name,Szelesseg,Magassag,Wc,Bufe);
            FirstAllomas->operator+(NextAllomas);
        }
    }
    if (FirstAllomas == nullptr) {
        throw "FirstAllomas was not initialised!";
    }
    return FirstAllomas;

}


int main(int argc, char const *argv[])
{

    Allomas* FirstAllomas = AllomasRead();
    std::cout << FirstAllomas->getAllomasNev();
    return 0;
}

// Default Test
/*
    Kocsi *TesztKocsi = new Kocsi(1, Masod);
    Allomas *TestAllomas = new Allomas("Szex", 23.0, 43.0, false, true);
    Ido *TesztErkezoIdo = new Ido();
    TesztErkezoIdo->ora = 14;
    TesztErkezoIdo->perc = 12;
    Ido *TestInduloIdo = new Ido();
    TestInduloIdo->ora = 14;
    TestInduloIdo->perc = 15;
    Menetrend *TesztMenetrend = new Menetrend(TestAllomas, TesztErkezoIdo, TestInduloIdo);
    Vonat *TesztVonat = new Vonat(Szemelyi, 2, TesztKocsi, 120, 5, 20);
    Jarat *TesztJarat = new Jarat("Nyomod",TesztVonat, TesztMenetrend);
    TesztJarat->getFirstMenetrend()->printInfo();
    TesztJarat->getJVonat()->printVonatStat();
    HelyJegy *TesztJegy = new HelyJegy(TesztJarat,TestAllomas, TestAllomas, 10, 69);
    TesztJegy->PrintJegy();
    TesztJarat->getFirstMenetrend()->setKeses(15);
    TesztJarat->getFirstMenetrend()->printInfo();
 */