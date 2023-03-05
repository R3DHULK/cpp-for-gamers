#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

struct Point
{
    int x;
    int y;
};

class Asteroid
{
private:
    Point position;

public:
    Asteroid()
    {
        srand(time(NULL));
        position.x = rand() % WIDTH;
        position.y = 0;
    }
    Point getPosition() const
    {
        return position;
    }
    void move()
    {
        position.y++;
    }
};

class Ship
{
private:
    Point position;
    int score;

public:
    Ship()
    {
        position.x = WIDTH / 2;
        position.y = HEIGHT - 1;
        score = 0;
    }
    Point getPosition() const
    {
        return position;
    }
    int getScore() const
    {
        return score;
    }
    void moveLeft()
    {
        position.x--;
        if (position.x < 0)
        {
            position.x = 0;
        }
    }
    void moveRight()
    {
        position.x++;
        if (position.x >= WIDTH)
        {
            position.x = WIDTH - 1;
        }
    }
    void increaseScore()
    {
        score++;
    }
};

int main()
{
    vector<Asteroid> asteroids;
    Ship ship;
    bool game_over = false;

    while (!game_over)
    {
        // Clear screen
        system("clear");

        // Display game board
        cout << "Score: " << ship.getScore() << endl;
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                bool asteroid_here = false;
                Point current_point = {j, i};
                for (auto asteroid : asteroids)
                {
                    if (asteroid.getPosition().x == j && asteroid.getPosition().y == i)
                    {
                        asteroid_here = true;
                        break;
                    }
                }
                if (current_point.x == ship.getPosition().x && current_point.y == ship.getPosition().y)
                {
                    cout << "O";
                }
                else if (asteroid_here)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        // Move asteroids
        for (int i = 0; i < asteroids.size(); i++)
        {
            asteroids[i].move();
            if (asteroids[i].getPosition().y == HEIGHT - 1)
            {
                asteroids.erase(asteroids.begin() + i);
            }
        }

        // Add new asteroid
        if (rand() % 10 == 0)
        {
            asteroids.push_back(Asteroid());
        }

        // Move ship
        char input;
        cin >> input;
        switch (input)
        {
        case 'a':
            ship.moveLeft();
            break;
        case 'd':
            ship.moveRight();
            break;
        }

        // Check collision
        for (auto asteroid : asteroids)
        {
            if (asteroid.getPosition().y == ship.getPosition().y && asteroid.getPosition().x == ship.getPosition().x)
            {
                game_over = true;
                break;
            }
        }

        // Increase score
        for (auto asteroid : asteroids)
        {
            if (asteroid.getPosition().y == HEIGHT - 1)
            {
                ship.increaseScore();
            }
        }

        // Delay for smooth gameplay
        for (int i = 0; i < 1000000; i++)
        {
            // Do nothing
        }
    }

    // Game over
    cout << "Game over! Final score" << endl;
    cout << " is " << ship.getScore() << endl;

    return 0;
}
