#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

// COMSC-210 | Lab 37: Hash Table II | Erick Pascual-Bautista


// Function prototypes
int gen_hash_index(string);

int main() {
    // Creatnig Hash Table (map of key ints, value list of strings)
    map<int, list<string>> hash_table;

    ifstream file("data.txt");
    if(!file.is_open()) {cout << "Error opening file" << endl;}

    string line;
    while(getline(file , line)) {
        hash_table[gen_hash_index(line)].push_back(line);
    }

    // Outputing elementsToOutput number of elements from the map
    int count = 0;
    int elementsToOutput = 30;
    for(auto iterator = hash_table.begin(); iterator != hash_table.end() && count < elementsToOutput; iterator++, count++) {
        cout << "[" << iterator->first << "] = ";
        cout << "[";
        for (auto& str : iterator->second) { // for every string in the list
            cout << str << ",";
        } 
        cout << "]" << endl << endl;
    }

    return 0;
}

int gen_hash_index(string str) {
    int sum = 0;
    for (auto& character : str) {
        sum += int (character);
    }
    return sum;
}
