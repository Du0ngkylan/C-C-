#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
enum {hs=100};
int a[hs][hs], dau[hs], cuoi[hs], v[hs];
int n,m;
void tb(char *s) {
     puts(s);
     getch();
     exit(0);
}
char *fi="dothi.txt";
void doctep() {
     int i,j,k;
     FILE *f;
     f=fopen(fi,"r");
     if (!f) tb("loi mo tep!");
     fscanf(f,"%d%d",&n,&m);
     for (i=1;i<=n;i++) {
         for (j=1;j<=n;j++) {
             a[i][j]=0;
         }
     }
     for (k=1;k<=m;k++) {
         fscanf(f,"%d%d",&i,&j);
         a[i][j]=1;
         dau[k]=i;
         cuoi[k]=j;
     }
     fclose(f);
}

void intep() {
     int i,j;
     for (i=1;i<=n;i++) {
         for (j=1;j<=n;j++) {
             printf("%3d",a[i][j]);
         }
         puts("");
     }
     
}
void sacso() {
     int i,k, tiep;
     tiep=1;
     v[1]=1;
     while (tiep) {
           tiep=0;
           for (k=1;k<=m;k++) {
               if (v[dau[k]]) {
                  if (v[cuoi[k]]==v[dau[k]]) 
                     tb("do thi ko co sac so =2\n");
                  if (v[cuoi[k]]==0) {
                     tiep=1;
                     v[cuoi[k]]=3-v[dau[k]];
                  }
               }
               if (v[cuoi[k]]) {
                  if (v[cuoi[k]]==v[dau[k]]) 
                     tb("do thi ko co sac so =2\n");
                  if (v[dau[k]]==0) {
                     tiep=1;
                     v[dau[k]]=3-v[cuoi[k]];
                  }
               }
               if (v[dau[k]]+v[cuoi[k]]==0) {
                  tiep=1;
                  v[dau[k]]=1;
               }
           }
     }
     printf("cac dinh co mau =2 la : \n");
     for (i=1;i<=m;i++) {
         if (v[i]==2) {
            printf("%3d",i);
         }
     }
     puts("");
}

int main() {
    doctep();
    intep();
    sacso();
    puts("do thi co sac so =2");
    
    getch();
}
