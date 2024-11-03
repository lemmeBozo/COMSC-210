#include <iostream>
#include <map>
#include <vector>
#include <tuple> // this is really cool reminds me of how arrays work in javascript

using namespace std;

// COMSC-210 | Lab 27: Villager Map | Erick Pascual-Bautista

void printMap(const map<string, tuple<int, string, string>>&);

void displayMenu();
void programControl(int, map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);

int main() {
    // stores a name(key) associated with data[ friend lvl, species, catchphrase ]
    map<string, tuple<int, string, string>> village;
    // while(true) {
        displayMenu();
        int choice;
        cin >> choice;
        programControl(choice, village);
    //}
    
    
    
    // // declarations
    // map<string, vector<string>> villagerColors;

    // // insert elements into the map
    // // note how the right-hand side of the assignment are the vector elements
    // villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    // villagerColors["Raymond"] = {"Black", "Gray", "White"};
    // villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // // access the map using a range-based for loop
    // cout << "village and their favorite colors (range-based for loop):" << endl;
    // for (auto pair : villagerColors) {
    //     cout << pair.first << ": ";
    //     for (auto color : pair.second)
    //         cout << color << " ";
    //     cout << endl;
    // }

    // // access the map using iterators
    // cout << "\nvillage and their favorite colors (iterators):" << endl;
    // for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
    //                                            it != villagerColors.end(); ++it) {
    //     cout << it->first << ": ";
    //     for (auto color : it->second) {
    //         cout << color << " ";
    //     }
    //     cout << endl;
    // }

    // // delete an element
    // villagerColors.erase("Raymond");

    // // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto it = villagerColors.find(searchKey);
    // if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
    //                                    // if searchKey is not found
    //     cout << "\nFound " << searchKey << "'s favorite colors: ";
    //     for (auto color : it->second)  // range loop to traverse the value/vector
    //         cout << color << " ";
    //     cout << endl;
    // } else
    //     cout << endl << searchKey << " not found." << endl;

    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerColors.size() << endl;
    // villagerColors.clear();
    // cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}

// prints out the map
void printMap(const map<string, tuple<int, string, string>>& village) {
    cout << "This works" << endl;
    for (const auto& villager : village) { // for each villager in my village
        cout << villager.first << endl;
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
void programControl(int choice, map<string, tuple<int, string, string>>& village) {
    switch(choice) {
        case 1:
            addVillager(village);
            break;
        case 2:
            deleteVillager(village);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "INVALID VALUE" << endl;
            return;
    }
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
}