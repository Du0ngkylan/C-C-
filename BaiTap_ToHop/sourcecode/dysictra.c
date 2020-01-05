#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int a[hs][hs],b[hs],t[hs],q[hs],v[hs];
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
              a[i][j]=0;
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
void in_duong(){
     int i,j;
     i=y;
     j=0;
     while (i!=x && t[i]>0){
           ++j;
           q[j]=i;
           i=t[i];
     }
     printf("so duong di ngan nhat se la: ");
     printf("%d",x);
     for (i=j;i>=1;i--){
         printf("----->%d",q[i]);
         
     }
     puts("");
}
void tim_min(){
     int i,j,tiep;
     for (i=1;i<=n;i++){
         v[i]=-1;
     }
     v[x]=0;
     t[x]=0;
     tiep=1;
     while (tiep){
           tiep=0;
           for (i=1;i<=n;i++){
               for (j=1;j<=n;j++){
                   if (v[i]>=0 && v[j]==-1 && a[i][j]>0||(v[i]>=0 && v[j]>=0 && a[i][j]>0 && v[j]>v[i]+a[i][j])){
                               v[j]=v[i]+a[i][j];
                               t[j]=i;
                               tiep=1;
                   }
               }
           }
     }
     if (v[y]==-1){
                   printf("khong ton tai duong di tu %d den %d",x,y);
     }
     else 
          printf("duong di ngan nhat tu %d den %d co do dai la : %3d",x,y,v[y]);
          puts("");
}
int main(){
    doctep();
    inmatran();
    printf("nhap hai dinh x,y: ");scanf("%d%d",&x,&y);
    tim_min();
    in_duong();
    
    getch();
}
