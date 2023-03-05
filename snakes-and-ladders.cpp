#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 100;
const int NUM_SNAKES = 10;
const int NUM_LADDERS = 10;

struct Snake
{
    int head;
    int tail;
};

struct Ladder
{
    int bottom;
    int top;
};

void initBoard(Snake *snakes, Ladder *ladders)
{
    // Initialize snakes
    snakes[0] = {14, 7};
    snakes[1] = {19, 8};
    snakes[2] = {23, 16};
    snakes[3] = {40, 36};
    snakes[4] = {47, 26};
    snakes[5] = {56, 53};
    snakes[6] = {64, 60};
    snakes[7] = {88, 68};
    snakes[8] = {94, 77};
    snakes[9] = {98, 79};

    // Initialize ladders
    ladders[0] = {2, 15};
    ladders[1] = {5, 7};
    ladders[2] = {10, 25};
    ladders[3] = {20, 41};
    ladders[4] = {30, 32};
    ladders[5] = {36, 52};
    ladders[6] = {47, 63};
    ladders[7] = {59, 78};
    ladders[8] = {66, 91};
    ladders[9] = {83, 96};
}

void displayBoard(int position)
{
    cout << " ---------------------" << endl;
    for (int row = 9; row >= 0; row--)
    {
        cout << "|";
        for (int col = 0; col < 10; col++)
        {
            int i = row * 10 + col + 1;
            if (i == position)
            {
                cout << " * ";
            }
            else
            {
                cout << " " << i << " ";
            }
        }
        cout << "|" << endl;
        cout << " ---------------------" << endl;
    }
}

int rollDice()
{
    return rand() % 6 + 1;
}

int move(int position, Snake *snakes, Ladder *ladders)
{
    int oldPosition = position;
    int dice = rollDice();
    position += dice;
    if (position > BOARD_SIZE)
    {
        position = BOARD_SIZE - (position - BOARD_SIZE);
    }
    for (int i = 0; i < NUM_SNAKES; i++)
    {
        if (position == snakes[i].head)
        {
            position = snakes[i].tail;
            break;
        }
    }
    for (int i = 0; i < NUM_LADDERS; i++)
    {
        if (position == ladders[i].bottom)
        {
            position = ladders[i].top;
            break;
        }
    }
    cout << "You rolled a " << dice << ". ";
    if (position > oldPosition)
    {
        cout << "You moved forward to position " << position << "." << endl;
    }
    else if (position < oldPosition)
    {
        cout << "Oh no! You landed on a snake and slid back to position " << position << "." << endl;
    }
    else
    {
        cout << "You stay at position " << position << "." << endl;
    }
    return position;
}

int main()
{
    srand(time(NULL));
    Snake snakes[NUM_SNAKES];
    Ladder ladders[NUM_LADDERS];
    initBoard(snakes, ladders);
    int position = 1;
    char answer;
    cout << "Welcome to Snake and Ladder!" << endl;
    do
    {
        displayBoard(position);
        position = move(position, snakes, ladders);
        if (position == BOARD_SIZE)
        {
            cout << "Congratulations, you have won the game!" << endl;
            break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    cout << "Thanks for playing!" << endl;
    return 0;
}
