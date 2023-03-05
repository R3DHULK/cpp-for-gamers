#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Pet
{
private:
    string name;
    int hunger;
    int boredom;

public:
    Pet(string petName = "Puppy")
    {
        name = petName;
        hunger = 0;
        boredom = 0;
    }
    void play()
    {
        boredom -= 5;
        if (boredom < 0)
        {
            boredom = 0;
        }
        hunger += 1;
    }
    void feed()
    {
        hunger -= 3;
        if (hunger < 0)
        {
            hunger = 0;
        }
    }
    void checkStatus()
    {
        if (hunger >= 10)
        {
            cout << name << " is hungry!" << endl;
        }
        if (boredom >= 10)
        {
            cout << name << " is bored!" << endl;
        }
        if (hunger == 0 && boredom == 0)
        {
            cout << name << " is happy and healthy!" << endl;
        }
    }
    bool isAlive()
    {
        return hunger < 10 && boredom < 10;
    }
    string getName()
    {
        return name;
    }
    int getHunger()
    {
        return hunger;
    }
    int getBoredom()
    {
        return boredom;
    }
};

int main()
{
    srand(time(NULL));
    Pet myPet;
    cout << "Welcome to Virtual Pet Game!" << endl;
    cout << "What would you like to name your pet? ";
    string name;
    cin >> name;
    myPet = Pet(name);
    while (myPet.isAlive())
    {
        myPet.checkStatus();
        cout << "What would you like to do? (1 = Play, 2 = Feed, 3 = Quit) ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            myPet.play();
            break;
        case 2:
            myPet.feed();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        int randomEvent = rand() % 3;
        if (randomEvent == 0)
        {
            myPet.feed();
            cout << "Your pet found some food to eat!" << endl;
        }
        else if (randomEvent == 1)
        {
            myPet.play();
            cout << "Your pet found a toy to play with!" << endl;
        }
        else
        {
            cout << "Your pet is resting." << endl;
        }
    }
    cout << "Game over. " << myPet.getName() << " has died." << endl;
    return 0;
}
