#include<stdio.h>
#include<conio.h> 
int n,T,i,j,GT,TL; 
int d[100][100]; 
int a[100],c[100]; 
int F[100][100];
int max(int a, int b)
{ 
      return(a>b ? a : b);
}  
void bangphuongan() 
{ 
    for(int i=0;i<=n;i++) 
         F[i][0]=0; 
    for(int j=0;j<=T;j++) 
         F[0][j]=0; 
    for(int i=1;i<=n;i++) 
   { 
        for(int j=1;j<=T;j++) 
       { 
             if (a[i]>j) 
            {
                  F[i][j]=F[i-1][j]; 
            } 
            else 
            { 
                  F[i][j]=max(F[i-1][j],F[i-1][j-a[i]]+c[i]); 
            } 
        } 
    } 
}
 
//de quy
 
void dequy() 
{ 
      i=n; 
      j=T;
      while ((i!=0)&&(j!=0))
      {
           if (F[i][j]!=F[i-1][j])
          {
                printf("%2d",i); 
                GT=GT+c[i];
                TL=TL+a[i]; 
                j=j-c[i]; 
           } 
           i--;
       } 
}
int main() 
{ 
   FILE *f;
   f = fopen("BaLo.txt", "r");
    if(!f)
    {
          puts("Loi mo tep");
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &T);
    for(int j=0; j<n; j++)
    {
          fscanf(f, "%d", &c[j]);
          fscanf(f, "%d", &a[j]);
    }
      printf("So do vat da cho la: ");
      printf("%2d",n); 
      printf("\n"); 
      printf("Tong trong luong cho phep cua tui : ");
      printf("%2d",T);
      printf("\n"); 
      printf("gia tri cac do vat "); 
      for(int j=0;j<n;j++) 
      { 
            printf("%5d",c[j]); 
      } 
      printf("\n");
      printf("trong luong cac do vat "); 
      for(int j=0;j<n;j++) 
      { 
               printf("%5d",a[j]);
      } 
      printf("\n"); 
      printf("Puong an bang thuat toan de quy :");
      bangphuongan();
      dequy();
      getch(); 
}
