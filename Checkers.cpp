#include <iostream>
#include <ctime>
#include "Checkers.h"

using namespace std;


int main()
{

    cout <<"                   Checkers Game                        \n" << endl;

    cout << "Instructions:\n";
    cout << "=============\n";
    cout << "Player 1 is [b] \n";
    cout << "Player 2 is [r]\n\n";
    cout << "A capital letter of the respective b/r pieces represents a king on the board.\n";
    cout << "A piece is 'crowned' king by reaching the end of the board (the opposite side from which it started on)\n";
    cout << "Rows and columns start with an index of 0, not 1\n" <<endl;
    cout << "Rows run down the left side of the board, columns are labeled along the top of the board \n";
    cout << "When you input board positions, remember to input the ROW number first and then the COLUMN\n\n\n";
    cout << "Press enter to begin...";
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

