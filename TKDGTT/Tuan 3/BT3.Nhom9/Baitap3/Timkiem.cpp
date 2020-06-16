#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

int a[MAX],n;
int x;

void Nhap(){
	printf("\nNhap vao so phan tu cua mang: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\na[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
//VD: 1 2 3 4 5 6
void Search(int a[],int l,int r,int x){
	
	int mid = (l+ r)/2;
	
	if(l<=r){
		
		if(a[mid] == x){
			printf("\nPhan tu %d xuat hien o vi tri: %d",x,mid);
			getch();
			exit(0);
		}
			
		if(x < a[mid]){
			r = mid - 1;
			Search(a,l,mid-1,x);
		}	
		else{
			l = mid + 1;	
			Search(a,mid+1,r,x);
		}
	}
}

void KetQua(int a[],int n,int l,int r){
	printf("\nNhap vao so can tim: ");
	scanf("%d",&x);
	Search(a,0,n-1,x);
	printf("\n%d khong xuat hien trong day!",x);
}

int main(){
	
	Nhap();
	KetQua(a,n,0,n-1);
	
    getch();
    return 0;
}
