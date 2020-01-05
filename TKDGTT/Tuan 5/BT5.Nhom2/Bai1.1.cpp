//Bai toan doi tien

#include<stdio.h>
#include<conio.h>

int k[100];
int A[10];
void nhap(int *A,int n)
{
     int i;
     for(i=0;i<n;i++)
     {
         printf("A[%d]= ",i);
         scanf("%d",&A[i]);
     }
}

void sapxep(int *A,int n) // Sap xep theo thu tu giam dan cua menh gia
{
     int i,j,t;
     for(i=0;i<n;i++)
     for(j=i+1;j<n;j++)
        if(A[i]<A[j])
        {
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
}

int  ChangeMoney(int *A,int n, int T)
{
     int i,j,d;
     for(i=0;i<n;i++)
     {
        k[i]=0;
     }
         i=0;
         while(i<n&&T>0)
         {
             k[i]=T/A[i];
             T-=k[i]*A[i];
             i++;
         }
     if(T>0)
         return -1;
}

int main()
{
     int n,T,i;
     printf("So cac loai tien la: ");scanf("%d",&n);
     printf("\nSo tien can doi la: ");scanf("%d",&T);    
     printf("\nMenh gia cua cac loai tien la:\n");
     nhap(A,n);
     sapxep(A,n);
     printf("So luong cac loai tien sau khi doi:\n");
     if(ChangeMoney(A,n,T)==-1) printf("khong co phuong an");
     else 
        for(i=0;i<n;i++)
            printf("\n Menh gia %d co so luong la: %d ",A[i],k[i]);
     getch();
     return 0;
}
     
     
