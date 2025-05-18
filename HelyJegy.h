#ifndef HELYJEGY_H
#define HELYJEGY_H
#include "Jegy.h"
/**
 * Child clas of Jegy.
 */
class HelyJegy : public Jegy
{
    /**
     * The seat number.
     */
    int UlesSzam;
    
public:
    /**
     * HelyJegy contsructor.
    *  @param FelJarat The Jarat pointer to the associated jarat.
     * @param Elso First station pointer.
     * @param Utolso Last station pointer.
     * @param Ar Price of the ticket.
     * @param Ules The seat number.
     */
    explicit HelyJegy(Jarat *FelJarat = nullptr, Allomas *Elso = nullptr, Allomas *Utolso = nullptr, int Ar = -1, int Ules = -1) : Jegy(FelJarat,Elso,Utolso,Ar), UlesSzam(Ules){};
    /**
     * Copy constructor.
     * @param CopyHelyJegy HelyJegy to copy.
     */
    explicit HelyJegy(HelyJegy* CopyHelyJegy): Jegy(CopyHelyJegy), UlesSzam(CopyHelyJegy->UlesSzam){};
    /**
     * Copy method used in array functions.
     * @return Cloned Jegy.
     */
    Jegy* Clone() override;
    /**
     * Method used in file writing.
     * @return String to write.
     */
    std::string FileToWrite() override;
    /**
     * Ules Szam getter.
     * @return Ules szam to get.
     */
    int getUlesSzam() const;
    /**
     * HelyJegy destructor.
     */
    ~HelyJegy() override = default;
    /**
     * Jegy printer.
     */
    void PrintJegy() const override;

};
#endif // HELYJEGY_H
