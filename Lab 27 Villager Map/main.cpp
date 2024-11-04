#include <iostream>
#include <map>
#include <vector>
#include <tuple> // this is really cool reminds me of how arrays work in javascript

using namespace std;

// COMSC-210 | Lab 27: Villager Map | Erick Pascual-Bautista

// Helper functions
void clearScreen() {cout << "\033[2J\033[1;1H";} // clears the screen (I searched this up)
void findVillager(int index) {}
void printMap(const map<string, tuple<int, string, string>>&);


// menu 
void displayMenu();

// menu functions
bool programControl(int, map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);


int main() {
    // stores a name(key) associated with data[ friend lvl, species, catchphrase ]
    map<string, tuple<int, string, string>> village;
    int exit = false;
    while(!exit) {
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
        clearScreen();
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
    switch(choice) {
        case 1:
            clearScreen();
            addVillager(village);
            break;
        case 2:
            clearScreen();
            deleteVillager(village);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout << "EXITTING" << endl;
            return true;
            break;
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

    cout << endl << "Villager name: ";
    getline(cin, name);
    cout << endl << "Friendship level: ";
    cin >> friendLevel;
    
    cin.ignore();

    cout << endl << "Species: ";
    getline(cin, species);
    cout << endl << "Catchphrase: ";
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
    cin.ignore();
    cin >> choice;
    cout << "Select a villager to delete: " << endl;

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
    cin.ignore();
    cin >> choice;
    cout << "Select a villager to increase friendship with: ";

    // increments friendship by 1
}