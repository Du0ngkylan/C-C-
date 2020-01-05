/*Bai toan day ABC*/

#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

int n,BestC;
int a[100],temp[100];
//BestC: So ki tu C it nhat cua bai toan
//a[] mang chua day ket qua
//temp[] mang luu cac thanh phan hien tai cua xau

void InXau(int *a, int n)
{
    for(int i = 0; i < n; i++)
       printf("%c", a[i]);
    puts("");
}

int Check(int k)
{
    int t = 0;
    for(int i = 1; i <= k/2; i++)
    {
        for(int j = 1; j <= i; j++)
            if(temp[k-j] != temp[k-j-i])
            {
                t++;
                break;
            }
    }
    if(t == k/2)
        return 1; //khong co 2 day con ke nhau giong nhau
    return 0; //co 2 day con ke nhau giong nhau
}

 void Try(int i, int S) //sinh thanh phan thu i voi so ki tu 'C'  hien co la S
{ 
    int k, j, c1; 
    for(k = 'A'; k <= 'C'; k++) 
    { 
        temp[i-1] = k; 
        if(Check(i)) //kiem tra xem co 2 day con lien ke giong nhau khong
        { 
            c1 = (k == 'C') ? S+1 : S; 
			if((c1 + (n-i)/4) < BestC) 
            { 
                if(i == n) 
                { 
                    BestC = c1; 
                    for(j = 0; j < n; j++) 
                        a[j] = temp[j]; 
                } 
                else 
                    Try(i+1, c1);  
               } 
          } 
    }
}
     
int main()
{
    printf("\nBAI TOAN XAU ABC:\n\n");
    do
    {
        printf("Nhap n = ");
        scanf("%d", &n);
    }while(n <= 0 || n > 100);
    BestC = n;//so ki tu C it nhat trong thoi diem hien tai
    Try(1,0);
    printf("\nXau thoa man yeu cau bai toan la: ");
    InXau(a, n);
    printf("\n==> So ki tu C it nhat co the la %d", BestC);
    getch();
}
