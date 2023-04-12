#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>
//

using namespace std;

typedef unsigned short int ushort;

void displayMessage1();
void displayMessage2();
void inputFirstMove(char& rfirstMove);
void renderBoard(vector<ushort>& board);

int main()
{
    vector<ushort> board = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    char firstMove;

    displayMessage1();
    renderBoard(board);
    displayMessage2();
    inputFirstMove(firstMove);
}

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
    } while (rfirstMove != 'y' || rfirstMove != 'n');
}

void renderBoard(vector<ushort>& board)
{
    for (int i = 0; i < board.size(); i++) {
        cout << "\t" << board[i] << " ¦ " << board[++i] << " ¦ " << board[++i] << "\n";

        if (i <= board.size()-3)
        {
            cout << "\t_________\n";
        }
    }
}
