#include<stdio.h>
#include<conio.h>

void trau_an_co(){
	int x,y,z;
	for(x=1;x<=20;x++)
		for(y=1;y<=33;y++)
			for(z=1;z<=100;z++)
				if(((x+y+z)==100)&&((15*x+9*y+z)==300)){
					printf(" %d, %d, %d",x,y,z);
					printf("\n");
					}
	}

int main(){
	printf("So luong trau dung, trau nam va trau gia lan luot la: \n");
	trau_an_co();
	getch();
	return 0;
	}
