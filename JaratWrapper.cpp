//
// Created by hgz05 on 2025. 05. 17..
//

#include "JaratWrapper.h"

JaratWrapper::~JaratWrapper() {
    if (nextNode != nullptr) {
        delete nextNode;
    }
    delete this;
}

Jarat * JaratWrapper::getJarat() {
    return currJarat;
}

JaratWrapper * JaratWrapper::getNextNode() {
    return nextNode;
}
