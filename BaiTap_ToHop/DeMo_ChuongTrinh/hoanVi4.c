/*
	thuat toan Steinhauss - Johnson - Trotter
	sinh hoan vi cua n phan tu
*/

#include<stdio.h>
#include<conio.h>

void swap(int a[], int i, int j);
int find(int a[], int n, int d[]);
void hoanVi4(int a[], int n, int d[]);

void swap(int a[], int i, int j){
	int c;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}

// tim vi tri cua so nguyen di dong lon nhat
int find(int a[], int n, int d[]){
	int i, j = 0;
	int max = 0;;
	
	for(i = 1; i<=n; i++)
		if(((d[i] &&  a[i] > a[i-1]) || (!d[i] && a[i] > a[i+1])) && a[i] > max){
				max = a[i];
				j = i;
			}
	return j;
}

void hoanVi4(int a[], int n, int d[]){
	int i, k, count = 1;;
	
	// khoi tao
	for(i=1; i<=n; i++){
		a[i] = i;
		d[i] = 1;
	}
	a[0] = n+1;
	
	k = find(a, n, d);
	while(k <=n && k > 0){
		// in ket qua
		printf("%d: ", count++);
		for(i = 1; i<=n; i++)
			printf("%d ", a[i]);
		puts("");
		
		// hoan doi
		if(d[k]){
			swap(a, k, k-1);
			swap(d, k, k-1);
			k--;
		}
		else{
			swap(a, k, k+1);
			swap(d, k, k+1);
			k++;
		}
		
		// dao chieu di chuyen cua moi so nguyen > k
		for(i = 1; i<= n; i++)
			if(a[i] > a[k])
				d[i] = 1-d[i];

		k = find(a, n, d);
	}
	// hoan vi cuoi cung
	printf("%d: ", count++);
	for(i = 1; i<=n; i++)
			printf("%d ", a[i]);
		puts("");
}

int main(){
	int a[100], d[100];
	int n = 5;
	
	printf("sinh cac hoan vi cua %d phan tu: \n\n", n);
	hoanVi4(a, n, d);
	
	getch();
	return 0;
}
