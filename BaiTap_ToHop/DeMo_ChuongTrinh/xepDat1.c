/*
	liet ke so cach xep n do vat khac nhau vao m hop
	(1 hop khong gioi han so luong vat)
	kq = m^n
*/

#include<stdio.h>
#include<conio.h>

void xepDat1(int a[], int n, int m, int k, int *count);
void inKetQua(int a[], int n, int m, int count);

// a[k] = i: vat k duoc xep vao hop i
void xepDat1(int a[], int n, int m, int k, int *count){
	if(k == n){
		inKetQua(a, n, m, *count);
		(*count)++;
		return;
	}
	else{
		int i;
		for(i = 0; i<m; i++){
			a[k] = i;
			xepDat1(a, n, m, k+1, count);
		}
	}
}

void inKetQua(int a[], int n, int m, int count){
	int i, j;
	printf("[%d]:", count+1);
	for(i = 0; i<m; i++){
		printf("\thop %d: ", i+1);
		for(j=0; j<n; j++)
			if(a[j] == i)
				printf("%d ", j+1);
			puts("");
		}
	puts("");
}

int main(){
	int a[100];
	int n, m, count = 0;
	
	puts("******* Bai toan xep dat 1 ***********");	
	printf("nhap so do vat: n = ");
	scanf("%d", &n);
	printf("nhap so hop: m = ");
	scanf("%d", &m);
	
	printf("cac cach xep %d do vat vao %d hop la:\n\n", n, m);
	xepDat1(a, n, m, 0, &count);
	
	getch();
	return 0;
}
