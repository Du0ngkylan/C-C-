/*
	Sinh cac hoan vi cua n phan tu bang thuat toan heap
*/

#include<stdio.h>
#include<conio.h>

void swap(int a[], int i, int j);
void hoanvi3(int a[], int n, int k, int *count);

void swap(int a[], int i, int j){
	int c;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}

void hoanvi3(int a[], int n, int k, int *count){
	int i;
	if(k == 0){
		printf("%d: ", ++(*count));
		for(i=0; i<n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	else{
		for(i = 0; i<k; i++){
			hoanvi3(a, n, k-1, count);
			swap(a, k%2?0:i , k-1);
		}
	}
}

int main(){
	int i, count, a[100];
	int n = 4;
	count = 0;
	
	for(i = 0; i<n; i++)
		a[i] = i;

	printf("sinh cac hoan vi cua %d phan tu:\n", n);
	hoanvi3(a, n, n, &count);
	
	
	getch();
	return 0;
}
