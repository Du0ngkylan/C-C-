/*
De bai:
    Kim tu thap N tang
    Tang i co i phong
    Moi phong co 1 so vang
    Tim duong di tu dinh kim tu thap xuong chan kim tu thap
    Sao cho tong so vang lay duoc la toi da.

Input:
    N
    So vang moi phong    

Output:
    So vang toi da
    Duong di    
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "KimTuThap.txt"

int n, a[100][100], c[100][100];

void docDuLieu(){
    FILE *file;
    int t;
    
    file = fopen(INPUT_FILE, "r");    
    if(file!=NULL){
        fscanf(file, "%d",&n );
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++){
                fscanf(file, "%d", &t);
                a[i][j] = t;
            }
    }else{
        puts("khong tim thay file");   
        getch();
        exit(0);
    }
}

void inDuLieu(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            printf("%d ", a[i][j]);    
        puts("");
    }    
}

void dungBang(){
    /*Co so*/
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            c[i][j] = 0;
            
    /*Dung bang*/
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++){
            c[i][j] = c[i-1][j-1];
            if(c[i][j] < c[i-1][j])
                c[i][j] = c[i-1][j];   
            c[i][j] += a[i][j];
        }    
    
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++)
            printf("%2d ", c[i][j]);    
        puts("");
    }
    */
}

void truyVet(){
    int i=n, j, max=1;
    for(j=2; j<=n; j++)
        if(c[n][j] > c[n][max])
            max = j;
    
    printf("So vang lon nhat: %d\n", c[n][max]);
    j=max;
    while(i>1 || j>1){
        printf("(%d, %d) <- ", i, j);
        if(c[i][j] == c[i-1][j-1]+a[i][j]){
            j--;    
        }
        i--;
    }
    puts("(1, 1).");
}

int main(){
    docDuLieu();
    inDuLieu();
    dungBang();
    truyVet();
    
    puts("Hoan thanh!");    
    getch();
    return 0;
}
