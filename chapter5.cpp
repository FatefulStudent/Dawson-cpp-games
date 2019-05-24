// Mad-Lib
// Creates a story based on user input
#include <iostream>
#include <string>
using namespace std;
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, 
string verb);

int main()
{
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";
    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");
    tellStory(name, noun, number, bodyPart, verb);
    return 0;
}

int askNumber(string prompt)
{
    int number;
    cout << prompt;
    cin >> number;
    return number;
}

string askText(string prompt)
{
    string word;
    cout << prompt;
    cin >> word;
    return word;
}


void tellStory(string name, string noun, int number, string bodyPart, 
string verb)
{
    cout << "\nHere's your story:\n";
    cout << "The famous explorer "<< name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of " << noun;
    cout << " when one day, the " << noun << " found the explorer.\n";
    cout << "Surrounded by " << number << " " << noun << ", a tear came to ";
    cout << name << "'s "<< bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the " << noun << "\n";
    cout << "promptly devoured " << name << ". ";
    cout << "The moral of the story? Be careful what you " << verb << " for.";
}