#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get random number between min and max
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Function to simulate a hunting attempt
bool hunt()
{
    int probability = getRandomNumber(1, 100);
    if (probability <= 50)
    {
        cout << "You successfully hunted an animal!" << endl;
        return true;
    }
    else
    {
        cout << "You failed to hunt an animal." << endl;
        return false;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator with current time

    int food = 10; // Start with 10 units of food
    int daysSurvived = 0;

    cout << "Welcome to the survival game!" << endl;

    while (food > 0)
    {
        // Display status
        cout << "Days survived: " << daysSurvived << endl;
        cout << "Food remaining: " << food << endl;

        // Ask for user input
        cout << "What would you like to do?" << endl;
        cout << "1. Hunt for food" << endl;
        cout << "2. Do nothing" << endl;
        int choice;
        cin >> choice;

        // Process user input
        switch (choice)
        {
        case 1:
            if (hunt())
            {
                food += 2; // Hunted animal provides 2 units of food
            }
            else
            {
                food--; // Failed hunt consumes 1 unit of food
            }
            break;
        case 2:
            // Do nothing, but consume 1 unit of food
            food--;
            break;
        default:
            cout << "Invalid choice. Please choose 1 or 2." << endl;
            break;
        }

        daysSurvived++;

        // Check if the player has survived for 7 days
        if (daysSurvived == 7)
        {
            cout << "Congratulations! You have survived for 7 days!" << endl;
            break;
        }
    }

    if (food == 0)
    {
        cout << "You have run out of food and have starved to death." << endl;
    }

    cout << "Game over." << endl;

    return 0;
}
