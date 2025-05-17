#ifndef VONAT_H
#define VONAT_H
#include "Kocsi.h"
#include <string>
enum eVonatTipus
{
    InterCity,
    Gyors,
    Zonazo,
    Szemelyi
};
class Vonat
{
    eVonatTipus VonatTipus;
    int VonatSzam;
    Kocsi *KocsiArray; // Linked list
    int MaxSeb;
    int MaxKocsi;
    int Kor;

public:
    Vonat(eVonatTipus VonatTipus = Szemelyi, int VonatSzam = 1, Kocsi *KocsiArray = nullptr, int MaxSeb = 80, int MaxKocsi = 10, int Kor = 45) : VonatTipus(VonatTipus), VonatSzam(VonatSzam), KocsiArray(KocsiArray), MaxSeb(MaxSeb), MaxKocsi(MaxKocsi), Kor(Kor) {};
    ~Vonat();
    eVonatTipus getVonatTipus() const;
    std::string enumToString(eVonatTipus type) const;
    int getVonatSzam() const;
    Kocsi *getKocsi();
    int getMaxSeb() const;
    int getMaxKocsi() const;
    int getKor() const;
    void printVonatStat() const;
};

#endif