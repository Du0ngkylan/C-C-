/* Thuat toan tham lam: Bai toan balo
Cho 1 balo co the dung dc trong luong toi da W,co n loai do vat, vat thu i co trong luong g_i va
gia tri v_i. Tim 1 cach lua chon cac do vat dung vao balo sao cho tong trong luong khong vuot qua W
va tong gia tri la max
*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

int n;//so loai do vat
int W;// trong luong cho phep cho vao Balo
typedef struct dovat
{
        int ten;//ten do vat duoc danh so 1 2 3 ...
        int g;//trong luong
        int v;//gia tri
        float dongia;//ti so v/g
        int soChon;// so luong do vat nay dc chon
}dovat;
dovat *nhap()
{
     dovat *a;
     int i;
     FILE *f;
     char s[200];
     f=fopen("balo_input.dat","r");
     if(!f)
     {
           printf("Loi mo tep!");     getch();   exit(0);
     }
     fscanf(f,"%d%d",&n,&W);
     fgets(s,200,f);
     a=(dovat *)malloc(n* sizeof(dovat));
     for(i=1;i<=n;i++)
     {
            a[i].ten=i;
            fscanf(f,"%d%d",&a[i].g,&a[i].v);
            a[i].dongia=(float)a[i].v/a[i].g;
            fgets(s,200,f);
     }
     fclose(f);
     return a;
}

void in(dovat *a,int n)
{
     int i;
     for(i=1;i<=n;i++)
     {
           if(a[i].soChon!=0)
           {
                  printf("Do vat %d\t Trong luong:%d\t Gia tri: %d\t So luong chon:%d\n",a[i].ten,a[i].g,a[i].v,a[i].soChon);
           }
     }
}
void swap(dovat *a,dovat *b)
{
     dovat temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
//sap xep cac do vat theo thu tu don gia giam dan
void quicksort(dovat *a,int l, int r)
{
     int i,j,m;
	m=(l+r)/2;
	i=l;
	j=r;
	while(i<j)
	{
		while(a[i].dongia>a[m].dongia)
			i++;
		while(a[j].dongia<a[m].dongia)
			j--;
		if(i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
	
		if(l<j)
			quicksort(a,l,j);
		if(i<r)
			quicksort(a,i,r);
   }
}
 void Greedy(dovat *a)
{
      int i;
      for(i=1;i<=n;i++)
           a[i].soChon=0;
      i=1;
      while (i<=n&& W>0)
      {
            a[i].soChon=W/a[i].g;
            W-=a[i].soChon* a[i].g;
            i++;
      }

}
int main()
{
    dovat *a;//tap cac do vat
    a=nhap();
    quicksort(a,1,n);
    Greedy(a);
    printf("\n...............Phuong an lua chon do vat vao Balo:.............\n");
    in(a,n);
    getch();
    return 0;
}
