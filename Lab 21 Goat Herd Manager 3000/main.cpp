#include <iostream>
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding

#include "DoublyLinkedList.h" // includes improved version of doubly linked list 

using namespace std;

// COMSC-210 | Lab 21: Goat Herd Manager 3000 | Erick Pascual-Bautista

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

int generateRandomInt(int, int);

struct Goat {
    // private: 
    int age;
    string name;
    string color;
    string names[15] = {
        "Alice", "Bob", "Charlie", "Diana", "Eve",
        "Frank", "Grace", "Hank", "Ivy", "Jack",
        "Karen", "Liam", "Mona", "Nate", "Olivia"
    };
    string colors[15] = {
        "Red", "Blue", "Green", "Yellow", "Purple",
        "Orange", "Pink", "Brown", "Black", "White",
        "Cyan", "Magenta", "Teal", "Grey", "Violet"
    };

    // Defalut Constructor
    Goat() {
        age = generateRandomInt(1,20);
        name = names[generateRandomInt(0,14)];
        color = colors[generateRandomInt(0,14)];
    }

    // Parameterized Constructor 
    Goat (int age, string name, string color) 
        : age(age), name(name), color(color) {}

    friend ostream& operator<<(ostream& os, const Goat& obj) {
        os << "[ Name: " << obj.name << ", Color: " << obj.color << ", Age: " << obj.age << "]" << endl;
        return os; 
    }

};

// Driver program
int main() {
    DoublyLinkedList<Goat> list;
    int size = generateRandomInt(5, 20);

    for (int i = 0; i < size; i++) {
        Goat goat;
        list.pushBack(goat);
    }
    cout << "List Forward: " << endl;
    list.print();

    cout << endl << "List Backwards: " << endl;
    list.printReverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}

int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}