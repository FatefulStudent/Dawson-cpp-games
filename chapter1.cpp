#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    short groupSize, deadGroupmates, aliveGroupmates, spareCoins; 
    const short TREASURE_SIZE = 900;
    std::string heroName;
    cout << "Welcome to Lost Fortune!" << endl << endl;
    cout << "Please enter the following information for your personalized ";
    cout << "adventure" << endl << endl;

    cout << "Enter a number: ";
    cin >> groupSize;
    cout << "Enter a number, smaller than the first one: ";
    cin >> deadGroupmates;
    cout << "Enter your last name: ";
    cin >> heroName;
    cout << endl;

    aliveGroupmates = groupSize - deadGroupmates;

    cout << "A brave group of "<< groupSize << " set out on a quest -- in search of ";
    cout << "the lost treasure of the Ancient Dwarves. The group was led by that ";
    cout << "legendary rogue, " << heroName << "." << endl << endl;
    
    cout << "Along the way, a band of marauding ogres ambushed the party. All fought ";
    cout << "bravely under the command of " << heroName << ", and the ogres were ";
    cout << "defeated, but at a cost. Of the adventurers " << deadGroupmates << " ";
    cout << "vanquished, leaving just " << aliveGroupmates << " at the group." << endl;
    cout << endl;

    cout << "The party was about to give up all hope. But while burying the deceased, ";
    cout << "they stumbled upon the buried fortune. So the adventurers split ";
    cout << TREASURE_SIZE << " gold pieces. " << heroName << "held on to the extra ";
    cout << TREASURE_SIZE%aliveGroupmates <<" pieces to keep things fair, of course.";
    cin.get();
}