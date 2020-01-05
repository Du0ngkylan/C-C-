/*de bai:
    Co N cuoc hop cung dang ki tai mot phong hop.
    Cuoc hop thu i bat dau vao thoi diem ai va ket thuc o thoi diem bi.
    Moi thoi diem phong chi phuc vu duoc mot cuoc hop.
    Hay bo tri de phong phuc vu duoc nhieu cuoc hop nhat?
thuat giai:
    Ta di sap xep cac cuoc hop theo thu tu tang dan ve thoi diem ket thuc.
    Neu cac cuoc hop co cung thoi diem ket thuc thi ta se sap xep tang dan theo thoi diem bat dau.
    E[i] la so cuoc hop co the to chuc nhieu nhat neu i la cuoc hop cuoi cung.
    so cuoc hop nhieu nhat co the to chuc chinh la gia tri lon nhat trong tat ca cac E[i].
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100],b[100],E[100],n;
void nhap()
{
    int i;
    printf("Hay nhap so cuoc hop ma ban can bo tri = ");
    scanf("%d",&n);
    printf("hay nhap thoi gian bat dau cuoc hop a[i] va thoi gian  ket thuc b[i]\n");
    for(i=1;i<=n;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
        printf("b[%d] = ",i);
        scanf("%d",&b[i]);
    }
}
void in()
{
     int i;
     //printf("+**************************+\n");
     printf("cuochop||batdau||ketthuc\n");
    // printf("+**************************+\n");
    printf ("\n");
     for(i=1;i<=n;i++)
    {
        printf("%d\t||%5d\t||%5d\n",i,a[i],b[i]);
    }
       // printf("+**************************+\n");
}
void swap(int *x,int *y)
{
     int t = *x;
     *x = *y;
     *y = t;
}
void sapxep()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(b[j] < b[i])
            {
            swap(&b[i],&b[j]);
            swap(&a[i],&a[j]);
            }
            else if(b[i] == b[j])
            {                                                              
                if(a[j]<a[i])
                {
                    swap(&a[i],&a[j]);
                    swap(&b[i],&b[j]);
                }
            }
        }
    }
}
int max(int i)
{
    int j,max = 0;
    for(j=1;j<=i;j++)
    {
        if(E[j] > max && b[j] <= a[i+1])
        max = E[j];
    }
    return max;
}    
void bangphuongan()
{
    int i;
    E[1] = 1;
    for(i=2;i<=n;i++)
    {
        E[i] = max(i-1)+ 1;
    }
}
void truyvet()
{
    int k=1;
    for(int i=2; i<=n; i++)
        if(E[i]>E[k])
            k=i;
            int maxi = E[k];
            int x[100];
            int t = maxi - 1;
        while(E[k] != 1 && t>=0)
        {
            x[t] = k;      
            t--;
            for(int i = k-1; i>0; i--)
            {
                if(E[i]+1 == E[k] && b[i]<=a[k])
                {
                    k = i;
                    break;         
                }       
            }
        }
    x[t] = k;
    printf("\nSO CUOC HOP MAX DUOC TO CHUC: %d\n", maxi);
    printf ("\n");
	//printf("+********************************+\n");
	printf("| cuochop || batdau ||  ketthuc |\n");
	//printf("+********************************+\n");
	for(int i=0; i<maxi; i++)
    {
		printf("|   %d\t||   %3d \t||   %3d |\n", i+1, a[x[i]], b[x[i]]);	 
	}
	//printf("+********************************+\n");
    printf("\nHay an phim enter neu ban muon thoat khoi chuong trinh"); 
}                       
     
     
     
int main()
{
    nhap();
    sapxep();
    in();
    bangphuongan();
    truyvet();
    getch();
    return 0;
}
     
     
