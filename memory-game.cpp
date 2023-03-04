#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
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

// Function to clear the console screen
void clear_screen()
{
    cout << "\033[2J\033[1;1H";
}

int main()
{
    // Set up game variables
    const int board_size = 4;
    const int board_cells = board_size * board_size;
    vector<int> board(board_cells);
    for (int i = 0; i < board_cells; i += 2)
    {
        board[i] = board[i + 1] = (i / 2) + 1;
    }
    shuffle(board.begin(), board.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

    vector<bool> revealed(board_cells, false);
    int score = 0;
    bool game_over = false;

    // Play the game
    while (!game_over)
    {
        // Clear the screen
        clear_screen();

        // Print the board
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                int index = i * board_size + j;
                if (revealed[index])
                {
                    cout << board[index] << "\t";
                }
                else
                {
                    cout << "X\t";
                }
            }
            cout << endl;
        }

        // Get the user's guess
        int guess1, guess2;
        do
        {
            cout << "Enter two coordinates (row column) to reveal a card: ";
            cin >> guess1 >> guess2;
            guess1--;
            guess2--;
        } while (guess1 < 0 || guess1 >= board_size || guess2 < 0 || guess2 >= board_size);

        int index = guess1 * board_size + guess2;
        revealed[index] = true;

        // Clear the screen
        clear_screen();

        // Print the board
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                int index = i * board_size + j;
                if (revealed[index])
                {
                    cout << board[index] << "\t";
                }
                else
                {
                    cout << "X\t";
                }
            }
            cout << endl;
        }

        // Wait for a moment before clearing the screen again
        this_thread::sleep_for(chrono::seconds(1));

        // Check if the guess was correct
        if (score < board_size * board_size / 2 && board[index] == board[(board_size * board_size) - index - 1])
        {
            score++;
            if (score == board_size * board_size / 2)
            {
                game_over = true;
                cout << "Congratulations! You win!" << endl;
            }
        }
        else
        {
            revealed[index] = false;
        }
    }

    return 0;
}
