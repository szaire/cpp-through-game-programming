#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned short int ushort;

// Constants
const ushort MIN_CHAR_POS = (ushort) '0';
const ushort MAX_CHAR_POS = (ushort) '8';

// visuals
void displayMessage1();
void displayMessage2();
void inputFirstMove(char& rfirstMove);
void renderBoard(const vector<char>& board);

// moves
void playerMove(vector<char>& board, vector<char>& visitedPos);
void computer_randomDecision(vector<char>& board, vector<char>& visitedPos);

// end game conditions
bool drawCondition(const vector<char>& board);
bool checkVictoryCondition(const vector<char>& board, char symbol);
bool victoryCondition(const vector<char>& board);

int main()
{
    vector<char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    vector<char> visitedPos;
    char firstMove;

    displayMessage1();
    renderBoard(board);
    displayMessage2();
    inputFirstMove(firstMove);
    system("clear");

    while (!victoryCondition(board) && !drawCondition(board))
    {
        renderBoard(board);

        if (firstMove == 'y')
        {
            playerMove(board, visitedPos);
        }
        computer_randomDecision(board, visitedPos);

        firstMove = 'y';
        system("clear");
    }
}

// Visuals
inline void displayMessage1()
{
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe\n";
    cout << "Where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number (0-8).\nThe number corresponds to the desired board position, as illustrated:\n\n";
}

inline void displayMessage2()
{
    cout << "\nPrepare yourself, human. The battle is about to begin.\n";
}

void inputFirstMove(char& rfirstMove)
{
    do {
        cout << "Do you require the first move? (y/n): ";
        cin >> rfirstMove;
    } while (rfirstMove != 'y' && rfirstMove != 'n');
}

void renderBoard(const vector<char>& board)
{
    for (int i = 0; i < board.size(); i++) {
        cout << "\t" << board[i] << " ¦ " << board[++i] << " ¦ " << board[++i] << "\n";

        if (i <= board.size()-3)
        {
            cout << "\t_________\n";
        }
    }
}

// End game conditions
// Victory (Either Player or Computer)
bool victoryCondition(const vector<char>& board)
{
    if (checkVictoryCondition(board, 'X'))
    {
        cout << "You won! Congratulations!\n\n";
        renderBoard(board);
        cout << "\n";

        return true;
    }

    if (checkVictoryCondition(board, 'O'))
    {
        cout << "The computer won! Nice try, baka ;)\n\n";
        renderBoard(board);
        cout << "\n";

        return true;
    }

    return false;
}

// Check Victory Condition
bool checkVictoryCondition(const vector<char>& board, char symbol)
{
    // Vertical Line Segment
    if (((board[0] == symbol) && (board[3] == symbol) && (board[6] == symbol)) ||
    ((board[1] == symbol) && (board[4] == symbol) && (board[7] == symbol)) ||
    ((board[2] == symbol) && (board[5] == symbol) && (board[8] == symbol)))
    {
        return true;
    }

    // Horizontal Line Segment
    if (((board[0] == symbol) && (board[1] == symbol) && (board[2] == symbol)) ||
    ((board[3] == symbol) && (board[4] == symbol) && (board[5] == symbol)) ||
    ((board[6] == symbol) && (board[7] == symbol) && (board[8] == symbol)))
    {
        return true;
    }
    
    // Diagonal Line Segment
    if (((board[0] == symbol) && (board[4] == symbol) && (board[8] == symbol)) ||
    ((board[2] == symbol) && (board[4] == symbol) && (board[6] == symbol)))
    {
        return true;
    }

    return false;
}

// Draw
bool drawCondition(const vector<char>& board)
{
    for (int i = 0; i < board.size(); i++) {
        if ((ushort) board[i] >= MIN_CHAR_POS && (ushort) board[i] <= MAX_CHAR_POS)
        {
            return false;
        }
    }

    cout << "There's no winner! The game drawed 😂😂😂😂\nThe results are:\n\n";
    renderBoard(board);
    cout << "\n";

    return true;
}

// Moves
// Player:
// TODO: Look for the infinite game bug...
void playerMove(vector<char>& board, vector<char>& visitedPos)
{
    ushort position;
    cout << "\nChoose the place to input the symbol: ";
    cin >> position;

    while (position < 0 || position > 8) {
        cout << "Wrong position! Choose a place between 0 and 8: ";
        cin >> position;
    } 

    if ((ushort) board[position] >= MIN_CHAR_POS && (ushort) board[position] <= MAX_CHAR_POS)
    {
        board[position] = 'X';
        visitedPos.push_back(position);
    }
}

// AI:
// Worst decision making algorithm
void computer_randomDecision(vector<char>& board, vector<char>& visitedPos)
{
    srand(static_cast<unsigned int>(time(0)));

    ushort randBoardPos;

    do {
        randBoardPos = rand() % board.size();
    } while (count(visitedPos.begin(), visitedPos.end(), randBoardPos) && !drawCondition(board));

    board[randBoardPos] = 'O';
    visitedPos.push_back(randBoardPos);
}

