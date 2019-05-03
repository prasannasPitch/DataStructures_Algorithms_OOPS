#pragma once

#include "pch.h"
#include <iostream>

class LinkedList {
    public:
        int key, value;
        LinkedList* next;
        LinkedList(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
};

