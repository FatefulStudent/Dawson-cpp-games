#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Critter
{
public:
    Critter(const string& name = "");
    string GetName() const;
private:
    string m_Name;
};
Critter::Critter(const string& name):
m_Name(name)
{}
inline string Critter::GetName() const
{   
    return m_Name;
}


class Farm
{
public:
    Farm(int spaces = 1);
    void Add(Critter* aCritter);
    void RollCall() const;
private:
    vector<Critter*> m_Critters;
};
Farm::Farm(int spaces)
{
    m_Critters.reserve(spaces);
}
void Farm::Add(Critter* aCritter)
{
    cout << "Adding " << aCritter->GetName() << endl;
    m_Critters.push_back(aCritter);
    cout << "Added " << (*m_Critters.end())->GetName() << endl;
}
void Farm::RollCall() const
{
    for (vector<Critter*>::const_iterator iter = m_Critters.begin();
        iter != m_Critters.end(); ++iter)
    {
        cout << (*(*iter)).GetName() << endl;// << " here.\n";
    }
}

int main()
{
    Critter crit("Poochie");
    cout << "My critters name is " << crit.GetName() << endl;
    cout << "\nCreating critter farm.\n";
    Farm myFarm(3);
    cout << "\nAdding three critters to the farm.\n";
    myFarm.Add(&Critter("Moe"));
    myFarm.Add(&Critter("Larry"));
    myFarm.Add(&Critter("Curly"));
    cout << "\nCalling Roll...\n";
    myFarm.RollCall();
    return 0;
}