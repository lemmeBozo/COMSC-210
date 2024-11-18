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

    // Starting simulation
    simulateTollBooth(lanes);

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
            cout << "Lane " << i << ": Is empty" << endl;
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
    // Probabilities
    int payChance = 46; 
    int joinChance = 39;
    int shiftChance = 15; // isn't relaly necessary but will be included
                            // in case other events are added

    for (int i = 0; i < CYCLES; i++) { // runs the simulation for 20 cycles
        cout << endl << "Time " << i + 1 << endl << endl;    
        int laneNumber = 1;
        for (auto& lane : lanes) {
            if (!lane.empty()) { // if the lane isn't empty           
                // Used to compare against event probabilities
                int chance = generateRandomInt(1,100);

                // Outputs lane number
                cout << "Lane " << laneNumber << " ";

                // If statements for events
                if (chance <= payChance) { 
                    cout << "Paid: ";
                    Car car = lane.front();
                    car.print();
                    lane.pop_front();
                } else if (chance <= payChance + joinChance) {
                    cout << "Joined lane: ";
                    Car car; // Creates a new instance of a car
                    car.print(); // prints out the details of the car
                    lane.emplace_back(car); // adds car to the back of the queue
                } else { // otherwise 
                    cout << "Switched: ";
                    Car car = lane.back(); // returns a reference to the car
                    car.print(); // prints out the details of the car
                    lane.pop_back(); // removes car from queue
                    
                    // switches the lane of the current car to the next lane
                    int nextLaneIndex = laneNumber % lanes.size();
                    lanes[nextLaneIndex].emplace_back(car);
                }
            } else { // otherwise if lane is empty
                // Special probabilities for empty queue
                int emptyLaneJoinChance = 50;

                // Used to compare against probabilities
                int chance = generateRandomInt(1,100);

                cout << "Lane " << laneNumber << " ";

                // If statement for events
                if (chance <= emptyLaneJoinChance) {
                    cout << " Joined lane: ";
                    Car car; // Creates a new instance of a car
                    car.print(); // prints out the details of the car
                    lane.emplace_back(car); // adds car to the back of the queue                    
                } else {cout << "No change" << endl;} 
            }
            laneNumber++;
        }
        // displays state of lanes at the end of each loop iteration
        cout << endl;
        displayLanes(lanes);
    }
}


