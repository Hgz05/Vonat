#ifndef JEGYLIST_H
#define JEGYLIST_H
#include "JaratWrapper.h"
#include "Jegy.h"
#include "HelyJegy.h"
class JegyList {
    Jegy** JegyArray = nullptr;
    int JegyArraySize = 0;

    public:
    explicit JegyList(Jegy* FirstJegy);
    explicit JegyList(HelyJegy *FirstHelyJegy);
    ~JegyList();
    void setJegyListSize(int size);
    int getJegyListSize() const;
    void AddToJEgyArray(Jegy* JegyToAdd);
    void DeleteFromJEgyArray(const Jegy* JegyToRemove);
    void BuyJegy(JaratWrapper* FirstJarat);
    void PrintJegyList() const;
    static JegyList* InitJegyList(JaratWrapper* FirstJarat, Allomas* FirstAllomas);
    static void SaveJegyList(JegyList* JegyList);
};



#endif //JEGYLIST_H
