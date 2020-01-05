#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,W,p[100],v[100],c[100][100];
void doctep()
{
     int i;
     FILE *file;
     file = fopen("balo.txt","r");
     if(!file)
     {
              puts("loi mo tep");
              }
     fscanf(file,"%d",&n);
     fscanf(file,"%d",&W);
     for(i=1;i<=n;i++)
     {
                      fscanf(file,"%d",&p[i]);
                      fscanf(file,"%d",&v[i]);
                      }
     fclose(file);
}
void bangphuongan()
{
     int i,j;
     for(i=0;i< n ;i++){
                c[i][0] = 0; // khong the cho vat nao vao balo
                }
     for(j= 0; j < W;j++){
            c[0][j] = 0; // khong co vat nao de cho vao balo
            }
     for(i=1;i<=n;i++)
     {
                     for(j=1;j<=W;j++){//su dung 2 vong for de tinh ma tran phuong an
                                           c[i][j] = c[i-1][j];// gia su khong chon vat thu i
                                           if(j >= p[i]  && (c[i][j] < c[i-1][j-p[i]] + v[i]))//neu vat i vua tui va gia tri i tot nhat
                                                c[i][j] = c[i-1][j-p[i]] + v[i];
                                                }
                                                }
}
void truyvet()
{
     int i=n;
     int j = W;
     if(c[n][W] > 0 )
     {
                while(i> 0 && j>0){
                         if(c[i][j] == c[i-1][j-p[i]] + v[i]){
                                    printf("chon vat %d:(%d,%d)\n",i,p[i],v[i]);
                                    j = j- p[i];
                                    }
                                    i--;
                                    }
                                    }
                printf("gia tri lon nhat = %d",c[n][W]);
    }
void indl()
{
     int i;
     printf("so do vat  = %d\n",n);
     printf("gioi han cua ba lo = %d\n",W);
     printf("vat\ttrongluongvat\t\tgiatri vat\n");
     for(i=1;i<=n;i++)
     {
                     printf("%d\t%d\t\t\t%d\n",i,p[i],v[i]);
                     }
}                     
int main()
{
    doctep();
    indl();
    bangphuongan();
    truyvet();
    getch();
    return 0 ;
}                                                                         
                                                                                          
                                           
                                      
                      
