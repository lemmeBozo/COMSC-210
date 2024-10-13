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
    ~DoublyLinkedList();

    // Push methods
    void pushFront(const T&); 
    void pushBack(const T&);

    // Insert method
    void insertAfter(const T&, int);

    // Deletes methods
    void deleteNode(const T&);

    // Checks if list is empty
    bool isEmpty() {return (head == nullptr);}

    // returns the size of the list
    int size() {return currSize;}

    // Prints methods
    void print();
    void printReverse();

};


// Methods to implement
// deleteNode()
// print()
// printReverse();

template <typename T>
void DoublyLinkedList<T>::deleteNode(const T& data) {
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
}

// FIX THE BELOW METHOD IF IT DOESN"T WORK
template <typename T>
void DoublyLinkedList<T>::insertAfter(const T& data, int position) {
    if (position < 0) {
        cout << "Position must be >= 0" << endl;
        return;
    }

    Node* node = new Node(data);
    if (!head) {
        head = tail = node;
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
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(head) {
        node* temp = head;
        head = head->nextLink;
        delete temp;
    }
}


#endif