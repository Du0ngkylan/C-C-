#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],b[hs],t[hs],q[hs],p[hs];
int m,n,x,y;

void tb(char *s){
     puts(s);
     getch();
     exit(0);
}
char *fi="dothi.txt";
void doctep(){
     int i,j,k;
     FILE *f;
     f=fopen(fi,"r");
     if (!f) tb("loi mo tep!");
     fscanf(f,"%d%d",&n,&m);
     for (i=1;i<=n;i++){
          for (j=1;j<=n;j++){
              a[i][j]=0;
          }
     }
     for (k=0;k<m;k++){
         fscanf(f,"%d%d",&i,&j);
         a[i][j]=1;
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
int ke(int i, int j){
    return a[i][j]>0;
}
void khoi_dau(){
     int i;
     for (i=1;i<=n;i++){
         b[i]=0;
     }
}
void manglt(){
     int i,j,c,d;
     c=d=1;
     q[1]=1;
     b[1]=1;
     while (d<=c){
           j=q[d];
           for (i=1;i<=n;i++){
               if (b[i]==0 && ke(j,i)){
                           c++;
                           q[c]=i;
                           b[i]=1;
               }
           }
           d++;
     }
     if (c==n) printf("do thi lien thong.");
     else 
          printf("do thi khong lien thong.");
}
int main(){
    doctep();
    inmatran();
    khoi_dau();
    manglt();
    
    getch();
}
