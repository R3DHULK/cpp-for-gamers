#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number between min and max (inclusive)
int random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    // Set up the game
    const int trackLength = 20;
    const int numCars = 3;
    int carPositions[numCars] = {0};
    char track[trackLength];
    for (int i = 0; i < trackLength; i++)
    {
        track[i] = '-';
    }

    // Play the game
    while (true)
    {
        // Update the positions of the cars
        for (int i = 0; i < numCars; i++)
        {
            int move = random(1, 3); // Randomly move the car 1-3 spaces
            carPositions[i] += move;
            if (carPositions[i] >= trackLength)
            {
                carPositions[i] = trackLength - 1; // Ensure the car doesn't go past the end of the track
            }
        }

        // Update the track based on the new positions of the cars
        for (int i = 0; i < trackLength; i++)
        {
            track[i] = '-';
        }
        for (int i = 0; i < numCars; i++)
        {
            track[carPositions[i]] = '0' + i; // Use the character representing the car number to show its position on the track
        }

        // Print the updated track
        cout << track << endl;

        // Check if any of the cars have won
        for (int i = 0; i < numCars; i++)
        {
            if (carPositions[i] == trackLength - 1)
            {
                cout << "Car " << i << " wins!" << endl;
                return 0;
            }
        }

        // Wait for a moment before updating the game again
        system("sleep 0.5"); // Sleep for half a second
    }

    return 0;
}
