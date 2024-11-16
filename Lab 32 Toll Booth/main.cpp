#include <iostream>
#include <deque>
#include "Car.h"

// For RNG
#include <random>
#include <chrono>

using namespace std;

// COMSC-210 | Lab 32: Tool Booth | Erick Pascual-Bautista

// Global variables
const int INITIAL_QUEUE_SIZE = 2;

// Function prototypes
int generateRandomInt(int, int); // helper function

void initializedQueue(deque<Car>&, int);
void displayQueue(deque<Car>&);
void simulateTollBooth(deque<Car>&);

int main() {
    deque<Car> tollBoothQueue;

    // Initializing queue
    initializedQueue(tollBoothQueue, INITIAL_QUEUE_SIZE);

    // Printing out the initial queue before starting simulation
    cout << "Initial queue: " << endl; 
    displayQueue(tollBoothQueue);

    return 0;
}

// Reusing Code from Lab 21
int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
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

void simulateTollBooth(deque<Car>& queue) {
    while (!queue.empty()) { // while the queue is empty run the simulation
        if (generateRandomInt(1,55) <= 55) { // 55% chance (Car pays toll)
            queue.pop_front(); // removes the car from the 
                               //queue as they have already payed
        } 
        if (generateRandomInt(1,45) <= 45) {
            
        }
    }
}


