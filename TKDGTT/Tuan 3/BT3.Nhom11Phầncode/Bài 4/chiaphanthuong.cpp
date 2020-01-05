#include <stdio.h>
#include <conio.h>

         
void nhap(int &m, int &n)
    {
    printf("BAI TOAN CHIA THUONG\n");
    printf("________________Nhap_____________\n||  m (phan thuong)\t");
    scanf("%d",&m);
    printf("||  n(sinh vien)\t");
    scanf("%d",&n);
    printf("||________________________________");
    }
int SCC(int m, int n)
   	{ 
     	 if (n==0) return 0;
        	else if (m==0||n==1) return 1;
                else if (m<n) return SCC(m,m);
                    else return SCC(m,n-1)+SCC(m-n,n);

    }
void xuat(int m, int n)
    {
    printf("\n\n____________________ket qua_________________________\n");
    printf("||%d phan thuong \n||%d sinh vien\n|| => %d cach chia\n",m,n,SCC(m,n));
    printf("||______________________________________________________");
    }
int main()
    {
    int m,n;
    char k;
    do 
    {
       nhap(m,n);
       xuat(m,n);
       printf("\n\n Nhan 0 neu muon thoat\n Nhan so bat ki neu muon tiep tuc\n");
       scanf("%d",&k);
    }
    while(k!=0);
    printf("Chao ban^-^");
    getch();
    }
