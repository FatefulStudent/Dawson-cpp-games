#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Critter
{
private:
    int m_Hunger;
    int m_Mood;
public:
    Critter(int hunger=3, int mood=3);
    void passTime();
    void talk();
    void feed();
    void play();
};

Critter::Critter(int hunger, int mood):
m_Hunger(hunger),
m_Mood(mood)
{
    cout << "A new challenger appeared!" << endl;
}

void Critter::passTime()
{
    m_Hunger -= 1;
    m_Mood -= 1;
}

void Critter::feed()
{
    m_Hunger = (m_Hunger + 3)%11;
}

void Critter::play()
{
    m_Mood = (m_Mood + 3)%11;
}

void Critter::talk()
{   
    string moodState, hungerState;

    if (m_Mood < 0)
        throw domain_error("he is too sad");
    else if (m_Mood < 3)
        moodState = "mad";
    else if (m_Mood < 7)
        moodState = "bored";
    else if (m_Mood < 11)
        moodState = "happy";
    else
        throw domain_error("he is too happy");


    if (m_Hunger < 0)
        throw domain_error("he is too starved");
    else if (m_Hunger < 3)
        hungerState = "starving";
    else if (m_Hunger < 7)
        hungerState = "hungry";
    else if (m_Hunger < 11)
        hungerState = "fed";
    else
        throw domain_error("he is too fed");

    cout << "I am a critter. I am " + hungerState;
    cout << " and " +  moodState + "\n";
}

int getAction()
{
    int choice;
    cout << "\nCritter Caretaker\n\n";
    cout << "0 - Quit\n";
    cout << "1 - Listen to your critter\n";
    cout << "2 - Feed your critter\n";
    cout << "3 - Play with your critter\n\n";
    cout << "Choice: ";
    cin >> choice;
    return choice;
}


int main()
{
    int choice = 1;
    Critter tamagochi = Critter();
    tamagochi.talk();
    
    while (choice != 0)
    {
        choice = getAction();
        switch (choice)
        {
        case 0:
            cout << "Thank you for playing!";
            break;
        case 1:
            tamagochi.talk();
            break;
        case 2:
            tamagochi.feed();
            break;
        case 3:
            tamagochi.play();
            break;
        }
        tamagochi.passTime();
    }

}