#include <iostream>
#include <vector> 
#include <random> // for rng
#include <chrono> // for better time percision
#include <cmath> // for rounding
#include <iomanip>


using namespace std;

// COMSC-210 | Lab 20: Chair Maker 3000 | Erick Pascual-Bautista

const int SIZE = 3;

int generateRandomInt(int, int);
double generateRandomDouble(double, double);

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    // TODO
    //  change legs such that it either equals 3 or 4 legs
    // change prices such that they range from 100.00 to 999.99
    Chair() {
        prices = new double[SIZE];
        legs = generateRandomInt(3,4);
        for (int i = 0; i < SIZE; i++)
            prices[i] = generateRandomDouble(100.00, 999.99);
    }
    
    Chair(int l) {
        prices = new double[SIZE];
        legs = generateRandomInt(3,4);
        for (int i = 0; i < SIZE; i++)
            prices[i] = generateRandomDouble(100.00, 999.99);
    }

    Chair(int l, vector<double>& priceVector) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = priceVector[i];
        }
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
    ~Chair() {delete[] prices;}
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}

double generateRandomDouble(double min, double max) {
    // returns time in miliseconds
    // using type of auto as that is convention when dealing with chrono
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_real_distribution<double> distribution(min,max); 

    // Generates random number
    double ranValue = distribution(generator);
    return round(ranValue * 100.00) / 100.00;
}

int generateRandomInt(int min, int max) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed); // Mersene Twister RNG algorithm
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}