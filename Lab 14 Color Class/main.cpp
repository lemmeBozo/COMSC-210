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
    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);
    Color blue = Color(0, 0, 255);
    red.print();
    green.print();
    blue.print();
    return 0;
}

