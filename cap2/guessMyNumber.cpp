#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int guessCount = 0;
    bool isCorrect = false;

    // Random number generator and seeding
    srand(static_cast<unsigned int>(time(0)));
    int randomGenNum = rand();
    unsigned short int range = 100;
    int randomNumber = (randomGenNum % range) + 1;
    
    // The game
    cout << "\tWelcome to Guess My Number!" << endl;
    cout << "\tI doubt you can guess a number I\'m thinking between 1 and 100 😏";
    while (!isCorrect) {
        int guess;

        cout << "\nEnter a guess: ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high!🤣" << endl;
        }
        else if (guess < randomNumber) {
            cout << "Too low!🙄" << endl;
        }
        else {
            cout << "That\'s it! You got it in " << guessCount << " guesses!🥳🥳🎉🎉🎉" << endl;
            isCorrect = true;
        }

        guessCount++;
    }

    return 0;
}
