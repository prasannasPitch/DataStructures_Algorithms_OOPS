#pragma once

#include <iostream>
#include <string>
using namespace std;

class linkedListClass {
    public:
        struct node {
            int id;
            string name;
            struct node* next;
        }* head, *tail, *ptr;

        linkedListClass() : head(NULL), tail(NULL) {}  // constructor
        ~linkedListClass();            // destructor


        //methods
        void reverse();
        void addNode(struct linkedListClass::node*);
        void insertNode(struct linkedListClass::node*);
        void deleteNode(struct linkedListClass::node*);
        void deleteList(struct linkedListClass::node*);
        void displayList(struct linkedListClass::node*)const;
        void displayNode(struct linkedListClass::node*) const;
        struct linkedListClass::node* searchName(struct linkedListClass::node*, string);
        struct linkedListClass::node* searchId(struct linkedListClass::node*, int);
        struct linkedListClass::node* initNode(string, int);
};

