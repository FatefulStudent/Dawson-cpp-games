// Word Jumble
// The classic word jumble game where the player can ask for a hint
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

std::string wordJumble(std::string word)
{
    int index1, index2;
    char tempLetter;
    // cout << rand() << endl;

    for(int i=0; i < word.size(); i++)
    {
        index1 = rand() % word.size();
        index2 = rand() % word.size();
        tempLetter = word[index1];
        word[index1] = word[index2];
        word[index2] = tempLetter;
    }

    return word;
}

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;

    const std::string WORDS[NUM_WORDS][NUM_FIELDS]=
    {
        {"wall", "Just a brick in the.."},
        {"glasses", "Makes your vision clearer"},
        {"cologne", "Men's parfume"},
        {"persistent", "Do not give up!"},
        {"jumble", "You are playing it ;)"},
    };

    srand(static_cast<unsigned int>(time(0)));

    int chosenWord = rand() % NUM_WORDS;
    std::string realWord = WORDS[chosenWord][WORD];
    std::string wordHint = WORDS[chosenWord][HINT];
    std::string jumbleWord = wordJumble(realWord);

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n";
    
    while(true)
    {
        std::string guess;
        cout << endl << "The jumble is: " << jumbleWord << endl;
        cout << "Your guess: ";
        cin >> guess;

        if (guess == "hint")
        {
            cout << "Hint for this word is: "<< endl;
            cout << wordHint << endl;
        }
        else if (guess == "quit")
        {
            break;
        }
        else if (guess == realWord)
        {
            cout << "Congrats! You did it :)" << endl;
            break;
        }
        else
        {
            continue;
        }
    }

    cout << "Thank you for playing!";
    cin.get();
    cin.get();
}