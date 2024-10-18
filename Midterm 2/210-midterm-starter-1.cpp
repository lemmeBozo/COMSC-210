#include <iostream>
#include <vector> // for vector
#include <string> // for string
#include <fstream> // for reading files
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding

#include "DoublyLinkedList.h"
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;


// function to read names from the file (filename)
vector<string> readNames (const string&);

// REUSING CODE FROM LAB 21
int generateRandomInt(int, int);

// function to simulate the coffee shop
void simulateCoffeeShop();




int main() {
    simulateCoffeeShop();
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
    DoublyLinkedList<int> line; // creates the line/queue
    vector<string> names = readNames("names.txt");
    // add 5 customers immediately
    cout << "Store opens: " << endl;
    for (int i = 0; i < 5; i++) {   
        // Selects random name from the list
        int index = generateRandomInt(0, names.size()  - 1);
        cout << "\t" << names[index] << " joined the line." << endl; // Output that they are waiting in line in the console
        // Add them to the line 
        line.pushBack(index); // we are using index as the value for who is in the line (and when anyone who is added  will be pushed to the back of the queue)
    }

    // simulation should run for 20 minutes (lets just say 20 run a loop 20 times)
    for (int minute = 1; minute <= 20; minute++) { // each itereation of the loop is 1 minute
        // probabilty of a customer being helped at the beggining of the line and ordering their coffee is 40%
        if (!line.isEmpty() && generateRandomInt(1, 100) <= 40)    { // if the line is NOT empty and our rng is less than or equal to 40 i.e. 40% chance has been hit
            cout << names[line.popFront()] << " is sereved" << endl;
        }
    }
    // in the following time

    // new customer joining 60% probability
    // Customer at the end of the line deciding to leave is 20%
    // Any customer at any time deciding to leave at any time is 20%
    // A vip customer with a coffe house gold card gets to skip the line and go straight to the counter 10% change
    // the way the chance will be calculated will be with an rng generate a number from 1 to 100
    // for the 60% chance if you get a number between 1 and 60 then you do whatever the fuck it says to do 
}