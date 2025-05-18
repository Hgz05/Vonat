#ifndef ALLOMAS_H
#define ALLOMAS_H
#include <string>
#include <utility>
/**
 * Allomas class.
 */
class Allomas
{
    /**
     * Allomas linked list next node.
     */
    Allomas *nextNode = nullptr;
    /**
     * Name of the allomas.
     */
    std::string Nev;
    /**
     * Geographical latitude of the allomas.
     */
    double Szelesseg;
    /**
     * Geographical longitude of the allomas.
     */
    double Magassag;
    /**
     * Is there a toalet in the station.
     */
    bool Wc;
    /**
     * Is there a cafeteria in the station.
     */
    bool Bufe;

public:
    /**
     * Allomas constructor.
     * @param Nev Name of the allomas.
     * @param x Geographical latitude of the allomas.
     * @param y Geographical longitude of the allomas.
     * @param wc Is there a toalet in the station.
     * @param bufe Is there a cafeteria in the station.
     */
    explicit Allomas(std::string Nev = "Timbuktu", double x = -1, double y = -1, bool wc = false, bool bufe = false) : Nev(std::move(Nev)), Szelesseg(x), Magassag(y), Wc(wc), Bufe(bufe) {};
    /**
     * Allomas destructor.
     */
    ~Allomas();

    /**
     * Name getter.
     * @return Name of the allomas.
     */
    std::string getAllomasNev() const;
    /**
     * X cord getter.
     * @return X cord.
     */
    double getX() const;
    /**
     * Y cord getter.
     * @return Y cord.
     */
    double getY() const;
    /**
     * Is there restroom getter.
     * @return Bool value.
     */
    bool getWc() const;
    /**
     * Is there cafeteria getter.
     * @return Bool value.
     */
    bool getBufe() const;
    /**
     * Getter of the next node of the array.
     * @return The next nodo of the allmas array.
     */
    Allomas *getNextNode();
    /**
     * Delete all Allomas.
     */
    void DelAllomas();

    /**
     * Next node setter.
     * @param nextNode Next node to set.
     */
    void setNextNode(Allomas *nextNode);
    /**
     * Adds an allomas at the end of the linked list.
     * @param newAllomas Allomas pointer to add.
     */
    void operator+(Allomas *newAllomas);
    /**
     * Delete an element of the linked list.
     * @param AllomasToDelete Pointer to delete.
     * @param ElsoAllomas First element of the array.
     * @return The First elemnt of the array in case the first is element is to delete.
     */
    Allomas* AllomasDelete (Allomas *AllomasToDelete, Allomas* ElsoAllomas);
    /**
     * Initialiton of the allomas class initiates file read.
     * @return
     */
    static Allomas* InitAllomas();
    /**
     * Searches for allomay by name.
     * @param Nev The searched allomas's name.
     * @return The allomas with the name.
     */
    Allomas* FindAllomasByName(const std::string& Nev);
};

#endif
