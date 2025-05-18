#ifndef JEGYLIST_H
#define JEGYLIST_H
#include "JaratWrapper.h"
#include "Jegy.h"
#include "HelyJegy.h"
/**
 * A class for heterogen collection for the Jegy class and it's child.
 */
class JegyList {
    /**
     * Heterogen collection to Jegy class.
     */
    Jegy** JegyArray = nullptr;
    /**
     * The size of the collection.
     */
    int JegyArraySize = 0;

    public:
    /**
     * JegyList constructor
     * @param FirstJegy First jegy to add to the collection.
     */
    explicit JegyList(Jegy* FirstJegy);
    /**
     * JegyList constructor.
     * @param FirstHelyJegy First helyjegy to add to the collection.
     */
    explicit JegyList(HelyJegy *FirstHelyJegy);
    /**
     * JegyList destructor.
     */
    ~JegyList();
    /**
     * JegyList size setter.
     * @param size  intiger value.
     */
    void setJegyListSize(int size);
    /**
     * JegyList size getter.
     * @return The size of the array.
     */
    int getJegyListSize() const;
    /**
     * Adder to the array.
     * @param JegyToAdd New Jegy to add to the array.
     */
    void AddToJEgyArray(Jegy* JegyToAdd);
    /**
     * Deeleter from the array.
     * @param JegyToRemove Jegy to delete from the array.
     */
    void DeleteFromJEgyArray(const Jegy* JegyToRemove);
    /**
     * User interface method to add new Jegy to the array.
     * @param FirstJarat The Jarat array.
     */
    void BuyJegy(JaratWrapper* FirstJarat);
    /**
     * Jegy printer to iostream.
     */
    void PrintJegyList() const;
    /**
     * JegyList initialiser used for file read.
     * @param FirstJarat The Jarat Array.
     * @param FirstAllomas The Allomas Array.
     * @return The Heterogen Collection.
     */
    static JegyList* InitJegyList(JaratWrapper* FirstJarat, Allomas* FirstAllomas);
    /**
     * Jegy list file write.
     * @param JegyList The list for the file write.
     */
    static void SaveJegyList(JegyList* JegyList);
};



#endif //JEGYLIST_H
