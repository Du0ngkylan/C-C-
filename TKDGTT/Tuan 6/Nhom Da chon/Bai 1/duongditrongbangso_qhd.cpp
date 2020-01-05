#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,m,c[100][100],a[100][100];
void doctep()
{
     int i,j,t;
     FILE *f;
     f = fopen ("duongditrongbangso.txt","r");
     if(!f){
            puts("loi mo tep");
            }
     fscanf(f,"%d",&n);
     fscanf(f,"%d",&m);
     for(i=1;i<=n;i++)
     {
                      for(j=1;j<=m;j++)
                      {
                                       fscanf(f,"%d",&t);
                                       a[i][j] = t;
     
                                       }
                                       }
     fclose(f);
}
void in()
{
     int i,j;
     for(i=1;i<=n;i++){
                       printf("\n");
                        for(j=1;j<=m;j++){
                                          printf("%5d",a[i][j]);
                                          }
                                          }
     printf("\n");
}
int max(int a,int b,int c)
{
    int max;
    max = a;
    if(max<b)
            max = b;
    if(max<c)
           max = c;
    return max;
}    
void bangphuongan()
{
     int i,j;
     for(i=0;i<n;i++)
     {
                     c[i][0] = 0;
                     }
     for(j=0;j<m;j++){
                      c[0][j] = 0;
                      }
     for(i=1;i<=n;i++){
                       for(j=1;j<=m;j++){
                                         c[i][j] = max(c[i-1][j-1],c[i][j-1],c[i+1][j-1]) + a[i][j];
                                         }
                                         }
}
void truyVet(){
    printf("Tong gia tri cac o tren duong di: %d\n", c[n][m]);
    int i=n, j=m,k;
    while(j>0){
        printf("(%d, %d)", i, j);
        if(i>1)
            printf(" <- ");
        if(j>1){
            k=c[i][j]-a[i][j];
            if(c[i-1][j-1]==k){
                i--;
                j--;    
            } else if(c[i][j-1]==k)
                j--;
            else
                i--;
        } else
            j--;    
    }
    
}

                       
int main()
{
    doctep();
    in();
    bangphuongan();
    truyVet();
    getch();
    return 0;
}                                                   
                                    
