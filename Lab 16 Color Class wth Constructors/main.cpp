#include <iostream>
#include <iomanip> // for setw

using namespace std;

// COMSC-210 | Lab 14: Color Class | Erick Pascual-Bautista

class Color {
    // Private: 
    int red;
    int green;
    int blue;

    public: 
    // Parameterized constructor function
    Color(int red, int green, int blue) : red(red), green(green), blue(blue) {}

    Color() {
        red = 0;
        green = 0;
        blue = 0;
    }

    Color(int redColor) {
        red = redColor;
        green = 0;
        blue = 0;
    }

    // Getters that return the associated value
    int getRed() {return red;}
    int getGreen() {return green;}
    int getBlue() {return blue;}

    // Setters that set the associtaed value 
    void setRed(int red) {this->red = red;}
    void setGreen(int green) {this->green = green;}
    void setBlue(int blue) {this->blue = blue;}

    // Print function (prints out rgb values)
    void print() {
        cout << setw(10) << "Red" << setw(10) << "Green" << setw(10) << "Blue" << endl;
        cout << setw(10) << red << setw(10) << green << setw(10) << blue << endl;
        cout << endl;
    }

};

int main() {
    // parameterized constructor
    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);
    Color blue = Color(0, 0, 255);
    red.print();
    green.print();
    blue.print();

    Color redTwo = Color(255); // partial constructor

    Color black = Color(); // default constructor

    redTwo.print();
    black.print();



    return 0;
}

