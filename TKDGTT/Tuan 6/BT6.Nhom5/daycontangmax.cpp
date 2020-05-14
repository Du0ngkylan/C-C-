#include<stdio.h>
#include<conio.h>

void nhap(int a[], int n){
	int i;
	for(i=1; i<=n; i++){
		printf("Nhap a[%d]=  ",i);
		scanf("%d",&a[i]);
		}
	}
	
void in(int a[], int n){
	int i;
	for( i=1; i<=n; i++)
		printf("%d\t",a[i]);
	printf("\n");
	}
	
void khoi_tao(int a[], int n){
	int i;
	for ( i=1; i<=n; i++)
		a[i] = 1;
	}
	
int max( int a[], int n){
	int i,max;
	max = a[1];
	for ( i=1; i<=n; i++){
		if ( a[i] > max) max = a[i];
		}
	return max;
	}
	
void tim_kiem( int a[], int n ){
	int b[50];
	int max1,max2;
	int i,j;
	khoi_tao(b,n);
	for ( i=1; i<=n; i++){
		if(a[i+1] > a[i] ){
			b[i+1] = max(b,i) + 1;
		}
		if( a[i+1] < a[i]){
		    for ( j=1; j<i; j++){
				if (a[j] < a[i+1]){
					if ( (b[j] + 1) > b[i+1] ) {
					b[i+1] = b[j] + 1;
					}
				}
				}
		}
	}
	in(b,n);
    max1 = max(b,n);
    j = 1;
    while( j<max1 ){
    for(i=1; i<=n; i++){
		if ( b[i] == j ){
			printf("%4d",a[i]);
			j++;
			}
		}
	}
}

int main(){
	int a[50];
	int n;
	printf("Nhap vao do dai day so:   ");
	scanf("%d",&n);
	nhap(a,n);
	printf("Day so da nhap la: \n");
	in(a,n);
	printf("Day con tang dai nhat:\n");
	tim_kiem(a,n);
	getch();
	return 0;
	}
