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

// Function to simulate a single kick
bool kick()
{
    const int goalSize = 3;
    int kickPos = random(1, 10);               // Randomly choose where to kick the ball
    int goalPos = random(1, 10);               // Randomly choose where the goal is
    return abs(kickPos - goalPos) <= goalSize; // Determine if the kick was successful
}

// Function to simulate a game
int playGame()
{
    const int numKicks = 5;
    int score = 0;

    cout << "Let's start the game!" << endl;

    for (int i = 1; i <= numKicks; i++)
    {
        cout << "Kick " << i << ": ";
        bool success = kick();
        if (success)
        {
            score++;
            cout << "GOAL!" << endl;
        }
        else
        {
            cout << "Missed." << endl;
        }
    }

    cout << "The game is over!" << endl;
    cout << "Your score: " << score << endl;

    return score;
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    int totalScore = 0;
    int numGames = 0;

    while (true)
    {
        cout << "Welcome to the football game!" << endl;
        cout << "Press enter to play, or type 'quit' to exit." << endl;

        string input;
        getline(cin, input);

        if (input == "quit")
        {
            break;
        }

        int score = playGame();
        totalScore += score;
        numGames++;

        cout << "Your total score after " << numGames << " games: " << totalScore << endl;
        cout << "Average score per game: " << static_cast<double>(totalScore) / numGames << endl;
    }

    return 0;
}
