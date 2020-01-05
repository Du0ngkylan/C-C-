#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],b[hs],v[hs];
int m,n;

void tb(char *s){
     puts(s);
     getch();
     exit(0);
}
char *fi="dothi1.txt";
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
         a[j][i]=1;
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
void khoi_dau(){
     int i;
     for (i=1;i<=n;i++){
         b[i]=0;
     }
}
int ke(int i, int j){
    return a[i][j] + a[j][i];
}
void in_kq(){
     int i;
     for (i=1;i<=n;i++){
         printf("%3d",v[i]);
     }
     printf("%3d",1);
     puts(" ");
     return;
}
void chu_trinhH(int k){
     int i;
     if (k>n) return ;
     if (k == n && ke(v[k],v[1])) in_kq();
     for (i=1;i<=n;i++){
         if (b[i]==0 && ke(v[k],i)){
                  v[k+1]=i;
                  b[i]=1;
                  chu_trinhH(k+1);
                  b[i]=0;
         }
     }
}
int main(){
    doctep();
    inmatran();
    khoi_dau();
    v[1] = 1;
    b[1] = 1;
    printf("chu trinh H cua do thi la: \n");
    
    chu_trinhH(1);
    
    getch();
}
