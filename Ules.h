#ifndef ULES_H
#define ULES_H
/**
 * The ules class.
 */
class Ules
{
    /**
     * The number of the ules.
     */
    int UlesSzam = 0;
    /**
     * If the ules is next to a window.
     */
    bool AblakMel = false;
    /**
     * If the ules is taken.
     */
    bool Szabad = true;

public:
    /**
     * Ules constructor.
     */
    Ules() = default;
    /**
     * Ules destructor.
     */
    ~Ules() = default;
    /**
     * Ules copy constructor.
     * @param UlesCopy Ules to be copied.
     */
    explicit Ules(Ules* UlesCopy) {
        UlesSzam = UlesCopy->UlesSzam;
        AblakMel = UlesCopy->AblakMel;
        Szabad = UlesCopy->Szabad;
    }
    /**
     * Ules number getter.
     * @return The ules number.
     */
    int getUlesSzam() const;
    /**
     * Next to window getter.
     * @return bool value.
     */
    bool getAblakMel() const;
    /**
     * Is free getter.
     * @return bool value.
     */
    bool getSzabad() const;
    /**
     * Is free settter.
     */
    void setSzabad();
    /**
     * Ules num setter
     * @param szam the number of the seat.
     */
    void setUlesSzam(int szam);
    /**
     * Next to window setter.
     * @param ablak bool value.
     */
    void setAblakmel(bool ablak);
};

#endif