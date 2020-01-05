//bài toán xêp ti?n
#include<stdio.h>
#include<conio.h>
#include<string.h>
/*int sapxep(int a[],int n)
{
    int i,temp;
    for(i=1;i<=n;i++)
    {
                     if(a[i]<a[i+1])
                     {
                              temp=a[i];
                              a[i]=a[i+1];
                              a[i+1]=temp;      
                                    }
                     }
    
    }*/
void sapxep(int a[],int n)
{
 int temp,i;
 for(int i=2;i<=n;i++)
  {
   temp=a[i];
   int vt=i;
   while ((a[vt-1]>temp)&&(vt>1))
    {
     a[vt]=a[vt-1];
     vt=vt-1;
    }
   a[vt]=temp;
  }
}

int main()
{
    int n,i,b,c;
    int a[100];
    printf("so loai tien menh gia la:");
    scanf("%d",&n);
    printf("nhap vao menh gia cua cac dong tien:\n");
    for(i=1;i<=n;i++)
    {
                     printf("menh gia:");
                     scanf("%d",&a[i]);
                     }
    sapxep(a,n);
    for(i=1;i<=n;i++)
    {
                     printf("%d\t",a[i]);
                     }
    printf("\nnhap vao so tien can doi:");
    scanf("%d",&b);
    i=n;
    printf("%d=",b);
    do{
                  //i=n;
                   c=b/a[i];
                   b=b-a[i];
                   printf("%d*%d\t",c,a[i]);
                   i--;
                   }while(i!=0);
   // printf("%d*%d+",b/a[n],a[n],(b-a[n])/);
    getch();
    
    }
