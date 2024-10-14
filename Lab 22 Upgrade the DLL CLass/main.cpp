#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// COMSC-210 | Lab 22: Upgrade the DLL Class | Erick Pascual-Bautista

int main() {
    // Test Driver Application
    DoublyLinkedList<int> list;
    
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

    // Test deleteValue

    return 0;
}
