#ifndef JEGYLIST_H
#define JEGYLIST_H
#include "JaratWrapper.h"
#include "Jegy.h"
class JegyList {
    Jegy** JegyArray = nullptr;
    int JegyArraySize = 0;

    public:
    JegyList(Jegy* FirstJegy);
    ~JegyList();
    void setJegyListSize(int size);
    int getJegyListSize() const;
    void AddToJEgyArray(Jegy* JegyToAdd);
    void DeleteFromJEgyArray(Jegy* JegyToRemove);
    static JegyList* InitJegyList(JaratWrapper* FirstJarat, Allomas* FirstAllomas);
};



#endif //JEGYLIST_H
