#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    int playerHealth = 100;
    int monsterHealth = 100;
    string playerName;
    string monsterName = "Goblin";
    int playerAttackPower = 10;
    int monsterAttackPower = 5;
    bool isPlayerTurn = true;
    bool isGameOver = false;

    cout << "Welcome to Monster Battle!" << endl;
    cout << "What is your name, adventurer? ";
    cin >> playerName;
    cout << "Welcome, " << playerName << "! Your adventure begins now!" << endl;

    while (!isGameOver)
    {
        // Display current health of both player and monster
        cout << "==============================" << endl;
        cout << "Player: " << playerHealth << " HP" << endl;
        cout << monsterName << ": " << monsterHealth << " HP" << endl;
        cout << "==============================" << endl;

        if (isPlayerTurn)
        {
            // Player's turn to attack
            cout << "It's your turn, " << playerName << "! What do you do?" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Run" << endl;
            int choice;
            cin >> choice;

            if (choice == 1)
            {
                // Player chooses to attack
                int damage = rand() % playerAttackPower + 1;
                monsterHealth -= damage;
                cout << "You attack the " << monsterName << " for " << damage << " damage!" << endl;
            }
            else if (choice == 2)
            {
                // Player chooses to run
                cout << "You attempt to run away!" << endl;
                int escape = rand() % 2;
                if (escape == 1)
                {
                    cout << "You successfully escape from the " << monsterName << "!" << endl;
                    isGameOver = true;
                }
                else
                {
                    cout << "You fail to escape from the " << monsterName << "!" << endl;
                }
            }
            else
            {
                cout << "Invalid choice. Please choose 1 or 2." << endl;
            }

            isPlayerTurn = false; // Player's turn is over
        }
        else
        {
            // Monster's turn to attack
            int damage = rand() % monsterAttackPower + 1;
            playerHealth -= damage;
            cout << "The " << monsterName << " attacks you for " << damage << " damage!" << endl;

            isPlayerTurn = true; // Monster's turn is over
        }

        // Check if the game is over
        if (playerHealth <= 0)
        {
            cout << "You have been defeated by the " << monsterName << "! Game over." << endl;
            isGameOver = true;
        }
        else if (monsterHealth <= 0)
        {
            cout << "You have defeated the " << monsterName << "! Congratulations!" << endl;
            isGameOver = true;
        }
    }

    return 0;
}
