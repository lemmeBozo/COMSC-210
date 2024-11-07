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
        return; // end program execution
    }

    // File processing
    // For ecah line in the file:
    //  Extract lane name and car details
    //  insert car details into the appropriate list in the vector based on its state

    // Closing file
    file.close();

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
    // 2. Depending on the time, change the light state (i.e. green, red, yellow)
    // 3. Adjust the car lists based on the light state
    // 4. Print or log the traffic changes for each lane at this itme periond

   // For each time period
   for (int i = 0; i < periods; i++) {
        // Display the current time period
        cout << "Time period: " << i + 1 << endl;
   }

   // Loop through each lane in the map
   for (auto& lane : lanes) { // for each lane in lanes map
        // Get the current state of the lane (i.e. green, yellow or red)

        // Depending on light state do the following:
        

        
        // If green, move the cars from the waiting list to the moving list
        // If yellow move cars to the slowing list
        // If red keep cars in the waiting list

        // Apply random events (car breakdown, accidents, new car arrivals etc...)
        // If a breakdown/accident occurs cars are added to the waitlist
        // If a new car arrives add to the appropriate list based on the light
   }

}

