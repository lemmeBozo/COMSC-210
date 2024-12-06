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
    int sum = 0;
    while(getline(file , line)) {
        hash_table[toAscii(line)].push_back(line);
    }


    cout << "The total sum of the file is " << sum << endl;
    /* 
        Create a map [ascii sum] = [string, string string] 
        note the strings have a ascii sum of well ascii sum

        TODO 
        1. create a map
        2. Read file
        3. properly store string in the correct list associtaed with the ascii value
        map[key].push_back(element)
    */


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
