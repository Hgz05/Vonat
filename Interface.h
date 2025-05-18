#ifndef INTERFACE_H
#define INTERFACE_H
#include "JegyList.h"

struct Interface{
    static int InterfaceInit(Allomas* FirstAllomas, Vonat** VonatArray, JaratWrapper* FirstJarat, JegyList* JegyList);
    static void JaratInterface(JaratWrapper *FirstJarat);
    static void JegyListInterface(JaratWrapper *FirstJarat, JegyList* JegyList);
    static void ManagerInterface(Vonat **VonatArray, JaratWrapper *FirstJarat);
    static int UserInputChecker();
};

#endif //INTERFACE_H
