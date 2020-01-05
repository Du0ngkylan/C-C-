#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],next[hs][hs];
int m,n,x,y;

void tb(char *s){
     puts(s);
     getch();
     exit(0);
}
char *fi="dothi1.txt";
void doctep(){
     int i,j,k,t;
     FILE *f;
     f=fopen(fi,"r");
     if (!f) tb("loi mo tep!");
     fscanf(f,"%d%d",&n,&m);
     for (i=1;i<=n;i++){
          for (j=1;j<=n;j++){
              a[i][j]=-1;
          }
     }
     for (k=0;k<m;k++){
         fscanf(f,"%d%d%d",&i,&j,&t);
         a[i][j]=t;
     }
     fclose(f);
}
void inmatran(){
     int i,j;
      for (i=1;i<=n;i++){
          for (j=1;j<=n;j++){
              printf("%5d",a[i][j]);
          }
          puts("");
      }
}
void Floyd(){
     int i,j,k;
     for (i=1;i<=n;i++){
          for (j=1;j<=n;j++){
              next[i][j]=j;
          }
     }
     for (k=1;k<=n;k++){
         for (i=1;i<=n;i++){
             for (j=1;j<=n;j++){
                 if (a[i][k]>=0 && a[k][j]>=0)
                 if (a[i][j]<0 ||(a[i][j]>=0 && a[i][j]>a[i][k]+a[k][j]))
                 {
                               a[i][j]=a[i][k]+a[k][j];
                               next[i][j]=next[k][j];
                 }
             }
         }
     }
     if (a[x][y]<0) puts("khong co duong di!");
     else 
          printf("do dai ngan nhat tu %d den %d la: %3d",x,y,a[x][y]);
}
void in_duong(){
     int k=x;
     printf("duong di ngan nhat tu %d den %d la: ",x,y);
     while (k!=y){
           printf("%d----->",k);
           k=next[k][y];
     }
     printf("%d",y);
}
int main(){
    doctep();
    inmatran();
    printf("nhap hai dinh x,y: ");scanf("%d%d",&x,&y);
    Floyd();
    puts("");
    in_duong();
    
    getch();
}

