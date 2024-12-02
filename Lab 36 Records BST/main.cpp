#include <iostream>
#include <fstream> // For reading a file
#include <string>
using namespace std;

// COMSC-210 | Lab 36: Records BST | Erick Pascual-Bautista

// Function Prototypes
void printMenu(); 
void printLineBreaks(int);
int getUserInput();
void handleUserInput(int);
string fetchNextString();

int main() {
    while (true) {
        printMenu();
        handleUserInput(getUserInput());
        printLineBreaks(2);
    }
    return 0;
}

// displays the menu
void printMenu() { 
        cout << "*** Binary Search Tree Operation  ***" << endl;
        cout << "[1] Add element" << endl;
        cout << "[2] Delete element" << endl;
        cout << "[3] Search for element" << endl;
        cout << "[4] Modify records at" << endl;
        cout << "[5] QUIT" << endl;
        cout << "ENTER CHOICE: ";
}

void printLineBreaks(int breaks) {
    for (int i = 0; i < breaks; i++) {
        cout << endl;
    }
}

int getUserInput() {
    int value;
    cin >> value;
    return value;
}

void handleUserInput(int userInput) {
    switch(userInput) {
        case 1:
            // Call addElement(string)
            break;
        case 2:
            // Call deleteElement() 
            break;
        case 3:
            // findElement(string)
            break;
        case 4:
            // modifyElement(string)
        case 5:
            cout << endl << "Exiting program..." << endl << endl;
            exit(0); // Completly exits from the program
        default:
            cout << endl << "Error: not a valid option" << endl;
            break;
    }
}

string fetchNextString() {
    static int index = 0; // Only initialized once

    string line;
    ifstream file("codes.txt");
    if(!file.is_open()) {
        cerr << "Error: Unable to open file 'codes.txt'" << endl;
        return 0;
    }
    for (int i = 0; i < index; i++) {
        if (getline(file, line)) {
            return line;
        }
    }
    file.close();
    index++;
}

