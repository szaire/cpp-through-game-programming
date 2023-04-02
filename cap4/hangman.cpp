// Hangman Game
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

// New additions
#include <algorithm>

using namespace std;

int main()
{
    // Typedef
    typedef unsigned short int ushort; 

    // Constants
    const ushort MAX_GUESS = 10;

    // Basic Variables
    vector<string> words = {"photo", "history", "shirt", "data", "book", "river", "philosophy", "potato", "winner", "music"};
    vector<char> usedLetters;
    ushort guessesLeft = MAX_GUESS; // Descendent counting
    bool playerWin = false;

    // Random Numbers
    srand(static_cast<unsigned int>(time(0)));
    unsigned int randomNum = rand();

    // Game
    // Reference Varibles
    string randomWord = words[randomNum % words.size()];
    string hiddenWord(randomWord.size(), '-'); // initializing with standard value
    ushort letterLength = randomWord.size();

    // Game Loop:
    cout << "Welcome to Hangman. Good luck!\n";

    while(!playerWin && guessesLeft != 0) {
        cout << "\nYou have " << guessesLeft << " incorrect guesses left.\n";

        if (usedLetters.size() == 0) {
            cout << "You didn't guess any letter yet...";
        }
        else {
            cout << "You've used the following letters: ";
            for (int i = 0; i < usedLetters.size(); i++) {
                cout << usedLetters[i] << " ";
            }
        }

        cout << "\n\nSo far the word is:\n";
        // Showing the hiddenWord:
        cout << hiddenWord << "\n";

        // Outdated:
        // for (int i = 0; i < hiddenWord.size(); i++) {
        //     cout << hiddenWord[i];
        // }

        cout << "\nEnter your guess: ";
        char guessLetter;
        cin >> guessLetter;
        usedLetters.push_back(guessLetter);

        vector<ushort> guessIndex; // Holds the letter correct guess indexes
        for (int i = 0; i < letterLength; i++) {
            if (guessLetter == randomWord[i]) {
                guessIndex.push_back(i);
            }
        }

        // Enters the if statement = The guess is correct
        if (!guessIndex.empty()) {
            for (int i = 0; i < guessIndex.size(); i++) {
                // cout << "hiddenWord[" << i << "] = " << hiddenWord[guessIndex[i]] << "\n";
                // cout << "randomWord[" << i << "] = " << randomWord[guessIndex[i]] << "\n";
                hiddenWord[guessIndex[i]] = randomWord[guessIndex[i]];
            }
        }
        else {
            --guessesLeft;
            cout << "You guessed incorrectly! There's still " << guessesLeft << " tries left.\n";
        }
        guessIndex.erase(guessIndex.begin(), guessIndex.end());
        playerWin = hiddenWord == randomWord;
        cout << "\n===========================================\n";
    }

    if (playerWin) {
        cout << "YES! The word is \"" << randomWord << "\"! Congratulations you won the hangman!!!1🥳🥳🎉🎉🎉\n\n";
    }
    else {
        cout << "The word was \"" << randomWord << "\". You lose, sorry :/. Wanna play again? Compile again hehe...\n\n";
    }

    return 0;
}
