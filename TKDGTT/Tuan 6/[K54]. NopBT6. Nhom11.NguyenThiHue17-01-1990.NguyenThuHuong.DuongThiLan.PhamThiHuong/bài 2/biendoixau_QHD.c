//Liet ke day cac phep bien doi dua xau X ve xau Y mot cach nhanh nhat.
//F[i][j]: so phep bien doi de dua xau con dau i phan tu cua X thanh xau con dau j phan tu cua Y
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char x[20],y[20];
int f[20][20],m,n;
void lapbang()
{
     int i,j;
     for(i=0;i<=m;i++) f[i][0]=i;
     for(j=0;j<=n;j++) f[0][j]=j;
     for (i=1;i<=m;i++)
     {
         for (j=1;j<=n;j++)
         {
             if(x[i-1]==y[j-1]) f[i][j]=f[i-1][j-1];//do xau co ki hieu tu x[0] den x[m-1]
                            
             else{
                  f[i][j]=f[i-1][j-1]+1;
                  if(f[i][j]>f[i-1][j]+1) f[i][j]=f[i-1][j]+1;
                  if(f[i][j]>f[i][j-1]+1) f[i][j]=f[i][j-1]+1;
                  }
         }
     }
     printf("\nBang phuong an");
     for(i=0;i<=m;i++){
                       printf("\n");
                       for(j=0;j<=n;j++) printf("%d\t",f[i][j]);
                       }
}
void truyvet()
{
     int i,j,k;
     for (i=m,j=n;i>0&&j>0;)
     {
         if(f[i-1][j-1]+1==f[i][j]){
                                    printf("\nThay ki tu %c thanh ki tu %c",x[i-1],y[j-1]);
                                    i--;
                                    j--;
                                    }
         else if(f[i-1][j]+1==f[i][j]){
                                       printf("\nXoa ki tu %c",x[i-1]);
                                       i--;
                                       }
         else if(f[i][j-1]+1==f[i][j]){
                                       printf("\nChen them ki tu %c vao",y[j-1]);
                                       j--;
                                       }
         else if(f[i-1][j-1]==f[i][j]){
                                       i--;
                                       j--;
                                       }
     }
     if(i==0) for(k=1;k<=j;k++) printf("\nChen them ki tu %c vao",y[k-1]);
     if(j==0) for(k=1;k<=i;k++) printf("\nXoa ki tu %c",x[k-1]);
}
int main()
{
    int i,j;
    printf("\nNhap xau chuan: ");
    fflush(stdin);
    gets(y);
    n=strlen(y);
    printf("\nNhap xau can bien doi: ");
    fflush(stdin);
    gets(x);
    m=strlen(x);
    lapbang();
    truyvet();
    getch();
    return 0;
}
    
              
         
                             
     
