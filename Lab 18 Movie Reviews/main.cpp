#include <iostream>
#include <string> 
#include "LinkedList.h" // personal linked list I created
using namespace std;

// COMSC-210 | Lab 18: Movie Reviews | Erick Pascual-Bautista

struct Review {
    float rating;
    string comment;

    Review(float rating, string comment) : rating(rating), comment(comment) {};
};

void getReview();

int main() {

    LinkedList<Review> list;
    getReview();


    return 0;
}

void getReview() {
    bool pushFront = false;
    bool pushBack = false;
    int choice = 0;

    cout << "Which linked list method would you like to use?" << endl;
    cout << "\t[1] New nodes are added to the head of the linked list" << endl;
    cout << "\t[2] New nodes are added to the tail of the linked list" << endl;
    cout << "Choice: ";

    cin >> choice; // gets user choice


}