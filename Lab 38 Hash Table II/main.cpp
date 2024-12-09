#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

// COMSC-210 | Lab 37: Hash Table II | Erick Pascual-Bautista

// Function prototypes
int gen_hash_index(string);

void printMenu();
int getUserInput();
void promptInput();
void handleUserInput(int input, map<int, list<string>>&);

// Helper function
bool findKey(map<int, list<string>>&, int);

// Menu operatinos
void printElements(map<int, list<string>>&, int = 20);
void userFindKey(map<int, list<string>>&, int);
void addKey(map<int, list<string>>&, int);

int main() {
    // Creatnig Hash Table (map of key ints, value list of strings)
    map<int, list<string>> hash_table;

    // Opening File
    ifstream file("data.txt");
    if(!file.is_open()) {cout << "Error opening file" << endl;}

    // Processing key value pairs
    string line;
    while(getline(file , line)) {
        hash_table[gen_hash_index(line)].push_back(line);
    }

    while(true) {
        // PROGRAM LOGIC GOES HERE
        printMenu();
        promptInput();
        handleUserInput(getUserInput(), hash_table);
    }



    return 0;
}

int gen_hash_index(string str) {
    int sum = 0;
    for (auto& character : str) {
        sum += int (character);
    }
    return sum;
}


// displays the menu
void printMenu() { 
        cout << "*** Binary Search Tree Operation  ***" << endl;
        cout << "[1] Print out 20 elements" << endl;
        cout << "[2] Find Key" << endl;
        cout << "[3] Add key" << endl;
        cout << "[4] Modify key" << endl;
        cout << "[5] QUIT" << endl;
        cout << "ENTER CHOICE: ";
}

void promptInput() {cout << "Please select a operation: ";}

int getUserInput() {
    int value;
    cin >> value;
    return value;
}

void handleUserInput(int input, map<int, list<string>>& table) {
    switch(input) {
        case 1:
            printElements(table);
            break;
        case 2:
            cout << "Please enter a key to find: ";
            userFindKey(table, getUserInput());
            break;
        case 3:
            // Adding key
            cout << "Please enter a key to add: ";
            addKey(table, getUserInput());
            break;
        case 4:
            break;
        case 5:
            cout << endl << "Exiting program..." << endl << endl;
            exit(0); // Completely exits from the program
        default:
            break;
    }
}

void printElements(map<int, list<string>>& table, int elementsToOutput) {
    // Outputing elementsToOutput number of elements from the map
    int count = 0;
    for(auto iterator = table.begin(); iterator != table.end() && count < elementsToOutput; iterator++, count++) {
        cout << "[" << iterator->first << "] = ";
        cout << "[";
        for (auto& str : iterator->second) { // for every string in the list
            cout << str << ",";
        } 
        cout << "]" << endl << endl;
    }
}

bool findKey(map<int, list<string>>& table, int keyToFind) {
    auto iterator = table.find(keyToFind); 
    if(iterator != table.end()) {return true;} 
    else {return false;}
}

void userFindKey(map<int, list<string>>& table, int keyToFind) {
    auto iterator = table.find(keyToFind); 
    if (iterator != table.end()) {
        cout << endl << "KEY FOUND" << endl << endl;
        cout << "[" << iterator->first << "] = [";
        for (auto& str : iterator->second) { // Output every string in the string list
            cout << str << ",";
        }
        cout << "]" << endl << endl;
    } else {cout << endl << "KEY NOT FOUND" << endl << endl;}
}

void addKey(map<int, list<string>>& table, int keyToAdd) {
    bool keyIsFound = findKey(table, keyToAdd);
    if (keyIsFound) {
        cout << endl << "KEY IS FOUND: To add more elements please use '[4]' MODIFY KEY OPERATION" << endl << endl;
    } else {
        
        //table.[index].push(string);
    }
}