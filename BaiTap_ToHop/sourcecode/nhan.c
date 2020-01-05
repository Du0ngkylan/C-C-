#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
enum {hs=100};
int a[hs][hs], q[hs];
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
int ke(int i, int j) {
    return a[i][j]+a[j][i]>0;
}
void nhan() {
     int kt, k, tiep, c, i;
     c=1;
     q[1]=1;
     tiep=1;
     while (tiep) {
           tiep=0;
           for (i=1;i<=n;i++) {
               kt=1;
               for (k=1;k<=c;k++) {
                   if (q[k]==i || ke(q[k],i)) {
                               kt=0;
                               break;
                   }
               }
               if (kt) {
                       c++;
                       q[c]=i;
                       tiep=1;
               }
           }
     }
     printf("nhan cua do thi la: \n");
     for (i=1;i<=c;i++) {
         printf("%3d",q[i]);
     }
     puts("");
}
int main() {
    doctep();
    intep();
    nhan();
    
    getch();
}
