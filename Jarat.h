#ifndef JARAT_H
#define JARAT_H
#include "Vonat.h"
#include "Menetrend.h"
#include <string>
/**
 * Jarat class.
 */
class Jarat
{
    /**
     * Name of the jarat.
     */
    std::string JNev;
    /**
     * Vonat pointer to the jarat.
     */
    Vonat *JVonat;
    /**
     * Linked list to menetrends.
     */
    Menetrend *MenetRendArray; // Linked list

public:
    /**
     * Jarat constructor
     * @param Nev Jarat name.
     * @param JVonat Vonat pointer.
     * @param ElsoAllomas First element of the linked list.
     */
    explicit Jarat(std::string Nev,Vonat *JVonat = nullptr, Menetrend *ElsoAllomas = nullptr);;
    /**
     * Jarat destructor.
     */
    ~Jarat();
    /**
     * Jarat name getter.
     * @return Name of the jart.
     */
    std::string getJaratName();
    /**
     * Jarat info printer.
     */
    void PrintJarat() const;
    /**
     * Vonat setter.
     * @param sVonat Vonat to set.
     */
    void setJVonat(Vonat *sVonat);
    /**
     * Vonat getter.
     * @return Vonat to get.
     */
    Vonat *getJVonat();
    /**
     * Menetrend linked list first element setter.
     * @param sFirstMenetrend The pointer of the firs element of the menetrend list to be set.
     */
    void setFirstMenetrend(Menetrend *sFirstMenetrend);
    /**
     * The first element of the linked list.
     * @return Meneterend pointer.
     */
    Menetrend *getFirstMenetrend();
};

#endif