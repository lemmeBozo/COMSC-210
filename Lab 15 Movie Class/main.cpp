#include <iostream>
#include <string> // for string
#include <fstream> // for file input
#include <vector> // for vectors

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
    } else {
        cout << "File not found" << endl;
    }

    string line;
    vector<Movie> movies;
    int i = 0;

    while(getline(file, line)) { // Reads title
        string title;
        string screenWriter;
        int yearReleased;

        if (line.empty()) {continue;} // Skips empty lines
        title = line;

    }



    return 0;
}

