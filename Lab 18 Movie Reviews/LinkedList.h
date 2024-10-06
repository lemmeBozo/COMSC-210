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
    }

    Node* head;
    int currSize;

    public:
    LinkedList();

    ~LinkedList() {clear();}

    void push(T&); // push element to the front of the list
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
void LinkedList<T>::push(T& data) {
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