#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
enum{hs=100};
int dau[hs],cuoi[hs],b[hs],v[hs];
int n,m;
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
     for (k=1;k<=m;k++){
         fscanf(f,"%d%d",&i,&j);
         dau[k]=i;
         cuoi[k]=j;
     }
     fclose(f);
}

void intep(){
     int i;
     for (i=1;i<=m;i++){
         printf("%d %d",dau[i],cuoi[i]);
         puts("");
     }
}
void khoi_dau(){
     int i;
     for (i=1;i<=m;i++){
         b[i]=0;
     }
}
void chu_trinhE(int k){
     int i;
     if (k>m+1) return ;
     if (k==m+1 && v[k]==v[1]){
                for (i=1;i<=k;i++){
                    printf("%2d",v[i]);
                }
                puts("");
     }
     for (i=1;i<=m;i++){
         if (b[i]==0 && v[k]==dau[i]){
                     v[k+1]=cuoi[i];
                     b[i]=1;
                     chu_trinhE(k+1);
                     b[i]=0;
         }
     }
} 
int main(){
    doctep();
    intep();
    khoi_dau();
    v[1]=1;
    printf("chu trinh Euler cua do thi la:\n");
    chu_trinhE(1);
    
    getch();
}
     
