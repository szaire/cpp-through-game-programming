#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
//

using namespace std;

typedef unsigned short int ushort;

// visuals
void displayMessage1();
void displayMessage2();
void inputFirstMove(char& rfirstMove);
void renderBoard(vector<char>& board);

// moves
void playerMove(vector<char>& board, vector<char>& visitedPos, ushort& position);
void computer_randomDecision(vector<char>& board, vector<char>& visitedPos);

// end game conditions
bool drawCondition(vector<char>& board);

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

    while (!drawCondition(board))
    {
        ushort position;
        renderBoard(board);
        if (firstMove == 'y')
        {
            playerMove(board, visitedPos, position);
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

void renderBoard(vector<char>& board)
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
// Draw
bool drawCondition(vector<char>& board)
{
    ushort minCharPos = (ushort) '0';
    ushort maxCharPos = minCharPos + board.size();

    for (int i = 0; i < board.size(); i++) {
        if ((ushort) board[i] >= minCharPos && (ushort) board[i] < maxCharPos)
        {
            return false;
        }
    }
    return true;
}

// Moves
// Player:
// TODO: Look for the infinite game bug...
void playerMove(vector<char>& board, vector<char>& visitedPos, ushort& position)
{
    cout << "\nChoose the place to input the symbol: ";
    cin >> position;

    ushort minCharPos = (ushort) '0';
    ushort maxCharPos = minCharPos + board.size();

    if ((ushort) board[position] >= minCharPos && (ushort) board[position] < maxCharPos)
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

    ushort minCharPos = (ushort) '0';
    ushort maxCharPos = minCharPos + board.size();

    ushort randBoardPos;
    do {
        randBoardPos = rand() % board.size();
    } while (std::count(visitedPos.begin(), visitedPos.end(), randBoardPos));

    board[randBoardPos] = 'O';
    visitedPos.push_back(randBoardPos);
}

