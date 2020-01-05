#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],q[hs],b[hs];
int m,n,x;

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
int cung(int i,int j){
    return a[i][j]>0;
}
void khoi_dau(){
     int i;
     for (i=1;i<=n;i++){
         b[i]=0;
     }
}
int liet_ke(int k){
    int i,c,d,y;
    c=d=1;
    q[c]=x;
    b[x]=1;
    while (d<=c){
          y=q[d];
          d++;
          for (i=1;i<=n;i++){
              if (b[i]==0 && cung(y,i)){
                          c++;
                          b[i]=1;
                          q[c]=i;                         
              }
          }
    }
    printf("cac dinh co the di tu dinh %d la: ",x);
    for (i=2;i<=c;i++){
        printf("%3d",q[i]);
    }
    puts("");
}
int main(){
    doctep();
    inmatran();
    khoi_dau();
    printf("nhap dinh x: ");scanf("%d",&x);
    //khoi_dau();
    liet_ke(x);
    
    getch();
}
