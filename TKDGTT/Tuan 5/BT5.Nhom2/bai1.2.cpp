#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int s[100],f[100],n;
void nhap()
{
     FILE *F;
     int i;
     printf("Du lieu duoc nhap tu tep data.txt\n");
     F=fopen("data.txt","r");
     if(!F)
     {
          puts("Loi mo tep: ");
          getch();
          exit(1);
     }
     fscanf(F,"%d",&n);
     for(i=0;i<n;i++)
     {
          fscanf(F,"%d  %d",&s[i],&f[i]);
     }
     fclose(F);
}

void in()
{
     int i;
     printf("\nSo cac hoat dong :  %d",n);
     printf("\n\n|i   |s[i]      |f[i]");
     printf("\n----------------------");
     for(i=1;i<=n;i++)
     {
            printf("\n| %d  |  %.2d      | %.2d ",i,s[i],f[i]);
     }
}
     

void sapxep()//sap xep cac hoat dong theo thu tu tang dan cua thoi gian ket thuc
{
     int i,j,t;
     for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
       if(f[i]>f[j])
        {
            t=f[i];
            f[i]=f[j];
            f[j]=t;
        }
}

void Activity_Selector()
{
     int i=1,j=1;
     printf("\n\nLich su dung tai nguyen duoc sap xep nhu sau:");
     printf("\na1: %5d %5d\n",s[1],f[1]);
     for(i=2;i<=n;i++)
     {
         if(s[i]>=f[j])
         {
       	    printf("a%d: %5d %5d\n",i,s[i],f[i]);
            j=i;
         }
     }
}    
     
main()
{
     nhap();
     in();
     sapxep();
     Activity_Selector();
     getch();
     return 0;
}
