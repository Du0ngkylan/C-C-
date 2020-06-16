// bai toan xep ma tren ban co
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *nhap(int *n,int *BC)
{
	printf("Nhap vao kich thuoc ma tran: n = ");	
	scanf("%d",n);
	BC = (int *) calloc ((*n)*(*n),sizeof(int));
	return BC;
}

void in(int n, int *BC)
{
	printf("\n");
	for(int i =0; i<n ;i++)
	{
		for(int j =0; j<n; j++)
			printf("%5d ",*(BC + i*n +j));
		printf("\n\n");
	}			
}

void Try(int i, int *x, int *y, int *BC, int n,int dx[], int dy[],int *mark)
{
	int u,v;
	for(int j =0; j < 8; j++)
	{
		//printf("\n-----------------1");
		u = *x + dx[j];
		v = *y + dy[j];
		
		if(u >=0 && u <n && v >=0 && v <n && *(BC + u*n +v) == 0)
		{
			*(BC + u*n +v) = i;
			//printf("\nu = %d,v = %d",u,v);
			//in(n,BC);
			//getch();
			if(i == n*n){
				in(n,BC);
				*mark = 1;
				printf("\nThe End!");
				getch();
				exit(1);
			}
			else 
			{
				*x = u;
				*y = v;
				Try(i+1,x,y,BC,n,dx,dy,mark);
				*x = u - dx[j];
				*y = v - dy[j];
				*(BC + u*n +v) = 0;
			}
		}
			
	}
}
int main(){
	int n , *BC ,mark = 0;
	int dx[8] = {-2 , -1 ,  1 , 2 ,  2 ,  1 , -1 , -2};
	int dy[8] = { 1 ,  2 ,  2 , 1 , -1 , -2 , -2 , -1};
	BC = nhap(&n,BC);
	int x=0,y=0;
	*(BC + x*n + y) = 1;
	Try(2,&x,&y,BC,n,dx,dy,&mark);
	if(mark == 0)
		printf("\nKhong The Di Duoc!");
    getch();
    return 0;
}
