#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> games;
    games.push_back("Metal Gear Solid");
    games.push_back("Crash Bandicoot");
    games.push_back("Splatoon 2");
    games.push_back("Paper Mario");
    games.push_back("Kingdom Hearts 3");

    // Listing the games
    vector<string>::const_iterator games_iter;
    cout << "Game List:" << endl;
    for (games_iter = games.begin(); games_iter != games.end(); ++games_iter) {
        cout << "- " << *games_iter << endl;
    }
    cout << "Total of games: " << games.size() << endl;

    // Adding a game
    string gameName;
    cout << "\nEnter the game name you want to add: ";
    cin >> gameName;

    games.push_back(gameName);

    cout << "\nGame List:" << endl;
    for (games_iter = games.begin(); games_iter != games.end(); ++games_iter) {
        cout << "- " << *games_iter << endl;
    }
    cout << "Total of games: " << games.size() << endl;

    // Removing a game:
    unsigned short int index;
    cout << "\nType the order of the Game you want to delete from the list: ";
    cin >> index;
    
    while (index < 1 || index >= games.size()) {
        cout << "Invalid index number! Type again: ";
        cin >> index;
    }

    //💩:
    games[--index] = "zzz";
    sort(games.begin(), games.end());
    cout << "Game List:" << endl;
    for (int i = 0; games[i] != "zzz"; i++) {
        cout << "- " << games[i] << endl;
    }

    return 0;
} 
