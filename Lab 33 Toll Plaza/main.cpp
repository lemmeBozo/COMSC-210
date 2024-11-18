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
    // Probabilities
    int payChance = 46; 
    int joinChance = 39;
    int shiftChance = 15; 

    for (int i = 0; i < CYCLES; i++) { // runs the simulation for 20 cycles
        vector<string> operations; // will hold operations that occur
        cout << endl << "Time " << i + 1 << endl;    
        int laneNumber = 1;
        for (auto& lane : lanes) {
            if (!lane.empty()) { // if the lane isn't empty           
                // Used to compare against event probabilities
                int chance = generateRandomInt(1,100);
                cout << "Lane " << laneNumber << ": ";
                if (chance <= payChance) { 
                    cout << "Paid: ";
                    Car car = lane.front();
                    car.print();
                    lane.pop_front();
                } else if (chance <= payChance + joinChance) {
                        cout << "Car has joined queue" << endl;
                } else if (chance <= payChance + joinChance + shiftChance) {
                    // the above condition is not necessary (is implied)
                    // but will include in case other events are added instead using else {}
                    cout << "Car will chance lanes" << endl;
                }
            } else { // otherwise you

            }
            // if lane is NOT empty 
            // regular probalities
            // else
        }
        laneNumber++;
    }
}


