#include <stdio.h>
#include <conio.h>

         
void nhap(int &n)
    {
    printf("BAI TOAN CHIA TAM GIAC\n");
    printf("________________Nhap_____________\n||m (so dinh)\t");
    scanf("%d",&n);
    printf("||________________________________");
    }
int DC(int n)
   	{ 
     	 if (n<=3) return 0;
        	else if (n==4) return 1;
                else return DC(n-1)+1;
     }
void xuat(int n)
    {
    printf("\n\n____________________ket qua_________________________\n");
    printf("||tam giac co so dinh:%d \n|| => so duong cheo toi thieu: %d\n",n,DC(n));
    printf("||______________________________________________________");
    }
int main()
    {
    int n;
    char k;
    do 
    {
       nhap(n);
       xuat(n);
       printf("\n\n Nhan 0 neu muon thoat\n Nhan so bat ki neu muon tiep tuc\n");
       scanf("%d",&k);
    }
    while(k!=0);
    printf("An phim bat ki");
    getch();
    }
