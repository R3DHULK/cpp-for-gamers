#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    const int MAX_WRONG = 8; // maximum number of incorrect guesses allowed

    vector<string> words; // collection of possible words to guess
    words.push_back("COMPUTER");
    words.push_back("PROGRAMMING");
    words.push_back("CODING");
    words.push_back("ALGORITHM");
    words.push_back("PYTHON");
    words.push_back("JAVASCRIPT");
    words.push_back("JAVA");
    words.push_back("HTML");
    words.push_back("CSS");
    words.push_back("DATABASE");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    const string THE_WORD = words[0];   // word to guess
    int wrong = 0;                      // number of incorrect guesses
    string soFar(THE_WORD.size(), '-'); // current guess so far
    string used = "";                   // letters already guessed

    cout << "Welcome to Hangman. Good luck!\n";

    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n"
             << used << endl;
        cout << "\nSo far, the word is:\n"
             << soFar << endl;

        char guess;
        cout << "\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // make uppercase since words are in uppercase

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    // end of game
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout << "\nCongratulations! You guessed the word!";
    }

    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}
