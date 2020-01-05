
/*ho va ten: Bui Thi Thu Dung*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int n, w, c[50][50], p[100], v[100] ;
void doctep()
{
    FILE *f;
    int i;
    f=fopen("balo.txt","r");
    fscanf(f,"%d %d",&n,&w);printf ("%d\t%d\n",n,w);
        for(i=1; i<=n; i++){ 
                fscanf(f, "%d %d", &p[i], &v[i]);   
        }       
        fclose(f);
}



void intep(){
        for(int i=1; i<=n; i++){
            printf(" Cac do vat thu %d: (%d, %d)\n", i, p[i], v[i]);
        }
        printf("Gioi han toi da cua ba lo: %d\n\n", w);
}

void BangPhuongAn(){
        for (int i=0; i<=n; i++)
           for (int j=0; j<=w; j++)
           {
               c[i][j]=0;
           }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                c[i][j] = c[i-1][j];
                if(p[i]<=j){
                    if(c[i-1][j-p[i]]+ v[i] > c[i][j] ){    
                        c[i][j]= c[i-1][j-p[i]]+v[i];
                    }
                }
            }        
        }     
}

void TimVet(){
    int i=n, j=w;
    if(c[n][w]>0){
        while(i>0&& j>0){
                if(c[i][j]==c[i-1][j-p[i]]+v[i]){
                    printf("Su dung vat thu %d: (%d, %d) \n", i, p[i], v[i] );
                    j-=p[i]; 
                } 
                    i--;
        }
    } 
    printf("Gia tri lon nhat la: %d\n", c[n][w]);
}

int main(){
    doctep();
    intep();
    BangPhuongAn();
    TimVet();   
    getch();
    return 0;
}

