#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Choice {
    ROCK,
    PAPER,
    SCISSORS
};

int main() {
    srand(time(NULL));

    while (true) {
        int computer = rand() % 3;
        int player;
        cout << "Enter your choice (0 for rock, 1 for paper, 2 for scissors): ";
        cin >> player;

        if (player < 0 || player > 2) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Computer chose ";
        switch (computer) {
            case ROCK:
                cout << "rock.\n";
                break;
            case PAPER:
                cout << "paper.\n";
                break;
            case SCISSORS:
                cout << "scissors.\n";
                break;
        }

        if (player == computer) {
            cout << "Tie!\n";
        } else if ((player == ROCK && computer == SCISSORS) || 
                   (player == PAPER && computer == ROCK) || 
                   (player == SCISSORS && computer == PAPER)) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }

        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }
    }

    return 0;
}
