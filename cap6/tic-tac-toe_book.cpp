#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// functions
void instructions(); // Display Games instructions
char askYesNo(string question); // Receives a question, return y o n
int askNumber(string question, int high, int low = 0); // Ask for a number within a range
char playerPiece(); // Determine the player piece based on the next function
char opponentPiece(char piece); // Calculates the opponent piece
void displayBoard(const vector<char>& board); // Receives a board and display it on the screen
char winner(const vector<char>& board); // Determines the game winner, Returns X, O, T (Tie) or N (No one won yet)
bool isLegal(const vector<char>& board, int move); // Determines wether a move is legal, returns true or false
int playerMove(const vector<char>& board, char player); // Receive the board and the player piece. Returns the player move (?)
int computerMove(const vector<char>& board, char computer); // Receive the board and the player piece. Returns the computer move (?)
void announceWinner(char winner, char player, char computer); // end the program showing the winner

int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char player = playerPiece();
    char computer = opponentPiece(player);
    char turn = X;

    system("clear");
    displayBoard(board);

    while (winner(board) == NO_ONE)
    {
        if (turn == player)
        {
            move = playerMove(board, player);
            board[move] = player;
        }
        else {
            move = computerMove(board, computer);
        }
        displayBoard(board);
        turn = opponentPiece(turn);
        system("clear");
    }
    
    system("clear");
    announceWinner(winner(board), player, computer);

    return 0;
}

inline void instructions()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";
    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "\t 0 | 1 | 2\n";
    cout << "\t ————————— \n";
    cout << "\t 3 | 4 | 5\n";
    cout << "\t ————————— \n";
    cout << "\t 6 | 7 | 8\n\n";

    cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char askYesNo(string question)
{
    char response;

    do {
        cout << question << "(y/n): ";
        cin >> response;
    }while (response != 'y' || response != 'n');

    return response;
}

int askNumber(string question, int high, int low)
{
    int response;

    do {
        cout << question << "( " << low << " - " << high << "): ";
        cin >> response;
    }while (response < low || response > high);

    return response;
}

char playerPiece()
{
    char goFirst = askYesNo("Do you require the first move? (y/n)");

    if (goFirst == 'y')
    {
        cout << "\nThen take the first move, you'll need it >:(.\n";
        return X;
    }
    else {
        cout << "\nYour bravery will be your undoing... I will go first >:).\n";
        return O;
    }
}

void displayBoard(const vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "—————————";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "—————————";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

// THE FUNCTION WINNER:
// This function receives a board and returns the winner. There are four possible
// values for a winner. The function will return either X or O if one of the players
// has won. If every square is filled and no one has won, it returns TIE. Finally, if no
// one has won and there is at least one empty square, the function returns NO_ONE
char winner(const vector<char>& board)
{
    // all possible winning combinations:
    const int WINNING_COMB[8][3] = {
        {0, 1, 2}, // 1st horizontal winning combination
        {3, 4, 5}, // 2nd horizontal winning combination
        {6, 7, 8}, // 3rd horizontal winning combination
        {0, 3, 6}, // 1st vertical winning combination
        {1, 4, 7}, // 2nd vertical winning combination
        {2, 5, 8}, // 3rd vertical winning combination
        {0, 4, 8}, // 1st diagonal winning combination
        {2, 4, 6}  // 2nd diagonal winning combination
    };

    const int TOTAL_ROWS = 8;

    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for (int row = 0; row < TOTAL_ROWS; row++) {
        if ((board[WINNING_COMB[row][0]] != EMPTY) &&
            (board[WINNING_COMB[row][0]] == board[WINNING_COMB[row][1]]) &&
            (board[WINNING_COMB[row][1]] == board[WINNING_COMB[row][2]]))
        {
            return board[WINNING_COMB[row][0]];
        }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(board.begin(), board.end(), EMPTY) == 0)
    {
        return TIE;
    }

    return NO_ONE; // No one has won yet...
}

inline bool isLegal(int move, const vector<char>& board)
{
    return board[move] == EMPTY;
}

int humanMove(const vector<char>& board, char human)
{
    int move = askNumber("Where will you move?", (board.size() - 1));

    while (!isLegal(move, board))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move", (board.size() - 1));
    }
    cout << "Fine...\n";

    return move;
}

// 1. If the computer can win on this move, make that move.
// 2. Otherwise, if the human can win on his next move, block him.
// 3. Otherwise, take the best remaining open square. The best square is the
// center. The next best squares are the corners, and then the rest of the
// squares.

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;

    //if computer can win on next move, that’s the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, board))
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

    //otherwise, if human can win on next move, that’s the move to make
    if (!found)
    {
        move = 0;
        char human = opponentPiece(computer);
        while (!found && move < board.size())
        {
            if (isLegal(move, board))
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

    //otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        for (unsigned int i = 0; !found && i < board.size(); i++)
        {
            move = BEST_MOVES[i];
            if (isLegal(move, board))
            {
                found = true;
            }
        }
    }

    cout << "I shall take square number" << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if (winner == computer)
    {
        cout << winner << "’s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }
    else if (winner == human)
    {
        cout << winner << "’s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I, the computer, so swear it!\n";
    }
    else
    {
        cout << "It’s a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
    }
}









