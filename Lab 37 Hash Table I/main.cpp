#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int toAscii(string);

int main() {
    ifstream file("data.txt");
    if(!file.is_open()) {cout << "Error opening file" << endl;}

    string line;
    int sum = 0;
    while(getline(file , line)) {
        sum += toAscii(line);
    }

    cout << "The total sum of the file is " << sum << endl;

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
