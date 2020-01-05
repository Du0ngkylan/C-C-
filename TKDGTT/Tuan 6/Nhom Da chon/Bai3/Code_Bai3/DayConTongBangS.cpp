#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "DayConTongBangS.txt"
//====================================
int a[100], n, s;
bool c[100][100];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    if(file != NULL){    
          fscanf(file,"%d", &n);
          for(int i=1; i<=n; i++)
                  fscanf(file, "%d", &a[i]);
          fscanf(file, "%d", &s);        
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}
//====================================
void inDuLieu(){
    for(int i=1; i<=n; i++)
            printf("%d ", a[i]);
    puts("");
}
//====================================
void dungBangPhuongAn()
{
    for(int j=0;j<=s;j++)
    c[0][j]=false;
    for(int i=0;i<=n;i++)
        c[i][0]=true;        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=s;j++)
        {
            if(c[i-1][j]==true)
                c[i][j]=true;
            else if(j>=a[i]){
                if(c[i-1][j-a[i]]==true)
                    c[i][j] = true;    
            }
            else c[i][j] = false;
        }
}
//====================================
void truyVet()
{
    if(c[n][s]==false)
        printf("Khong co phuong an bieu dien %d\n", s);
    else{
        int i=n, j=s;
        while(j>0){
            if(j>=a[i]){
                if(c[i-1][j-a[i]]==true){
                    j -= a[i];
                    printf("%d", a[i]);                        
                    if(j==0)
                        printf(" = %d\n", s);
                    else printf(" + ");                        
                }                        
            }
            i--;
        }
    }    
}
//====================================
int main(){
    docDuLieu();
    inDuLieu();
    dungBangPhuongAn();
    truyVet();   
    getch();
    return 0;
}
