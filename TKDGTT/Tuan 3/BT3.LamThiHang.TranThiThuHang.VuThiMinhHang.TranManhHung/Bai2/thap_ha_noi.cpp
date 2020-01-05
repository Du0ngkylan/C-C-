#include<stdio.h>
#include<conio.h>

void chuyen_thap(int n, char x, char t, char d){
	if(n==1)
		printf("%c -> %c\n",x,d);
	else{
		chuyen_thap(n-1,x,d,t);
		chuyen_thap(1,x,t,d);
		chuyen_thap(n-1,t,x,d);
		}
	}
	
int main(){
	int n;
	printf("\nNhap vao so dia :  ");
	scanf("%d",&n);
	printf("Cach chuyen dia : \n");
	chuyen_thap(n,'x','t','d');
	getch();
	return 0;
	}
