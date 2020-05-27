/* Ước số chung lớn nhất */
#include<stdio.h>
int uocchung(int a , int b)
{
	if(b) uocchung(b,a%b);
	else return a;
}
void main(){
	int a,b;
	printf("Nhap a b ");
	scanf("%d%d",&a,&b);
	printf("Uoc chung lon nhat la %d ",uocchung(a,b));
}