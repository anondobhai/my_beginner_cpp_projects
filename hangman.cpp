/**
 * Hangman
 **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int MAX_WRONG = 8; // defining max wrong number

    vector<string> words;      // creating word array
    words.push_back("ANONDO"); // adding words in array
    words.push_back("SWEET");
    words.push_back("METE");

    srand(static_cast<unsigned int>(time(0)));  // seeding for random value
    random_shuffle(words.begin(), words.end()); // shuffling words array elements

    const string THE_WORD = words[0]; // collecting first word from shuffled word array
    int wrong = 0;                    // defining wrong guess

    string soFar(THE_WORD.size(), '_'); //
    string used = "";                   // creating used string

    cout << "Welcome to Hangman. Good luck!\n\n";
    while ((THE_WORD != soFar) && (wrong < MAX_WRONG)) // playing loop until not guessed correctly or wrong limit exceed
    {
        cout << "You have " << (MAX_WRONG - wrong) << " incorrect left." << endl;
        cout << "You've used the following letters:\n"
             << used;

        cout << "\n\nSo far, the word is: \n";
        cout << soFar;

        char guess; // creating guess to get character from user
        cout << "\n\nEnter your guess: ";
        cin >> guess;           // collecting guess from user
        guess = toupper(guess); // uppercasing the guess because all word are in uppercases

        while (used.find(guess) != string::npos) //  looping until he guesses not used one
        {
            cout << "You have already guessed: " << guess << endl;
            cout << "\n\nEnter your guess: ";
            cin >> guess;
        }

        used += guess; // defining guess as it is used

        if (THE_WORD.find(guess) != string::npos) // checking if the guess in the word or not
        {
            cout << "That's right! " << guess << " is in the word. \n";
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
            cout << "\nSorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    if (wrong == MAX_WRONG)
    {
        cout << "\n You've been hanged!!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }

    cout << "The word is: " << THE_WORD;

    return 0;
}