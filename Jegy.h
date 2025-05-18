#ifndef JEGY_H
#define JEGY_H
#include "Jarat.h"
#include "Allomas.h"
/**
 * Jegy Class used for tickets.
 */
class Jegy
{
    /**
     * The Jarat pointer to the associated jarat.
     */
    Jarat *JJarat;
    /**
     * First station pointer.
     */
    Allomas *ElsoAllomas;
    /**
     * Last station pointer.
     */
    Allomas *VegAllomas;
    /**
     * Price of the ticket.
     */
    int Jegyar;

public:
    /**
     * Jarat Constructor.
     * @param FelJarat The Jarat pointer to the associated jarat
     * @param Elso First station pointer.
     * @param Utolso Last station pointer.
     * @param Ar Price of the ticket.
     */
    explicit Jegy(Jarat *FelJarat = nullptr, Allomas *Elso = nullptr, Allomas *Utolso = nullptr, int Ar = -1) : JJarat(FelJarat), ElsoAllomas(Elso), VegAllomas(Utolso), Jegyar(Ar) {};
    /**
     * Copy constructor.
     * @param CopyJegy Jegy to be copied.
     */
    explicit Jegy(Jegy* CopyJegy);
    /**
     * Clone method used in the array functions
     * @return Cloned Jegy.
     */
    virtual Jegy* Clone();
    /**
     * Jegy destructor.
     */
    virtual ~Jegy() = default;
    /**
     * Jarat getter.
     * @return The associated jarat.
     */
    Jarat* getJarat();
    /**
     * Helper method in the file write sequence.
     * @return String to write.
     */
    virtual std::string FileToWrite();
    /**
     * First station getter.
     * @return First station.
     */
    Allomas* getElsoAllomas();
    /**
     * Last station getter.
     * @return Last station.
     */
    Allomas* getVegAllomas();
    /**
     * Jegy price getter.
     * @return Jegy price.
     */
    int getJegyAr() const;
    /**
     * Jegy printer.
     */
    virtual void PrintJegy() const;
};
#endif // JEGY_H
