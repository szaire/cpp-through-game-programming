#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    unsigned int group;
    unsigned int slained; 
    string lastName;
    const int GOLD_PIECES = 900;

    cout << "Welcome to Lost Fortune!" << endl;

    cout << "\nPlease enter the following for your personalized adventure" << endl;

    cout << "Enter a number: ";
    cin >> group;

    cout << "Enter a number, smaller than the first: ";
    cin >> slained;

    cout << "Enter your last name: ";
    cin >> lastName;
    
    unsigned int survivors = group - slained;

    cout << "\nA brave group of " << group << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue, " << lastName << ".\n";
    
    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << lastName;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventurers, " << slained << " were vanquished, ";
    cout << "leaving just " << survivors << " in the group.\n";
    
    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
    cout << lastName << " held on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";

    return 0;
}
