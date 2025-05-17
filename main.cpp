#include "Jarat.h"
#include "Jegy.h"
#include "HelyJegy.h"


int main(int argc, char const *argv[])
{
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
    return 0;
}
