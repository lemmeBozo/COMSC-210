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

// COMSC-210 | Lab 26: Data Structures Races | Erick Pascual-Bautista

// function template to test out functions (will average out the result over 15 test runs)
template <typename function, typename T>
auto timeFunction(function func, T& arg) {
    int iterations = 15;
    long long totalDuration = 0; // Duration time will be a VERY large value thus long long
    for (int i = 0; i < iterations; i++) { // will run the test 15 times and average the result
        auto start = high_resolution_clock::now();    
        func(arg);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);   
        totalDuration += duration.count();     
    }
    return totalDuration / iterations; // average duration in miliseconds
}




// function template to test out functions (will average out the result over 15 test runs)
template <typename function, typename T>
auto timeFunctionNS(function func, T& arg) {
    int iterations = 15;
    long long totalDuration = 0; // Duration time will be a VERY large value thus long long
    for (int i = 0; i < iterations; i++) { // will run the test 15 times and average the result
        auto start = high_resolution_clock::now();    
        func(arg);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);   
        totalDuration += duration.count();     
    }
    return totalDuration / iterations; // average duration in miliseconds
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

// Deleting function prototypes
void deleteVector(vector<string> &l);
void deleteList(list<string> &l);
void deleteSet(set<string> &l);


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

    // Note for the below functions some were too fast
    // so I used nano seconds instead

    cout << setw(12) << "Insert"
        << setw(10) << timeFunctionNS(insertVector, vectorList) << "ns"
        << setw(10) << timeFunctionNS(insertList, listList) << "ns"
        << setw(10) << timeFunctionNS(insertSet, setList) << "ns" << endl;

    cout << setw(12) << "Insert"
        << setw(10) << timeFunctionNS(deleteVector, vectorList) << "ns"
        << setw(10) << timeFunctionNS(deleteList, listList) << "ns"
        << setw(10) << timeFunctionNS(deleteSet, setList) << "ns" << endl;

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

// Deleting functions
void deleteVector(vector<string> &l) {
    int middle = l.size() / 2;
    l.erase(l.begin() + middle);
}

void deleteList(list<string> &l) {
    auto middle = next(l.begin(), l.size() / 2); 
    l.erase(middle); 
}

void deleteSet(set<string> &l) {
    auto middle = next(l.begin(), l.size() / 2); 
    l.erase(middle);
}