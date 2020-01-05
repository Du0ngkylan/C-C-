#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

const int size = 8;
void Possible();
void Heuristic(int);

const int ver[]={-1,-2,-2,-1,1,2,2,1},
          hor[]={2,1,-1,-2,-2,-1,1,2};

int row, col;
        
int board[size][size];
int choice[8][8][8];
int accessible[8][8];
int main()
{

    int count = 1,k,j;

    cout <<"position [from (0,0) to (7,7)]:";
    cin  >> row >> col;
    cout << endl;

    board[row][col]=count;


    while(count!=size*size)
    {
        count++;
        Possible();
        Heuristic(count);
        for(j=0;j<=7;j++)
        {
            for(k=0;k<=7;k++)
                cout <<  setw(3) << accessible[j][k];
            cout <<"\t";
            for(k=0;k<=7;k++)
                cout <<  setw(3) << board[j][k];
            cout <<"\n\n";
        }

        cout <<"\n\n";        
    }
    for(j=0;j<=size-1;j++)
    {
        for(k=0;k<=size-1;k++)
                    cout <<  setw(3) << board[j][k];
        cout <<"\n\n";
    }
    
        system("pause");
        return 0;

}
void Possible()
{
    int next_pos;
    for(int r=0;r<=size-1;r++)
    {

        for(int c=0;c<=size-1;c++)
        {
            next_pos = 0;
            
            for(int i=0;i<=7;i++)
            {
                if(((r+ver[i] >=0) && (r+ver[i] <=size-1))&&((c+hor[i] >=0) && (c+hor[i] <=size-1))&&(board[r+ver[i]][c+hor[i]] == 0))
                {
                    
                    choice[r][c][next_pos] = i;
                    next_pos++;
                }
            }
            accessible[r][c] = next_pos;    
        }
    }

     
}
void Heuristic ( int move )
{
        int min =  accessible[row+ver[choice[row][col][0]]][col+hor[choice[row][col][0]]];
    int r   =  row+ver[choice[row][col][0]],
            c   =  col+hor[choice[row][col][0]];

    for(int i=1; i < accessible[row][col]; i++)
        {  
        if( min >= accessible[row+ver[choice[row][col][i]]][col+hor[choice[row][col][i]]] )
        {
            min = accessible[row+ver[choice[row][col][i]]][col+hor[choice[row][col][i]]];
            r = row + ver[choice[row][col][i]];
            c = col + hor[choice[row][col][i]]; 
        }
    }    
        cout <<"\n min ="<<min <<"  ("<<r<<','<<c<<") \n";
        
                board[r][c] = move;
        row = r;
        col = c;

}
