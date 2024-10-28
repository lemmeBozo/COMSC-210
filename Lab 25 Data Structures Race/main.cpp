#include <iostream>
#include <chrono>
#include <fstream>

#include <vector>

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
    return duration;
}


// functions to test
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

int main() {
    cout << "Read Vector operation: " << timeFunction(vectorRead) << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

