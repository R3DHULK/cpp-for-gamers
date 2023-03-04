#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Building
{
public:
    string name;
    int cost;
    int income;
    int population;
    Building(string n, int c, int i, int p)
    {
        name = n;
        cost = c;
        income = i;
        population = p;
    }
};

int main()
{
    vector<Building> buildings;
    buildings.push_back(Building("Residential", 100, 0, 5));
    buildings.push_back(Building("Commercial", 150, 50, 0));
    buildings.push_back(Building("Industrial", 200, 100, -5));

    int money = 1000;
    int population = 10;

    cout << "Welcome to the city building game!" << endl;

    while (true)
    {
        cout << "==============================" << endl;
        cout << "Money: " << money << endl;
        cout << "Population: " << population << endl;
        cout << "-----------------------" << endl;

        cout << "Buildings:" << endl;
        for (int i = 0; i < buildings.size(); i++)
        {
            cout << i + 1 << ". " << buildings[i].name << " (cost: " << buildings[i].cost << ")" << endl;
        }

        cout << "-----------------------" << endl;
        cout << "Enter a number to build a building or 0 to end the game: ";
        int choice;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        if (choice < 1 || choice > buildings.size())
        {
            cout << "Invalid choice, please try again." << endl;
            continue;
        }

        Building building = buildings[choice - 1];

        if (money < building.cost)
        {
            cout << "You don't have enough money to build that!" << endl;
            continue;
        }

        money -= building.cost;
        population += building.population;

        if (building.income > 0)
        {
            money += building.income * population;
        }
    }

    cout << "Game over! Final score: " << money << endl;

    return 0;
}
