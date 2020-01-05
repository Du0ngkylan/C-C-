#include<stdio.h>
#include<conio.h>

void nhap_mang(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("Nhap a[%d] =  ",i+1);
		scanf("%d", &a[i]);
		}
	}
	
void in_mang(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%4d", a[i]);
	printf("\n");
	}
	
int max_day(int x, int y){
	if(x>y) return x;
	return y;
	}
	
int min_day(int x, int y){
	if(x<y)  return x;
	return y;
	}

void max_min(int a[], int l, int r,int &max, int &min){
	int max1,max2,min1,min2;
	if(r-l<=1){
         max = max_day(a[l],a[r]);
         min = min_day(a[l],a[r]);      
	}
	else{
	    max_min(a,l,(l+r)/2,max1,min1);
		max_min(a,(l+r)/2,r,max2,min2);
		max = max_day(max1,max2);
		min = min_day(min1,min2);
	}
}

int main(){
	int a[50];
	int n,max,min;
	printf("Nhap vao do dai day :  ");
	scanf("%d",&n);
	nhap_mang(a,n);
	printf("Day so vua nhap la : \n");
	in_mang(a,n);
	max_min(a,0,n-1,max,min);
	printf("Phan tu lon nhat va nho nhat la %d va %d.\n",max,min);
	getch();
	return 0;
	}
