#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Define the player's swimmer class
class Swimmer {
public:
    Swimmer(string name, int speed) {
        this->name = name;
        this->speed = speed;
        this->distance = 0;
    }

    string getName() {
        return name;
    }

    int getSpeed() {
        return speed;
    }

    int getDistance() {
        return distance;
    }

    void swim() {
        int distance_swimmed = rand() % (speed + 1);
        distance += distance_swimmed;
        cout << name << " swam " << distance_swimmed << " meters." << endl;
    }

private:
    string name;
    int speed;
    int distance;
};

// Define a function to generate a random swimmer
Swimmer generateSwimmer() {
    string names[] = {"Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Henry", "Isabelle", "Jack"};
    int speeds[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int random_index = rand() % 10;
    return Swimmer(names[random_index], speeds[random_index]);
}

int main() {
    srand(time(0));

    cout << "Welcome to the swimming pool game!" << endl;

    // Generate three swimmers
    Swimmer swimmer1 = generateSwimmer();
    Swimmer swimmer2 = generateSwimmer();
    Swimmer swimmer3 = generateSwimmer();

    // Display the swimmers' names and speeds
    cout << "Swimmer 1: " << swimmer1.getName() << " (speed: " << swimmer1.getSpeed() << ")" << endl;
    cout << "Swimmer 2: " << swimmer2.getName() << " (speed: " << swimmer2.getSpeed() << ")" << endl;
    cout << "Swimmer 3: " << swimmer3.getName() << " (speed: " << swimmer3.getSpeed() << ")" << endl;

    // Loop until one swimmer has swum 50 meters
    while (swimmer1.getDistance() < 50 && swimmer2.getDistance() < 50 && swimmer3.getDistance() < 50) {
        swimmer1.swim();
        swimmer2.swim();
        swimmer3.swim();
    }

    // Determine the winner
    Swimmer winner;
    if (swimmer1.getDistance() >= 50) {
        winner = swimmer1;
    } else if (swimmer2.getDistance() >= 50) {
        winner = swimmer2;
    } else {
        winner = swimmer3;
    }

    // Display the winner
    cout << winner.getName() << " wins!" << endl;

    return 0;
}
