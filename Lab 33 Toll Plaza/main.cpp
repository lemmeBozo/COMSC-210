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
int CYCLES = 20;

// Function prototypes
int generateRandomInt(int, int); // helper function

void initializedArray(vector<deque<Car>>&);
void displayLanes(vector<deque<Car>>&);

void simulateTollBooth(vector<deque<Car>>&);

int main() {
    // Creating an array of toll booth lanes (4)
    vector<deque<Car>> lanes(4);
    
    // Initializing the array with cars in each lane
    initializedArray(lanes);

    // displays the Initial state of the lanes
    cout << "Initial state of lanes" << endl;
    displayLanes(lanes);
    return 0;
}

// Reusing Code from Lab 21
int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void initializedArray(vector<deque<Car>>& lanes) {
    for (int i = 0; i < lanes.size(); i++) { // loops through each deque
        for (int j = 0; j < generateRandomInt(1, 3); j++) { // adds 1-3 car for each queue
            lanes[i].emplace_back(Car());
        }
    }
}

void displayLanes(vector<deque<Car>>& lanes) {
    int i = 1;
    for (auto& lane : lanes) { // for lane in lanes array
        if (lane.empty()) { // if the lane is empty, output status to console
            cout << "Lane " << i << ": is empty" << endl;
        } else { // otherwise 
            cout << "Lane " << i << ": " << endl;
            for (auto& car : lane) { // print out each car in the lane
                cout << "\t";
                car.print(); 
            }        
        }
        i++;
    }
}

void simulateTollBooth(vector<deque<Car>>& lanes) {
    for (int i = 0; i < CYCLES; i++) { // runs the simulation for 20 cycles
        cout << endl << "Time " << time;    
        for (auto& lane : lanes) {
            if ()
        }
    }


    // int time = 1;
    // while (!queue.empty()) { // while the queue is empty run the simulation
    //     // I am going to assume only 1 operation may happen per time period

    //     if (generateRandomInt(1,100) <= 55) { // 55% chance (Car pays toll)
    //         cout << " Operation: Car Paid: "; 
    //         Car car = queue.front();
    //         car.print();

    //         queue.pop_front(); // removes the car from the 
    //                            //queue as they have already payed
    //     } else {
    //         cout << " Operation: Joined lane: ";
    //         Car car; // create a new car
    //         car.print();
    //         queue.emplace_back(car);
    //     }
    //     cout << "Queue: ";
    //     displayQueue(queue);
    //     time++;
    // }
    // // the above will run until the queue is empty
}


