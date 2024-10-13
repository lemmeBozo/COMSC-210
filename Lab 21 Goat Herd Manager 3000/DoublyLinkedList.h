#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// I have a general question about linked list
// I have always been confused on the distinction between lists, queues and stacks
// like my code below just feels like a mix of a queue / stack 

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

    // Destructor
    ~DoublyLinkedList() {clear();}

    // Push methods
    void pushFront(const T&); 
    void pushBack(const T&);

    // Insert method
    void insertAfter(const T&, int);

    // Deletes methods
    void pop();
    void deleteNode(const T&);

    // Returns the latest element
    T peek(); 

    // Checks if list is empty
    bool isEmpty() {return (head == nullptr);}

    // returns the size of the list
    int size() {return currSize;}

    // Helper function for the destructor (pops all elements of the list)
    void clear();

    // Prints methods
    void print();
    void printReverse();

};


// Methods to implement
// insertAfter()
// deleteNode()
// print()
// printReverse();

template <typename T>
void DoublyLinkedList<T>::insertAfter(const T& data, int position) {
    if (position < 0) {
        cout << "Position must be >= 0" << endl;
        return;
    }

    Node* node new Node(data);
    if (!head) {
        head = tail = newNode;
        return
    }

    Node* temp = head;
    for (int i = 0; i < position && temp; i++) { // traverse the list until it reaches the desired position
        temp = temp->nextLink;
    }

    if (!temp) { // if node is out of range (caused from the above) then deletes node and returns
        cout << "Position exceeds list size. Node not inserted." << endl;
        delete newNode;
        return
    }

    // otherwise do the following
    node->nextLink = temp->nextLink;
}

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

template <typename T>
void DoublyLinkedList<T>::pop() {
    if (!isEmpty()) {
        Node* tempPtr = head;
        head = head->nextLink;
        delete tempPtr;
        currSize--;
    }
}

template <typename T>
T DoublyLinkedList<T>::peek() {
    return head->data;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while(!isEmpty()) { 
        pop();
    }
}

#endif