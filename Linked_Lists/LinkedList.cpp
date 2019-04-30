// linked list example - using struct inside a class

#include "pch.h"
#include <iostream>
#include <string>
#include "linkedListClass.h"

using namespace std;

int main() {
    int id;
    string name;
    linkedListClass myList;
    linkedListClass::node* ptr;

    // add
    ptr = myList.initNode("s1", 1);
    myList.addNode(ptr);
    ptr = myList.initNode("s2", 2);
    myList.addNode(ptr);
    ptr = myList.initNode("s3", 3);
    myList.addNode(ptr);
    ptr = myList.initNode("s4", 4);
    myList.addNode(ptr);
    ptr = myList.initNode("s5", 5);
    myList.addNode(ptr);
    myList.displayList(myList.head);

    // delete
    name = "s2";
    ptr = myList.searchName(myList.head, name);
    if(ptr == NULL) {
        cout << "\nName: " << name << " not found" << endl;
    }
    else {
        cout << "\nDeleting a node ...  ";
        myList.displayNode(ptr);
        myList.deleteNode(ptr);
    }
    myList.displayList(myList.head);

    // insert
    name = "s2";
    id = 2;
    ptr = myList.initNode(name, id);
    myList.insertNode(ptr);
    cout << "\nInserting a node ...  ";
    myList.displayNode(ptr);
    myList.displayList(myList.head);

    // reverse
    cout << "\nReversing the list ...  \n";
    myList.reverse();
    myList.displayList(myList.head);

    // delete
    cout << "\nIn the end, deleting the list ...  \n";
    myList.deleteList(myList.head);
    myList.displayList(myList.head);
    return 0;
}