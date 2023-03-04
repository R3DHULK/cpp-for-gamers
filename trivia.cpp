#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Question struct
struct Question
{
    string question;
    vector<string> choices;
    int correct_choice_index;
};

// Function to shuffle choices randomly
void shuffle_choices(vector<string>& choices)
{
    random_shuffle(choices.begin(), choices.end());
}

// Function to get user input
char get_user_input()
{
    char choice;
    cin >> choice;
    choice = tolower(choice);
    while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd')
    {
        cout << "Invalid choice. Please choose a, b, c, or d." << endl;
        cin >> choice;
        choice = tolower(choice);
    }
    return choice;
}

// Function to display question and choices
void display_question(Question q)
{
    cout << q.question << endl;
    cout << "A. " << q.choices[0] << endl;
    cout << "B. " << q.choices[1] << endl;
    cout << "C. " << q.choices[2] << endl;
    cout << "D. " << q.choices[3] << endl;
}

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize game variables
    int num_questions = 0;
    int num_correct = 0;
    vector<Question> questions;

    // Add questions to vector
    Question q1 = {"What is the capital of France?", {"Paris", "Madrid", "Rome", "Berlin"}, 0};
    Question q2 = {"Who directed the movie 'Jurassic Park'?", {"Steven Spielberg", "George Lucas", "Christopher Nolan", "Martin Scorsese"}, 0};
    Question q3 = {"What is the largest organ in the human body?", {"Heart", "Liver", "Skin", "Brain"}, 2};
    Question q4 = {"What is the largest planet in our solar system?", {"Venus", "Mars", "Jupiter", "Saturn"}, 2};
    Question q5 = {"What is the name of the first man to walk on the moon?", {"Neil Armstrong", "Buzz Aldrin", "Michael Collins", "Alan Shepard"}, 0};
    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);
    questions.push_back(q4);
    questions.push_back(q5);

    // Shuffle questions
    random_shuffle(questions.begin(), questions.end());

    // Ask questions
    for (int i = 0; i < questions.size(); i++)
    {
        num_questions++;

        // Shuffle choices
        shuffle_choices(questions[i].choices);

        // Display question
        cout << "Question " << num_questions << ":" << endl;
        display_question(questions[i]);

        // Get user input
        char choice = get_user_input();

        // Check if answer is correct
        if (choice - 'a' == questions[i].correct_choice_index)
        {
            cout << "Correct!" << endl;
            num_correct++;
        }
        else
        {
            cout << "Incorrect. The correct answer was " << questions[i].choices[questions[i].correct_choice_index] << "." << endl;
        }
    }

    // Display final score
    cout << "Game over. You answered " << num_correct << " out of " << num_questions << " questions correctly." << endl;

    return 0;
}
