#include <stdio.h>
#include <stdlib.h>


void Show(int board[12][12]);
void Init(int board[12][12])
{
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
                    if(i>=2 && i<=9 && j>=2 && j<=9)
            board[i][j]=0;
            else
                        board[i][j]=-1;          

}
void Try(int step,int i,int j,int board[12][12],int *I,int *J)
{    
    for(int l=0;l<7;l++)//duyet cac truong hop theo kim dong ho
    {
        if(board[i+I[l]][j+J[l]]==0)
            //o chua qua , dat duoc
        {
            if(step+1==63)//hoan tat
            {
                   for(i=2;i<10;i++)
                    for(j=2;j<10;j++)
                        if(board[i][j]==0)
                                                board[i][j]=63;
                               Show(board);
                                        exit(0);
            }
                              
                              
            else
            {
                i=i+I[l];
                j=j+J[l];
                board[i][j]=step+1;
                Try(step+1,i,j,board,I,J);
                board[i][j]=0;
                
            
            }
        }
        
    }
}
void Show(int board[12][12])
{
    for(int i=0;i<12;i++)
        {
        for(int j=0;j<12;j++)
            printf("%4d",board[i][j]);
            printf("\n\n");
        }

}
 main()
{

int board[12][12];
int I[8]={-2,-1,1,2,2,1,-1,-2};
int J[8]={1,2,2,1,-1,-2,-2,-1};
Init(board);
board[6][3]=1;
Show(board);
Try(1,6,3,board,I,J);
}
