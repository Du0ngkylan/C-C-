// Tim max min cua day so. 
#include<stdio.h>
#include <conio.h>
#include<string.h>
void nhap(int *a,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}

void in(int *a,int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("\na[%d]= %d",i,a[i]);
}
void doicho(int &a,int &b)
{
     int temp;
     temp=a;
     a=b;
     b=temp;
}

void sapxep(int a[], int m)
{
     int i,j;
     for(i=0;i<m;i++)
     for(j=i+1;j<m;j++)
     if(a[i]>a[j]) doicho(a[i],a[j]);
}
            
int main(){
    int a[100],m,n;
    printf("tim kiem phan tu tren mang dc sap xep \n \n");
    printf("nhap so phan tu cua mang: "); scanf("%d",&m);
    
    nhap(a,m);
    sapxep(a,m);
    in(a,m);
    int min=0;
    int max=m;
    printf("\n nhap so can tim:"); scanf("%d",&n);
    
    int mid=0;
    // thuat toan
    while(min<=max){
         int b=(max-min);
         mid=b/2;
         if(a[mid]==n)
         {
             printf("\n phan tu can tim la a[%d]= %d",mid,a[mid]);
             break;
         }
         else
             if(a[mid]>n)
             
                min=mid;
             
             else
                 max=mid;           
    }                
    getch();
    return 0;
}
