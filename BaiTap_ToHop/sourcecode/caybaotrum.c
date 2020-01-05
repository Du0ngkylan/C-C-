#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
enum {hs=100};
int dau[hs], cuoi[hs], v[hs], vc[hs];
int n,m;
void tb(char *s) {
     puts(s);
     getch();
     exit(0);
}
char *fi="cay.txt";
void doctep() {
     int i,j,k;
     FILE *f;
     f=fopen(fi,"r");
     if (!f) tb("loi mo tep!");
     fscanf(f,"%d%d",&n,&m);     
     for (k=1;k<=m;k++) {
         fscanf(f,"%d%d",&i,&j);         
         dau[k]=i;
         cuoi[k]=j;
     }
     fclose(f);
}

void intep() {
     int i;
     for (i=1;i<=m;i++) {
         printf("%d %d",dau[i], cuoi[i]);
         puts("");
     }
}
void cay_bao_trum() {
     int i, tiep, dem;
     tiep=dem=1;
     for (i=1;i<=m;i++) {
         vc[i]=0;
         v[i]=0;
     }
     vc[1]=1;
     v[dau[1]]=v[cuoi[1]]=1;
     while (tiep) {
           tiep=0;
           for (i=1;i<=m;i++) {
               if (v[dau[i]]+v[cuoi[i]]==1) {
                            vc[i]=1;
                            v[dau[i]]=v[cuoi[i]]=1;
                            dem++;
                            tiep=1;
               }
           }
     }
     if (dem!=n-1) printf("do thi khong lien thong\n");
     else {
          printf("cay bao trum cua do thi la: \n");
          for (i=1;i<=m;i++) {
              if (vc[i]>0) {
                  printf("%d %d",dau[i], cuoi[i]);
                  puts("");
              }
          }
     }
}                                                  
int main() {
    doctep();
    intep();
    cay_bao_trum();
    
    getch();
}
