#include <iostream>

using namespace std;

// COMSC-210 | Lab 36: Records BST | Erick Pascual-Bautista

// Global Variable
int QUIT_CONDITION = 5;

// Function Prototypes
void printMenu(); 
void printLineBreaks(int);
int getUserInput();
void handleUserInput(int);

int main() {
    while (true) {
        printMenu();
        int userInput = getUserInput();
        if (userInput == QUIT_CONDITION) {
            cout << "Exiting program..." << endl;
            break; 
        }

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
            // Call addElement()
            break;
        case 2:
            // Call deleteElement()
            break;
        case 3:

        case 4:
        case 5:
        default:
            break;
    }
}