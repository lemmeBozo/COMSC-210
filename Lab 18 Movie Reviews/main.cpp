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

void addReviews(LinkedList<Review>&); // function prototype for adding reviews
void outputReviews(LinkedList<Review>&); // function prototype for outputing reviews

int main() {

    LinkedList<Review> list;
    addReviews(list);


    return 0;
}

void addReviews(LinkedList<Review>& list) { // function declaration for adding reviews
    bool moreReviews = true;

    while(moreReviews) { // while moreReviews = true;
        float rating = 0;
        int choice = 0;
        string comment;

        cout << "Which linked list method would you like to use?" << endl;
        cout << "\t[1] New nodes are added to the head of the linked list" << endl;
        cout << "\t[2] New nodes are added to the tail of the linked list" << endl;
        cout << "Choice: ";

        cin >> choice; // gets user choice

        cout << endl << "Enter movie review rating 0-5 (floats included): " ;
        cin >> rating; // gets user rating
        cin.ignore();
        cout << "Enter move review comments: ";
        getline(cin, comment); // gets user comment (note gets the whole line instead of only the first string)

        cout << endl << "Would you like to enter anothe review (0 for no 1 for yes): ";
        Review review(rating,comment); // Instantiates a review struct

        if (choice == 1) { // push review to the front of the list
            list.pushFront(review);
        } else { // push review to the back of the list
            list.pushBack(review);
        }

        cin >> moreReviews;
    }
}

void outputReviews(LinkedList<Review>& list) {
    // the way my code works is by poping the elements to see the next one
    // should I have added an iterator to iterate through my linked list to see what each element is?
    // instead of just poping them?
    int i = 1;
    while(!list.isEmpty()) { // while the list is not empty run the below code
        cout << "Outputting all reviews: " << endl;
        Review currReview = list.peek();
        cout << "\tReview #" << i << ": " << currReview.rating << ": " << currReview.comment << endl;
        list.pop();
        i++;
    }
}