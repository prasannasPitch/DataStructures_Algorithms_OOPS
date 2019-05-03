#pragma once

#include "pch.h"
#include <iostream>
#include "LinkedList.h"
const int TABLE_SIZE = 5;

class hashMap {
    private:
        LinkedList** htable;
    public:
        hashMap();
        ~hashMap();
        int HashFunc(int key);
        void Insert(int key, int value);
        int Find(int key);
        void Delete(int key);
        void Display();
};

