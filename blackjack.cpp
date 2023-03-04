#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number between min and max (inclusive)
int get_random_number(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

// Function to convert card number to face value
int get_card_value(int card_number)
{
    if (card_number > 10)
    {
        return 10;
    }
    else if (card_number == 1)
    {
        return 11;
    }
    else
    {
        return card_number;
    }
}

int main()
{
    // Initialize game variables
    int player_score = 0;
    int dealer_score = 0;
    int player_aces = 0;
    int dealer_aces = 0;

    // Print welcome message
    cout << "Welcome to CLI Blackjack!" << endl;

    // Deal initial cards
    player_score += get_card_value(get_random_number(1, 13));
    dealer_score += get_card_value(get_random_number(1, 13));
    player_score += get_card_value(get_random_number(1, 13));
    dealer_score += get_card_value(get_random_number(1, 13));

    // Check for blackjack
    if (player_score == 21)
    {
        cout << "Player has blackjack! Player wins!" << endl;
        return 0;
    }
    if (dealer_score == 21)
    {
        cout << "Dealer has blackjack! Dealer wins!" << endl;
        return 0;
    }

    // Print initial scores
    cout << "Player score: " << player_score << endl;
    cout << "Dealer score: " << dealer_score << endl;

    // Player's turn
    while (player_score < 21)
    {
        char choice;
        cout << "Hit or stand? (h/s) ";
        cin >> choice;
        if (choice == 'h')
        {
            int card = get_card_value(get_random_number(1, 13));
            player_score += card;
            if (card == 11)
            {
                player_aces++;
            }
        }
        else
        {
            break;
        }

        // Check for bust
        if (player_score > 21 && player_aces > 0)
        {
            player_score -= 10;
            player_aces--;
        }

        // Print current score
        cout << "Player score: " << player_score << endl;
    }

    // Check for player bust
    if (player_score > 21)
    {
        cout << "Player busts! Dealer wins!" << endl;
        return 0;
    }

    // Dealer's turn
    while (dealer_score < 17)
    {
        int card = get_card_value(get_random_number(1, 13));
        dealer_score += card;
        if (card == 11)
        {
            dealer_aces++;
        }

        // Check for bust
        if (dealer_score > 21 && dealer_aces > 0)
        {
            dealer_score -= 10;
            dealer_aces--;
        }
    }

    // Check for dealer bust
    if (dealer_score > 21)
    {
        cout << "Dealer busts! Player wins!" << endl;
        return 0;
    }

    // Compare scores
    if (player_score > dealer_score)
    {
        cout << "Player wins!" << endl;
    }
    else if (dealer_score > player_score)
    {
        cout << "Dealer wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
