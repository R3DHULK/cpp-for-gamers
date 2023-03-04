#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_Board(char board[7][7]);
void boardm(char board[7][7]);
void mines(char board[7][7]);
void get_Input(int *x, int *y, char board1[7][7]);

int main()
{
    cout << "Minesweeper is a deceptively simple test of memory and reasoning and one of the most popular Windows games of all time." << endl
         << endl
         << "THE GOAL : find the empty squares and avoid the mines." << endl
         << endl;
    cout << "THE RULES IN  MINESWEEPER ARE SIMPLE : " << endl
         << endl
         << "1. Uncover a mine, and the game ends." << endl
         << endl
         << "2. Uncover a number, and it tells you how many mines lay hidden in the eight surrounding squares." << endl
         << endl
         << "3. Use the information gathered from the number to unravel the position of mine";
    cout << endl
         << endl
         << endl
         << "NOTE :  you have to enter the position of numbers (NOT MINES)" << endl
         << endl
         << endl;

    // starting the game
    char board1[7][7]; // to be seen by the user
    char board[7][7];  // backend board
    boardm(board1);
    cout << "LET START TEH GAME...." << endl
         << " this is your board : " << endl;
    print_Board(board1);

    // filling data in backend board
    mines(board);
    print_Board(board);

    // PLAYING THE GAME

    for (;;)
    {

        // TAKING VALID INPUT FROM THE USER AND PRINTING THE CURRENT SITUATION OF THE BOARD

        int x, y;
        get_Input(&x, &y, board1);
        board1[x][y] = board[x][y];
        print_Board(board1);

        // CHECKING IF THE USER LOST THE GAME

        if (board1[x][y] == '*')
        {
            cout << "THE MINE BLASTED....." << endl
                 << "YOU LOST THE GAME....." << endl
                 << "BETTER LUCK NEXT TIME....";
            return 0;
        }

        int count1 = 0, count2 = 0;

        // CHECKING IF THE USER WON THE GAME....

        for (int i = 1; i < 6; i++)
        {
            for (int j = 1; j < 6; j++)
            {
                if (board1[i][j] == '#')
                {
                    count1++;
                }
                if (board[i][j] == '*')
                {
                    count2++;
                }
            }
        }
        cout << endl
             << count2 << " mines left out of remaining " << count1 << " positionns" << endl
             << endl;

        if (count1 == count2)
        {
            cout << "CONGRATS....." << endl
                 << "YOU FOUND ALL THE MINES...." << endl
                 << "YOU WON THE GAME....";
            return 0;
        }
    }

    return 0;
}

// printing the current situation of the board

void print_Board(char board[7][7])
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// initialising board

void boardm(char board[7][7])
{

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = '#';
        }
    }
}

// SETTING UP MINES AND NUMBERS IN THE GAME DATABASE

void mines(char board[7][7])
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            board[i][j] = '0';
        }
    }
    srand(time(0));
    for (int k = 1; k < 7; k++)
    {
        int x = (rand() % 5) + 1;
        int y = (rand() % 5) + 1;
        if (board[x][y] == '*')
        {
            continue;
        }
        else
        {
            board[x][y] = '*';
            for (int i = x - 1; i < x + 2; i++)
            {
                for (int j = y - 1; j < y + 2; j++)
                {
                    if (board[i][j] == '*')
                        continue;
                    else
                    {
                        int temp = (int)board[i][j] + 1;
                        board[i][j] = (char)temp;
                    }
                }
            }
        }
    }
}

// TAKING VALID INPUT FROM THE USER

void get_Input(int *x, int *y, char board1[7][7])
{
    cout << "enter the row position : ";
    cin >> *x;
    while (*x < 1 || *x > 5)
    {
        cout << "INVALID POSITION.... enter row between 1-10 : ";
        cin >> *x;
    }
    cout << "enter the coloumn position : ";
    cin >> *y;
    while (*y < 1 || *y > 5)
    {
        cout << "INVALID POSITION.... enter coloumn between 1-10 : ";
        cin >> *y;
    }
    while (board1[*x][*y] != '#')
    {
        cout << endl
             << "THIS POSITION IS ALREADY ENTERED....TRY DIFFERNT ONE......" << endl;
        cout << "enter the row position : ";
        cin >> *x;
        while (*x < 1 || *x > 5)
        {
            cout << "INVALID POSITION.... enter row between 1-10 : ";
            cin >> *x;
        }
        cout << "enter the coloumn position : ";
        cin >> *y;
        while (*y < 1 || *y > 5)
        {
            cout << "INVALID POSITION.... enter coloumn between 1-10 : ";
            cin >> *y;
        }
    }
    cout << endl;
}
