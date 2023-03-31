#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    // Programming Logic
    // - Variable declaration
    string jumbleWord;
    string guess = "";
    unsigned short int playerPoints = 0;
    // - Word List
    // enum fields {, , NUM_FIELDS};
    enum fields {WORD, HINT};
    const short int NUM_FIELDS = 2;
    const short int NUM_WORDS = 5; 
    string words[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you’re banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It’s what the game is all about."}
    };

    // - Random config
    srand(static_cast<unsigned int>(time(0)));
    unsigned int pseudo = rand();
    unsigned short int random = (pseudo % NUM_WORDS) + 1;
    string sortedWord = words[random][0];
    string sortedHint = words[random][1];

    // Game logic
    // Defining the random letters
    jumbleWord = sortedWord;
    int length = sortedWord.size();
    for (int i = 0; i < length; i++) {
        int letter1 = (rand() % length);
        int letter2 = (rand() % length);

        char temp = jumbleWord[letter1];
        jumbleWord[letter1] = jumbleWord[letter2];
        jumbleWord[letter2] = temp;
    }

    // User Interface
    cout << "\t\tWelcome to Word Jumble!";
    
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n";

    cout << "The jumble is: " << jumbleWord << endl;
    
    do {
        // unsigned short int points = sortedWord.size();

        cout << "\nYou have " << playerPoints << " points";
        cout << "\nYour guess: ";
        cin >> guess;
        
        if (guess == sortedWord) {
            cout << "You made it! You hit the word! 🎉🎉🎉🥳🥳\n\n";
            playerPoints += sortedWord.size();
            cout << "You scored: " << playerPoints << " points.\n";
        }
        else if (guess != "hint") {
            cout << "You failed! But try one more time :]\n\n";
            --playerPoints;
        }
        else {
            cout << "\nHint: " << sortedHint << "\n\n";
            --playerPoints;
        }
    } while(guess != sortedWord && guess != "quit");
    
    return 0;
}

