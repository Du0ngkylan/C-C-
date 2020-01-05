
// bai toan sap xep su dung tai nguyen.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int s[100],f[100],n;

void nhap()
{
     FILE *f;
     int t,i;
     f=fopen("data1.txt","r");
     if(!f)
     {
        puts("Loi mo tep: ");
        getch();
        exit(0);
     }
     fscanf(f,"%d",&n);
     for(i=1;i<=n;i++)
     {
        fscanf(f,"%d  %d",&s[i],&f[i]);
     }
     fclose(f);
}

void in()
{
     int i;
     printf("\n So cac hoat dong la:  %d",n);
     printf("\n Cac hoat dong dien ra la: ");
     for(i=1;i<=n;i++)
     {
        printf("\nHoat dong %d duoc bat dau tu %d den %d",i,s[i],f[i]);
     }
}
     

int kiemtratang()
{
    int i,count=0;
    for(i=1;i<=n-1;i++)
     if(f[i]<f[i+1])
       count++;
     if(count==n-1)
       return 1;
       return 0;
}

void swap(int *m,int *n)
{
     int temp;
     temp=*m;
     *m=*n;
     *n=temp;
}

void sapxep()
{
     int i,j;
     for(i=1;i<=n-1;i++)
      for(j=i+1;j<=n;j++)
       if(f[i]>f[j])
        swap(f+i,f+j);
}

void Activity_Selector()
{
     int i=1,count=1,j=1;
     j=1;
     printf("\n Cac hoat dong duoc sap xep nhu sau:");
     printf("\n Cong viec 1: %5d %5d\n",s[1],f[1]);
     for(i=2;i<=n;i++)
     {
        if(s[i]>=f[j])
        {
           count++;
       	   printf("Cong viec thu %d: %5d %5d\n",count,s[i],f[j]);
           j=i;
        }
     }
}    
     
main()
{
    nhap();
    in();
    if(!kiemtratang())
    {
        sapxep();
        printf("\n");
    }
    Activity_Selector();
    getch();
    return 0;
}
