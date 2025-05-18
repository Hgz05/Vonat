#ifndef VONAT_H
#define VONAT_H
#include "Kocsi.h"
#include <string>
/**
 * This enum indicates the VonatTypes
 */
enum eVonatTipus
{
    InterCity,
    Gyors,
    Zonazo,
    Szemelyi
};
/**
 * Vonat Class
 */
class Vonat
{
    /**
     * Stores the vonat type enum.
     */
    eVonatTipus VonatTipus;
    /**
     * Int assigned to the Vonat.
     */
    int VonatSzam;
    /**
     * The first element of a linked list that stores Kocsi Classes.
     */
    Kocsi *KocsiArray;
    /**
     * The maximum amount of speed the train can go.
     */
    int MaxSeb;
    /**
     * The age of the train.
     */
    int Kor;
    /**
     * The number of cars attached to the train.
     */
    int KocsiDarab;
    /**
     * A static intiger that indicates the amount of trains that are currently exist.
     */
    static int VonatArraySize;

public:

    /**
     *Vonat constructor.
     * @param VonatTipus The type of the train.
     * @param VonatSzam An intiger assigned to the train.
     * @param KocsiArray A linked list that stores Kocsi classes.
     * @param MaxSeb Maximum speed the train can go.
     * @param KocsiDarab Amount of cars attached to the train.
     * @param Kor Age of the train.
     */
    explicit Vonat(eVonatTipus VonatTipus = Szemelyi, int VonatSzam = 1, Kocsi *KocsiArray = nullptr, int MaxSeb = 80, int KocsiDarab = 10, int Kor = 45) : VonatTipus(VonatTipus), VonatSzam(VonatSzam), KocsiArray(KocsiArray), MaxSeb(MaxSeb), KocsiDarab(KocsiDarab), Kor(Kor) {};
    /**
     * Vonat copyconstructor.
     * @param VonatCopy Vonat class to copy.
     */
    explicit Vonat(Vonat* VonatCopy);

    /**
     * Cipies the kocsio array.
     * @param NextNode The next node of the kocsi array.
     * @return The kocsi pointer.
     */
    static Kocsi* copyKocsiArray(Kocsi* NextNode);
    /**
     * Vonat destructor.
     */
    ~Vonat();

    /**
     * This deletes the whole kocsi array.
     * @param ArrayElement The first element of the kocsi array.
     */
    static void DeleteKocsiArray(Kocsi* ArrayElement);

    /**
     * Vonat type getter.
     * @return Vonat type.
     */
    eVonatTipus getVonatTipus() const;
    /**
     * String to vonat type converter.
     * @param VonatTipus String representation of vonat type.
     * @return Vonat type.
     */
    static eVonatTipus stringToVonatTipus(const std::string& VonatTipus);

    /**
     * Vonat type to string converter.
     * @param type The type of the vonat.
     * @return String representation of the vonat type.
     */
    static std::string enumToString(eVonatTipus type);

    /**
     * Vonat szam getter.
     * @return VonatSzam.
     */
    int getVonatSzam() const;
    /**
     * Current kocsi getter.
     * @return Current kocsi.
     */
    Kocsi *getKocsi();
    /**
     * Max speed getter.
     * @return Max sepeed.
     */
    int getMaxSeb() const;
    /**
     * Amount of cars getter.
     * @return Amount of cars attached to train.
     */
    int getKocsiDarab() const;
    /**
     * Age getter.
     * @return Age of the train.
     */
    int getKor() const;
    /**
     * Vonat statistics printer used for user interface.
     */
    void printVonatStat() const;
    /**
     * Checks if the string's characters are in the alfabet.
     * @param VString Input string.
     * @return True of False.
     */
    static int CheckStringInt(std::string VString);
    /**
     * Finds a kocsi pointer by an int value
     * @param KocsiSzam The search parameter.
     * @return The kocsi pointer.
     */
    Kocsi* FindKocsiBySzam(int KocsiSzam);
    /**
     * This method creates a new Vonat object. It is used by the user interface and it requires user input.
     * @param VonatArray The array that stores the Vonat objects.
     * @return The Vonat array.
     */
    static Vonat** CreateNewVonat(Vonat** VonatArray);
    /**
     * This function initialises the Vonat. It reads from file and stores it in the VonatArray.
     * @return The vonat array.
     */
    static Vonat** InitVonat();
    /**
     * This function saves the data to a file.
     * @param VonatArray The vonat array.
     */
    static void SaveVonat(Vonat** VonatArray);
    /**
     * Adds a vonat object to the vontat array.
     * @param VonatArray The vonat array.
     * @param VonatToAdd The vonat object to be added to the arra.
     * @return The new vonat array.
     */
    static Vonat** AddToVonatArray(Vonat** VonatArray, Vonat* VonatToAdd);
    /**
     * Removes an object from the vonat array.
     * @param VonatArray The vonat array.
     * @param VonatToRemove Object to be removed from the vonat array.
     * @return The new vonat array.
     */
    static Vonat** RemoveFromVonatArray(Vonat** VonatArray, Vonat* VonatToRemove);
    /**
     * This function finds a vonat by a number in the vonat array.
     * @param VonatArray The vonat array.
     * @param VonatNumber The number of the searched object.
     * @return The vonat pointer of the number.
     */
    static Vonat* FindVonatByNumber(Vonat** VonatArray, int VonatNumber);
};

#endif