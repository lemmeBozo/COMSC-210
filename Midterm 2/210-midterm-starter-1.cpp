#include <iostream>
#include <vector> // for vector
#include <string> // for string
#include <fstream> // for reading files
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
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

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
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

// function to read names from the file (filename)
vector<string> readNames (const string&);

// REUSING CODE FROM LAB 21
int generateRandomInt(int, int);

// function to simulate the coffee shop
void simulateCoffeeShop();




int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning
    return 0;
}

vector<string> readNames (const string& filename) {
    vector<string> names;
    ifstream file(filename);
    // checks if the file has been opened properly
    if (file.is_open()) {
        string name;
        while(getline(file,name)) { // while there is a name to read
            names.push_back(name); // pushes the name into the vecotr
        }
        return names;
    } else { // if file was not opened
        cout  << "FILE was not opened" << endl;
        return names; // returns an empty vector 
    }
}

// REUSING CODE FROM LAB 21 (just a random number generator)
int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count(); // uses the milisecond as the seed for the rng to be more accurate
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max); // sets the distribuition of number to be within our range
    return distribution(generator); // returns the number generated
}

void simulateCoffeeShop() {
    // Store opens
    DoublyLinkedList line; // creates the line/queue
    vector<string> names = readNames("names.txt");
    // add 5 customers immediately
    for (int i = 0; i < 5; i++) {   
        // Selects random name from the list
        int index = generateRandomInt(0, names.size()  - 1);

        cout << names[index] << " joined the line." << endl; // Output that they are waiting in line in the console
        // Add them to the line 
        line.push_back(index); // we are using index as the value for who is in the line (and when anyone who is added  will be pushed to the back of the queue)
    }
    // simulation should run for 20 minutes (lets just say 20 run a loop 20 times)
    // in the following time
    // probabilty of a customer being helped at the beggining of the line and ordering their coffee is 40%
    // new customer joining 60% probability
    // Customer at the end of the line deciding to leave is 20%
    // Any customer at any time deciding to leave at any time is 20%
    // A vip customer with a coffe house gold card gets to skip the line and go straight to the counter 10% change
    // the way the chance will be calculated will be with an rng generate a number from 1 to 100
    // for the 60% chance if you get a number between 1 and 60 then you do whatever the fuck it says to do 
}