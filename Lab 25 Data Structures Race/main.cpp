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
    cout << setw(12) << "Operation"
        << setw(10) << "Vector"
        << setw(10) << "List"
        << setw(10) << "Set" << endl;

    cout << setw(12) << "Read"
        << setw(10) << timeFunction(vectorRead);
        << setw(10) << timeFunction(listRead);
        << setw(10) << timeFunction(setRead) << endl;
    return 0;
}


// Reading Functions

void vectorRead() {
    vector<string> list;

    ifstream file("codes.txt"); // opening the file

    if(!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line; 
    while (getline(file , line)) {
        list.push_back(line); // adding each line to the vector
    }
    file.close(); // close the file after reading
} 

void listRead() {
    list<string> list;

    ifstream file("codes.txt"); // opening file

    if (!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line;
    while(getline(file, line)) {
        list.push_back(line);
    }
    file.close();
}

void setRead() {
    set<string> list;

    ifstream file("codes.txt"); // opening file

    if (!file) {
        cout << "Unable to open file!" << endl;
        return;
    }
    string line;
    while(getline(file, line)) {
        list.push_back(line);
    }
    file.close();
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

