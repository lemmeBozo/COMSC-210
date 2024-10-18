#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    // Defines a Node for our Linked List
    struct Node {
        int data;   // The value our node is storing
        Node* prev; // Pointer to the previous element in our list
        Node* next; // Pointer to the next element in our list

        // Parameterized Constructor which sets the values equal to the inputed values
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head; // Pointer to the head node i.e. first element in our list
    Node* tail; // Pointer to the tail node i.e. the last element in our list 

public:
    // Default Constructor for our list that sets the head and tail equal to nullptr, since the list will be empty created via default constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    // Adds a new element to the back of the list
    void push_back(int v) {
        Node* newNode = new Node(v);    // Creates a new node with the integer v stored inside the node
        if (!tail)                      // if the list is emepty (we check the tail because if there is one element in the list then the head = tail and if there is no tail then the list must be empty)
            head = tail = newNode;      // then we set the head equal to the tail which is equal to the new node we want to add

        else {                          // If the list is not emetpy
            tail->next = newNode;       // tail->next should point to the new last element
            newNode->prev = tail;       // since newNode is now the new last element its previous element should point to the old tail
            tail = newNode;             // now that newNode is the last element in the list it should be equal to tail (i.e. tail should point to newNode)
        }
    }
    
    // Adds a new element to the front of the list 
    void push_front(int v) {
        Node* newNode = new Node(v);    // Creates a new node with the integer v stored inside the node
        if (!head)                      // if the list is emetpy (list is emetpy when tail =  nullptr)
            head = tail = newNode;      // then we set the head equal to the tail which is equal to the new node we want to add
        else {                          // If the list is not empty
            newNode->next = head;       // then the newNode->next element will now be the head
            head->prev = newNode;       // 
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}