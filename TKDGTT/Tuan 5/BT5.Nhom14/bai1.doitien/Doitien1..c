#include "stdio.h"
//#include "stdafx.h"
#include "conio.h"
int main()
{
int i, j, k;
int n, dem=0;
printf("\n CHUONG TRINH DOI TIEN ");
printf("\n nhap vao so tien can doi (don vi 1 d) ");
printf("\n so tien=");
scanf("%d",&n);
for(i=0; i<=n/50;i++)
for(j=0; j<=(n-i*50)/30; j++)
for(k=0; k<=(n-i*50-j*30)/20; k++)
if(i*50+j*30+k*20==n)
{
printf("\n LAN THU %d so to 50: %d , so to 30: %d, so to 20: %d", dem, i, j, k);
dem++; 
}
getch();
return 0;
}

