/**
 * Tic Tac Toe Game
 * */

// it's working
// it's working
// it's working
// it's working
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global variables
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes
void instruction();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char> &board);
char winner(const vector<char> &board);
bool isLegal(const vector<char> &board, int move);
int humanMove(const vector<char> &board, char human);
int computerMove(vector<char> &board, char computer);
void announcerWinner(char winner, char human, char computer);

int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instruction();

    char human = humanPiece();
    char computer = opponent(human);
    char turn = 'X';

    while (winner(board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }

    announcerWinner(winner(board), human, computer);

    return 0;
}

void instruction()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n ";

    cout << "Make your move known by entering a number, 0-8.\n";
    cout << "The number corresponds to the desired board position, as illustrator: \n\n";

    cout << "0 | 1 | 2\n";
    cout << "---------\n";
    cout << "3 | 4 | 5\n";
    cout << "---------\n";
    cout << "6 | 7 | 8\n\n";

    cout << "Prepare yourself, human.The battle is about to begin.\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
        response = tolower(response);
    } while ((response != 'y' && response != 'n'));

    return response;
}

int askNumber(string question, int high, int low)
{
    int response;
    do
    {
        cout << question;
        cin >> response;
    } while ((response > high) || (response < low));

    return response;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move: ");

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

void displayBoard(const vector<char> &board)
{
    cout << "\n\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---------\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---------\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

char winner(const vector<char> &board)
{
    const int TOTAL_ROWS = 8;
    const int WINNING_POS[8][3] =
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}};
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ((board[WINNING_POS[row][0]] != EMPTY) && (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) && (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
        {
            return board[WINNING_POS[row][0]];
        }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0)
    {
        return TIE;
    }

    return NO_ONE;
}

inline bool isLegal(const vector<char> &board, int move)
{
    return (board[move] == EMPTY);
}

int humanMove(const vector<char> &board, char human)
{
    int move = askNumber("\nWhere will you move: ", board.size());
    while (!isLegal(board, move))
    {
        cout << "\nThat sqaure is already occupied, foolish human.\n";
        move = askNumber("\nWhere will you move: ", board.size());
    }

    return move;
}

int computerMove(vector<char> &board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    while (!found && move < board.size())
    {
        if (isLegal(board, move))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
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

        while (!found && move < board.size())
        {
            if (isLegal(board, move))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
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

        while (!found && move < board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(board, move))
            {
                found = true;
            }
            ++i;
        }
    }

    cout << "\nI shall take sqaure number " << move << endl;
    return move;
}

void announcerWinner(char winner, char computer, char human)
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
