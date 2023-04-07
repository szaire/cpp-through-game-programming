#include <iostream>
#include <string>

using namespace std;

string  inputName();
string  inputPluralNoun();
int     inputNumber();
string  inputBodyPart();
string  inputVerb();
void    tellStory(string name, string pluralNoun, int number, string bodyPart, string verb);

int main()
{
    // Variables
    string name;
    string pluralNoun;
    int number;
    string bodyPart;
    string verb;

    // Interface
    cout << "Welcome to MadLib.\n\n";

    cout << "Answer the following questions to help create a new story.\n";
    name = inputName();
    pluralNoun = inputPluralNoun();
    number = inputNumber();
    bodyPart = inputBodyPart();
    verb = inputVerb();
    tellStory(name, pluralNoun, number, bodyPart, verb);

    return 0;
}

inline string inputName()
{
    string name;
    cout << "Please enter a name: ";
    cin >> name;
    
    return name;
}

inline string inputPluralNoun()
{
    string pluralNoun;
    cout << "Please enter a pluralNoun: ";
    cin >> pluralNoun;
    
    return pluralNoun;
}

inline int inputNumber()
{
    int number;
    cout << "Please enter a number: ";
    cin >> number;
    
    return number;
}

inline string inputBodyPart()
{
    string bodyPart;
    cout << "Please enter a bodyPart: ";
    cin >> bodyPart;
    
    return bodyPart;
}

inline string inputVerb()
{
    string verb;
    cout << "Please enter a verb: ";
    cin >> verb;
    
    return verb;
}

void tellStory(string name, string pluralNoun, int number, string bodyPart, string verb)
{
    cout << "\nHere’s your story:\n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << pluralNoun;
    cout << " when one day, the ";
    cout << pluralNoun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << number;
    cout << " " << pluralNoun;
    cout << ", a tear came to ";
    cout << name << "’s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << pluralNoun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.\n\n";
}
