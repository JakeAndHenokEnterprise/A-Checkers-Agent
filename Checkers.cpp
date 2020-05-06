#include <iostream>
#include <ctime>
#include "Checkers.h"

using namespace std;


int main()
{

	intro();
    cin.get();                //Waits for the user to press enter
do{
    while (gameStatus)
    {
        dispBoard();

        if (turn == 'X')
        {
            cout << "--Player 1 [X]--\n";
        }
        else if (turn == 'O')
        {
            cout << "--Player 2 [O]--\n";
        }

        input();
        move();
        king();
        endGame();
    }

    if (turn == 'X')
    {
        cout << endl << endl << "Player 2 [Red] wins!!!\n";
        scoreBoard[1]++;//increment the score board
    }
    else if (turn == 'O')
    {
        cout << endl << endl << "Player 1 [Black] wins!!!\n";
        scoreBoard[0]++;//increment the score board
    }
    cout << "SCORE---> PLAYER 1: " << scoreBoard[0] << "\n";
    cout << "SCORE---> CPU: " << scoreBoard[1] << "\n\n";
    cout<<"rematch?(y/n)";
    cin>>rematch;//request for rematch

}while(rematch=='y'||rematch=='Y');
    cout << "GAME OVER!\n";
    
}


