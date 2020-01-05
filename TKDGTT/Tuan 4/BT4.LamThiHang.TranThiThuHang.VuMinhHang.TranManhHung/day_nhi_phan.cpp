#include<stdio.h>
#include<conio.h>

void printResult(int x[], int n){
	int i;
	printf("\t");
	for(i=1;i<=n;i++){
		printf("%d",x[i]);
	    }
	printf("\n");
	}
	
void Try(int i,int x[],int n){
	int j;
	for(j=0;j<=1;j++){
		x[i] = j;
		if(i==n) printResult(x,n);
		else Try(i+1,x,n);
		}
	}
	
int main(){
	int n;
	printf("Nhap n =  ");
	scanf("%d",&n);
	int x[n];
	printf("Cac day nhi phan do dai %d: \n",n);
	x[0] = 0;
	Try(1,x,n);
	getch();
	return 0;
	}
