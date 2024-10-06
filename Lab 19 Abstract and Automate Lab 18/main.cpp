#include <iostream>
#include <string> 
#include "LinkedList.h" // personal linked list I created

#include <random>
#include <cmath>

using namespace std;

// COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Erick Pascual-Bautista

void generateRandomRating();

struct Movie {
    string title;
    string comment;
    float rating;

    Movie() {
        title = "";
        comment = "";
        rating = 0;
    }

};

int main() {

    generateRandomRating();

    return 0;
}

void generateRandomRating() {
    random_device rd;
    float randomFloat = static_cast<float>(rd()) / rd.max() * 5.0f; // generates random number between 0-5 
    randomFloat = round(randomFloat * 10.0f) / 10.0f; // rounds to the nearest tenth
    cout << randomFloat << endl;
}