#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time()
#include <cmath> // for round()

using namespace std;

// COMSC-210 | Lab 20: Chair Maker 3000 | Erick Pascual-Bautista

const int SIZE = 3;

int generateRandomInt(int, int);
float generateRandomFloat(float, float);

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
        legs = 0;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }
    Chair(int l) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
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
};

int main() {
    srand(time(0)); // seed for random number generator 
    return 0;
}

// returns a number between min and max
int generateRandomInt(int min, int max) { 
    return (min + rand() % (max - min + 1));
}

float generateRandomFloat(float min, float max) {
    floa
}