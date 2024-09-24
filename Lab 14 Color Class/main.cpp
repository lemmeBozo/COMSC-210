#include <iostream>

using namespace std;

// COMSC-210 | Lab 14: Color Class | Erick Pascual-Bautista

class Color {
    // Private: 
    int red;
    int green;
    int blue;

    public: 
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
        cout << "Red: " << red << endl;
        cout << "Green: " << green << endl;
        cout << "Blue: " << blue << endl;
    }

};

int main() {
    Color red = Color(0, 188, 250);
    red.print();
    return 0;
}

