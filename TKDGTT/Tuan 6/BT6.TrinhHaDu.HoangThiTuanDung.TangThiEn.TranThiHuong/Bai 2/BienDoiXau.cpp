/*
De bai:
    Cho 3 phep bien doi xau:
        Chen 1 ky tu vao sau vi tri i
        Xoa ky tu tai vi tri i
        Thay the ky tu tai vi tri i bang 1 ky tu khac
    Cho 2 xau X, Y.
    Chon cach bien doi X thanh Y sao cho so phep bien doi it nhat.        

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE "BienDoiXau.txt"

char x[100], y[100], x1[100], y1[100];
int m, n, c[100][100];

void dichPhai(char *xauNguon, char *xauDich){
    int doDaiXau = strlen(xauNguon);
    xauDich[0]=' ';
    for(int i=0; i<=doDaiXau; i++){
        xauDich[i+1] = xauNguon[i];    
    }
}

void doc(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        //Doc du lieu        
        fgets(x1, 255, file);
        fflush(stdin);
        fgets(y1, 255, file);
        
        m=strlen(x1)-1;
        n=strlen(y1);
        
        dichPhai(x1, x);
        dichPhai(y1, y);
        
    }
    else{
        puts(" Error file!");    
        getch();
        exit(0);
    }
}

void in(){
    printf("M=%d, N=%d\n", m, n);
    printf("X=%s", x);
    printf("Y=%s\n", y);
}

int min(int a, int b, int c){
    int min=a;
    if(min>b)
        min=b;
    if(min>c)
        min=c;
    return min;    
}

void BangPhuongAn(){
    /*Co so*/    
    for(int i=0; i<=m; i++)
        c[i][0] = i;
    for(int j=0; j<=n; j++)
        c[0][j] = j;
        
    /*Dung bang*/        
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(x[i]==y[j])
                c[i][j] = c[i-1][j-1];
            else{
                c[i][j] = min(c[i-1][j-1], c[i-1][j], c[i][j-1])+1;         
            }    
        }
	}

void TruyVet(){
    int i=m, j=n;
    while(i>0 || j>0){
        if(x[i]==y[j]){
            i--;
            j--;
        }    
        else{
            if(i>0){
                if(j>0){
                    if(c[i][j]==c[i-1][j-1]+1){
                        printf(" thay the ky tu tai vi tri %d bang ky tu %c\n", i, y[j]);    
                        i--;
                    }                                        
                    else
                        printf(" chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                    j--;
                }   
                else{
                    printf(" xoa ky tu tai vi tri %d\n", i);    
                    i--;
                }
            }else if(j>0){
                printf(" chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                j--;
            }    
        }
    }    
}

int main(){
    doc();
    in();
    BangPhuongAn();
    TruyVet();   
    getch();
    return 0;
}

