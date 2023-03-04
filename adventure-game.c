#include <iostream>
#include <string>

using namespace std;

// Function to get user input
string getUserInput()
{
    string input;
    cout << "> ";
    getline(cin, input);
    return input;
}

// Function to handle room interactions
void handleRoom(string roomName)
{
    cout << "You are in the " << roomName << " room." << endl;

    // Room-specific interactions
    if (roomName == "kitchen")
    {
        cout << "You see a refrigerator and a stove." << endl;
    }
    else if (roomName == "bedroom")
    {
        cout << "You see a bed and a dresser." << endl;
    }
    else if (roomName == "bathroom")
    {
        cout << "You see a sink and a toilet." << endl;
    }
}

int main()
{
    string room = "kitchen"; // Starting room

    // Game loop
    while (true)
    {
        handleRoom(room);

        // Get user input
        string input = getUserInput();

        // Handle user input
        if (input == "exit")
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (input == "north")
        {
            if (room == "kitchen")
            {
                room = "bedroom";
            }
            else if (room == "bedroom")
            {
                cout << "There is no exit to the north." << endl;
            }
            else if (room == "bathroom")
            {
                room = "kitchen";
            }
        }
        else if (input == "south")
        {
            if (room == "kitchen")
            {
                room = "bathroom";
            }
            else if (room == "bedroom")
            {
                room = "kitchen";
            }
            else if (room == "bathroom")
            {
                cout << "There is no exit to the south." << endl;
            }
        }
        else if (input == "west")
        {
            cout << "There is no exit to the west." << endl;
        }
        else if (input == "east")
        {
            cout << "There is no exit to the east." << endl;
        }
        else
        {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
