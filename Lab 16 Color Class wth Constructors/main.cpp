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
        cout << setw(20) << "Title" << setw(20) << "Screen Writer" << setw(20) << "Year Released" << endl;
        cout << setw(20) << this->title << setw(20) << this->screenWriter << setw(20) << this->yearReleased << endl;
        cout << endl;
    }
};

int main() {
    ifstream file;
    file.open("text.txt");
    if (!file.good()) {
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

    file.close(); // closes file after reading everything
    return 0;
}

/*just a test why can't I commit my stuff*/