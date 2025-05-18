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
    int Kor;
    int KocsiDarab;
    static int VonatArraySize;

public:

    Vonat(eVonatTipus VonatTipus = Szemelyi, int VonatSzam = 1, Kocsi *KocsiArray = nullptr, int MaxSeb = 80, int KocsiDarab = 10, int Kor = 45) : VonatTipus(VonatTipus), VonatSzam(VonatSzam), KocsiArray(KocsiArray), MaxSeb(MaxSeb), KocsiDarab(KocsiDarab), Kor(Kor) {};
    Vonat(Vonat* VonatCopy);
    Kocsi* copyKocsiArray(Kocsi* NextNode);
    ~Vonat();
    void DeleteKocsiArray(Kocsi* ArrayElement);

    eVonatTipus getVonatTipus() const;
    static eVonatTipus stringToVonatTipus(std::string VonatTipus);
    std::string enumToString(eVonatTipus type) const;

    int getVonatSzam() const;
    Kocsi *getKocsi();
    int getMaxSeb() const;
    int getKocsiDarab() const;
    int getKor() const;
    void printVonatStat() const;
    Kocsi* FindKocsiBySzam(int KocsiSzam);
    static Vonat** InitVonat();
    static void SaveVonat(Vonat** VonatArray);
    static Vonat** AddToVonatArray(Vonat** VonatArray, Vonat* VonatToAdd);
    static Vonat** RemoveFromVonatArray(Vonat** VonatArray, Vonat* VonatToRemove);
    static Vonat* FindVonatByNumber(Vonat** VonatArray, int VonatNumber);
};

#endif