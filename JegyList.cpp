#include "JegyList.h"

JegyList::JegyList(Jegy *FirstJegy) {
    if (FirstJegy == nullptr) {
        throw "FirstJegy is null!";
    }
    JegyArray = new Jegy*[1];
    JegyArray[0] = FirstJegy;
    JegyArraySize = 1;
}

JegyList::~JegyList() {
}

void JegyList::setJegyListSize(int size) {
    JegyArraySize = size;
}

int JegyList::getJegyListSize() {
    return JegyArraySize;
}

void JegyList::AddToJEgyArray(Jegy *JegyToAdd) {
    if (JegyToAdd == nullptr) {
        throw "JegyToAdd is null!";
    }
    Jegy** NewJegyArray = new Jegy*[JegyArraySize+1];
    for (int i = 0; i < JegyArraySize; i++) {
        NewJegyArray[i] = new Jegy(JegyArray[i]);
    }
    delete[] JegyArray;
    NewJegyArray[JegyArraySize] = JegyToAdd;
    setJegyListSize(getJegyListSize() + 1);
    JegyArray = NewJegyArray;
}

void JegyList::DeleteFromJEgyArray(Jegy *JegyToRemove) {
    if (JegyToRemove == nullptr) {
        throw "JegyToRemove is null!";
    }
    int j = 0;
    Jegy** NewJegyArray = new Jegy*[JegyArraySize-1];
    for (int i = 0; i < JegyArraySize; i++) {
        if (JegyArray[i] != JegyToRemove) {
            NewJegyArray[j] = new Jegy(JegyArray[i]);
            j++;
        }
    }
    setJegyListSize(getJegyListSize() - 1);
    delete[] JegyArray;
    JegyArray = NewJegyArray;
}
