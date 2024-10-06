#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// This is my own personal linked list that I created for another class
// I hope you don't mind that I used this for the assignment

template <typename T>
class LinkedList {
    // private
    struct Node {
        T data;
        Node* nextLink;
        Node(T data) {
            this->data = data;
            nextLink = nullptr;
        }
    };

    Node* head;
    int currSize;

    public:
    LinkedList();

    ~LinkedList() {clear();}

    void pushFront(T&); // push element to the front of the list

   void pushBack(T&); // ADDING A NEW METHOD (for the lab since items can either be added to front or back of list)

    void pop(); // remove first element from the list
    T peek(); // returns the value of the first element
    bool isEmpty() {return (head == nullptr);}
    int size() {return currSize;}
    void clear();
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    // more code goes here
    currSize = 0;
}

template <typename T>
void LinkedList<T>::pushFront(T& data) {
    Node* node = new Node(data);
    node->nextLink = head;
    head = node;
    currSize++;

    /*
    This was my original implementation 
    before I learned the easier way
    
    if (isEmpty()) { // if list is empty
        head = new Node(data);
    }
    else {
        Node* node = new Node(data)
        if (head->nextLink == nullptr){
            head->nextLink = node;
        }
        else {
            Node* tempNode = head->nextLink;
            head->nextLink = node;
            node->nextLink = tempNode;
        }
    }
*/
}

template <typename T>
void LinkedList<T>::pushBack(T& data) {
    Node* node = new Node(data); // creates a new node with the data
    if(isEmpty()) { // If the list is emetpy
        head = node;
    } else {
        Node* temp = head;
        while(temp->nextLink != nullptr) { // traverese the linked list untill we reach the last element
            temp = temp->nextLink;
        }
        temp->nextLink = node; // once last element is reached we set it equal to nextLink
    }
    currSize++;
}

template <typename T>
void LinkedList<T>::pop() {
    if (!isEmpty()) {
        Node* tempPtr = head;
        head = head->nextLink;
        delete tempPtr;
        currSize--;
    }
}

template <typename T>
T LinkedList<T>::peek() {
    return head->data;
}

template <typename T>
void LinkedList<T>::clear() {
    while(!isEmpty()) { 
        pop();
    }
}

#endif