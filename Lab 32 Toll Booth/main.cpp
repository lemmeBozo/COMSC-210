#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// COMSC-210 | Lab 32: Tool Booth | Erick Pascual-Bautista

// Global variables
const int INITIAL_QUEUE_SIZE = 2;

// Function prototypes
void initializedQueue(deque<Car>&, int);
void displayQueue(deque<Car>&);

int main() {
    deque<Car> tollBoothQueue;

    // Initializing queue
    initializedQueue(tollBoothQueue, INITIAL_QUEUE_SIZE);

    // Printing out the initial queue before starting simulation
    cout << "Initial queue: " << endl; 
    displayQueue(tollBoothQueue);

    return 0;
}

void initializedQueue(deque<Car>& queue, int size) {
    for (int i = 0; i < size; i++) {
        queue.emplace_back(Car()); // Constructs car object 
                                   //and directly places it in queue

    }
}

void displayQueue(deque<Car>& queue) {
    if (queue.empty()) { // if the queue is empty
        cout << "No one waiting in line" << endl; // print out no one is waiting
    } else { // otherwise print display the cars in line
        for (auto& car : queue) { // for every car in the queue
            cout << "\t";
            car.print(); // print out the data about the car
        }
    }
}