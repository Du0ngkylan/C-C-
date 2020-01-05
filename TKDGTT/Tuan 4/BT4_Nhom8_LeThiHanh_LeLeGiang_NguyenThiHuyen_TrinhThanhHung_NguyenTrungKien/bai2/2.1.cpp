#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
int *B,*A,n;
void init(int*B,int n)
{
for (int i=1;i<=n;i++)
B[i]=true;
}
void process(int A[],int n,int count)
{
printf("\nhoan vi thu %5d:",count);
for(int i=1;i<=n;i++) printf("%d",A[i]);
}
void Try(int i,int n,int &count)
{
for(int j=1;j<=n;j++)
if(B[j])
{
A[i]=j;
B[j]=false;
if(i==n)
{
count++;
process(A,n,count);
}
else
Try(i+1,n,count);
B[j]=true;
}
}
 main()
{
printf("nhap so phan tu ");
scanf("%d",&n);
A=(int*)malloc(n*sizeof(int));
B=(int*)malloc(n*sizeof(int));
init(B,n);
int count =0;
Try(1,n,count);
free(A);free(B);
getch();
}
