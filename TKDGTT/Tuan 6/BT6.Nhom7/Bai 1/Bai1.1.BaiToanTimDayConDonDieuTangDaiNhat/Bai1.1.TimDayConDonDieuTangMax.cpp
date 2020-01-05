/*Bai 1.1: Tim day con don dieu tang dai nhat

- Bai toan: Tim day con dai nhat cua 1 day da cho. 
			Cac phan tu co the khong lien tiep.
- Phan tich:
	+ Input: (a,n)
	+ Output: m lon nhat cac phan tu cua day theo thu tu tang dan
	+ Ham toi uu l(i): la do dai DC行TDN den phan tu i
		La do dai cac day con dai nhat den j cong 1 khi ghep them a(i) vao sau
		voi dieu kien j<i, a(j)<a(i).
	+ Cong thuc truy hoi:
		l(i) = max{l(i)}+1 voi j<i, a(j)<a(i)
	+ Co so quy hoach dong: 
		l(0)=0, l(1)=1
	+ Truy vet tim nghiem;
		. Bat dau tu vi tri toi uu. l(i) dat max
		. Tai moi buoc: xet o l(i), phan tu dung trc a(i) trong day con la a(j)
			neu j<i, a(j)<a(i) va l(j)=l(i)-1
		. Ket thuc khi den phan tu dau tien cua day con (l(i)=1)
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define hs 50

int n; //n-so phan tu cua day
int a[hs];
int l[hs]; //do dai DC行TDN den phan tu i
int tr[hs];//vi tri phan tu ngay trc a[i] trong DC行TDN cua day a[1],...,a[i]
int kq[hs];//luu ket qua DC行TDN

int max = 1; //do dai DC行TDN cua day a[1],...,a[i]
int viTriMax = 0; //a[viTriMax] se la phan tu cuoi cung trong DC行TDN cua day a[1],...,a[i]

/*Nhap day ban dau*/
void nhapDay(){
	int i;
	FILE *f;
	f = fopen("input.txt", "r");
	if(!f){
		printf("\nLoi mo tep!");
		getch();
		exit(1);	
	}	
	fscanf(f, "%d ", &n);
	printf("\n  - So phan tu cua day ban dau: n = %d", n);
	printf("\n\n  - Day ban dau la: ");
	for(i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
}

/*In day*/
void inDay(int a[], int n){
	int i;
	for(i=1; i <= n; i++)
		printf("%d  ", a[i]);	
}

/*lap bang phuong an*/
void lapBangPhuongAn(){
	int i, j, max;
	
	l[1]=1;//co so quy hoach dong: cho phan a[1] cua day a[1],...,a[i] vao DC行TDN

	for(i=2; i<=n; i++)//i chay tu 2 do phan tu dau tien da thuoc DC行TDN
	{
		max =1;//do dai DC行TDN cua day a[1],...,a[i]
		for(j=1; j<i; j++)
		{
			if(a[j] < a[i] && max < l[j]+1)
			{
				max = l[j] +1;
				tr[i] = j; //truy vet: phan tu ngay phia sau a[i] la a[j]	
			}		
		}	
		l[i] = max;
	}
	printf("\n  - Bang phuong an:\n");
	printf("     i: a[i] l[i]\n");
	for(int i=1; i<=n; i++)
        printf("     %d:  %d    %d\n", i, a[i], l[i]);
}

/*Truy vet tim DC行TDN*/
void truyVet(){ 
    int i;
    /*Tim vi tri cuoi cung cua DC行TDN*/
    for(i=1; i < n; i++)
        if(l[i] > max)
        {
            max = l[i];
            viTriMax = i;
        }		
    for(i=max; i>=1; i--){
        kq[i] = a[viTriMax];
        viTriMax = tr[viTriMax];
    }   
    printf("\n\n=> Day con don dieu tang dai nhat co do dai la: %d", max);
	printf("\n\nDay con don dieu tang dai nhat la: ");	
	inDay(kq,max);	
}

/*Chuong trinh chinh*/
main(){
	nhapDay();
	inDay(a,n);
	lapBangPhuongAn();
	truyVet();
	getch();	
}
