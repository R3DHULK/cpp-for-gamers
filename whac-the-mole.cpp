#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Function to generate a random number between min and max (inclusive)
int get_random_number(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

int main()
{
    // Initialize game variables
    const int NUM_HOLES = 9;
    const int NUM_ROUNDS = 3;
    int score = 0;

    // Print welcome message
    cout << "Welcome to CLI Whac-a-Mole!" << endl;

    // Play game for NUM_ROUNDS rounds
    for (int round = 1; round <= NUM_ROUNDS; round++)
    {
        cout << "Round " << round << endl;

        // Initialize round variables
        int current_score = 0;
        bool holes[NUM_HOLES] = {false};

        // Play round for 30 seconds
        auto start_time = std::chrono::system_clock::now();
        while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time).count() < 30)
        {
            // Choose a random hole
            int hole_number = get_random_number(0, NUM_HOLES - 1);

            // If hole is not already active, activate it
            if (!holes[hole_number])
            {
                holes[hole_number] = true;

                // Print board with active hole
                cout << "+---+---+---+" << endl;
                for (int i = 0; i < NUM_HOLES; i++)
                {
                    if (holes[i])
                    {
                        cout << "| X ";
                    }
                    else
                    {
                        cout << "|   ";
                    }
                }
                cout << "|" << endl;
                cout << "+---+---+---+" << endl;

                // Wait for player to hit ENTER
                cout << "Hit ENTER when ready to whac!" << endl;
                cin.ignore();

                // If player hit ENTER while the hole was active, add to score
                if (holes[hole_number])
                {
                    current_score++;
                    holes[hole_number] = false;
                    cout << "WHAC!" << endl;
                }

                // Wait for 1 second before clearing board
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

        // Print round score
        cout << "Round " << round << " score: " << current_score << endl;

        // Add round score to total score
        score += current_score;
    }

    // Print total score
    cout << "Total score: " << score << endl;

    return 0;
}
