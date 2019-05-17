#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    bool guessed = false;
    short luckyNumber, guess, tries = 0;
    const short MAX_NUMBER = 100;

    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);

    luckyNumber = rand() % MAX_NUMBER;

    cout << "Welcome to Guess My Number!" << endl << "RULES: " << endl;
    cout << "You need to guess a number from 0 to "<< MAX_NUMBER;
    cout << " in as few attempts as possible." << endl;
    cout << "After each attempt computer will tell you if the number is larger, ";
    cout << "smaller or if your guessed it correctly." << endl;
    cout << "Good Luck!" << endl;

    while (!guessed)
    {
        tries++;
        cout << endl << "Enter a guess ";
        cin >> guess;

        if (guess > luckyNumber)
            cout << "Too high!";
        else if (guess < luckyNumber)
            cout << "Too low!";
        else 
        {
            cout << "Congratulations!" << endl; 
            cout << "You guessed it using "<< tries <<" guesses";
            guessed = true;
        }
    }

    cin.get();
    cin.get();
}