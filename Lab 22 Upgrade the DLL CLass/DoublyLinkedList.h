#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;
// Question isn't our linked list below really just a stack/queue because we have pop back and front methods that again either act like a stack or a queue
// the same can be said for our push methods
template <typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* nextLink;
        Node* prevLink;
        Node() { 
            data = T();
            nextLink = nullptr;
            prevLink = nullptr;
        }
        Node(T data) { 
            this->data = data;
            nextLink = nullptr;
            prevLink = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int currSize;

    public:
    // Default Constructor
    DoublyLinkedList(); 

    // Push methods
    void pushFront(const T&); 
    void pushBack(const T&);

    // Insert method
    void insertAfter(const T&, int);

    // Deletes methods
    void deleteValue(const T&);
    void deleteAt(int);

    // Pop methods
    T popFront();
    T popBack();


    // Checks if list is empty
    bool isEmpty() {return (head == nullptr);}

    // returns the size of the list
    int size() {return currSize;}

    // Prints methods
    void print();
    void printReverse();

    // Destructor
    ~DoublyLinkedList();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    currSize = 0;
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T& data) {
    Node * node = new Node(data);
    if(isEmpty()) { // if the list is empty
        head = tail = node; 
    } else { // if the list is not empty 
        node->nextLink = head;
        head->prevLink = node;
        head = node;
    }
    currSize++;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T& data) {
    Node* node = new Node(data); 
    if(isEmpty()) { 
        head = tail = node;
    } else {
        tail->nextLink = node;
        node->prevLink = tail;
        tail = node;
    }
    currSize++;
}

// FIX THE BELOW METHOD IF IT DOESN"T WORK
template <typename T>
void DoublyLinkedList<T>::insertAfter(const T& data, int position) {
    if (position < 0) {
        cout << "Position must be >= 0" << endl;
        return;
    }

    Node* node = new Node(data);
    if (isEmpty()) {
        head = tail = node;
        return;
    }

    if (position == currSize) {
        pushBack(data);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position && temp; i++) { // traverse the list until it reaches the desired position
        temp = temp->nextLink;
    }

    if (!temp) { // if node is out of range (caused from the above) then deletes node and returns
        cout << "Position exceeds list size. Node not inserted." << endl;
        delete node;
        return;
    }

    // otherwise perform the following
    node->nextLink = temp->nextLink;
    node->prevLink = temp;
    if (temp->nextLink) {
        temp->nextLink->prevLink = node;
    } else {
        tail = node;
    }
    temp->nextLink = node;
    currSize++;
}

template <typename T>
void DoublyLinkedList<T>::deleteValue(const T& data) {
    if(isEmpty()) {return;} // if array is empty returns (can't delete everything)

    Node* temp = head;
    while (temp && temp->data != data) {
        temp = temp->nextLink;
    }

    if (!temp) {return;} // value not found

    // Adjusts the previous node's next link
    if (temp->prevLink) {
        temp->prevLink->nextLink = temp->nextLink;
    } else {
        head = temp->nextLink;
    }

    // Adjusts the next node's previous link
    if (temp->nextLink) {
        temp->nextLink->prevLink = temp->prevLink;
    } else {
        tail = temp->prevLink;
    }
    delete temp;
    currSize--;
}

template <typename T>
void DoublyLinkedList<T>::deleteAt(int position) {

    // Case 1: List is empty
    if(isEmpty()) {return;} // do nothing if true

    // Case 2: Position is out of bounds
    if (position < 0 || position >= this->size()) {return;} // do nothing if true

    Node* current = head;

    // Traverse through the linked list 
    for (int i = 0; i < position; i++) { // Case 3: Position is found
        current = current->nextLink;
    }

    // Case 3.1: Position is the first element
    if (current == head) {
        head = head->nextLink; // sets head equal to the next element
        if (head != nullptr) { // if the list is not empty
            head->prevLink = nullptr; // Update the new head's prev
        }
        delete current;
        currSize--;
    }
    
    // Case 3.2: Position is the last element
    else if (current->nextLink == nullptr) { 
        current->prevLink->nextLink = nullptr; // updates the 2nd to last node
        delete current;
        currSize--;
    }

    // Case 3.3: Position has both next and prev links
    else {
        current->prevLink->nextLink = current->nextLink;
        current->nextLink->prevLink = current->prevLink;
        delete current;
        currSize--;
    }
};

template <typename T>
T DoublyLinkedList<T>::popFront() {
    if (isEmpty()) {throw runtime_error("Error: Cannot pop from an empty list");} // Case 1: List is empty (Throw an exception)

    Node* temp = head; // Stores the pointer for the head
    T value = temp->data; // Stores the data value at the head

    // Case 2: List has only one element
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else { // Case 3: List has more than one element
        head = head->nextLink;
        head->prevLink = nullptr;
    }
    delete temp;
    currSize--;
    return value;
}

template <typename T>
T DoublyLinkedList<T>::popBack() {
    if (isEmpty()) {throw runtime_error("Error: Cannot pop from an empty list");} // Case 1: List is empty (Throw an exception)

    Node* temp = tail;
    T value = temp->data;

    // Case 2: List has only one element
    if (head ==tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prevLink;
        tail->nextLink = nullptr;    
    }
    delete temp;
    currSize--;
    return value;
}

// MAKE SURE TO OVERLOAD << for any data that is a class
template <typename T>
void DoublyLinkedList<T>::print() {
    Node* current = head;
    if (!current) {return;}
    while (current) {
        cout << current->data << " ";
        current = current->nextLink;
    }
    cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::printReverse() {
    Node* current = tail;
    if (!current) {return;}
    while (current) {
        cout << current->data << " ";
        current = current->prevLink;
    }
    cout << endl;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(head) {
        Node* temp = head;
        head = head->nextLink;
        delete temp;
    }
}

#endif