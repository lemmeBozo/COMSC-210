#include <iostream>
#include <string> 
#include "LinkedList.h" // personal linked list I created
#include <fstream> // for file input
#include <random> 
#include <cmath>
#include <vector> 

using namespace std;

// COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Erick Pascual-Bautista

float generateRandomRating();

struct Movie {
    string title;
    string comment;
    float rating;

    Movie() { // Default Constructor Initilization
        title = "";
        comment = "";
        rating = generateRandomRating();
    }

    Movie(string title)
        : title(title), comment(""), rating(generateRandomRating()) {};

    Movie(string title, string comment) // Parameterized member initilization constructor 
        : title(title), comment(comment), rating(generateRandomRating()) {};

};

int main() {

    LinkedList<Movie> movies;
    string line;

    // Creating Movie objects
    Movie interstellar("Interstellar");
    Movie inception("Inception");
    
    // Creating vector

    // Opening comments file
    ifstream file;
    file.open("comments.txt");
    if (!file.good()) {
        cout << "File not found" << endl;
    }
    
    while (getline(file, line)) { // as long as there is a next line to get
        if (!line.empty()) { // if line is not empty
           
        }
    }

    file.close(); // closes file after reading everything

    return 0;
}

float generateRandomRating() {
    random_device rd;
    float randomFloat = static_cast<float>(rd()) / rd.max() * 5.0f; // generates random number between 0-5 
    randomFloat = round(randomFloat * 10.0f) / 10.0f; // rounds to the nearest tenth
    return randomFloat;
}