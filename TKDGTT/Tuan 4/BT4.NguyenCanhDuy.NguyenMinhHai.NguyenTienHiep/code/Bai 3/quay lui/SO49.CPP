#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>

int s=0;
int n;
int kt;
int status;

void SinhChuSo(int i)
{
	if (i==(n+1)) {}
	else
	for (int a=1; a<=3; a++){
		s=s*10+a;
		if (s%49 ==0) {
                 cout<<"So nho nhat thoa man la "<<s;
                 kt=1;  
                 status=getch();
                 exit(status-'0');               
                 }
        else SinhChuSo(i+1);
        s=(int)((s-a)/10);
        }
}

int main()
{
    n=1;
    kt=0;
    while (kt==0){
           s=0;
           SinhChuSo(1);
           n++;
           }
	getch();
	return 0;
}
