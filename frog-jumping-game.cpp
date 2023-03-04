#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;

// Struct to represent a frog
struct Frog
{
    int x;
    int y;
};

// Function to print the game board
void printBoard(const vector<vector<char>> &board)
{
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            cout << board[y][x];
        }
        cout << endl;
    }
}

// Function to move the frog up
void moveUp(Frog &frog)
{
    if (frog.y > 0)
    {
        frog.y--;
    }
}

// Function to move the frog down
void moveDown(Frog &frog)
{
    if (frog.y < BOARD_HEIGHT - 1)
    {
        frog.y++;
    }
}

// Function to move the frog left
void moveLeft(Frog &frog)
{
    if (frog.x > 0)
    {
        frog.x--;
    }
}

// Function to move the frog right
void moveRight(Frog &frog)
{
    if (frog.x < BOARD_WIDTH - 1)
    {
        frog.x++;
    }
}

// Function to update the game board
void updateBoard(vector<vector<char>> &board, Frog &frog)
{
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            if (y == frog.y && x == frog.x)
            {
                board[y][x] = 'F';
            }
            else
            {
                board[y][x] = '.';
            }
        }
    }
}

// Function to play the game
void playGame()
{
    vector<vector<char>> board(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, '.'));
    Frog frog = {4, 9};
    board[frog.y][frog.x] = 'F';

    while (true)
    {
        printBoard(board);

        cout << "Use the w/a/s/d keys to move the frog. Press Q to quit." << endl;

        char input;
        cin >> input;

        if (input == 'Q' || input == 'q')
        {
            break;
        }

        switch (input)
        {
        case 'w':
        case 'W':
            moveUp(frog);
            break;
        case 'a':
        case 'A':
            moveLeft(frog);
            break;
        case 's':
        case 'S':
            moveDown(frog);
            break;
        case 'd':
        case 'D':
            moveRight(frog);
            break;
        }

        updateBoard(board, frog);
    }

    cout << "Thanks for playing!" << endl;
}

int main()
{
    playGame();
    return 0;
}

