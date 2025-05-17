#ifndef IDO_H
#define IDO_H
struct Ido {
    int ora;
    int perc;

public:
    Ido(int ora = 0, int perc = 0) : ora(ora), perc(perc) {}
    explicit Ido(Ido* CIdo) {
        ora = CIdo->ora;
        perc = CIdo->perc;
    }
    Ido operator-(Ido const &Alapido) const;
    bool operator==(Ido const &Alapido) const;
    void operator+(int min);
    void printTime() const;
};

#endif