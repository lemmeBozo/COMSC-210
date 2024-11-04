#include <iostream>
#include <fstream>
#include <iomanip>
#include <set> // replaced <list> with <ste>
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding
#include "Goat.h"
#include <algorithm>
using namespace std;

// COMSC-210 | Lab 28: STL Algorithms | Erick Pascual-Bautista

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> &trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
void main_menu(set<Goat> &trip, string [], string []);
int generateRandomInt(int, int);

// Additional STL algorithm functinos
void findGoatByName(set<Goat> &trip);
void countGoatByAge(set<Goat>& trip); 
void checkIfAllGoatsAreYoung(set<Goat>& trip);
void findOldestGoat(set<Goat>& trip);
void copyTrip(set<Goat>& trip); // this function is not really useful but included it anyways
// as it uses a stl algorithm
void sumAges(set<Goat>& trip);
void sortGoatByNameAscending(set<Goat>& trip);
void sortGoatByNameDescending(set<Goat>& trip);


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
        cout << "[4] Find goat by name" << endl;
        cout << "[5] Cout goats by age" << endl;
        cout << "[6] Check if all goats are young" << endl;
        cout << "[7] Find oldest goat" << endl;
        cout << "[8] Copy trip" << endl;
        cout << "[9] Sum goat ages" << endl;
        cout << "[10] Sort goats by name ascending" << endl;
        cout << "[11] Sort goats by name descending" << endl;
        cout << "[12] Quit" << endl << endl;
        cin >> option;  // 

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
                findGoatByName(trip);
                break;
            case 5:
                countGoatByAge(trip);
                break;
            case 6:
                checkIfAllGoatsAreYoung(trip);
                break;
            case 7:
                findOldestGoat(trip);
                break;
            case 8:
                copyTrip(trip);
                break;
            case 9:
                sumAges(trip);
                break;
            case 10:
                sortGoatByNameAscending(trip);
                break;
            case 11:
                sortGoatByNameDescending(trip);
                break;

            case 12:
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


// stl algorithm functions
// Lambda functions are used here for their simplicity and concise syntax
// They are really similar to javascripts arrow functions which I always fonud useful and
// continue to find useful here



void findGoatByName(set<Goat> &trip) {
    string name;
    cout << "Enter goat name to find: ";
    cin >> name;

    // using stl find_if to check if name is inside the trip of goats
    auto it = find_if(trip.begin(), trip.end(), [name](const Goat& goat) {
        return (goat.get_name() == name);
    });

    if (it!= trip.end()) {
        cout << "Goat found: " << *it << endl;
    } else {cout << "Goat not found" << endl;}

}

void countGoatByAge(set<Goat>&  trip) {
    int age;
    cout << "Enter age to count: ";
    cin >> age;
    // couts how many times the condition is true and adds 1 to the count
    // using algorithm count_if
    int count = count_if(trip.begin(), trip.end(), [age](const Goat& goat) {
        return goat.get_age() == age;
    });
    cout << "Number of goats with age " << age << ": " << count << endl;
}

void checkIfAllGoatsAreYoung(set<Goat>& trip) {
    // the stl all_of checks if all of the goats in our trip meets the condition
    // if so it returns true otherwise it returns false
    bool allYoung = all_of(trip.begin(), trip.end(), [](const Goat& goat) {
        return goat.get_age() < 5;
    });

    if (allYoung) {
        cout << "All goats are young" << endl;
    } else {cout << "Not all the goats are young" << endl;}

}

void findOldestGoat(set<Goat>& trip) {
    // using stl max_element to find which goat age element is larger than the last/previous
    // will return an iterator to the oldest goat
    auto it = max_element(trip.begin(), trip.end(), [](const Goat& a, const Goat& b) {
        return a.get_age() < b.get_age();
    });
    if (it != trip.end()) {
        cout << "Oldest goat: " << *it << endl;
    }
}

void copyTrip(set<Goat>& trip) {
    // creating copy set
    set<Goat> copy;
    // uses the stl copy to copy the trip from the begin to the end 
    // and inserts the elements into copy starting from the begginning
    std::copy(trip.begin(), trip.end(), inserter(copy, copy.begin()));

    cout << "Copied trip: " << endl;
    display_trip(copy);
}

void sumAges(set<Goat>& trip) {
    // adds up the age of each goat and stores it into total age
    // incrementing the age everytime we get the current goat age
    int totalAge = accumulate(trip.begin(), trip.end(), 0, [](int sum, const Goat& goat) { 
        return sum + goat.get_age(); 
    });
    cout << "Total age of all goats: " << totalAge << endl;
}

void sortGoatByNameAscending(set<Goat>& trip) {
    // create vector of the goats
    vector<Goat> sortedTrip(trip.begin(), trip.end()); // copies the trip from beggining to end
    // using stl sort to sort the vector
    sort(sortedTrip.begin(), sortedTrip.end(), [](const Goat& a , const Goat& b) {
        return a.get_name() < b.get_name();
    });
    // prints out the goats in ascending sorted
    for (const auto& goat : sortedTrip) {
        cout << goat << endl;
    }
}

void sortGoatByNameDescending(set<Goat>& trip) {
    // create vector of the goats
    vector<Goat> sortedTrip(trip.begin(), trip.end()); // copies the trip from beggining to end
    // using stl sort to sort the vector
    sort(sortedTrip.begin(), sortedTrip.end(), [](const Goat& a , const Goat& b) {
        return a.get_name() > b.get_name();
    });
    // prints out the goats in ascending sorted
    for (const auto& goat : sortedTrip) {
        cout << goat << endl;
    }
}