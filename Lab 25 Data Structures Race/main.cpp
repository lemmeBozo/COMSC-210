#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// COMSC-210 | Lab 25: Data Structures Races | Erick Pascual-Bautista

// Use function template for timer?
// and you just pass in the string somehow to call the appropriate funciton
template <typename function, typename... Args>
auto timeFunction(function name, Args... args) {
    auto start = high_resolution_clock::now();

    // Calling the passed function with its provided arguments (if any)
    auto result = func(args...);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
}

int main() {
    // Start timing
    auto start  = high_resolution_clock::now();


    // Test 1 Reading 20,000 values
    // put code here

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/