/*
  Name:  Bien Doi Xau
  Author: Nhom 12
  Date: 23/04/12 07:43
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>

char x[100], y[100];
char x1[100], y1[100];
int m, n, c[100][100];


void dichPhai(char *xauNguon, char *xauDich){
    int doDaiXau = strlen(xauNguon);
    xauDich[0]=' ';
    for(int i=0; i<=doDaiXau; i++){
        xauDich[i+1] = xauNguon[i];    
    }
}

void DocDL(){
    FILE *file;
    file = fopen("BienDoiXau.txt", "r");
    
    if(file == NULL)
    {
        printf("Loi mo tep");    
        getch();
        exit(0);
    }
    else
    {    
        fgets(x1, 255, file);
        fflush(stdin);
        fgets(y1, 255, file);
        
        m=strlen(x1)-1;
        n=strlen(y1)-1;
        
        dichPhai(x1, x);
        dichPhai(y1, y);
    } 
}

void InDL()
{
    printf("Do dai xau 1: %d.\n",m);
    for(int i = 1;i<= m; i++)
    printf("%c",x[i]);     
    printf("\n");
    
    printf("Do dai xau 2: %d.\n",n);
    for(int i = 1;i<= m; i++)
    printf("%c",y[i]);  
    printf("\n");
}


void KhoiTao()
{
    for(int i=0; i<=m; i++)
        c[i][0] = i;
    for(int j=0; j<=n; j++)
        c[0][j] = j;     
}

int TimMin(int a, int b, int c)
{
   int min;
   if (b<c) min = c;
   else min = b;
 
   if (a<min) min = a;
   return min;
}

void LapBangQHD()
{
    KhoiTao();
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++){
            if(x[i]==y[j])
                 c[i][j] = c[i-1][j-1];      
            
            else
                c[i][j] = TimMin(c[i-1][j-1], c[i-1][j], c[i][j-1])+1;  
            
            printf("%d    ",c[i][j]);   
        }
        printf("\n");
     }
     
    printf("In Ma Tran QHD:\n");
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++)
            printf("%d ", c[i][j]);    
        puts("");
    }
}     

void TruyVetVaIn()
{
    int i=m, j=n;
    while(i>0 || j>0)
    {
        if(x[i]==y[j])
        {
            i--;
            j--;
        }    
        else
        {
            if(i>0)
            {
                if(j>0)
                {
                    if(c[i][j]==c[i-1][j-1]+1)
                    {
                        printf("su dung phep thay the ky tu tai vi tri %d bang ky tu %c\n", i, y[j]);    
                        i--;
                    }                                        
                    else
                        printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                    j--;
                }   
                else
                {
                    printf("Su dung phep xoa ky tu tai vi tri %d\n", i);    
                    i--;
                }
            }else if(j>0)
            {
                printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                j--;
            }    
        }
    }         
}

int main()
{
   DocDL();
   InDL();
   KhoiTao();
   LapBangQHD();
   TruyVetVaIn();
   getch();   
}
