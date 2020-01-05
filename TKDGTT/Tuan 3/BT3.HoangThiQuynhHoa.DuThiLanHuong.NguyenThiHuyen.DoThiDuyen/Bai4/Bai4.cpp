/*
bai toan chia thuong: Co m phan thuong chia cho n hoc sinh gioi co xep hang theo
thu tu tu 1 toi n.Hoi co bao nhieu cach chia phan tuong thoa man:
    1)hoc sinh gioi hon co so thuong it hon hoc sinh kem hon
    2)m vat thuong phai chia het cho cac hoc sinh
*/
#include"stdio.h"
#include"conio.h" 
//chia m phan thuong cho n hoc sinh
int chia(int m,int n)
{
    //int
    //neu khong co phan thuong nao thi co 1 cach chia(tat ca deu khong co thuong)
    if(m==0)
            return 1;
    //neu khong co hoc sinh nao thi khong co cach chia
    if(n==0)
            return 0;
    else
    {
        //neu so phan thuong it hon so hoc sinh
        if(m<n)    return chia(m,m);
        //so phan thuong lon hon hoac bang so hoc sinh
        else       return (chia(m-n,n)+chia(m,n-1));
            
    }
    
}
int main()
{
    int m,n;
    printf("nhap so hoc sinh n=");
    scanf("%d",&n);
    printf("nhap so phan thuong m=");
    scanf("%d",&m);
    printf("so cach chia phan thuong la:%d",chia(m,n));
    getch();
    return 0;
}
