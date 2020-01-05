//bai toan to hop
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,k,x[100];
void thu(int i)
{
    for(int j=1; j<=n;j++)
    if((j>=x[i]+1)&&(j<=n-k))
    {
     x[i]=j;
     if(i<k)
     thu(i+1);
     else
     printf("%d",x[i]);                      
    }
}
int main(){
    printf("nhap so n=");
    scanf("%d",&n);
    printf("nhap so k=");
    scanf("%d",&k);
    thu(0);
    getch();
    exit(0);
}
