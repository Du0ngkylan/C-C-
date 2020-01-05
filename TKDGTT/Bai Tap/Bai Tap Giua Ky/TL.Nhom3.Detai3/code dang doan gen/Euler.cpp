
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

#define vocung 0

int *Matrix;	//Luu ma tran.
int *Mark;		//Danh dau canh da qua.
int *Trave;		//Luu vet. 
int number_edge = 0;
int temp;
int n;

void Input(void)
{
	int i,j;
	if(freopen("Euler.txt","rt",stdin) == NULL)
	{
		printf("Khong co file nguon");
		getch();
		exit(0);
	}
	scanf("%d",&n);
	
	Matrix = (int*)malloc(n*n*sizeof(int));
	Mark = (int*)malloc(n*n*sizeof(int));
	
	for(i = 0;i < n;i ++)
		for(j = 0;j < n;j ++)
		{
			scanf("%d",&Matrix[i*n + j]);
			if((Matrix[i*n + j] != vocung)&&(i != j))
				number_edge++;
			Mark[i*n + j] = 0;
		}
	Trave = (int*)malloc(number_edge*sizeof(int) + 1);
	Trave[0] = 0;
	temp = number_edge/2;
	return ;	//Ok, Input data is complete.
}
void Check_Euler(void)
{
	int *check1,*check2;
	int i,j;
	check1 = (int*)malloc(n*n*sizeof(int));
	check2 = (int*)malloc(n*n*sizeof(int));
	for(i = 0;i < n;i ++)
	{
		int t = 0;
		for(j = 0;j < n;j ++)
			if((i != j) && (Matrix[i*n + j] != vocung))
				t ++;
		check1[i] = t;
	}
	
	for(i = 0;i < n;i ++)
	{
		int t =0;
		for(j = 0;j < n;j ++)
			if((i != j) && (Matrix[i + j*n] != vocung))
				t++;
		check2[i] = t;
	}
	for(i = 0;i < n;i ++)
			if(((check1[i] + check2[i]) % 2) != 0)
			{
				printf("Khong ton tai chu trinh Euler.\nAn mot phim bat ki de thoat");
				getch();
				exit(0);
			}
	printf("Chu trinh Euler la :: ");
	return ;
}
void Print(void)
{
	int i;
	printf("1 ");
	for(i = number_edge/2 - 1;i >= 0;i--)	
		printf("--> %d",Trave[i]+ 1);
	return;
}
void Euler(int k)
{
	if((k == 0) && (temp <= 0))
	{
		Print();
		getch();
		exit(0)	;
	}
	else
	{
		for(int i = 0;i < n;i ++)	
			if((Mark[k*n + i] == 0) && (k != i) && (Matrix[k*n + i] != vocung))
			{
				temp--;
				Trave[temp] = i;
				Mark[k*n + i] = 1;
				Mark[i*n + k] = 1;
				Euler(i);
				temp++;
				Mark[k*n + i] = 0;
				Mark[i*n + k] = 0;
			}
	}
	return;
}
int main(void)
{
	Input()	;
	Check_Euler();
	Euler(0);
	getch();
	return 0;
}
