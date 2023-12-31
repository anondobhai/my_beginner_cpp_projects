/**
 * Mad-Lib
 **/

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt); // created function for getting text
int askNumber(string prompt);  // created function for getting number

void tellStory(string name, string noun, int number, string bodyPart, string verb); // creating function for telling story

int main()
{
    cout << "Welcome to Mad Lib!" << endl;
    cout << "Answer the following questions to help create a new story" << endl;

    string name = askText("Please enter a name: ");        // sending prompt in function parameter to get text from the user
    string noun = askText("Please enter a plural noun: "); // sending prompt in function parameter to get number from the user
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body name: ");
    string verb = askText("Please enter a verb: ");

    tellStory(name, noun, number, bodyPart, verb);

    return 0;
}

string askText(string prompt)
{
    string response;

    cout << prompt;
    cin >> response;

    return response;
}

int askNumber(string prompt)
{
    int response;

    cout << prompt;
    cin >> response;

    return response;
}

void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
    cout << "\nHere's your story: \n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " when one day, the ";
    cout << noun;
    cout << " found the explorer.\n";
    cout << "Surround by ";
    cout << number;
    cout << " " << noun;
    cout << ", a tear come to ";
    cout << name << "`s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.";
}