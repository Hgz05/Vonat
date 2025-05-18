#ifndef INTERFACE_H
#define INTERFACE_H
#include "JegyList.h"

struct Interface{
    static int InterfaceInit(Allomas* FirstAllomas, Vonat** VonatArray, JaratWrapper* FirstJarat, JegyList* JegyList);
    static void JaratInterface(JaratWrapper const *FirstJarat);
    static void JegyListInterface();
    static void ManagerInterface();
    static int UserInputChecker();
};

#endif //INTERFACE_H
