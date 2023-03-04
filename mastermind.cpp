#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int CODE_LENGTH = 4;  // Length of the secret code
const int NUM_COLORS = 6;   // Number of possible colors
const int MAX_GUESSES = 10; // Maximum number of guesses allowed

// Function to generate a random code
vector<int> generateCode()
{
    vector<int> code(CODE_LENGTH);
    srand(time(NULL));
    for (int i = 0; i < CODE_LENGTH; i++)
    {
        code[i] = rand() % NUM_COLORS;
    }
    return code;
}

// Function to get a guess from the player
vector<int> getGuess()
{
    vector<int> guess(CODE_LENGTH);
    cout << "Enter your guess (0-" << NUM_COLORS - 1 << ") separated by spaces: ";
    for (int i = 0; i < CODE_LENGTH; i++)
    {
        cin >> guess[i];
    }
    return guess;
}

// Function to compare the guess to the secret code and return the number of exact and partial matches
void checkGuess(const vector<int> &code, const vector<int> &guess, int &numExactMatches, int &numPartialMatches)
{
    numExactMatches = 0;
    numPartialMatches = 0;
    vector<bool> codeUsed(CODE_LENGTH, false);
    vector<bool> guessUsed(CODE_LENGTH, false);
    // Count exact matches
    for (int i = 0; i < CODE_LENGTH; i++)
    {
        if (code[i] == guess[i])
        {
            numExactMatches++;
            codeUsed[i] = true;
            guessUsed[i] = true;
        }
    }
    // Count partial matches
    for (int i = 0; i < CODE_LENGTH; i++)
    {
        if (!codeUsed[i])
        {
            for (int j = 0; j < CODE_LENGTH; j++)
            {
                if (!guessUsed[j] && code[i] == guess[j])
                {
                    numPartialMatches++;
                    guessUsed[j] = true;
                    break;
                }
            }
        }
    }
}

// Function to print a vector
void printVector(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    vector<int> code = generateCode();
    cout << "Welcome to Mastermind!" << endl;
    cout << "Guess the secret code (0-" << NUM_COLORS - 1 << ") in " << MAX_GUESSES << " or fewer tries." << endl;
    for (int guessNum = 1; guessNum <= MAX_GUESSES; guessNum++)
    {
        cout << endl
             << "Guess #" << guessNum << ":" << endl;
        vector<int> guess = getGuess();
        int numExactMatches, numPartialMatches;
        checkGuess(code, guess, numExactMatches, numPartialMatches);
        cout << "Result: ";
        printVector(guess);
        cout << " - " << numExactMatches << " exact matches, " << numPartialMatches << " partial matches" << endl;
        if (numExactMatches == CODE_LENGTH)
        {
            cout << "Congratulations! You guessed the code in " << guessNum << " tries." << endl;
            return 0;
        }
    }
    cout << "Sorry, you ran out of guesses. The secret code was: ";
    printVector(code);
    cout << endl;
    return 0;
}
