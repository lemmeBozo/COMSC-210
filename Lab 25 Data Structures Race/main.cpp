#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <algorithm> // for std::sort (that way I can use the same sort method? function on all the Data structures)

#include <vector>
#include <list>
#include <set>

using namespace std;
using namespace std::chrono;

// COMSC-210 | Lab 25: Data Structures Races | Erick Pascual-Bautista

// function template to test out functions
template <typename function, typename T>
auto timeFunction(function func, T& arg) {
    auto start = high_resolution_clock::now();

    // Calling the passed function with its provided arguments (if any)
    // going to assume there is no return statement
    func(arg);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count(); // will return elapsed time in milliseconds;
}

// Reading functions prototypes
void vectorRead(vector<string> &l);
void listRead(list<string> &l);
void setRead(set<string> &l);

// Sorting function prototypes
void sortVector(vector<string> &l);
void sortList(list<string> &l);
void sortSet(set<string> &l);

int main() {
    vector<string> vectorList;
    list<string> listList;
    set<string> setList;


    cout << setw(12) << "Operation"
        << setw(12) << "Vector"
        << setw(12) << "List"
        << setw(12) << "Set" << endl;

    cout << setw(12) << "Read"
        << setw(10) << timeFunction(vectorRead, vectorList) << "ms"
        << setw(10) << timeFunction(listRead, listList) << "ms"
        << setw(10) << timeFunction(setRead, setList) << "ms" << endl;

        cout << setw(12) << "Sort"
        << setw(10) << timeFunction(vectorRead, vectorList) << "ms"
        << setw(10) << timeFunction(listRead, listList) << "ms"
        << setw(10) << timeFunction(setRead, setList) << "ms" << endl;

    return 0;
}


// Reading Functions

void vectorRead(vector<string> &l) {
    ifstream file("codes.txt"); // opening the file

    if(!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line; 
    while (getline(file , line)) {
        l.push_back(line); // adding each line to the vector
    }
    file.close(); // close the file after reading
} 

void listRead(list<string> &l) {
    ifstream file("codes.txt"); // opening file

    if (!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line;
    while(getline(file, line)) {
        l.push_back(line);
    }
    file.close();
}

void setRead(set<string> &l) {
    ifstream file("codes.txt"); // opening file

    if (!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line;
    while(getline(file, line)) {
        l.insert(line);
    }
    file.close();
}


// Sorting functions
void sortVector(vector<string> &l) {
    sort(l.begin(), l.end()); // sorting (in ascending order)
}

void sortList(list<string> &l) {
    sort(l.begin(), l.end());
}

