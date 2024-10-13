#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


template <typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* nextLink;
        Node() { 
            nextLink = nullptr;
        }
        Node(T data) { 
            this->data = data;
            nextLink = nullptr;
        }
    };

    Node* head;
    int currSize;

    public:
    // Default Constructor
    DoublyLinkedList(); 

    // Destructor
    ~DoublyLinkedList() {clear();}

    // Push methods
    void pushFront(const T&); 
    void pushBack(const T&);

    // Insert method
    void insertAfter(const T&, int);

    // Deletes latest element
    void pop();
    // Returns the latest element
    T peek(); 

    // Checks if list is empty
    bool isEmpty() {return (head == nullptr);}

    // returns the size of the list
    int size() {return currSize;}

    // Helper function for the destructor (pops all elements of the list)
    void clear();
};






template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    currSize = 0;
}

// template <typename T>
// void DoublyLinkedList<T>::pushFront(const T& data) {
//     Node* node = new Node(data);
//     node->nextLink = head;
//     head = node;
//     currSize++;

//     /*
//     This was my original implementation 
//     before I learned the easier way
    
//     if (isEmpty()) { // if list is empty
//         head = new Node(data);
//     }
//     else {
//         Node* node = new Node(data)
//         if (head->nextLink == nullptr){
//             head->nextLink = node;
//         }
//         else {
//             Node* tempNode = head->nextLink;
//             head->nextLink = node;
//             node->nextLink = tempNode;
//         }
//     }
// */
// }

// template <typename T>
// void DoublyLinkedList<T>::pushBack(const T& data) {
//     Node* node = new Node(data); 
//     if(isEmpty()) { 
//         head = node;
//     } else {
//         Node* temp = head;
//         while(temp->nextLink != nullptr) { 
//             temp = temp->nextLink;
//         }
//         temp->nextLink = node; 
//     }
//     currSize++;
// }

// template <typename T>
// void DoublyLinkedList<T>::pop() {
//     if (!isEmpty()) {
//         Node* tempPtr = head;
//         head = head->nextLink;
//         delete tempPtr;
//         currSize--;
//     }
// }

// template <typename T>
// T DoublyLinkedList<T>::peek() {
//     return head->data;
// }

// template <typename T>
// void DoublyLinkedList<T>::clear() {
//     while(!isEmpty()) { 
//         pop();
//     }
// }

#endif