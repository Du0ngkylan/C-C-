#include <stdio.h>
#include <conio.h>

//BT Thap Ha Noi: Chuyen n cai dia tu coc a sang coc c
//Coc a la coc nguon
//Coc b la coc trung gian
//Coc c la coc dich

void HaNoiTower(int n,char a,char b,char c){
	if(n == 1)
		printf("\n%c --- > %c",a,c);
	else{
		HaNoiTower(n-1,a,c,b);		//Chuyen n-1 cai dia tu coc a sang coc b
		HaNoiTower(1,a,b,c);		//Chuyen 1 cai dia tu coc a sang coc c
		HaNoiTower(n-1,b,a,c);		//Chuyen n-1 cai dia tu coc b sang coc c
	}
}
int main(){
	int n;
	char a = 'a',b = 'b',c = 'c';
	printf("\nNhap so dia: ");
	scanf("%d",&n);
	HaNoiTower(n,a,b,c);
    getch();
    return 0;
}
