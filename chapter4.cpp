#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using std::cin;
using std::endl;
using std::cout;


void drawHangman(int fails)
{
    try
    {
        switch(fails)
        {
            case 0:
                cout << "\t ___" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;
            case 1:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;
            case 2:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;
            case 3:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;        
            case 4:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|  /|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;  
            case 5:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|  /|\\ " << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break; 
            case 6:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|  /|\\ " << endl;
                cout << "\t|   |" << endl;
                cout << "\t|" << endl;
                cout << "\t|" << endl;
                break;
            case 7:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|  /|\\ " << endl;
                cout << "\t|   |" << endl;
                cout << "\t|  /" << endl;
                cout << "\t|" << endl;
                break;
            case 8:
                cout << "\t ___" << endl;
                cout << "\t|   |" << endl;
                cout << "\t|   o" << endl;
                cout << "\t|  /|\\ " << endl;
                cout << "\t|   |" << endl;
                cout << "\t|  / \\ " << endl;
                cout << "\t|" << endl;
                break;    
            default:
                throw 1;
        }
    }
    catch (int n)
    {
        cout << "EXCEPTION: You are out of lives already!";
    }
    
}

void printGreeting(int maxFails)
{
    cout << "Welcome to the game Hangman!" << endl << endl;
    cout << "RULES: Each round you will guess a letter in the word. If it is ";
    cout << "in the word, you will be shown its location(s). If it is not, ";
    cout << "you will lose a life." << endl;
    cout << "You have " << maxFails << " lives, use them wisely\n\n";
}

bool letterAlreadyUsed(char letter, std::vector<char>& lettersHistory)
{
    for (int i=0; i<lettersHistory.size(); i++)
        if (lettersHistory[i] == letter)
            return true;
    return false;
}

int main()
{
    const int WORDS_IN_DIFFICULTY = 2;
    const int MAXIMUM_FAILS = 8;
    enum difficulty {EASY, MEDIUM, HARD, UNBEATABLE, DIFFICULTY_NUM};

    int difficultyChoice;
    
    printGreeting(MAXIMUM_FAILS);

    cout << "First choose a diffuculty (length of the word):"<< endl;
    cout << "EASY: 0\nMEDIUM: 1\nHARD: 2\nUNBEATABLE: 3\n";
    cout << "Your choice: ";
    cin >> difficultyChoice;

    std::string wordPool[DIFFICULTY_NUM][WORDS_IN_DIFFICULTY] = 
    {
        {"word", "tree"},
        {"table", "phone"},
        {"weather", "sun"},
        {"procrastination", "programming"}
    };

    srand(static_cast<unsigned int>(time(0)));
    int wordNum = rand()%WORDS_IN_DIFFICULTY;
    std::string wordToGuess = wordPool[difficultyChoice][wordNum];
    
    std::string guessedLetters = "";
    for (int i=0; i < wordToGuess.size(); i++)
        guessedLetters += "-";

    // cout << wordToGuess << endl;

    char letter;
    int fails = 0;
    std::vector<char> lettersHistory;
    bool invalidLetter, letterFound, guessedWord = false;
    while (true)
    {
        letterFound = false;
        
        drawHangman(fails);
        cout << "You have " << MAXIMUM_FAILS - fails << " lives left" << endl;

        cout << "You've tried the following letters:" << endl;
        for (int i=0; i < lettersHistory.size(); i++)
            cout << lettersHistory[i] << " ";
        cout << endl;

        cout << "So far the word is:" << endl << guessedLetters << endl;

        cout << "Enter a guess ";
        cin >> letter;

        invalidLetter = letterAlreadyUsed(letter, lettersHistory);
        if (invalidLetter)
        {
            cout << "WARNING: You already used this letter!" << endl;
            continue;
        }
        
        for (int i=0; i < wordToGuess.size(); i++)
            if (wordToGuess[i] == letter)
            {
                guessedLetters[i] = letter;
                letterFound = true;
            }

        if (!letterFound)
            fails += 1;

        if (fails == MAXIMUM_FAILS)
        {
            drawHangman(fails);
            cout << "So sorry.. you got hanged D:" << endl;
            cout << "Maybe you should try lowering difficulty? ;)" << endl;
            break;
        }
        else if (guessedLetters==wordToGuess)
        {
            cout << "CONGRATULATIONS, YOU WIN!" << endl;
            cout << "Maybe you should try higher difficulty? ;)" << endl;
            break;
        }
        else
        {
            lettersHistory.push_back(letter);
        }
        
    }
    cout << "Thank you for playing!";
    cin.get();
    cin.get();
    // cin >> fails;
    // drawHangman(fails);
    // cout << "Congrats!";
    // std::vector<int>::const_iterator iter;
    // cout << "Creating a list of scoresмл.";
    // std::vector<int> scores;
    // scores.push_back(1500);
    // scores.push_back(3500);
    // scores.push_back(7500);
    // cout << "\nHigh Scores:\n";
    // for (iter = scores.begin(); iter != scores.end(); ++iter)
    // {
    //     cout << *iter << endl;
    // }
    
    // cout << "\nFinding a score.";
    // int score;
    // cout << "\nEnter a score to find: ";
    // cin >> score;
    // iter = find(scores.begin(), scores.end(), score);
    // if (iter != scores.end())
    // {
    //     cout << "Score found.\n";
    // }
    // else
    // {
    //     cout << "Score not found.\n";
    // }
    
    // std::random_device rd;
    // std::mt19937 g(rd());
    // cout << "\nRandomizing scores.";
    // std::shuffle(scores.begin(), scores.end(), g);
    // cout << "\nHigh Scores:\n";
    // for (iter = scores.begin(); iter != scores.end(); ++iter)
    // {
    //     cout << *iter << endl;
    // }

    // cout << "\nSorting scores.";
    // sort(scores.begin(), scores.end());
    // cout << "\nHigh Scores:\n";
    // for (iter = scores.begin(); iter != scores.end(); ++iter)
    // {
    //     cout << *iter << endl;
    // }
}