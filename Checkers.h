#include <iostream>
#include <ctime>

using namespace std;

//variables
char turn = 'B';
bool leap;
bool gameStatus = true;
int row1, row2, col1, col2;

//functions
void minimax();
void input();
void move();
bool legalMove();
void doLeap();
void dispBoard();
void king();
void endGame();

char board[8][8] =
{
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
};

void minimax()
{
    
}

void input()
{
    cout << "Move piece\n";
    cout << "Row: ";
    cin >> row1;
    cout << "Column: ";
    cin >> col1;

    while (row1 < 0 || row1 > 7 || col1 < 0 || col1 > 7) //handles errors
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";
        cout << "Move piece\n";
        cout << "Row: ";
        cin >> row1;
        cout << "Column: ";
        cin >> col1;
    }

    cout << "To box\n";
    cout << "Row: ";
    cin >> row2;
    cout << "Column: ";
    cin >> col2;

    while (row2 < 0 || row2 > 7 || col2 < 0 || col2 > 7)
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";
        cout << "To box\n";
        cout << "Row: ";
        cin >> row2;
        cout << "Column: ";
        cin >> col2;
    }

    while (legalMove() == false)
    {
        cout << "Illegal Move. Please try again. Remember, rows first then columns (left hand side then the top)\n";
        input();
    }
}

void move()
{
    bool king_piece = false;
    if (board[row1][col1] == 'B' || board[row1][col1] == 'R')
    {
        king_piece = true;
    }

    board[row1][col1] = ' ';

    if (turn == 'B')
    {
        if (king_piece == false)
        {
            board[row2][col2] = 'b';
        }
        else if (king_piece == true)
        {
            board[row2][col2] = 'B';
        }

        turn = 'R';
    }
    else if (turn == 'R')
    {
        if (king_piece == false)
        {
            board[row2][col2] = 'r';
        }
        else if (king_piece == true)
        {
            board[row2][col2] = 'R';
        }

        turn = 'B';
    }

    if (leap == true)
    {
        doLeap();
    }
}

bool legalMove() //constructs restrictions based on rules of checkers and handles errors associated with it.
{
    //checks if a non-king piece is moving backwards.
    if (board[row1][col1] != 'B' && board[row1][col1] != 'R')
    {
        if ((turn == 'B' && row2 < row1) || (turn == 'R' && row2 > row1))
        {
            leap = false;
            return false;
        }
    }

    //checks if the location the piece is moving to is already taken.
    if (board[row2][col2] != ' '){leap = false; return false;}

    //checks if location entered by the user contains a piece to be moved.
    if (board[row1][col1] == ' '){leap = false; return false;}

    //checks if the piece isn't moving diagonally.
    if (col1 == col2 || row1 == row2){leap = false; return false;}

    //checks if the piece is moving by more than 1 column and only 1 row
    if ((col2 > col1 + 1 || col2 < col1 - 1) && (row2 == row1 +1 || row2 == row1 - 1)) {leap = false; return false;}

    //checks if the piece is leaping.
    if (row2 > row1 + 1 || row2 < row1 - 1)
    {
        //checks if the piece is leaping too far.
        if (row2 > row1 + 2 || row2 < row1 - 2){leap = false; return false;}

        //checks if the piece isn't moving by exactly 2 columns
        if (col2 != col1 + 2 && col2 != col1 - 2){leap = false; return false;}

        //checks if the piece is leaping over another piece.
        if (row2 > row1 && col2 > col1)
        {if (board[row2 - 1][col2 - 1] == ' '){leap = false; return false;}}
        else if (row2 > row1 && col2 < col1)
        {if (board[row2 - 1][col2 + 1] == ' '){leap = false; return false;}}
        else if (row2 < row1 && col2 > col1)
        {if (board[row2 + 1][col2 - 1] == ' '){leap = false; return false;}}
        else if (row2 < row1 && col2 < col1)
        {if (board[row2 + 1][col2 + 1] == ' '){leap = false; return false;}}
        leap = true; return true;}
    leap = false; return true;
}


void doLeap()
{
    char answer;

    //removes the checker piece after leap.
    if (row2 > row1 && col2 > col1)
    {
        board[row2 - 1][col2 - 1] = ' ';
    }
    else if (row2 > row1 && col2 < col1)
    {
        board[row2 - 1][col2 + 1] = ' ';
    }
    else if (row2 < row1 && col2 > col1)
    {
        board[row2 + 1][col2 - 1] = ' ';
    }
    else if (row2 < row1 && col2 < col1)
    {
        board[row2 + 1][col2 + 1] = ' ';
    }

    dispBoard();//displays/ refreshes the board after the changes

    //asks if the user wants to leap again.
    do
    {
        cout << "You just leaped once. Do you want to do a second leap IF YOU CAN? (y/n): ";
        cin >> answer;
    }
    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

    if (answer == 'y' || answer == 'Y')
    {
        row1 = row2;
        col1 = col2;
        cout << "Leap piece: row: " << row1 << ", column: " << col1 << endl;
        cout << "To box\n";
        cout << "row: ";
        cin >> row2;
        cout << "column: ";
        cin >> col2;

        while (row2 < 0 || row2 > 7 || col2 < 0 || col2 > 7)
        {
            cout << "Incorrect input. Enter numbers between 0 and 7.\n";
            cout << "To box\n";
            cout << "Row: ";
            cin >> row2;
            cout << "Column: ";
            cin >> col2;
        }

        if (turn == 'B')
        {
            turn = 'R';
        }
        else if (turn == 'R')
        {
            turn = 'B';
        }

        legalMove();

        if (leap == false)
        {
            cout << "INVALID LEAP!!\n";

            if (turn == 'B')
            {
                turn = 'R';
            }
            else if (turn == 'R')
            {
                turn = 'B';
            }
        }
        else if (leap == true)
        {
            move();
        }
    }
}

void dispBoard()
{
    cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << " _________________________________________________________________________________\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "0|    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    " << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "1|    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    " << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "2|    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    " << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "3|    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    " << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "4|    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    " << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "5|    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    " << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "6|    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    " << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << "7|    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    " << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
    cout << " |         |         |         |         |         |         |         |         |\n";
    cout << " |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}

void king() //capitalizes the checker letter so it becomes a KING
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == 'r')
        {
            board[0][i] = 'R';
        }

        if (board[7][i] == 'b')
        {
            board[7][i] = 'B';
        }
    }
}


void endGame()
{
    int counter = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != ' ')
            {
                counter++;
            }
        }
    }

    if (counter > 1)
    {
        gameStatus = true;
    }
    else if (counter == 1)
    {
        gameStatus = false;
    }
}
