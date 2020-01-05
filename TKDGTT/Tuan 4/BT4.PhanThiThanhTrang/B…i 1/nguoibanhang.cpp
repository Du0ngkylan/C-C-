/*
Bai toan ve nguoi ban hang du lich
*/
#include<stdio.h>
#include<conio.h>
int a[100][100], n, danhdau[100];
// mang danh dau de kiem tra xem thanh pho do da di qua chua
int  doctep()
{
     FILE *f;
     f = fopen("input.txt","r");//du lieu dua vao duoi dang ma tran, gia tri cua cac phan tu la do dai duong di gia cac thanh pho.     
     fscanf(f,"%d",&n);// doc du lieu tu file, n thanh pho
     printf("%d\n",n);
     for (int i =0;i<n;i++){
         for (int j=0;j<n;j++){
             fscanf(f,"%d",&a[i][j]);   //a[i][j] do dai duong di tu thanh pho i den thanh pho j. 
             printf("%d\t",a[i][j]);
         }
         puts("");
     }
}
void Thamlam()
{
     int x[100], sum = 0, i,k ;
     for (int i=0;i<=n;i++)
     {
         x[i]=i;
         danhdau[i]=0;//khoi tao ban dau cac thanh pho deu chua duoc di den.
     }
     danhdau[0]=1;// xuat phat tu thanh pho dau tien
     x[0]=0;
     for ( i=1;i<n;i++)
     {
         int min = 10000, chiso = 0;
         for ( k=1;k<n;k++)    
             if (danhdau[k]==0 && a[x[i-1]][k]<min)// neu tp do chua di qua va khoang cach chap nhan duoc
             {
                min = a[x[i-1]][k]                  ;
                chiso = k;
             }
         x[i]= chiso;
         sum = sum+a[x[i-1]][chiso];// tong do dai duong di tu tp dau tien den thanh pho thu k.
         danhdau[chiso]=1;//danh dau thanh pho da di.
     }
     printf("\nDuong di ngan nhat qua cac thanh pho :");
     for (int i=0;i<n;i++)
         printf("%d-->",x[i]+1);
     printf("1");
}
int main()
{ 
    doctep();
    Thamlam();
    getch();
    return 0;    
}

