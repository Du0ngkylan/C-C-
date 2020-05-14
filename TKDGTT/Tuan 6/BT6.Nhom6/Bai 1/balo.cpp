#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int n, w, c[50][50], p[100], v[100] ;
void docDuLieu(){
     FILE *f;
     f = fopen("BAG.INP", "r");
     if(f != NULL)
     {
          fscanf(f, "%d %d", &n,&w);
          for(int i = 1 ; i <= n ; i++)
                  fscanf(f, "%d %d", &p[i], &v[i]);
     }
     else{
          puts("Khong tim thay file!");
          getch();
          exit(1);
          }
}
void inDuLieu(){
     for(int i = 1; i <= n ; i++)
             printf("Vat thu %d: (%d, %d)\n", i, p[i], v[i]);
     printf("Gioi han cua ba lo: %d\n\n", w);
}
void dungBangPhuongAn(){
     int i,j;
     for(i=0; i<=n; i++)
         c[i][0]=0;
     for(j=0; j<=w; j++)
         c[0][j]=0;
     for(i = 1; i <= n; i++){
             for(j = 1; j <= w; j++){
                     c[i][j] = c[i-1][j];
                     if(p[i] <= j){
                                 if(c[i-1][j-p[i]]+ v[i] > c[i][j])
                                        c[i][j] = c[i-1][j-p[i]] + v[i];
                     }
             }
     }
}
void truyVet(){
     int i = n, j = w;
     if(c[n][w]>0){
                   while(i>0&& j>0){
                               if(c[i][j]==c[i-1][j-p[i]]+v[i])
                               {
                                     printf("Su dung vat thu %d: (%d, %d) \n", i, p[i], v[i] );
                                     j -= p[i];
                               }
                               i--;
                   }
     }
     printf("Gia tri lon nhat la: %d\n", c[n][w]);
}
int main(){
    docDuLieu();
    inDuLieu();
    dungBangPhuongAn();
    truyVet();
    getch();
    return 0;
}
