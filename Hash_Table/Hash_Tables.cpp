/*
 * C++ Program to Implement Hash Tables Chaining with List Heads
 */
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "LinkedList.h"
#include "hashMap.h"

using namespace std;
int main() {
    hashMap hash;
    int key, value;
    int choice;
    while(1) {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> value;
                cout << "Enter key at which element to be inserted: ";
                cin >> key;
                hash.Insert(key, value);
                break;
            case 2:
                cout << "Enter key of the element to be searched: ";
                cin >> key;
                if(hash.Find(key) == -1) {
                    cout << "No element found at key " << key << endl;
                }
                else {
                    cout << "Elements at key " << key << " : ";
                    cout << hash.Find(key) << endl;
                }
                break;
            case 3:
                cout << "Enter key of the element to be deleted: ";
                cin >> key;
                if(hash.Find(key) == -1) {
                    cout << "Key " << key << " is empty, nothing to delete" << endl;
                }
                else {
                    hash.Delete(key);
                    cout << "Entry Deleted" << endl;
                }
                break;
            case 4:
                exit(1);

            case 5:
                hash.Display();

            default:
                cout << "\nEnter correct option\n";
        }
    }
    return 0;
}