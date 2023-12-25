// Word Jumble
// A classic Word Jumble game
// Written by Abdullah-Al-Ahad Bhuiyan

// This program is created as a stupid programer
// only knowing Array, Operators, Branch and String

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum fields // Creating fields with enum
    {
        WORD,      // WORD = 0
        HINT,      // HINT = 1
        NUM_FIELDS // NUM_FIELDS = 2 (it's created because of we could know
                   // how many fields have that can used to define array size)
    };

    const int NUM_WORDS = 3; // defining number of words
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
        {
            {"anondo", "Big Brother"},   // storing words with hints
            {"sweet", "Medium Brother"}, // in a multidimentional array
            {"mete", "Small Brother"}};

    srand(static_cast<unsigned int>(time(0)));   // seeding for random values
    int choise = rand() % NUM_WORDS;             // generating random value for word choice for jumble
    const string THE_WORD = WORDS[choise][WORD]; // storing the chosen Word
    const string THE_HINT = WORDS[choise][HINT]; // storing the Hint from chosen Word

    string jumble = THE_WORD;               // storing the Word for randomizing letters order later
    for (int i = 0; i < jumble.size(); ++i) // randomizing the jumble word
    {
        int index1 = rand() % jumble.size();
        int index2 = rand() % jumble.size();

        char tmp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = tmp;
    }

    // Game instructions
    cout << "\tWelcome to word jumble" << endl;
    cout << "\nUnscramble the letters to make a word ";
    cout << "\nEnter `hint` for a hint.";
    cout << "\nEnter `quit` to quit a game.";

    cout << "\n\nThe jumble is: " << jumble;
    string guess; // creating variable for getting the guess from user
    do
    {
        cout << "\n\nYour Guess:";
        cin >> guess; // collecting guess from user

        if (guess != THE_WORD) // checking if guess is the Word or not
        {
            cout << "\nSorry, that's not it!";
        }
        else
        {
            cout << "\nThat's it. You guessed it!";
        }

    } while (guess != THE_WORD && guess != "quit"); // playing loop until user quits or
                                                    // guess the guesses the correct word

    return 0;
}
