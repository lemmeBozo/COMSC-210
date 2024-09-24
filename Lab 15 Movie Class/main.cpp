#include <iostream>
#include <string> // for string
#include <fstream> // for file input
#include <vector> // for vectors
#include <iomanip> // for setw

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

    // Print method
    void print() {
        cout << setw(10) << "Title" << setw(10) << "Screen Writer" << setw(10) << "Year Released" << endl;
        cout << setw(10) << this->title << setw(10) << this->screenWriter << setw(10) << this->yearReleased << endl;
        cout << endl;
    }
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



    while(getline(file, line)) { // Reads title
        string title;
        string screenWriter;
        int yearReleased;

        title = line;

        if (getline(file,line)) { // checks if new line is read
            yearReleased = stoi(line); // converts string to integer
        } else {break;} // exits out of execution if new line cannot be read

        if (getline(file,line)) { // checks if new line is read
            screenWriter = line;
        } else {break;} // exits out of execution if new line cannot be read
        movies.push_back(Movie(screenWriter, title, yearReleased));
    }

    for (int i = 0; i < movies.size(); i++) {
        movies[i].print();
    }

    cout << "Does this work" << endl;

    return 0;
}

