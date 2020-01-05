/*
Bai toan xep ba lo 0-1
    Cho N do vat voi trong luong tuong ung p[i],w[i]
    Chon cac do vat xep vao ba lo co trong luong P sao cho dat gia chi cao nhat.   
    Moi do vat chi duoc chon toi da 1 lan.
    W: tong gia tri lon nhat cac so vat da cho vao ba lo.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int n,W,c[50][50],p[100],w[100] ;

void Doctep()
{
    int i;
    FILE *f;
    f = fopen("XepBaLo.txt","r");
    if(!f){
         puts("Loi mo tep!");    
         getch();
         exit(0);
    }
    else
    {
        fscanf(f,"%d",&n);    
        for(i=1;i<=n;i++){ 
                fscanf(f,"%d %d",&p[i],&w[i]);   
        }       
        fscanf(f,"%d",&W);
    }
    fclose(f);
}

void In(){
    int i;
    printf("(trong luong, gia tri)\n");
    for(i=1;i<=n;i++){
        printf("\nvat thu %d: (%d, %d)",i,p[i],w[i]);
    }
    printf("\nTong gia tri lon nhat cac do vat cho vao balo : %d\n",W);
}

void BangPhuongAn()
{
    int i,j;
    for(i=0;i<=n;i++)     c[i][0]=0;
    for(j=0;j<=W;j++)     c[0][j]=0;
        
    for(i=1;i<=n;i++)
        for(j=1;j<=W;j++)
        {
            c[i][j] = c[i-1][j];
            if(p[i]<=j)
            {
                if(c[i-1][j-p[i]]+ w[i] > c[i][j])  
                    c[i][j]= c[i-1][j-p[i]]+w[i];
                    
            }
        }                
}

void truyvet(){
    int i=n,j=W;
    if(c[n][W]>0)
    {
        while(i>0&& j>0)
        {
                if(c[i][j]==c[i-1][j-p[i]]+w[i])
                {
                    printf("\nChon vat thu %d: (%d, %d)",i,p[i],w[i]);
                    j-=p[i]; 
                } 
                i--;
        }
    } 
    printf("\nGia tri toi uu: %d", c[n][W]);
}

int main(){
    Doctep();
    In();
    BangPhuongAn();
    truyvet();   
    getch();
    return 0;
}

