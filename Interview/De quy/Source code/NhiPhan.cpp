/* In ra số nhị phân */
#include<stdio.h>
void nhiphan(int n)
{
	if(n>=2) 
	{
		nhiphan(n/2);
		printf("%d",n%2);
	}
	else printf("%d",n);
}
void main(){
	int n=2;
	nhiphan(n);
}