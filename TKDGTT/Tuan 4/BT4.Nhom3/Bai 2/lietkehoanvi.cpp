#include <stdio.h>
#include <conio.h>
int n,count=0,a[100],dd[100];
void nhap()
     {
          int i;
          printf("Nhap n =");  scanf("%d",&n);
          for(i=1;i<=n;i++) dd[i]=1;
      }
void result()
     {
           int i;
           count+=1; 
           printf("\n% d:  ",count);
           for(i=1;i<=n;i++)
                 printf("%d ",a[i]);
      }
void Try(int i)
      {
            int j;
            for(j=1;j<=n;j++)
            if(dd[j])
            {
                      a[i]=j;
                      dd[j]=0;
                      if(i==n) result ();
                      else Try(i+1);
                      dd[j]=1;
            }
      }
int main()
      {
       nhap();
       Try(1);
       getch();
      }
