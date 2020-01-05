#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],t[hs],q[hs],v[hs],b[hs];
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
        // a[j][i]=1;
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
void in_duong(){
     int i,j;
     i=y;
     j=0;
     while (i!=x){
           ++j;
           q[j]=i;
           i=t[i];
     }
     printf("duong don tu %d den %d la: ",x,y);
     printf("%d",x);
     for (i=j;i>=1;i--){
         printf("----->%d",q[i]);
     }
     puts("");
}
int liet_ke(int k){
    int i;
    if (k > n) return ;
    if (v[k] == y) in_duong(); 
    for (i=1;i<=n;i++){
        if (b[i]==0 && cung(v[k],i)){                    
                    t[i]=v[k];                    
                    v[k+1]=i;
                    b[i]=1;
                    liet_ke(k+1);
                    b[i]=0;
        }
    }
}
int main(){
    doctep();
    inmatran();
    khoi_dau();
    printf("nhap hai dinh x,y: ");scanf("%d%d",&x,&y);
    v[1]=x;
    b[x]=1;
    liet_ke(x);
    
    getch();
}
         
