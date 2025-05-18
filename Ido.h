#ifndef IDO_H
#define IDO_H
/**
 * Ido struct for menternd
 */
struct Ido {
    /**
     * Hour.
     */
    int ora;
    /**
     * Minute.
     */
    int perc;

public:
    /**
     * Constructor.
     * @param ora Hour.
     * @param perc Min.
     */
    explicit Ido(int ora = 0, int perc = 0) : ora(ora), perc(perc) {}
    /**
     * Copy constructor.
     * @param CopyIdo Ido to copy.
     */
    explicit Ido(Ido* CopyIdo) {
        ora = CopyIdo->ora;
        perc = CopyIdo->perc;
    }
    /**
     * Subtraction.
     * @param Alapido Time to subtract.
     * @return Subtracted time.
     */
    Ido operator-(Ido const &Alapido) const;
    /**
     * Compares two time objects.
     * @param Alapido Time to evaluate.
     * @return Bool value.
     */
    bool operator==(Ido const &Alapido) const;
    /**
     * Add time.
     * @param min Minutes to add.
     */
    void operator+(int min);
    /**
     * Prints time.
     */
    void printTime() const;
};

#endif