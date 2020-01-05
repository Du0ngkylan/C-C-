#include<stdio.h>
#include<conio.h>

void bubbleSort( int a[], int n){
	int i,j,temp;
	for(i=2;i<n;i++)
		for(j=n;j>=i;j--)
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				}
	for(i=1;i<=n;i++)
		printf("%4d",a[i]);
	}
	
int main(){
	int a[100],n,i;
	printf("Nhap do dai day so:    ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Nhap a[%d] =   ",i);
		scanf("%d",&a[i]);
		}
	printf("Day sap xep tang dan : \n");
	bubbleSort(a,n);
	getch();
	return 0;
	}
