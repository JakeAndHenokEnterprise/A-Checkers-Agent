#include <iostream>
#include <ctime>
#include "Checkers.h"

using namespace std;


int main()
{
	intro();
    cin.get();                //Waits for the user to press enter

    while (gameStatus)
    {
        dispBoard();

        if (turn == 'B')
        {
            cout << "--Player 1 [B]--\n";
        }
        else if (turn == 'R')
        {
            cout << "--Player 2 [R]--\n";
        }

        input();
        move();
        king();
        endGame();
    }

    if (turn == 'B')
    {
        cout << endl << endl << "Player 2 [Red] wins!!!\n";

    }
    else if (turn == 'R')
    {
        cout << endl << endl << "Player 1 [Black] wins!!!\n";

    }

    cout << "GAME OVER!\n";
}

