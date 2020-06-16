/*
  Name: Tour of the Knight
  Copyright: Nhom 1 K54A2
  Author: Nhom 1 K54A2
  Date: 18/03/12 16:25
  Description: 
*/

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define maxsize 10

int BoardSquare[maxsize][maxsize];
const int sizeBoard=8;//size of a chess board
int drow[9] = {0,2,1,-1,-2,-2,-1,1,2}; //dr and dc mark the step of the knight
int dcol[9] = {0,-1,-2,-2,-1,1,2,2,1};

int check=0;//check as if the knight finish the tour
int first_r,first_c;

void Tour(int orderOfStep, int row, int col)
{
     int k,r1,c1;
     k=1;
     do
     {
         r1 = row+drow[k];
	     c1 = col+dcol[k];
	     if ((1 <= r1) && (r1 <= sizeBoard) && (1 <= c1) && (c1 <= sizeBoard) && (BoardSquare[r1][c1] == 0))
	     {
	        BoardSquare[r1][c1]=orderOfStep;
	        if (orderOfStep<sizeBoard*sizeBoard)
               {
		              Tour(orderOfStep+1,r1,c1);
		              if (check ==0) BoardSquare[r1][c1]=0;
                }
            else check = 1;
         }
	     k++;
     } while ((check ==0)&(k<(sizeBoard+1)));
}

//The result
void Result ()
{
     int r,c;
     if (check == 1)
     for (r=1;r<=sizeBoard;r++)
     {
	 for (c=1; c<=sizeBoard; c++)
	     if (BoardSquare[r][c]>=10) printf ("%i  ",BoardSquare[r][c]);//make sure that the result are in arrange by rows and cols
	     else printf ("%i   ",BoardSquare[r][c]);

	 printf ("\n\n");
     }
     else cout<<"Knight can make a tour though all the square of board from position "<<first_r<<", "<<first_c;
}

//Set up the first position of the knight
void FirstPosition (int first_row, int first_col)
{
     int r, c;
     for (r = 1; r <= sizeBoard; r++)
	 for (c=1; c <= sizeBoard;c++)
	     BoardSquare[r][c] = 0;
     BoardSquare[first_row][first_col]=1;
     
}
int main ()
{
     cout<<endl<<"Input the first position of the knight, row: ";
     cin>>first_r;
     cout<<" col: ";
     cin>>first_c;
     
     FirstPosition(first_r,first_c);
     Tour(2,first_r,first_c);
     printf ("\nTour of the knight:\n");
     Result();
     getch();
     return 0; 
} 

