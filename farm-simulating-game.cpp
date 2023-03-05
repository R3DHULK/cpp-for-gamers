#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int randInt(int min, int max);
int sellCrop(int crop, int &money);
void plantCrop(int &crop);
void waterCrop(int crop);

int main()
{
    // Set up random number generator
    srand(time(nullptr));

    // Initialize variables
    int crop = 0;    // Crop count
    int money = 100; // Starting money
    int days = 1;    // Number of days passed

    // Main game loop
    while (money > 0)
    {
        // Display current status
        cout << "Day " << days << endl;
        cout << "Crop count: " << crop << endl;
        cout << "Money: $" << money << endl;

        // Prompt user for action
        cout << "What do you want to do?" << endl;
        cout << "1. Plant crops" << endl;
        cout << "2. Water crops" << endl;
        cout << "3. Harvest crops" << endl;
        cout << "4. Quit game" << endl;

        int choice;
        cin >> choice;

        // Perform selected action
        switch (choice)
        {
        case 1:
            plantCrop(crop);
            break;
        case 2:
            waterCrop(crop);
            break;
        case 3:
            money += sellCrop(crop, money);
            break;
        case 4:
            cout << "Thanks for playing!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }

        // Randomly add new crop
        if (randInt(1, 10) == 1)
        {
            crop++;
            cout << "A new crop has grown!" << endl;
        }

        // Increment day counter
        days++;
    }

    // Game over
    cout << "You have run out of money. Game over!" << endl;
    return 0;
}

// Generates a random integer between min and max (inclusive)
int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Sells all crops and adds to money
int sellCrop(int crop, int &money)
{
    int value = crop * 10;
    money += value;
    cout << "You have sold " << crop << " crops for $" << value << "." << endl;
    crop = 0; // Reset crop count
    return value;
}

// Plant new crop if no crop is planted
void plantCrop(int &crop)
{
    if (crop == 0)
    {
        crop = 1;
        cout << "You have planted a new crop." << endl;
    }
    else
    {
        cout << "You already have a crop planted. Wait for it to grow." << endl;
    }
}

// Water crop to speed up growth
void waterCrop(int crop)
{
    if (crop > 0)
    {
        cout << "You watered your crop. It will grow faster now." << endl;
    }
    else
    {
        cout << "You don't have a crop planted. Plant a new crop first." << endl;
    }
}
