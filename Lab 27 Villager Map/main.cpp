#include <iostream>
#include <map>
#include <vector>
using namespace std;

// COMSC-210 | Lab 27: Villager Map | Erick Pascual-Bautista

void displayMenu();
void programControl(int choice);
void addVillager();

int main() {
    // stores a name(key) associated with data[ friend lvl, species, catchphrase ]
    map<string, tuple<int, string, string>> villagers;
    // while(true) {
        displayMenu();
        int choice;
        cin >> choice;
        programControl(choice);
    //}
    
    
    
    // // declarations
    // map<string, vector<string>> villagerColors;

    // // insert elements into the map
    // // note how the right-hand side of the assignment are the vector elements
    // villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    // villagerColors["Raymond"] = {"Black", "Gray", "White"};
    // villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // // access the map using a range-based for loop
    // cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    // for (auto pair : villagerColors) {
    //     cout << pair.first << ": ";
    //     for (auto color : pair.second)
    //         cout << color << " ";
    //     cout << endl;
    // }

    // // access the map using iterators
    // cout << "\nVillagers and their favorite colors (iterators):" << endl;
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



void displayMenu() {
        cout << "*** Villager MANAGER  ***" << endl;
        cout << "[1] Add Villager" << endl;
        cout << "[2] Delete Villager" << endl;
        cout << "[3] Increase Friendship" << endl;
        cout << "[4] Decrease Friendship" << endl;
        cout << "[5] Search for Villager" << endl;
        cout << "[6] Exit" << endl;
}

void programControl(int choice) {
    switch(choice) {
        case 1:
            addVillager();
            break;
        case 2:
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

void addVillager() {
    
}