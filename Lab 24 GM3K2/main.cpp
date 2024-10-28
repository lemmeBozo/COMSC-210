#include <iostream>
#include <fstream>
#include <iomanip>
#include <set> // replaced <list> with <ste>
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding
#include "Goat.h"
using namespace std;

// COMSC-210 | Lab 24: GM3K2 | Erick Pascual-Bautista

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> &trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
void main_menu(set<Goat> &trip, string [], string []);
int generateRandomInt(int, int);

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();


    // main menu
    set<Goat> trip;
    main_menu(trip, names, colors);

    return 0;
}

// Starting work again

void main_menu(set<Goat> &trip, string names[], string colors[]) {
    while(true) { 
        int option;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl << endl;
        cin >> option;  // Under the assumption user enters a valid number
        // otherwise I would have input validation

        switch (option) {
            case 1:
                // add goat
                add_goat(trip, names, colors);
                cout << endl << "Added Goat" << endl;
                cout << "Current trip:" << endl;
                display_trip(trip);
                break;
            case 2:
                // delete goat
                delete_goat(trip);
                break;
            case 3: 
                // lists out goats
                display_trip(trip);
                break;
            case 4:
                cout << "Exiting..." << endl;
                return; // exits out of function 
            default: 
                cout << "Invalid option!" << endl;
                break;
        }
    }
}


int select_goat(set<Goat> &trip) {
    // Prompt the user to select a goat
    // Show the user the options
    // NOTE remmeber to write overloaded << stream thingy operator
    int option;
    display_trip(trip);
    cout << "Select a goat: " ;
    cin >> option;
    cout << endl;
    return option;
} 

void add_goat(set<Goat> &trip, string names[], string colors[]) {
    // add a goat to trip
    string name = names[generateRandomInt(0,SZ_NAMES - 1)];
    string color = colors[generateRandomInt(0,SZ_COLORS - 1)];
    int age = generateRandomInt(0,MAX_AGE);
    Goat goat(name, age, color);
    trip.insert(goat);
}

void delete_goat(set<Goat> &trip) {
    // In order to delete a goat the user needs to select the goat to be deleted
    int index = select_goat(trip);
    // Iterate throughout the list to find the correct goat
    if (index < 0 || index >= trip.size()) {
        cout << "Invalid index!" << endl;
        return;
    }
    
    auto iterator = trip.begin();
    advance(iterator, index); // moves the iterator to the desired index;
    trip.erase(iterator); // erase the element at the itereator's position
    cout << "goat removed!" << endl;
}

void display_trip(set<Goat> trip) {
    int i = 0;
    for (auto goat : trip) { // Similiar to JS's forEach loop (for each goat in the trip output every goat)
        cout << "[" << i << "] " << goat << endl;
        i++;
    }
}

// Reusing Code from Lab 21
int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
