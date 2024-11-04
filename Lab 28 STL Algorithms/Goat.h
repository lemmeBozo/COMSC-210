// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
#include <string>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string name) {
        this->name = name;
        age = 0;
        color = "";
    }

    Goat (string name, int age) {
        this->name = name;
        this-> age = age;
        color = "";
    }

    Goat (string name, int age, string color) {
        this->name = name;
        this->age = age;
        this->color = color;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    //write overloaded < operator for the std::list
    bool operator<(const Goat& goat) const {
        return age < goat.age;
    }

    // Overloadedd << operator
    friend ostream& operator<<(ostream &os, const Goat &goat) {
        os << goat.name << " (" << goat.age << ", " << goat.color << ")" << endl;
        return os;
    }

    
};



#endif