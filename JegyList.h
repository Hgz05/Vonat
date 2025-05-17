#include "Jegy.h"
#ifndef JEGYLIST_H
#define JEGYLIST_H
class JegyList {
    Jegy** JegyArray = nullptr;
    int JegyArraySize = 0;
    public:
    JegyList(Jegy* FirstJegy);
    ~JegyList();
    void setJegyListSize(int size);
    int getJegyListSize();
    void AddToJEgyArray(Jegy* JegyToAdd);
    void DeleteFromJEgyArray(Jegy* JegyToRemove);



};



#endif //JEGYLIST_H
