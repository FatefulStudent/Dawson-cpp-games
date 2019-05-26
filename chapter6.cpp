// Inventory Referencer
// Demonstrates returning a reference
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <ctime>
#include <random>

using namespace std;

void greetings();
void drawTutorialBoard(const vector<int>& board);
void drawBoard(const vector<char>& board);
bool isPlayerFirst();
int getPlayerMove(const vector<char>& board);
int getComputerMove(const vector<char>& board);
void updateBoard(vector<char>& board, int move, char tick, 
                 int& moveCounter);
char checkWin(const vector<char>& board, char tick, 
              int moveCounter);

int main()
{
    vector<int> tutorialBoard(9);
    vector<char> gameBoard(9);
    for (int i=0; i < tutorialBoard.size(); i++)
    {
        tutorialBoard[i] = i;
        gameBoard[i] = ' ';
    }
    
    greetings();

    // Getting the answer
    bool playerIsFirst = isPlayerFirst();
    int playerMove, computerMove;
    char winStatus = '0';
    int moveCounter = 0;
    
    if (!playerIsFirst)
    {
        computerMove = getComputerMove(gameBoard);
        updateBoard(gameBoard, computerMove, 'O', moveCounter);
        cout << "After computer move:\n";
        drawBoard(gameBoard);
    }
   
    // Game loop
    while (true)
    {
        cout << "MoveCounter "<< moveCounter;

        drawTutorialBoard(tutorialBoard);
        drawBoard(gameBoard);

        playerMove = getPlayerMove(gameBoard);
        updateBoard(gameBoard, playerMove, 'X', moveCounter);
        cout << "After your move:\n";
        drawBoard(gameBoard);
        
        winStatus = checkWin(gameBoard, 'X', moveCounter);
        if (winStatus != '0')
            break;
        cout << "Press enter to continue\n";
        cin.get();

        computerMove = getComputerMove(gameBoard);
        updateBoard(gameBoard, computerMove, 'O', moveCounter);
        cout << "After computer move:\n";
        drawBoard(gameBoard);
        
        winStatus = checkWin(gameBoard, 'O', moveCounter);
        if (winStatus != '0')
            break;

        cout << "Press enter to continue\n";
        cin.get();
    }
    cout << "Thank you for playing!";
    cin.get();
    return 0;
}

void drawTutorialBoard(const vector<int>& board)
{   
    cout << "\tPossible Locations:\n";
    cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n\n";
    return;
}

void drawBoard(const vector<char>& board)
{
    cout << "\tGame Board:\n";
    cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t---------" << endl;
    cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n\n";
    return;
}

bool isPlayerFirst()
{
    char playerAnswer;
    while(true)
    {
        cout << "Do you need to go first? (y/n)\n";
        cin >> playerAnswer;  
        if (playerAnswer == 'y')
            return true;
        else if (playerAnswer == 'n')
            return false;
    }
}

int getPlayerMove(const vector<char>& board)
{
    int playerMove;
    while(true)
    {
        cout << "Please enter a location of your move. (0-8)\n";
        cout << "You cant overwrite existing moves\n";
        cin >> playerMove;  
        if (board[playerMove] == ' ')
            return playerMove;
        else
            cout << "Please Enter a valid move\n";
    }
    
}

int getComputerMove(const vector<char>& board)
{
    int computerMove;
    srand(static_cast<unsigned int>(time(0)));
    while(true)
    {   
        computerMove = rand()%9;
        if (board[computerMove] == ' ')
            return computerMove;
    }
}

void updateBoard(vector<char>& board, int move, char tick, 
                 int& moveCounter)
{   
    if (board[move] == ' ')
        board[move] = tick;
    else
        cout << "ERROR INVALID MOVE ENCOUNTERED!";
    moveCounter++;
    return;
}

void greetings()
{
    cout << "hello!\n\n";
}

char checkWin(const vector<char>& board, char tick, int moveCounter)
{
    for (int i=0; i<3; i++)
        if (board[3*i]==tick && board[3*i+1]==tick && board[3*i+2]==tick)
        {
            cout << tick <<" Wins!\n";
            return tick;
        }
        else if (board[i]==tick && board[i+3]==tick && board[i+6]==tick)
        {
            cout << tick <<" Wins!\n";
            return tick;
        }

    if (board[0]==tick && board[4]==tick && board[8]==tick)
        {
            cout << tick <<" Wins!\n";
            return tick;
        }
    else if (board[2]==tick && board[4]==tick && board[6]==tick)
        {
            cout << tick <<" Wins!\n";
            return tick;
        }

    if (moveCounter == 9)
    {
        cout <<"Its a draw!\n";
        return 'd';
    }

    return '0';
}