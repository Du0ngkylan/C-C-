#include <stdio.h>
#include <conio.h>
 
void nhap_day (int a[100], int n){
	int i;
	for(i=0; i<n; i++){
		printf("a[%d]=",i);
		scanf("%d",(a+i));
	}
}
void in_day(int a[100],int n){
	int i;
	for(i=0; i<n; i++)
	printf("%d\t",*(a+i));
	printf("\n");
	}
int main()
{
   int a[100], n;
    int l[100]; 
    int t[100];
    printf("Nhap so phan tu cua day:"); scanf("%d",&n); 
    nhap_day(a,n);
    l[0]=1; t[0]=-1; 
    for (int i=1; i<n; i++)
    {
        int max = 0; 
        for (int j=0; j<i; j++)
            if (a[j] < a[i] && max < l[j] + 1)
            {
                max = l[j] + 1;
                t[i] = j; 
            }
        l[i] = max;
    }
 
    //tim vi tri cuoi cua day
    int lMax = 0; //do dai cua day tang dai nhat
    int viTriMax = 0; 
    for (int i=1; i<n; i++)
        if (l[i] > lMax)
        {
            lMax = l[i];
            viTriMax = i;
        }
 
    //truy vet
    int kq[100]; 
    int k = lMax-1;
    do {
        kq[k] = a[viTriMax];
        k--;
        viTriMax = t[viTriMax];
    }while (k>=0); 
 
    //Xu ly ket qua
    printf("\n- Day A: "); //
    for (int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n- Day con don dieu tang dai nhat: "); 
    for (int i=0; i<lMax; i++) printf("%d ", kq[i]);
    printf("\n  (gom %d phan tu)", lMax);
    getch(); 
}
