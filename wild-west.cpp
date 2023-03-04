#include <iostream>
#include <string>

using namespace std;

// Function to print the game instructions
void printInstructions()
{
    cout << "Welcome to the Wild West! Your mission is to catch the notorious outlaw, Jesse James." << endl;
    cout << "You have a limited number of bullets, so use them wisely. Good luck!" << endl;
    cout << "Commands: 'shoot', 'reload', 'quit'" << endl;
}

// Function to play the game
void playGame()
{
    // Initialize game variables
    int bullets = 6;
    bool jesseJamesCaught = false;
    bool gameWon = false;
    string input;

    // Print instructions
    printInstructions();

    // Game loop
    while (bullets > 0 && !gameWon)
    {
        // Get player input
        cout << "You have " << bullets << " bullets. Enter command: ";
        getline(cin, input);

        // Process player input
        if (input == "shoot")
        {
            bullets--;
            cout << "You shoot your gun..." << endl;

            // Generate a random number between 1 and 10
            int randomNum = rand() % 10 + 1;

            // If the number is 1-4, Jesse James is caught
            if (randomNum >= 1 && randomNum <= 4)
            {
                jesseJamesCaught = true;
                gameWon = true;
                cout << "You caught Jesse James! You win!" << endl;
            }
            else
            {
                cout << "You missed Jesse James. He's still on the loose." << endl;
            }
        }
        else if (input == "reload")
        {
            bullets = 6;
            cout << "You reload your gun." << endl;
        }
        else if (input == "quit")
        {
            cout << "Quitting game." << endl;
            return;
        }
        else
        {
            cout << "Invalid command. Please enter 'shoot', 'reload', or 'quit'." << endl;
        }
    }

    // If the player runs out of bullets without catching Jesse James, they lose
    if (bullets == 0 && !jesseJamesCaught)
    {
        cout << "You ran out of bullets and Jesse James got away. Game over." << endl;
    }
}

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    playGame();

    return 0;
}
