#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum {hs=100};
int dau[hs], cuoi[hs], v[hs], v1[hs];
int n,m,max;
void tb(char *s) {
     puts(s);
     getch();
     exit(0);
}
char *fi="Tapcung.txt";
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
void gan_cung(int *x, int *y) {
     int i;
     for (i=1;i<=m;i++) {
         x[i]=y[i];
     }
}
int cung_doclap(int i, int j) {
     return (dau[i]==dau[j] || dau[i]==cuoi[j] || cuoi[i]==dau[j] || cuoi[i]==cuoi[j]);
}
int ktra_doclap(int x, int k) {
    int i;
    for (i=1;i<=k;i++) {
        if (cung_doclap(x,v[i])) 
           return 1;
    }
    return 0;
}
void tap_cung(int k) {
     int i;
     if (k>m) return;
     if (k>max) {
        max=k;
        gan_cung(v1,v);
     }
     for (i=1;i<=m;i++) {
         if (!ktra_doclap(i,k)) {
            v[k+1]=i;
            tap_cung(k+1);
         }
     }
}
int main() {
    int i;
    doctep();
    intep();
    max=0;
    tap_cung(0);
    printf("so cung doclap max cua do thi la: %d\n",max);
    printf("tap cung doc lap cua do thi la:\n");
    for (i=1;i<=max;i++) {
        printf("%2d %2d",dau[v1[i]], cuoi[v1[i]]);
        puts("");
    }
    getch();
}
