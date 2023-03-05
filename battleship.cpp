#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 10;
const int NUM_SHIPS = 3;

// Represents a square on the board
struct Square
{
    int row, col;
    bool occupied = false;
    bool hit = false;
};

// Represents a ship on the board
struct Ship
{
    int size;
    vector<Square> squares;
};

// Represents the game board
struct Board
{
    vector<vector<Square>> squares;
    vector<Ship> ships;
};

// Initialize the game board
void init_board(Board &board)
{
    board.squares.resize(BOARD_SIZE, vector<Square>(BOARD_SIZE));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board.squares[i][j].row = i;
            board.squares[i][j].col = j;
        }
    }
}

// Print the game board
void print_board(const Board &board)
{
    cout << "   ";
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << char('A' + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << " " << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board.squares[i][j].hit)
            {
                cout << "X ";
            }
            else if (board.squares[i][j].occupied)
            {
                cout << "O ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Place the ships randomly on the board
void place_ships(Board &board)
{
    int sizes[NUM_SHIPS] = {5, 4, 3};
    for (int i = 0; i < NUM_SHIPS; i++)
    {
        Ship ship;
        ship.size = sizes[i];
        bool placed = false;
        while (!placed)
        {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            int dir = rand() % 2;
            if (dir == 0 && col + ship.size <= BOARD_SIZE)
            {
                bool valid = true;
                for (int j = col; j < col + ship.size; j++)
                {
                    if (board.squares[row][j].occupied)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    for (int j = col; j < col + ship.size; j++)
                    {
                        board.squares[row][j].occupied = true;
                        ship.squares.push_back(board.squares[row][j]);
                    }
                    placed = true;
                }
            }
            else if (dir == 1 && row + ship.size <= BOARD_SIZE)
            {
                bool valid = true;
                for (int j = row; j < row + ship.size; j++)
                {
                    if (board.squares[j][col].occupied)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    for (int j = row; j < row + ship.size; j++)
                    {
                        board.squares[j][col].occupied = true;
                        ship.squares.push_back(board.squares[j][col]);
                    }
                    placed = true;
                }
            }
        }
        board.ships.push_back(ship);
    }
}

// Check if all ships are sunk
bool all_ships_sunk(const Board &board)
{
    for (const auto &ship : board.ships)
    {
        for (const auto &square : ship.squares)
        {
            if (!square.hit)
            {
                return false;
            }
        }
    }
    return true;
}

// Play one turn of the game
void play_turn(Board &board)
{
    cout << "Your turn." << endl;
    int row, col;
    cout << "Enter a row (0-" << BOARD_SIZE - 1 << "): ";
    cin >> row;
    cout << "Enter a column (A-" << char('A' + BOARD_SIZE - 1) << "): ";
    char col_char;
    cin >> col_char;
    col = col_char - 'A';
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        cout << "Invalid square." << endl;
        return;
    }
    Square &square = board.squares[row][col];
    if (square.hit)
    {
        cout << "Square already hit." << endl;
        return;
    }
    square.hit = true;
    if (square.occupied)
    {
        cout << "Hit!" << endl;
        for (auto &ship : board.ships)
        {
            for (auto &s : ship.squares)
            {
                if (s.row == row && s.col == col)
                {
                    s.hit = true;
                    if (all_of(ship.squares.begin(), ship.squares.end(), [](const Square &s)
                               { return s.hit; }))
                    {
                        cout << "You sunk a ship!" << endl;
                    }
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Miss." << endl;
    }
}

// Main function
int main()
{
    srand(time(nullptr));
    Board board;
    init_board(board);
    place_ships(board);
    while (!all_ships_sunk(board))
    {
        print_board(board);
        play_turn(board);
    }
    cout << "Congratulations, you won!" << endl;
    return 0;
}
