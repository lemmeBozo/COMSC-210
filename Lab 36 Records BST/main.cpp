#include <iostream>
#include <fstream> // For reading a file
#include <string>

// Including custom data structure
#include "StringBinaryTree.h" 
#include "StringBinaryTree.cpp"

using namespace std;

// COMSC-210 | Lab 36: Records BST | Erick Pascual-Bautista

// Function Prototypes
ifstream openFile(string);
void printMenu(); 
void printLineBreaks(int);
int getUserInput();
void handleUserInput(int, StringBinaryTree&, ifstream&);
string fetchNextString(ifstream&);

// BST Operations
void addElement(string, StringBinaryTree&);
void removeElement(StringBinaryTree&);
void searchForElement(StringBinaryTree&);
void modifyRecords(stringBinaryTree&); // Im going to 

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
        cout << "[4] Modify records" << endl;
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
            removeElement(tree);
            break;
        case 3:
            searchForElement(tree);
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
    cout << "Printing out Binary Tree in order: " << endl;
    tree.displayInOrder(); // Then displays tree in order
}

void removeElement(StringBinaryTree& tree) {
    string strToRemove;
    tree.displayInOrder();
    cout << "Please type in the element to delete: ";
    cin >> strToRemove;
    tree.remove(strToRemove);
    cout << "REMOVED ELEMENT, tree after removal: " << endl << endl;;
    tree.displayInOrder();
}

void searchForElement(StringBinaryTree& tree) {
    bool found = false;
    string strToFind;
    cout << "Please enter a string to find: ";
    cin >> strToFind;
    found = tree.searchNode(strToFind);
    if (found) {
        cout << "STRING FOUND" << endl;
    } else {cout << "STRING NOT FONUD" << endl;}
}

