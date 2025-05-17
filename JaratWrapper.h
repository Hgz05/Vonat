#ifndef JARATWRAPPER_H
#define JARATWRAPPER_H
#include "Jarat.h"


class JaratWrapper {
    Jarat* currJarat;
    JaratWrapper* nextNode;

    public:
    JaratWrapper(Jarat* JaratPtr = nullptr) : currJarat(JaratPtr){};
    ~JaratWrapper();
    Jarat* getJarat();
    JaratWrapper* getNextNode();
    static JaratWrapper* JaratWrapperInit(Allomas* FirstAllomas, Vonat** VonatArray);
    void operator+(JaratWrapper* newJaratWrapper);
};



#endif //JARATWRAPPER_H
