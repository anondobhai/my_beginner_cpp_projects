/* *
 * Tic Tac Toe 2.0
 * Written by Abdullah-al-ahad bhuiyan
 * */

// Brooooo it's really hard ;-; to create a program using pointer instead of reference
// never mind it's workinggggggggggggggggggggggggg

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Global Constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// Function Prototypes
void instruction();
char askYesNo(string prompt);
int askNumber(string prompt, int high, int low = 0);
void displayBoard(const vector<char> *const pBoard);
char winner(const vector<char> *const pBoard);
char humanPiece();
char opponent(char piece);
bool isLegal(const vector<char> *const pBoard, int move);
char humanMove(const vector<char> *const pBoard);
char computerMove(vector<char> *const pBoard, char computer);
void announcerWinner(char winner, char human, char computer);

int main()
{
    int move;
    const int NUM_SQAURES = 9;
    vector<char> board(NUM_SQAURES, EMPTY);

    instruction();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;

    while (winner(&board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(&board);
            board[move] = human;
        }
        else
        {
            move = computerMove(&board, computer);
            board[move] = computer;
        }

        displayBoard(&board);
        turn = opponent(turn);
    }

    announcerWinner(winner(&board), human, computer);

    return 0;
}

void instruction()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";

    cout << "\n";
    cout << "0 | 1 | 2\n";
    cout << "---------\n";
    cout << "3 | 4 | 5\n";
    cout << "---------\n";
    cout << "6 | 7 | 8\n\n";

    cout << "Prepare yourself, human.The battle is about to begin.\n\n";
}

char askYesNo(string propmt)
{
    char response;
    do
    {
        cout << propmt << " (y/n): ";
        cin >> response;
        response = tolower(response);
    } while ((response != 'y') && (response != 'n'));

    return response;
}

int askNumber(string prompt, int high, int low)
{
    int response;
    do
    {
        cout << prompt << " (" << low << "-" << high - 1 << "): ";
        cin >> response;
    } while ((response > high) || response < low);
}

void displayBoard(const vector<char> *const pBoard)
{
    cout << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2] << "\n";
    cout << "---------\n";
    cout << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5] << "\n";
    cout << "---------\n";
    cout << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8] << "\n\n";
}

char winner(const vector<char> *const pBoard)
{
    const int TOTAL_ROWS = 8;
    const int WINNING_POS[TOTAL_ROWS][3] =
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}};

    // winner check korar jonno
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if (((*pBoard)[WINNING_POS[row][0]] != EMPTY) &&
            ((*pBoard)[WINNING_POS[row][0]] == (*pBoard)[WINNING_POS[row][1]]) &&
            ((*pBoard)[WINNING_POS[row][1]] == (*pBoard)[WINNING_POS[row][2]]))
        {
            return (*pBoard)[WINNING_POS[row][0]];
        }
    }

    // Tie check korar jonno
    if (count((*pBoard).begin(), (*pBoard).end(), EMPTY) == 0)
    {
        return TIE;
    }

    // winner ba tie na thakle
    return NO_ONE;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");

    if (go_first == 'y')
    {
        cout << "\nThe take the first move. You will need it.\n";
        return X;
    }
    else
    {
        cout << "\nYour bravery will your undoing...I will go first.\n";
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

inline bool isLegal(const vector<char> *const pBoard, int move)
{
    return (*pBoard)[move] == EMPTY;
}

char humanMove(const vector<char> *const pBoard)
{
    int move = askNumber("Where will you move", pBoard->size());

    while (!isLegal(pBoard, move))
    {
        cout << "\nThat sqaure is already occupied, foolish human.\n";
        move = askNumber("Where will you move:", pBoard->size());
    }

    return move;
}

char computerMove(vector<char> *const pBoard, char computer)
{
    int move = 0;
    bool found = false;

    /**
     * 1. check korchi kothay computer move korle jitte parbe
     * 2. then check korchi kothay human move korle jitte parbe she jaygay block kora
     * 3. then best possible move kora
     *      3.1 prothome middle e
     *      3.2 na holee corners e
     *      3.3 ta na holee side e
     **/

    while (!found && move < pBoard->size())
    {
        if (isLegal(pBoard, move))
        {
            (*pBoard)[move] = computer;
            found = winner(pBoard) == computer;
            (*pBoard)[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }

    if (!found)
    {
        move = 0;
        char human = opponent(computer);
        while (!found && move < pBoard->size())
        {
            if (isLegal(pBoard, move))
            {
                (*pBoard)[move] = human;
                found = winner(pBoard) == human;
                (*pBoard)[move] = EMPTY;
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        while (!found && move < pBoard->size())
        {
            move = BEST_MOVES[i];
            if (isLegal(pBoard, move))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "\nI shall take sqaure number " << move << "\n\n";
    return move;
}

void announcerWinner(char winner, char human, char computer)
{
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

    else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human\n";
        cout << "but never again! I, the computer, so swear it!\n";
    }

    else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate...for this is the best you will ever achieved.\n";
    }
}
