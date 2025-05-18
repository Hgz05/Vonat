#ifndef JARATWRAPPER_H
#define JARATWRAPPER_H
#include "Jarat.h"


/**
 * A wrapper class that stores the Jarat objects.
 */
class JaratWrapper {
    /**
     * The Jarat stored in this object.
     */
    Jarat* currJarat;
    /**
     * Next node of the linked list.
     */
    JaratWrapper* nextNode = nullptr;

    public:
    /**
     * Jarat wrapper constructor.
     * @param JaratPtr Jarat to assign.
     */
    explicit JaratWrapper(Jarat* JaratPtr = nullptr) : currJarat(JaratPtr){};
    /**
     * JaratWrapper destructor.
     */
    ~JaratWrapper();
    /**
     * Deletes all jarat Wrapper.
     */
    void DelJaratWrapper();
    /**
     * Jarat Printer.
     */
    void PrintJarat();
    /**
     * Jarat getter.
     * @return Jarat to get.
     */
    Jarat* getJarat();
    /**
     * Next node getter.
     * @return next node.
     */
    JaratWrapper* getNextNode();
    /**
     * Initialiser used in file read.
     * @param FirstAllomas The array of all the Allomas.
     * @param VonatArray The array of all the Vonat.
     * @return First JaratWrapper pointer.
     */
    static JaratWrapper* InitJaratWrapper(Allomas* FirstAllomas, Vonat** VonatArray);
    /**
     * Adds an element to the end of the JaratWrapper linked list.
     * @param newJaratWrapper Element to add.
     */
    void operator+(JaratWrapper* newJaratWrapper);
    /**
     * Jarat finder by name.
     * @param Nev Name of the jarat.
     * @return Pointer of the searched jarat.
     */
    Jarat* FindJaratByName(const std::string &Nev);
    /**
     * Add keses to the jarat.
     */
    void AddKeses();

};



#endif //JARATWRAPPER_H
