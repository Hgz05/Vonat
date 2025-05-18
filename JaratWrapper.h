#ifndef JARATWRAPPER_H
#define JARATWRAPPER_H
#include "Jarat.h"


class JaratWrapper {
    Jarat* currJarat;
    JaratWrapper* nextNode = nullptr;

    public:
    JaratWrapper(Jarat* JaratPtr = nullptr) : currJarat(JaratPtr){};
    ~JaratWrapper();
    void PrintJarat() const;
    Jarat* getJarat();
    JaratWrapper* getNextNode();
    static JaratWrapper* InitJaratWrapper(Allomas* FirstAllomas, Vonat** VonatArray);
    static void SaveJaratWrapper(JaratWrapper* FistJarat);
    void operator+(JaratWrapper* newJaratWrapper);
    Jarat* FindJaratByName(const std::string &Nev);

};



#endif //JARATWRAPPER_H
