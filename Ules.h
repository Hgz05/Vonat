#ifndef ULES_H
#define ULES_H
class Ules
{
    int UlesSzam = 0;
    bool AblakMel = false;
    bool Szabad = true;

public:
    Ules() = default;
    ~Ules() = default;
    Ules(Ules* UlesCopy) {
        UlesSzam = UlesCopy->UlesSzam;
        AblakMel = UlesCopy->AblakMel;
        Szabad = UlesCopy->Szabad;
    }
    int getUlesSzam() const;
    bool getAblakMel() const;
    bool getSzabad() const;
    void setSzabad();
    void setUlesSzam(const int szam);
    void setAblakmel(const bool ablak);
};

#endif