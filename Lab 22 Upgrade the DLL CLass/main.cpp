#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// COMSC-210 | Lab 22: Upgrade the DLL Class | Erick Pascual-Bautista

int main() {
    // Test Driver Application
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> emptyList;
    
    // Test popFront on emptyList
    cout << "TEST POPPING FROM EMPTY LIST: " << endl << endl;

    try { // Should throw an error
        cout << "Popping front: " << list.popFront() << endl; 

    } catch(const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    try { // Should throw an error
        cout << "Popping back: " << list.popBack() << endl; 

    } catch(const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    // Pushing values into the list
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushBack(40);
    list.pushBack(50);

    cout << endl;

    // Testing popFront (10 value should be missing from the list)
    cout << "Popping front: (10 value should be missing from the list)" << endl;
    list.popFront();
    cout << "List after poping front: ";
    list.print();

    cout << endl;

    // Testing popBack (50 value should be missing from the list)
    cout << "Popping Back: (50 value should be missing from the list )" << endl;
    list.popBack();
    cout << "List after poping back: ";
    list.print();

    cout << endl;

    // Test deleteValue
    cout << "Deleting value 20." << endl;
    list.deleteValue(20);
    cout << "List after deleting 20: ";
    list.print();

    cout << endl;

    // Test deleValue empty list
    try {
        cout << "Deleting an empty list" << endl;
        emptyList.deleteValue(20);
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << endl;

    // Test deleteValue not found
    try {
        cout << "Deleting a value in which it isn't found" << endl;
        list.deleteValue(100);
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << endl;

    // Test deleteAt
    cout << "Deleting at position 0" << endl;
    list.deleteAt(0);
    cout << "List after deleting at position 0: ";
    list.print();

    cout << endl;

    // Test deleteAt invalid position
    try {
        cout << "Deleting at position 5 (invalid position)" << endl;
        list.deleteAt(5);
    }   catch(const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << endl;

    // Test deletAt empty 
    try {
        cout << "Deleting an empty list" << endl;
        emptyList.deleteAt(5);
    }   catch(const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }



    return 0;
}

