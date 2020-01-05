/*
De bai:
    Cho 2 day X (M phan tu) va Y (n phan tu)
    Tim day con chung dai nhat cua 2 day
    
Input:    
    M
    X[1]...X[M]
    N
    Y[1]...Y[N]
    
Output:
    K - do dai day con dai nhat
    Day con chung dai nhat        
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define INPUT_FILE "DayConChungDaiNhat.txt"

int n,m,C[100][100],X[100],Y[100];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        fscanf(file,"%d", &m);
        for(int i=1; i<=m; i++)
            fscanf(file, "%d", &X[i]);
        fscanf(file, "%d", &n);
        for(int i=1;i<=n;i++)
            fscanf(file, "%d", &Y[i]);
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void inDuLieu(){
    puts("Day X:");
    for(int i=1; i<=m; i++)
        printf("%d ", X[i]);
    puts("");
    
    puts("Day Y:");
    for(int i=1; i<=n; i++)
        printf("%d ", Y[i]);
    puts("");
    
}
void BangPhuongAn()
{
     int i,j;
     for(i=0;i<=m;i++)
        C[i][0]=0;
     for(j=0;j<=n;j++)
        C[0][j]=0;
     for(i=1;i<=m;i++)
     {
         for(j=1;j<=n;j++)
         if(X[i]==Y[j])
            C[i][j]=C[i-1][j-1]+1;
         else {
                 C[i][j]=C[i-1][j];
                 if(C[i][j-1]>C[i-1][j])
                    C[i][j]=C[i][j-1];
              }
     }
}
void TruyVet()
{
     int i,j;
     i=m;
     j=n;
     while(i>0&&j>0){
        if(X[i]==Y[j]){
            printf("%6.1d",X[i]);
            i=i-1;j=j-1;
        }
        else {
             if(C[i-1][j]>C[i][j-1])
                i=i-1;
             else j=j-1;
        }
     }      
}
int main()
{
    int i,j;
    docDuLieu();
    inDuLieu();
    BangPhuongAn();
    printf("Do dai day con chung dai nhat la: %d \n",C[m][n]);
    if(C[m][n]>0){
         printf("Day con chung dai nhat la (in nguoc tu cuoi len): \n");
         TruyVet();
    }
    else
        puts("Hai day khong co day con chung !");
    getch();
    return 0;
}
