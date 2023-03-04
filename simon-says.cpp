#include <iostream>
#include <ctime>

using namespace std;

// Number of turns to complete the game
const int NUM_TURNS = 5;

// Game objects
int sequence[NUM_TURNS];
int input[NUM_TURNS];

// Generate a random sequence of numbers
void generate_sequence()
{
    srand(time(NULL));
    for (int i = 0; i < NUM_TURNS; i++)
    {
        sequence[i] = rand() % 4 + 1;
    }
}

// Display a sequence of numbers
void display_sequence()
{
    cout << "Simon says: ";
    for (int i = 0; i < NUM_TURNS; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
}

// Get user input for the sequence
void get_input()
{
    cout << "Enter the sequence (separated by spaces): ";
    for (int i = 0; i < NUM_TURNS; i++)
    {
        cin >> input[i];
    }
}

// Compare the user input to the sequence
bool compare_sequence()
{
    for (int i = 0; i < NUM_TURNS; i++)
    {
        if (input[i] != sequence[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "*** Simon Says ***" << endl;
    generate_sequence();
    display_sequence();
    get_input();
    if (compare_sequence())
    {
        cout << "Correct!" << endl;
    }
    else
    {
        cout << "Incorrect!" << endl;
    }
    return 0;
}
