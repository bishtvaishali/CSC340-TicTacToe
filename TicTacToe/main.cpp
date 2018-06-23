#include <iostream>
using namespace std;


bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);
bool boardFull(char [][3]);


bool isDraw(char board[][3])
{
    for(int i = 0; i<= 2; i++)
    {
        for(int j = 0; j<= 2; j++)
        {
            if(isblank(board[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

bool isWon(char player,  char board[][3])
{
    //row checking
    for(int i = 0; i<= 2; i++)
    {
        char init = board[i][0];
        int rowCount = 0;
        for(int j = 1; j<= 2; j++)
        {
            if(board[i][j] == init && !isblank(board[i][j])&& !isblank(init))
            {
                rowCount++;
            }
        }
        if(rowCount  == 2 ) {
            return true;
        }
    }
    
    //column checking
    for(int i = 0; i<= 2; i++)
    {
        char init = board[0][i];
        int countCol = 0;
        for(int j = 1; j<= 2; j++)
        {
            if(!isblank(board[j][i])&& !isblank(init) && board[j][i] == init)
            {
                countCol++;
            }
        }
        if(countCol  == 2 ) {
            return true;
        }
    }
    
    
    //diagonal checking
    int countDiag1 = 0;
    for(int i = 1; i<= 2; i++)
    {
        char init = board[0][0];
        int countDiag1 = 0;
        if(!isblank(board[i][i])&& !isblank(init) && board[i][i] == init)
        {
            countDiag1++;
        }
    }
    if(countDiag1  == 2 )
    {
        return true;
    }
    
    //Diagonal right to left
    int countDiag2 = 0;
    int col = 2;
    char init = board[0][col];
    
    for(int i = 1; i<= 2; i++)
    {
        if(!isblank(board[i][col-i])&& !isblank(init) && board[i][col-i] == init)
        {
            countDiag2++;
        }

    }
    if(countDiag2 == 2 )
    {
        return true;
    }
    return false;
}



void displayBoard(char board[][3])
{
    cout << " --------------" << endl;
    
    cout <<   " | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
    cout << " --------------" << endl;
    
    cout <<   " | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
    cout << " --------------" << endl;
    
    cout <<   " | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl;
    cout << " --------------" << endl;
    
}


void makeAMove(char board[][3], char value)
{
    int row, coloumn;
    
    cout << "Enter a row (0, 1, 2) for player " << value << ":";
    cin >> row;
    cout << "Enter a column (0, 1, 2) for player " << value << ":";
    cin >> coloumn;

    
    if(isblank(board[row][coloumn]))
    {
        board[row][coloumn]= value;
    }
    else
    {
        cout << "This cell is already occupied. Try a different cell.";
        cout << "\n";
        makeAMove(board,value);
    }
}


bool boardFull(char board[][3])
{
    bool flag = false;
    for(int i =0 ; i<= 2; i++)
    {
        for(int j =0 ; j<= 2; j++)
        {
            if(isblank(board[i][j]))
            {
                flag  = true;
                break;
            }
        }
    }
    return flag;
}



int main() {
    
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);
    
    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
        
        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);
        
        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }
    
    return 0;
}