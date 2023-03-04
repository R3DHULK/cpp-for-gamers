#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent a suspect
struct Suspect
{
    string name;
    string occupation;
    string alibi;
};

// Function to print the list of suspects
void printSuspects(const vector<Suspect> &suspects)
{
    cout << "List of suspects:" << endl;
    for (int i = 0; i < suspects.size(); i++)
    {
        cout << i + 1 << ". " << suspects[i].name << " (" << suspects[i].occupation << ")" << endl;
    }
}

// Function to interrogate a suspect
void interrogateSuspect(Suspect &suspect)
{
    cout << "You are now interrogating " << suspect.name << "." << endl;
    cout << "What would you like to ask?" << endl;

    string input;
    getline(cin, input);

    if (input.find(suspect.alibi) != string::npos)
    {
        cout << "That matches their alibi. They might be telling the truth." << endl;
    }
    else
    {
        cout << "That contradicts their alibi. They might be lying." << endl;
    }
}

// Function to play the game
void playGame()
{
    vector<Suspect> suspects = {
        {"John Smith", "Doctor", "I was at the hospital all night."},
        {"Jane Doe", "Lawyer", "I was working late at the office."},
        {"Bob Johnson", "Construction worker", "I was at home with my family."},
        {"Samantha Lee", "Chef", "I was cooking at the restaurant all evening."}};

    cout << "A crime has been committed, and you are the detective in charge of the case." << endl;
    cout << "You have a list of suspects, and you need to figure out who did it." << endl;

    while (true)
    {
        printSuspects(suspects);

        cout << "Enter the number of the suspect you want to interrogate, or type 'quit' to exit." << endl;

        string input;
        getline(cin, input);

        if (input == "quit")
        {
            break;
        }

        int suspectIndex = stoi(input) - 1;
        if (suspectIndex < 0 || suspectIndex >= suspects.size())
        {
            cout << "Invalid suspect number." << endl;
            continue;
        }

        Suspect &suspect = suspects[suspectIndex];
        interrogateSuspect(suspect);
    }

    cout << "Thanks for playing!" << endl;
}

int main()
{
    playGame();
    return 0;
}
