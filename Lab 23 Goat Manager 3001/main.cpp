#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

// COMSC-210 | Lab 23: Goat Manager 3001 | Erick Pascual-Bautista

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

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

    return 0;
}

// Taking quick bathroom break will be back

int main_menu() {
    while(true) { 
        int option;
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cin >> option;  // Under the assumption user enters a valid number
        // otherwise I would have input validation

        switch (option) {
            case 1:
                // add goat
                break;
            case 2:
                // delete goat
                break;
            case 3: 
                // lists out goats
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