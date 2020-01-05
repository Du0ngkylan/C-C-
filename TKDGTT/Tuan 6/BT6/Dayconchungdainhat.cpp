#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define INPUT_FILE "DayConChung.txt"

int n,m,L[100][100],a[100],b[100];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        fscanf(file,"%d", &m);
        for(int i=1; i<=m; i++)
            fscanf(file, "%d", &a[i]);
        fscanf(file, "%d", &n);
        for(int i=1;i<=n;i++)
            fscanf(file, "%d", &b[i]);
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}
void inDuLieu(){
    puts("Day a:");
    for(int i=1; i<=m; i++)
        printf("%d ", a[i]);
    puts("");
    
    puts("Day b:");
    for(int i=1; i<=n; i++)
        printf("%d ", b[i]);
    puts("");
    
}
int Quyhoachdong()
{
    int i, j, x;
    for (i = 1; i <= m;i++)
        L[i][1] = 0;
    for (j = 1; j <= n;j++)
        L[1][j] = 0;
            for (i =2; i <= m; i++)
            for (j = 2; j <= n; j++)
            {
                if(a[i]==b[j])
            L[i][j]=L[i-1][j-1]+1;
         else 
                 {
                                  L[i][j]=L[i-1][j];
                                  if(L[i][j-1]>L[i-1][j])
                                  L[i][j]=L[i][j-1];
                 }
             }
        int k = L[m][n];
    return k;
}
void Truyvet()
{
   int i = m, j = n;
   while ( i > 0 && j > 0)
   {
         if(a[i]==b[j])
         {
            printf("%6.1d",a[i]);
            i=i-1;j=j-1;
         }
        else 
        {
             if(L[i-1][j]>L[i][j-1])
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
    Quyhoachdong();
    printf("Do dai day con chung dai nhat la: %d \n",L[m][n]);
    if(L[m][n]>0){
         printf("Day con chung dai nhat la (in nguoc tu cuoi len): \n");
         Truyvet();
    }
    else
        puts("Hai day khong co day con chung !");
    getch();
    return 0;
}
