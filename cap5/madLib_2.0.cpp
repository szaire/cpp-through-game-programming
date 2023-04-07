#include <iostream>
#include <string>

using namespace std;

string  inputText(string sentence);
int     inputNumber(string sentence);
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
    name = inputText("Please enter a name: ");
    pluralNoun = inputText("Please enter a plural noun: ");
    number = inputNumber("Please enter a number: ");
    bodyPart = inputText("Please enter a body part: ");
    verb = inputText("Please enter a verb: ");
    tellStory(name, pluralNoun, number, bodyPart, verb);

    return 0;
}

inline string inputText(string sentence)
{
    string text;
    cout << sentence;
    cin >> text;
    
    return text;
}

inline int inputNumber(string sentence)
{
    int number;
    cout << sentence;
    cin >> number;
    
    return number;
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
