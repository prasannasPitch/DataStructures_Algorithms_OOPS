#include "pch.h"
#include "hashMap.h"

using namespace std;

hashMap ::hashMap() {
    htable = new LinkedList*[TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++) {
        htable[i] = NULL;
    }
}


hashMap::~hashMap() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(htable[i] != NULL) {
            LinkedList* prev = NULL;
            LinkedList* entry = htable[i];
            while(entry != NULL) {
                prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }
}


int hashMap::HashFunc(int key) {
    return key % TABLE_SIZE;
}

void hashMap::Insert(int key, int value) {
    LinkedList* newLinkedList = new LinkedList(key, value);;
    int hash_val = HashFunc(key);
    if(htable[hash_val] == NULL) {
        htable[hash_val] = new LinkedList(key, value);
    }
    else {
        LinkedList* entry = htable[hash_val];
        while(entry->next != NULL) {
            entry = entry->next;
        }
        if(entry->key == key) {
            entry->next = new LinkedList(key, value);

        }
        else {
            entry->next = new LinkedList(key, value);
        }
    }
}

int hashMap::Find(int key) {
    int hash_val = HashFunc(key);
    if(htable[hash_val] == NULL) {
        return -1;
    }
    else {
        LinkedList* entry = htable[hash_val];
        while(entry != NULL && entry->key != key) {
            entry = entry->next;
        }
        if(entry == NULL) {
            return -1;
        }
        else {
            return entry->value;
        }
    }
}

void  hashMap::Delete(int key) {
    int hash_val = HashFunc(key);
    if(htable[hash_val] != NULL) {
        LinkedList* entry = htable[hash_val];
        LinkedList* prev = NULL;
        while(entry->next != NULL && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }
        if(entry->key == key) {
            if(prev == NULL) {
                LinkedList* next = entry->next;
                delete entry;
                htable[hash_val] = next;
            }
            else {
                LinkedList* next = entry->next;
                delete entry;
                prev->next = next;
            }
        }
    }
}

void hashMap::Display() {

    cout << "*****************************Hash Table********************************" << endl;
    for(int i = 0; i < TABLE_SIZE; i++) {
        LinkedList* entry = htable[i];
        cout << "Table Position : " << i << endl;
        while(entry != NULL) {
            cout << "Values : " << entry->value << "          ";
            entry = entry->next;
        }
    }
}
