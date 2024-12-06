#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

// Function prototypes
int toAscii(string);

int main() {
    // Creatnig Hash Table (map of key ints, value list of strings)
    map<int, list<string>> hash_table;

    ifstream file("data.txt");
    if(!file.is_open()) {cout << "Error opening file" << endl;}

    string line;
    while(getline(file , line)) {
        hash_table[toAscii(line)].push_back(line);
    }

    // Outputing 10 elements from the map
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

int toAscii(string str) {
    int sum = 0;
    for (auto& character : str) {
        sum += int (character);
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
