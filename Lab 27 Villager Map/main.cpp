#include <iostream>
#include <map>
#include <vector>
#include <tuple> // this is really cool reminds me of how arrays work in javascript

using namespace std;

// COMSC-210 | Lab 27: Villager Map | Erick Pascual-Bautista

// Helper functions
void clearScreen() {cout << "\033[2J\033[1;1H";} // clears the screen (I searched this up)
void printMap(const map<string, tuple<int, string, string>>&);


// menu 
void displayMenu();

// menu functions
bool programControl(int, map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void searchForVillager(map<string, tuple<int, string, string>>&);


int main() {
    // stores a name(key) associated with data[ friend lvl, species, catchphrase ]
    map<string, tuple<int, string, string>> village;
    int exit = false;
    while(!exit) {
        clearScreen();
        printMap(village);
        cout << endl << endl;
        displayMenu();
        int choice;
        cin >> choice;
        exit = programControl(choice, village);
    }
    
    
    

    return 0;
}

// prints out the map
void printMap(const map<string, tuple<int, string, string>>& village) {
    int i = 1;
    for (const auto& villager : village) { // for each villager in my village
        cout << "[" << i << "] " << villager.first << ": ";
        cout << "[" << get<0>(villager.second) << ", " <<
        get<1>(villager.second) << ", " <<
        get<2>(villager.second) << "]" << endl;
        i++;
    }
}

// displays the menu
void displayMenu() {
        cout << "*** Villager MANAGER  ***" << endl;
        cout << "[1] Add Villager" << endl;
        cout << "[2] Delete Villager" << endl;
        cout << "[3] Increase Friendship" << endl;
        cout << "[4] Decrease Friendship" << endl;
        cout << "[5] Search for Villager" << endl;
        cout << "[6] Exit" << endl;
        cout << "ENTER CHOICE: ";
}

// handles the choice for the user and calls the appropriate functions
bool programControl(int choice, map<string, tuple<int, string, string>>& village) {
    switch (choice) {
        case 1:
            clearScreen();
            addVillager(village);
            break;
        case 2:
            clearScreen();
            deleteVillager(village);
            break;
        case 3:
            clearScreen();
            increaseFriendship(village);
            break;
        case 4:
            clearScreen();
            // there is no way I spend all that time
            // before I figured out that decreaseFriendship(village) wasn't included
            decreaseFriendship(village);
            break;
        case 5: 
            clearScreen();
            searchForVillager(village);
            break;
        case 6:
            cout << "EXITING" << endl;
            return true;
        default:
            cout << "INVALID VALUE" << endl;
            break;
    }
    return false;
}

// adds a villager to the map
void addVillager(map<string, tuple<int, string, string>>& village) {
    string name;
    int friendLevel;
    string species;
    string catchphrase;

    cin.ignore();

    cout << "Villager name: ";
    getline(cin, name);
    cout << "Friendship level: ";
    cin >> friendLevel;
    
    cin.ignore();

    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    // creates a tupple made up of the below values and sets it equal to its key (name)
    //      key = data
    // i.e. name = tupple
    village[name] = make_tuple(friendLevel, species, catchphrase);
}


// deletes a villager from the map
void deleteVillager(map<string, tuple<int, string, string>>& village) {
    // first print out the map
    printMap(village);
    // then prompt the user to select which villager to delete    
    int choice;
    cout << "Select a villager to delete: " << endl;
    cin >> choice;

    // delete the villager
    auto iterator = village.begin();
    advance(iterator, (choice - 1));
    if (iterator != village.end()) { // if within range of the map
        village.erase(iterator); // deletes the value at the iterator position
    }

}

void increaseFriendship(map<string, tuple<int, string, string>>& village) {
    // Print out map
    printMap(village);

    // Prompt user to select villager to increase friendsip with    
    int choice;
    cout << "Select a villager to increase friendship with: ";
    cin >> choice;

    auto iterator = village.begin();
    advance(iterator, (choice - 1));

    // increments friendship by 1
    if (iterator != village.end()) { // if within range
        auto& friendshipLevel = get<0>(iterator->second);
        if (friendshipLevel < 10) {
            friendshipLevel++;            
        }

    } 
}

void decreaseFriendship(map<string, tuple<int, string, string>>& village) {
    printMap(village);
    int choice;
    cout << "Select a villager to decrease friendship with: ";
    cin >> choice;

    auto iterator = village.begin();
    advance(iterator, (choice - 1));

    if (iterator != village.end()) {
        auto& friendshipLevel = get<0>(iterator->second);
        if (friendshipLevel > 0) {
            friendshipLevel--;
        }
    }
}

void searchForVillager(map<string, tuple<int, string, string>>& village) {
    cout << "Type in name to search for: ";
    cin.ignore();
    
    string name;
    getline(cin, name);

    auto iterator = village.find(name);
    if (iterator != village.end()) {
        cout << "Villager found!" << endl;
        cout << "Friendship Level: " << get<0>(iterator->second) << endl;
        cout << "Species: " << get<1>(iterator->second) << endl;
        cout << "Catchphrase: " << get<2>(iterator->second) << endl;
    } else {cout << "Villager was NOT found" << endl;}
    cout << "Press Enter to continue...";
    cin.ignore();
}