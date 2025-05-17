#ifndef ALLOMAS_H
#define ALLOMAS_H
#include <string>
class Allomas
{
    Allomas *nextNode = nullptr;
    std::string Nev;
    double Szelesseg;
    double Magassag;
    bool Wc;
    bool Bufe;

public:
    Allomas(std::string Nev = "Timbuktu", double x = -1, double y = -1, bool wc = false, bool bufe = false) : Nev(Nev), Szelesseg(x), Magassag(y), Wc(wc), Bufe(bufe) {};
    ~Allomas();

    std::string getAllomasNev() const;
    double getX() const;
    double getY() const;
    bool getWc() const;
    bool getBufe() const;
    Allomas *getNextNode() const;
    void operator+(Allomas *newAllomas);
};

#endif
