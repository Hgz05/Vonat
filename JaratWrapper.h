#ifndef JARATWRAPPER_H
#define JARATWRAPPER_H
#include "Jarat.h"


class JaratWrapper {
    Jarat* currJarat;
    JaratWrapper* nextNode;

    public:
    JaratWrapper(Jarat* JaratPtr = nullptr, JaratWrapper* nextJarat = nullptr) : currJarat(JaratPtr), nextNode(nextJarat){};
    ~JaratWrapper();
    Jarat* getJarat();
    JaratWrapper* getNextNode();
};



#endif //JARATWRAPPER_H
