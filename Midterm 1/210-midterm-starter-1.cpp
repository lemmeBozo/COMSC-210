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

    // Deletes the node that holds value
    void delete_val(int value) {
        if (!head) return;  // if the list is empty exits from the method

        Node* temp = head;  // sets temp equal to the head 
        
        while (temp && temp->data != value) // while temp exists (!= nullptr) and temps->data doesn't equal the value we are trying to find (note if the node is found then the loop stops)
            temp = temp->next;

        if (!temp) return; // if temp is equal to nullptr (i.e. value not found) then exits out of the method

        if (temp->prev) // if temp has a previous node (i.e. isn't the first node in the list) then
            temp->prev->next = temp->next;  // sets prev->next = next
                                            // Sets prev next pointer equal to the node after temp (next)
                                            // [prev] [temp] [next]
                                            // the above becomes
                                            // [prev] [next]
        else                                // otherwise if it doesn't have a previous node
            head = temp->next;              // sets head equal to the value after temp
                                            //  [temp(the current head)] [next]
                                            // becomes
                                            // [next( the new head)]

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    // deletes the value at position pos
    void delete_pos(int pos) {
        if (!head) {    // if the list is emetpy
            cout << "List is empty." << endl;   // then outputs "List is emetpy to the console"
            return; // exits out of the function
        }
    
        if (pos == 1) { // if the position to be deleted is the first element in the list then just calls the pop_front() method which just deletes the first element in the list
            pop_front();
            return;
        }
    
        Node* temp = head;  // sets temp equal to the current head
    
        for (int i = 1; i < pos; i++){  // traveres through the list 
            if (!temp) {    // if temp points to a nullptr then the value at position doesn't exists
                cout << "Position doesn't exist." << endl;  // outputs "Position doesn't exists " to the console.
                return; // exits out of the function
            }
            else    // otherwise temp will point to the next element in the list (until it reaches the desired position )
                temp = temp->next;
        }
        if (!temp) {    // if after traversing through the list and temp points to a null ptr
            cout << "Position doesn't exist." << endl;  // then the value doesn't exists and outputs "Position doesn't exist." to the console.
            return; // exits out of the funciton
        }
    
        if (!temp->next) {  // if temp points to the last element in the list
            pop_back(); // then calls the pop_back() method which deletes the last element in the list
            return; // exits out of the function
        }
    
        Node* tempPrev = temp->prev;    // sets points tempPrev to the value before temp (just saves it temporaily)
        tempPrev->next = temp->next;    // since temp is going to be deleted then the element before temp's next value will point to temp's next value
                                        // in other words   imagine the following
                                        // [previous] -> [temp] -> [next] -> [...] -> ...
                                        // the above will now become 
                                        // [previous] -> [next] -> ......
                                        // the important thing to note is that the above code essentially does the following 
                                        //  previous->next = next (the previous value next pointer will point to next)

        temp->next->prev = tempPrev;    // sinces temp will be deleted its next value's previous pointer should point to the value before temp
                                        // in other words imagine the following
                                        // [previous] -> [temp] -> [next] -> [...] -> ...
                                        // the above will become 
                                        // [previous] -> [next] -> ...
                                        // the important thing to note is that the above code esesntially does the following
                                        // next->prev = previous
                                        // the next->prev value will now point to previous
        delete temp;                    // deletes temp
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
            newNode->next = head;       // the newNode's->next value should be the head because the newNode is now the new first element therefore its next element must be the head now being the new 2nd element in the list
            head->prev = newNode;       // the heads previous element should be our newly appened node because it is the 2nd element in the list and the 1st element in the list should be our newNode
            head = newNode;             // the head will now be equal/point to newNode because it should be the first element in the list i.e. be the head
        }
    }
    
    // Pops the first element in the list and deletes it
    void pop_front() {

        if (!head) { // if the list is emetpy
            cout << "List is empty." << endl; // then output the list is empty to the console
            return;
        }

        Node * temp = head; // temp will point to the head

        if (head->next) {   // If the head has a next pointer i.e. next element exists
            head = head->next;  // Then the head will now point to the next element in the list (because the original head will get deleted)
            head->prev = nullptr;   // The head's prev pointer should point to nothing because the head is the first element in the list 
        }
        else    // IF the head is the only element in the list
            head = tail = nullptr; // Then the head should point to tail and they should both be nullptr because we are removing the first element in the list
        delete temp;    // Deletes the first element in the list
    }

    // Pops the last element in the list and deletes it
    void pop_back() {
        if (!tail) {    // If the list  is empty then 
            cout << "List is empty." << endl;   // Output "List is emetpy" to the console
            return;
        }

        Node * temp = tail; // Temp points to the tail

        if (tail->prev) { // If the tail has a previous element (i.e. not the only element in the list )
            tail = tail->prev;  // then the tail should now point to its previous element (because the original tail is going to be deleted so the 2nd to last element is now the last element)
            tail->next = nullptr;   // sets the tail->next element in the list = to nullptr because the tail should be the last element in the list
        }
        else    // if the tail is the only element in the list
            head = tail = nullptr;  // then set both the head and the list eqaul to nullptr because there should be no elements in the list
        delete temp;    // Deletes the tail
    }

    // Destructor functionf or the list
    ~DoublyLinkedList() {   
        while (head) {  // while there is a head to delete
            Node* temp = head;  // sets temp equal to the head
            head = head->next;  // sets the head equal to the next value in the list (since the head is going to be deleted)
            delete temp;        // deletes the head of the list
            // This loop runs until the head is equal to nullptr meaning there are no more element to delete in the list
        }
    }
    // Prints out the elements in the elements in the list from the head to the tail
    void print() {
        Node* current = head;   // sets the current node equal to the head
        if (!current) { // if there is no current node since its pointing to the head then that means the list is emetpy
            cout << "List is empty." << endl;   // outputs "List is empty" to the console
            return; // exits out of the function
        }
        while (current) { // current is still a valid pointer i.e. isn't equal to null ptr i.e. hasn't reached the end of the list
            cout << current->data << " ";   // output the data stored in current
            current = current->next;        // then point to the next element in the list
            // until there are no more elemnets to point to
        }
        cout << endl;   // Ends the line the text is being outputed on i.e. presses enter  (note I know it doesn't actually press enter)
    }

    // Prints out the content of the list in reverese i.e. tail to head
    void print_reverse() {
        Node* current = tail;   // sets the current node equal to the tail
        if (!current) {         // if the list is empty
            cout << "List is empty." << endl;   // then output "List is emetpy" to the console
            return; // exits out of the function 
        }
        while (current) {   // while current is still a valid pointer i.e. hasn't reached the end of the list
            cout << current->data << " ";   // outputs the data stored in current
            current = current->prev;        // then points to the previous element in the list
        }
        cout << endl;   // Ends the line the text is being outputed on i.e. presses enter
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}