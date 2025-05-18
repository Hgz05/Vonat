#ifndef INTERFACE_H
#define INTERFACE_H
#include "JegyList.h"

/**
 * A class that serves as the user interface.
 */
struct Interface{
    /**
     * Main UI initialisation, barebone of the function of this class.
     * @param FirstAllomas Allomas linked list.
     * @param VonatArray All the Vonat in an array.
     * @param FirstJarat Jarat linked list.
     * @param JegyList Jegy heterogen collection.
     * @return
     */
    static int InterfaceInit(Allomas* FirstAllomas, Vonat** VonatArray, JaratWrapper* FirstJarat, JegyList* JegyList);
    /**
     * Prints all the Jarat.
     * @param FirstJarat Jarat linked list.
     */
    static void JaratInterface(JaratWrapper *FirstJarat);
    /**
     * Jegy menu.
     * @param FirstJarat  Jarat linked list.
     * @param JegyList Jegy heterogen collection.
     */
    static void JegyListInterface(JaratWrapper *FirstJarat, JegyList* JegyList);
    /**
     * Manager menu.
     * @param VonatArray Al the Vonat in an array.
     * @param FirstJarat Jarat linked list.
     */
    static void ManagerInterface(Vonat **VonatArray, JaratWrapper *FirstJarat);
    /**
     * User input checker.
     * @return Return int value.
     */
    static int UserInputChecker();
};

#endif //INTERFACE_H
