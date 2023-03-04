#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

bool gameOver;
string name;
const int width = 22;
const int height = 22;
char mat[width][height];
char fo[4] = {'A', 'M', 'P', 'O'};
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    FIRE
};
eDirection dir;
class board;
int score = 0;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void intial()
{
    const int width = 25;
    const int height = 35;
    for (int i = 0; i < height + 2; i++)
    {
        gotoxy(i, 0);
        cout << '*';
    }
    for (int i = 0; i < width + 2; i++)
    {
        gotoxy(height + 2, i);
        cout << '*';
    }
    for (int i = 0; i < height + 2; i++)
    {
        gotoxy(i, width + 2);
        cout << '*';
    }
    for (int i = 0; i < width + 2; i++)
    {
        gotoxy(0, i);
        cout << '*';
    }
}

void load()
{
    int row, col, r, c, q;
    gotoxy(16, 10);
    printf("loading...");
    gotoxy(10, 11);
    for (r = 1; r <= 20; r++)
    {
        Sleep(200); // to display the character slowly
        printf("%c", 177);
    }
    getch();
}

class enemy
{
public:
    int difficulity = 2, high = 2;
    ;
    vector<int> enemyX, enemyY;
    enemy() {}
    enemy(int y)
    {
        enemyX.push_back(10);
        enemyX.push_back(15);
        enemyY.push_back(0);
        enemyY.push_back(0);
    }
    void increase()
    {
        high++;
        difficulity = high;
        if (high < 4)
            for (int i = 0; i < high; i++)
            {
                int Y = 0;
                int X = rand() % height;
                enemyX.push_back(X);
                enemyY.push_back(Y);
            }
    }
    friend class fighter;
};

class fighter
{
public:
    int x, nBu;
    fighter() {}
    fighter(int y)
    {
        x = 10;
        dir = STOP;
    }
    void input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'A':
            case 'a':
                dir = LEFT;
                break;
            case 'D':
            case 'd':
                dir = RIGHT;
                break;
            case 'W':
            case 'w':
                shoot();
                break;
            case 'X':
            case 'x':
                gameOver = true;
                break;
            }
        }
    }
    void shoot()
    {
        int v = 18;
        mat[v][x] = '|';
    }
    void movement(enemy &e)
    {
        for (int i = 0; i < e.enemyY.size(); i++)
        {
            e.enemyY[i]++;
            if (e.enemyY[i] > 22)
                gameOver = true;
        }
        switch (dir)
        {
        case LEFT:
            if (x > 0)
                x--;
            break;
        case RIGHT:
            if (x < width - 1)
                x++;
            break;
        case FIRE:
            shoot();
            break;
        default:
            break;
        }
        dir = STOP;
    }
    friend class enemy;
};

class board
{
public:
    board()
    {
        gameOver = false;
        score = 0;
    }
    void Draw(fighter f1, enemy &e1)
    {
        vector<int>::iterator it;
        system("CLS"); // system clear
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (mat[i][j] != '|')
                    mat[i][j] = ' ';
            }
        }
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                for (int k = 0; k < e1.enemyX.size(); k++)
                    if (e1.enemyX[k] == j && e1.enemyY[k] == i)
                        mat[i][j] = 'e';
                for (int k = 0; k < e1.enemyX.size(); k++)
                {
                    if (mat[e1.enemyY[k]][e1.enemyX[k]] == '|')
                    {
                        score += 10;
                        mat[i][j] = ' ';
                        it = e1.enemyY.begin() + k;
                        e1.enemyY.erase(e1.enemyY.begin() + k);
                        it = e1.enemyX.begin() + k;
                        e1.enemyX.erase(e1.enemyX.begin() + k);
                        e1.difficulity--;
                        if (e1.difficulity == 0)
                            e1.increase();
                    }
                }
                if (j == f1.x)
                    mat[19][j] = '^';
                if (mat[i][j] == '|')
                {
                    mat[i - 1][j] = '|';
                    mat[i][j] = ' ';
                }
            }
        }
        for (int i = 0; i < width + 2; i++)
            cout << '*';
        cout << endl;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (j == 0 && i == 0)
                    cout << '*';
                else if (j == 0 && i != 0)
                    cout << '*';
                cout << mat[i][j];
                if (j == width - 1)
                    cout << '*';
            }
            cout << endl;
        }
        for (int i = 0; i < height + 2; i++)
            cout << '*';
        cout << endl
             << "Name :" << name << " Score :" << score << endl;
    }
    friend class enemy;
};

int main()
{
    int diff;
    char c;
    intial();
start:
    gotoxy(15, 8);
    cout << "Fighter game";
    gotoxy(13, 9);
    cout << "Name : ";
    getline(cin, name);
    gotoxy(11, 10);
    cout << "Difficutity(L/M/H) :";
    cin >> c;
    switch (c)
    {
    case 'L':
    case 'l':
        diff = 125;
        break;
    case 'M':
    case 'm':
        diff = 115;
        break;
    case 'H':
    case 'h':
        diff = 100;
        break;
    default:
        diff = 125;
    }
    system("CLS");
    intial();
    load();
    board b;
    enemy e(0);
    fighter f(0);
    while (!gameOver)
    {
        b.Draw(f, e);
        f.input();
        f.movement(e); // add e
        if (score >= 50)
            diff = 25;
        if (score >= 100)
            diff = 10;
        Sleep(diff);
    }
    cout << "Do you want to play again ? (Y/N)";
    cin >> c;
    if (c == 'Y' || c == 'y')
    {
        system("CLS");
        goto start;
    }
    return 0;
}
