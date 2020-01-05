#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
enum {hs=100};
int dau[hs], cuoi[hs], v[hs], vc[hs], w[hs];
int n,m;
void tb(char *s) {
     puts(s);
     getch();
     exit(0);
}
char *fi="Caykhung.txt";
void doctep() {
     int i,j,k,t;
     FILE *f;
     f=fopen(fi,"r");
     if (!f) tb("loi mo tep!");
     fscanf(f,"%d%d",&n,&m);     
     for (k=1;k<=m;k++) {
         fscanf(f,"%d%d%d",&i,&j,&t);         
         dau[k]=i;
         cuoi[k]=j;
         w[k]=t;
     }
     fclose(f);
}

void sap_xep_canh() {
     int i,t,j;
     for (i=1;i<m;i++) {
         for (j=1+i;j<=m;j++) {
             if (w[i]>w[j]) {
                t=dau[i];
                dau[i]=dau[j];
                dau[j]=t;
                t=cuoi[i];
                cuoi[i]=cuoi[j];
                cuoi[j]=t;
                t=w[i];
                w[i]=w[j];
                w[j]=t;
             }
         }
     }
     for (i=1;i<=m;i++) {
     printf("%d %d %d",dau[i], cuoi[i], w[i]);
     puts("");
     }
}
void cay_bao_trum() {
     int i,tiep, dem;
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
                  dem++;
                  tiep=1;
                  vc[i]=1;
                  v[dau[i]]=v[cuoi[i]]=1;
                  break;
               }
           }
     }
     if (dem!=n-1) {
        tb("do thi khong lien thong!\n");
     }
     else 
          printf("cay bao trum cua do thi la: \n");
          for (i=1;i<=m;i++) {
              if (vc[i]>0) {
              printf("%d %d",dau[i], cuoi[i]); 
              puts("");
          }
     }
}
int main() {
    doctep();
   // intep();
    sap_xep_canh();
    cay_bao_trum();
    
    getch();
}
