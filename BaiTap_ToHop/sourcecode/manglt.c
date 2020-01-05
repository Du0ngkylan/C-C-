#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
enum{hs=100};
int a[hs][hs],t[hs],q[hs],b[hs];
int m,n;
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
void intep(){
     int i,j;
     for (i=1;i<=n;i++){
         for (j=1;j<=n;j++){
             printf("%5d",a[i][j]);
         }
         puts("");
     }
     
}
int ke(int i,int j){
    return a[i][j]+a[j][i]>0;
}
void khoi_dau(){
     int i;
     for (i=1;i<=n;i++){
         b[i]=0;
     }
}
int tim(){
    int i;
    for (i=1;i<=n;i++){
        if ( b[i]==0 ) return i;
    }
    return 0;
}
void manglt(){
     int i,j,c,d,k,p;
     c=d=0;
     k=1;
     p=0;
     while (k>0){
           c++;
           p++;
           d=c;
           t[p]=d;
           b[k]=1;
           q[d]=k;
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
           k=tim();
     }
     t[p+1]=c+1;
     printf("do thi co %d mang lien thong: \n",p);
     for (k=1;k<=p;k++){
         printf("mang lien thong thu %d la: \t",k);
         for (i=t[k];i<t[k+1];i++){
             printf("%5d",q[i]);
         }
         //puts("");
     }
      //puts("");
}
int main(){
    doctep();
    intep();
    khoi_dau();
    manglt();
    getch();
}
