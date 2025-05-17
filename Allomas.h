#ifndef ALLOMAS_H
#define ALLOMAS_H
#include <string>
class Allomas
{
public:


private:
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
    void set_nev(const std::string nev);
    void set_szelesseg(const double szelesseg);
    void set_magassag(const double magassag);
    void set_wc(const bool wc);
    void set_bufe(const bool bufe);
    Allomas *getNextNode() const;
    void operator+(Allomas *newAllomas);

};

#endif
