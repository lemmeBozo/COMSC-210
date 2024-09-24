#include <iostream>
#include <string> // for string
#include <fstream> // for file input

using namespace std;

// COMSC-210 | Lab 15: Movie Class | Erick Pascual-Bautista

class Movie {
    // private: 
    string screenWriter;
    string title;
    int yearReleased;
    
    public:
    // Parameterized Constructor
    Movie(string screenWriter, string title, int yearReleased) 
    : screenWriter(screenWriter), title(title), yearReleased(yearReleased) {}

    // Basic Constructor
    Movie() {
        this->screenWriter = "";
        this->title = "";
        this->yearReleased = 0;
    }

    // Getters
    string getScreenWriter() {return this->screenWriter;}
    string getTitle() {return this->title;}
    int getYearReleased() {return this->yearReleased;}

    // Setters
    void setScreenWriter(string screenWriter) {this->screenWriter = screenWriter;}
    void setTitle(string title) {this->title = title;}
    void setYearReleased() {this->yearReleased = yearReleased;}

};

int main() {
    ifstream file;
    file.open("text.txt");
    if (file.good()) {// if file is open
        file.close(); // closes the file
    }
    return 0;
}

