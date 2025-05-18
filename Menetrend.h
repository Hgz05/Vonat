#ifndef MENETREND_H
#define MENETREND_H
#include "Allomas.h"
#include "Ido.h"
/**
 * Menetrend class.
 */
class Menetrend
{
    /**
     * The next node for the menetrend linked list.
     */
    Menetrend *nextNode = nullptr;
    /**
     * The allomas object for this menetrend.
     */
    Allomas *CurrAllomas;
    /**
     * Menetrend identification.
     */
    int MenetrendID;
    /**
     * Arrival time.
     */
    Ido *ErkezoIdo;
    /**
     * Departure time.
     */
    Ido *InduloIdo;
    /**
     * Original arrival time.
     */
    Ido *EredErkezoIdo;
    /**
     * Original departure time.
     */
    Ido *EredInduloIdo;

public:
    /**
     * Menetrend constructor.
     * @param MAllomas The allomas pointer.
     * @param ID Menetrend id.
     * @param ErkIdo Arrival time.
     * @param IndIdo Departure time.
     */
    explicit Menetrend(Allomas *MAllomas = nullptr, int ID = -1 ,Ido *ErkIdo = nullptr, Ido *IndIdo = nullptr);
    /**
     * The Arrival time getter.
     * @return Ido object.
     */
    Ido getErkezoIdo() const;
    /**
     * The departure time getter.
     * @return Ido object.
     */
    Ido getInduloIdo() const;
    /**
     * Allomas getter.
     * @return Allomas pointer.
     */
    Allomas *getAllomas() const;
    /**
     * It prints how much the train is late.
     */
    void printKeses();
    /**
     * Keses setter
     * @param Perc The keses by min.
     */
    void setKeses(int Perc);
    /**
     * It sets keses to all menetrends in the array.
     * @param Perc Kesese by min.
     */
    void setKesesToALl(int Perc);
    /**
     * Menetrend info printer.
     */
    void printInfo();
    /**
     * Menetrend info printer to all objects in the linked list.
     */
    void printAllInfo();
    /**
     * Next element of the linked list.
     * @return Menetrend pointer.
     */
    Menetrend *getNextNode();
    /**
     * Allomas finder by name.
     * @param Name Allomas name.
     * @return Allomas pointer by the name.
     */
    Allomas* FindAllomasByName(const std::string &Name);
    /**
     * Linked list to add method.
     * @param newMenetrend Menetrend to add.
     */
    void operator+(Menetrend *newMenetrend);
    /**
     * It deletes and element from the linked list.
     * @param curr First element of the linked list
     */
    void deleteElement(Menetrend *curr);
    /**
     * Menetrend destructor.
     */
    ~Menetrend();
};

#endif