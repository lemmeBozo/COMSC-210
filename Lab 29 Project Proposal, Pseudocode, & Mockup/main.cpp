#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

// COMSC-210 | Lab 29: Project Proposal, Pseudocode, & Mockup | Erick Pascual-Bautista

// function prototypes
void simulateTrafficFlow(map<string, vector<list<string>>>&, int);

int main() {
    // Defining the map with lane names as keys, each holding an array of 3 list
    map<string, vector<list<string>>> trafficLanes;
    // example of data trafficLanes["Northbound"] = {{"Car1"}, {"Car2"}, {"Car3"}};

    // Opening external file
    ifstream file("traffic-data.txt");
    if (!file.is_open()) { // if the file isn't open
        cout << "Error opening file" << endl;
        return 0; // end program execution
    }

    // File processing
    // For ecah line in the file:
    string line;
    while (getline(file,line)) {
        // 1. Split the line into Lane direction and state with cars parts
        // Example "Northbound" and "Green: Car1, Car2 etc...."
        // Will use a delimited like coma to separate lane direction from the rest

        // 2. Trim and store lane direction

        // 3. Extract the light state nad cars

        // 4. Map the light state to th ecorrect index in the vector of lists
        // i.e. Green is 0 index
        // Red is 1 index
        // Yellow is 2 index

        // 5. Split the list of cars into the correct list
    }

    // Closing file
    file.close();

    // Displaying inital state of lanes before simulation
    cout << "Inital Traffic Lane state:" << endl;
    for (const auto& lane : trafficLanes) {
        cout << "Lane: " << lane.first << "Initial State: {...}" << endl;
        // Add more detailed inital state display if needed
    }

    // Beginning simulation
    const int timePeriods = 25;
    simulateTrafficFlow(trafficLanes, timePeriods);

    return 0;
}

// Simulates traffic light changes and manages car states

//the string is the key, while the data is a vector of lists of strings
void simulateTrafficFlow(map<string, vector<list<string>>>& lanes, int periods) {
    // Pseudo code: 
    // 1. Iterate throughout each lane in the map
    // 2. Adjust the car lists based on the light state
    // 3. Print or log the traffic changes for each lane at this itme period

   // For each time period
   for (int i = 0; i < periods; i++) {
        // Display the current time period
        cout << "Time period: " << i + 1 << endl;
        // 1. Iterate throughout each lane in the map
        // Loop through each lane in the map
        for (auto& lane : lanes) { // for each lane in lanes map
            // For each light state (green, red or yellow)
            for (int state = 0; state < 3; state++) {
                // Processing each state of the car
                // 2. Adjust the car lists based on the light state
                switch (state) {
                    case 0: // if state is green light
                        // move cars from the waiting list to the moving list
                        break;
                    case 1: // if state is red light
                        // cars remain in the waiting list
                        break;
                    case 2: // if state is yellow light 
                        // keep cars in the slowing list
                        break;
                }
            }

            // Apply random events (car breakdown, accidents, new car arrivals etc...)
            // If a breakdown/accident occurs cars are added to the waitlist
            // If a new car arrives add to the appropriate list based on the light        

        } // End of State loop

        // 3. Print or log the traffic changes for each lane at this itme period
        // Display the updated state of each lane after processing this time period
        // example of data trafficLanes["Northbound"] = {{"Car1"}, {"Car2"}, {"Car3"}};
        //                                                  green     red      yellow
   } 
}

