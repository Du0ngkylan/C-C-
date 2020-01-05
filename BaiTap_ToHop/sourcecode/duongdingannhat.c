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
     while (i!=x && t[i]>0){
           ++j;
           p[j]=i;
           i=t[i];
     }
     printf("duong di ngan nhat tu %d den %d la: ",x,y);
     printf("%d",x);
     for (i=j;i>=1;i--){
         printf("----->%d",p[i]);
     }
}
void tim_min(){
     int i,c,d,k;
     c=d=1;
     q[c]=x;
     b[x]=1;
     t[x]=0;
     while (d<=c){
           k=q[d];
           d++;
           if (k==y) in_duong();
           for (i=1;i<=n;i++){
               if (b[i]==0 && cung(k,i)){
                           c++;
                           q[c]=i;
                           b[i]=1;
                           t[i]=k;
               }
           }
     }
}
                         
int main(){
    doctep();
    inmatran();
    printf("nhap hai dinh x,y: ");scanf("%d%d",&x,&y);
    khoi_dau();
    tim_min();
    
    getch();
}
         
