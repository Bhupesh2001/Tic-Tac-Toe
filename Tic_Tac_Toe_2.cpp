#include<stdlib.h>
#include <iostream>
using namespace std;
char a[5][5];                                       // it is the main array in which we store the keys in desored loction
int p, i, j, c = 1;

void display(char g[5][5]);                        // Display the the grid with entered KEYS (if any)
void check(int, int, char a[5][5]);                // check that it's player 1 or 2 and fill the key accordingly
int win(char a[5][5]);                             // checks if any winner is found
int occupied(int n,int done[]);                    // checks the location is already occupied or not

int main()
{
    string name1, name2, X, Y;
    char replay = 'y';
    cout << "Enter the name of 1st player : ";
    cin >> name1;
    cout << "Enter the name of 2nd player : ";
    cin >> name2;
    if (name2 == name1)                             // verify that name of both user is not same
    {
        cout << "You entered same name for both player\n\n";
        _Exit(1);
    }
    cout << "Enter a name for the X player : ";
    cin >> X;
    if (!(X == name1 || X == name2))        // assigns the player 1
    {
        cout << "!!!!!!!!    Name didn't matched    !!!!!!!!!\n\n";
        _Exit(1);
    }
    cout << "Enter a name for the 0 player : ";
    cin >> Y;
    if (X == Y)                             // assigns the player 2 
    {
        cout << "You entered same name for both player\n\n";
        _Exit(1);
    }
    if (!(Y == name1 || Y == name2)) 
    {
        cout << "!!!!!!!!    Name didn't matched    !!!!!!!!!\n\n";
        _Exit(1);
    }

while(replay == 'y')                    // loop will end when the user want it to end
{
    int done[9] = {11, 12, 13, 14, 15, 16, 17, 18, 19};             // used to check in OCCUPIED 
    c=1;

    for (i = 0; i < 5; i++)                     // creates an empty grid, without any keys
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = ' ';
            if (j == 1 || j == 3)
                a[i][j] = '|';
            if (i == 1 || i == 3)
                a[i][j] = '_';
        }
    }

    while (c <= 9)                  // Game begins with this loop
    {
        display(a);
        if (win(a))
        {
            cout << "\n\n----------                       " << Y << " WON                       ----------\n\n";
            break;
        }
        cout << X << " select a location : ";
        cin >> p;
        while (occupied(p,done))                // Asks the player to enter a loction until he doesn't enter a non occupied block
        {
            cout<<endl<<"Try again"<<endl<<"Select a location: ";
            cin>>p;
        }
        
        c++;
        check(p, c, a);                     // check and inserts the keys
        system("CLS");                      // refresh the page for next player
        display(a);                         // display the grid and keys
        if (win(a))
        {
            cout << "\n\n----------                       " << X << " WON                       ----------\n\n";
            break;
        }
        if (c == 10)
        {
            cout << "\n\n----------                       DRAW                       ----------\n\n";
            break;
        }
        cout << Y << " select a location : ";
        cin >> p;
        while (occupied(p,done))
        {
            cout<<endl<<"Try again"<<endl<<"Select a location: ";
            cin>>p;
        }
        c++;
        check(p, c, a);
        system("CLS");
    }
    cout<<"Do you want to play again(y/n) : ";
    cin>>replay;
    system("cls");
}
    return 0;
}
int occupied(int n,int done[])
{
    int count = 0, a = 0;
    if (n < 10)
    {
        for (int i = 0; i < 9; i++)
        {
            if (done[i] == n)
                a++;
        }
        if (a>0)
        {
            cout<<"You entered already occupied block"<<endl;
            return 1;
        }
        else
            done[n-1]=n;
    }
    else
    {
        cout<<"You entered a invalid location !!!!"<<endl;
    }    
    return 0;   
}
int win(char a[5][5])
{
    if ((a[0][0] == a[0][2] && a[0][0] == a[0][4] && a[0][0] != ' ') || (a[2][0] == a[2][2] && a[2][0] == a[2][4] && a[2][0] != ' ') ||
        (a[4][0] == a[4][2] && a[4][0] == a[4][4] && a[4][0] != ' ') || (a[0][0] == a[2][0] && a[0][0] == a[4][0] && a[0][0] != ' ') ||
        (a[0][2] == a[2][2] && a[0][2] == a[4][2] && a[0][2] != ' ') || (a[0][4] == a[2][4] && a[0][4] == a[4][4] && a[0][4] != ' ') ||
        (a[0][0] == a[2][2] && a[0][0] == a[4][4] && a[0][0] != ' ') || (a[4][0] == a[2][2] && a[4][0] == a[0][4] && a[4][0] != ' '))
        return 1;
    else
        return 0;
}
void check(int p, int c, char a[5][5])
{
    char n;
    if (c % 2 == 0)
        n = 'X';
    else
        n = '0';
    if (p == 1)
        a[0][0] = n;
    if (p == 2)
        a[0][2] = n;
    if (p == 3)
        a[0][4] = n;
    if (p == 4)
        a[2][0] = n;
    if (p == 5)
        a[2][2] = n;
    if (p == 6)
        a[2][4] = n;
    if (p == 7)
        a[4][0] = n;
    if (p == 8)
        a[4][2] = n;
    if (p == 9)
        a[4][4] = n;
}
void display(char g[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << g[i][j];
        }
        cout << "\n";
    }
}
