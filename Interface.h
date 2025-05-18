#ifndef INTERFACE_H
#define INTERFACE_H
#include "JegyList.h"

struct Interface{
    static int InterfaceInit(Allomas* FirstAllomas, Vonat** VonatArray, JaratWrapper* FirstJarat, JegyList* JegyList);
};

#endif //INTERFACE_H
