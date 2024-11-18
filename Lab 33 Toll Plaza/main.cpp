#include <iostream>
#include <deque>
#include <vector>
#include "Car.h"

// For RNG
#include <random>
#include <chrono>

using namespace std;

// COMSC-210 | Lab 33: Toll Plaza | Erick Pascual-Bautista

// Global variables
const int INITIAL_QUEUE_SIZE = 3;

// Function prototypes
int generateRandomInt(int, int); // helper function

void initializedArray(vector<deque<Car>>&, int);

void displayLanes(vector<deque<Car>>& lanes);
void simulateTollBooth(deque<Car>&);

int main() {
    // Creating an array of toll booth lanes (4)
    vector<deque<Car>> lanes;
    initializedArray(lanes, INITIAL_QUEUE_SIZE);


    return 0;
}

// Reusing Code from Lab 21
int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void initializedArray(vector<deque<Car>>& lanes, int size) {
    for (int i = 0; i < lanes.size(); i++) { // loops through each deque
        for (int j = 0; j < size; j++) { // for each deques adds n cars
            lanes[0].emplace_back(Car());
        }
    }
}

void displayLanes(vector<deque<Car>>& lanes) {
    for (const auto& queue : lanes) { // for each queue in lanes array
    
        for (auto& car : queue) { // for each car in the queues

        }
    }




    // if (queue.empty()) { // if the queue is empty
    //     cout << "No one waiting in line" << endl; // print out no one is waiting
    // } else { // otherwise print display the cars in line
    //     for (auto& car : queue) { // for every car in the queue
    //         cout << "\t";
    //         car.print(); // print out the data about the car
    //     }
    // }
}

void simulateTollBooth(deque<Car>& queue) {
    int time = 1;
    while (!queue.empty()) { // while the queue is empty run the simulation
        // I am going to assume only 1 operation may happen per time period
        cout << endl << "Time " << time;
        if (generateRandomInt(1,100) <= 55) { // 55% chance (Car pays toll)
            cout << " Operation: Car Paid: "; 
            Car car = queue.front();
            car.print();

            queue.pop_front(); // removes the car from the 
                               //queue as they have already payed
        } else {
            cout << " Operation: Joined lane: ";
            Car car; // create a new car
            car.print();
            queue.emplace_back(car);
        }
        cout << "Queue: ";
        displayQueue(queue);
        time++;
    }
    // the above will run until the queue is empty
}


