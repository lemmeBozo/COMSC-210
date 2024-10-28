#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <algorithm> // for std::sort (that way I can use the same sort method? function on all the Data structures)
#include <iterator> // for std::next

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


// function template to test out functions
template <typename function, typename T>
auto timeFunctionNS(function func, T& arg) {
    auto start = high_resolution_clock::now();

    // Calling the passed function with its provided arguments (if any)
    // going to assume there is no return statement
    func(arg);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count(); // will return elapsed time in nanoseconds;
}

// Reading functions prototypes
void vectorRead(vector<string> &l);
void listRead(list<string> &l);
void setRead(set<string> &l);

// Sorting function prototypes
void sortVector(vector<string> &l);
void sortList(list<string> &l);

// Inserting function prototypes
void insertVector(vector<string> &l);
void insertList(list<string> &l);
void insertSet(set<string> &l);

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
        << setw(10) << timeFunction(sortVector, vectorList) << "ms"
        << setw(10) << timeFunction(sortList, listList) << "ms"
        << setw(10) << "-1ms" << endl;

        cout << setw(12) << "Insert"
        << setw(10) << timeFunctionNS(insertVector, vectorList) << "ns"
        << setw(10) << timeFunctionNS(insertList, listList) << "ns"
        << setw(10) << timeFunctionNS(insertSet, setList) << "ns" << endl;

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

// Note although different sorthing algorithms are used they should both be 
// the same time complexity
void sortVector(vector<string> &l) {
    sort(l.begin(), l.end()); // O(n log(n)), uses Introsort algorithm
}

void sortList(list<string> &l) {
    l.sort(); // O(n log(n)), uses Merge Sort
}

// Inserting functions
void insertVector(vector<string> &l) {
    int middle = l.size() / 2;
    l.at(middle) = "TESTCODE";
}


void insertList(list<string> &l) {
    // The below is going to calculate the midpoint
    // this is done by advancing the iterator to the middle spot of the list
    auto middle = next(l.begin(), l.size() / 2); 

    // Inserting at the middle
    l.insert(middle, "TESTCODE");
}

void insertSet(set<string> &l) {
    l.insert("TESTCODE");
} 