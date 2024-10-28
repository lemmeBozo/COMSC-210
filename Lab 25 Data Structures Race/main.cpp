#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

#include <vector>
#include <list>
#include <set>

using namespace std;
using namespace std::chrono;

// COMSC-210 | Lab 25: Data Structures Races | Erick Pascual-Bautista

// function template to test out functions
template <typename function, typename... Args>
auto timeFunction(function func, Args... args) {
    auto start = high_resolution_clock::now();

    // Calling the passed function with its provided arguments (if any)
    // going to assume there is no return statement
    func(args...);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count(); // will return elapsed time in milliseconds;
}

void vectorRead();
void listRead();
void setRead();


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

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

