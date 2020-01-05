/* Bai 1
sinh day nhi phan voi n phan tu
*/

#include<stdio.h>
#include<conio.h>

int x[100],n;
int in()   
{
     int i;
     for(i=1;i<=n;i++)
                     printf("%3d",x[i]);
                     printf("\n");
}
void Try(int i)
{
        int v;
        for (v=0;v<=1;v++)
            {
            x[i]= v;
             if (i==n)in();
             else
                    Try(i+1);  
             }
}
void nhap()
{
    
        printf("nhap do dai cua day nhi phan can sinh:");
        scanf("%d",&n);
        while(n<1)
        {
                  printf("nhap do dai cua day nhi phan can sinh:");
                  scanf("%d",&n);
        }
}     
int main()
{    
        nhap();
        printf("\n\nday nhi phan sinh duoc la\n");
        Try(1);
        
   getch();
   return 0;
} 
