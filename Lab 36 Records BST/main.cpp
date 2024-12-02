#include <iostream>
#include <fstream> // For reading a file
#include <string>

#include "StringBinaryTree.h" // Including custom data structure

using namespace std;

// COMSC-210 | Lab 36: Records BST | Erick Pascual-Bautista

// Function Prototypes
ifstream openFile(string);
void printMenu(); 
void printLineBreaks(int);
int getUserInput();
void handleUserInput(int, StringBinaryTree&, ifstream&);
string fetchNextString(ifstream&);
void addElement(string, StringBinaryTree&);

int main() {
    // Opening File
    ifstream file = openFile("codes.txt");

    // Creating Binary Tree
    StringBinaryTree tree;

    // Binary tree operations loop
    while (true) {
        printMenu();
        handleUserInput(getUserInput(), tree, file);
        printLineBreaks(2);
    }

    return 0;
}

ifstream openFile(string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::ios_base::failure("Error: Unable to open file '" + fileName + "'");
    }
    return file; // Return the ifstream object
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

void handleUserInput(int userInput, StringBinaryTree& tree, ifstream& file) {
    switch(userInput) {
        case 1: 
            {
                string strToAdd = fetchNextString(file);
                addElement(strToAdd, tree);
            }
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

string fetchNextString(ifstream& file) {
    string line;
    if (getline(file, line)) {return line;} // If valid string return string
    return ""; // Otherwise return an empty string
}

void addElement(string strToAdd, StringBinaryTree& tree) {
    tree.insertNode(strToAdd); // Adds string to tree
    tree.displayInOrder(); // Then displays tree in order
}

