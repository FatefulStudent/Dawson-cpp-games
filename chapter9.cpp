#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
    Player(const string& name = "");
    string GetName() const;
    Player* GetNext() const;
    void SetNext(Player* next);
private:
    string m_name;
    Player* m_pNext;
};

Player::Player(const string& name):
m_name(name),
m_pNext(0)
{}

string Player::GetName() const
{
    return m_name;
}

Player* Player::GetNext() const
{   
    return m_pNext;
}

void Player::SetNext(Player* next)
{   
    m_pNext = next;
}

class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);
private:
    Player* m_pHead;
public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();
};

Lobby::Lobby():
m_pHead(0)
{}

Lobby::~Lobby()
{
    Clear();
}

void Lobby::AddPlayer()
{
    cout << "Please enter a name for the new player\n";
    string name;
    cin >> name;
    Player* newPlayer = new Player(name);
    if (m_pHead==0)
    {
        m_pHead = newPlayer;
    }
    else
    {
        Player* pIter = m_pHead;
        while (pIter->GetNext()!=0)
        {
            pIter = pIter->GetNext();
        }
        pIter->SetNext(newPlayer);
    }
    

}

void Lobby::RemovePlayer()
{
    if (m_pHead!=0)
    {
        Player* pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        delete pTemp;
    }
    else
    {
        cout << "No one to remove, lobby is empty\n";
    }
}

void Lobby::Clear()
{
    Player* pIter = m_pHead;
    while (m_pHead!=0)
    {
        RemovePlayer();
    }
}


ostream& operator<<(ostream& os, const Lobby& aLobby)
{
    if (aLobby.m_pHead!=0) // Lobby is not empty
    {
        Player* pIter = aLobby.m_pHead;
        while (pIter!=0)
        {
            os << pIter->GetName() << endl;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        os << "Lobby is empty\n";
    }
    return os;
}

int getChoice(Lobby& myLobby);  

int main()
{
    Lobby myLobby;
    int choice;
    bool gameEnded = false;
    cout << "Welcome to the lovvy!";
    while (!gameEnded)
    {
        choice = getChoice(myLobby);
        switch (choice)
        {
        case 0:
            gameEnded = true;
            cout << "Thank you for playing!\n";
            break;
        case 1:
            myLobby.AddPlayer();
            break;
        case 2:
            myLobby.RemovePlayer();
            break;
        case 3:
            myLobby.Clear();
            break;
        default:
            cout << "Please enter a valid option!\n";
            break;
        }
    }
    
    
    return 0;
}

int getChoice(Lobby& myLobby)
{
    int choice;
    cout << "\nGAME LOBBY:\n";
    cout << myLobby;
    cout << "0 - Exit the program.\n";
    cout << "1 - Add a player to the lobby.\n";
    cout << "2 - Remove a player from the lobby.\n";
    cout << "3 - Clear the lobby.\n";
    cout << endl << "Enter choice: ";
    cin >> choice;
    return choice;
}
