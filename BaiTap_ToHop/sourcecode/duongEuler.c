#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
enum{ hs = 100 };
int dau[hs], cuoi[hs], v[hs], b[hs], d[hs], n, m;
void tb(char *s){
     puts(s);
     getch();
     exit(0);
}
char *fi = "dothi.txt";
void doctep(){
     int i, j, k;
     FILE *f;
      f = fopen(fi,"r");
      if (!f) tb("loi mo tep! ");
      fscanf(f,"%d%d",&n,&m);
      for (k = 1; k <=m; k++){
          fscanf(f,"%d%d", &i, &j);
          dau[k] = i;
          cuoi[k] = j;
      }
      fclose(f);
}

void intep(){
     int i,j;
     for (i = 1; i <= m; i++){
         printf("%d  %d ",dau[i], cuoi[i]);
         puts("");
     }
}
void khoi_dau(){
     int i;
     for (i = 1; i <= m; i++){
         b[i] = 0;
     }
}
int tim_dinhxp(){
    int i;
    for (i = 1; i <= n; i++)
        d[i] = 0;
    for (i = 1; i <= m; i++){
        d[dau[i]]++;
        d[cuoi[i]]--;
    }
    for (i = 1; i <= n; i++)
        if (d[i] == 1) return i;
        return 0;
}
void chu_trinhEuler(int k){
     int i;
     if (k > m + 1) return;
     if (k == m + 1){
           for (i = 1; i <= k; i++){
               printf("%2d",v[i]);
           }
           puts("");
     }
     for (i = 1; i <= m; i++){
         if (b[i] == 0 && v[k] == dau[i]){
                  v[k+1] = cuoi[i];
                  b[i] = 1;
                  chu_trinhEuler(k + 1);
                  b[i] = 0;
         }
     }
}

int main(){
    int x;
    doctep();
    intep();
    x = tim_dinhxp();
    if (x == 0) tb("do thi khong co duong Euler");    
    khoi_dau();
    v[1] = x;
    printf("duong Euler cua do thi la: \n");
    chu_trinhEuler(x);
    
    
    getch();
}      
