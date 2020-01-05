#include<stdio.h>
#include<conio.h>

void trau_an_co1(){
	int x,y;
	for(x=1;x<=20;x++)
		for(y=1;y<=33;y++)
			if((14*x+8*y)==200){
				printf(" %d, %d, %d",x,y,100-(x+y));
				printf("\n");
				}
	}
	
int main(){
	printf("So luong trau dung, trau nam va trau gia lan luot la: \n");
	trau_an_co1();
	getch();
	return 0;
	}
