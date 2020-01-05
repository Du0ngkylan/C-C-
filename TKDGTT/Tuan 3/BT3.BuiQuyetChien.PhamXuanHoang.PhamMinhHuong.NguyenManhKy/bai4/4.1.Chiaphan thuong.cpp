#include <stdio.h>
#include <conio.h>
void nhap(int &m, int &n)
    {
    printf("BAI TOAN CHIA THUONG\n");
    printf("Nhap m (phan thuong), n (sinh vien): ");
    scanf("%d%d",&m,&n);
    }
int part(int m, int n)
    {
    if (m==0) return 1;
        else if (n==0) return 0;
            else if (m==1||n==1) return 1;
                else if (m<n) return part(m,m);
                    else return part(m,n-1)+part(m-n,n);
    }
void xuat(int m, int n)
    {
    printf("  co %d cach chia",part(m,n));
    }
main()
    {
   
    int m,n;
    nhap(m,n);
    xuat(m,n);
    getch();
    }
