#include<stdio.h>
#include<conio.h>

void printResult( int x[], int n ){
	int i;
	for(i=1;i<=n;i++)
		printf("%d",x[i]);
	printf("\n");
	}
	
void Try( int i, int x[],int n, int k){
	int j;
	for(j=x[i-1]+1;j<=n;j++){
		x[i] = j;
		if(i==k)  printResult(x,k);
		else  Try(i+1,x,n,k);
	}
}

int main(){
	int k,n;
	printf("Nhap n =   ");
	scanf("%d",&n);
	printf("\nNhap k =   ");
	scanf("%d",&k);
	int x[k];
	x[0] = 0;
	Try(1,x,n,k);
	getch();
	return 0;
	}
