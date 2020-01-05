// bai toan tim Min_max dung thuat giai chia de tri
#include <stdio.h>
#include <conio.h>

//----------------------------------------------------
int max(int a,int b)
{
if (a>=b) return a;
return b;
}
//----------------------------------------------------
int min(int a,int b)
{
if (a<=b) return a;
return b;
}
//----------------------------------------------------
void maxmin(int A[], int L, int R, int &Max, int &Min)
{
     int Max1,Min1,Max2,Min2;
        if ((R-L)>1)
        {
            maxmin(A,L,((R+L)/2),Max1,Min1);
            maxmin(A,(((R+L)/2) + 1),R, Max2,Min2);
            Max=max(Max1,Max2);
            Min=min(Min1,Min2);
        }
        else
        {
           if (A[L]<=A[R]) 
           {
              Max=A[R];
              Min=A[L];
           }
           else
              {
                 Max=A[L];
                 Min=A[R];
              }
        }
}
//----------------------------------------------------
int main()
{    
    int a[100]; 
    int Max,Min,i,n;
    printf("nhap so phan tu cua mang:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }     
       maxmin(a,0,n-1,Max,Min);
printf(" phan tu nho nhat:%d \n phan tu lon nhat %d",Min,Max);
getch();
}
