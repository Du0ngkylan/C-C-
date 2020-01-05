/*
	xep n do vat khac nhau vao m hop sao cho
	moi hop chua mot day co thu tu cac do vat
	==> coi so hop = n*m
	kq: m(m+1)... (m+n-1)
*/

#include<stdio.h>
#include<conio.h>

void xepDat3(int a[], int n, int m, int k, int *count, int d[]);
int kiemTra(int a[], int n, int m);
void inKetQua(int a[], int n, int m, int count);

// a[]: mang cac hop
// a[i] = k: vat k duoc xep vao hop i
void xepDat3(int a[], int n, int m, int k, int *count, int d[]){
	if(k > n){
		if(kiemTra(a, n, m)){
			inKetQua(a, n, m, *count);
			(*count)++;
			return;
		}
	}
	else{
		int i;
		for(i = 1; i<=m*n; i++)
			if(!d[i]){
				a[i] = k;
				d[i] = 1;
				xepDat3(a, n, m, k+1, count, d);
				d[i] = 0;
				a[i] = 0;
			}
	}
}

int kiemTra(int a[], int n, int m){
	int i,j;
	for(i=1; i<=m*n; i++)
		if(i%n == 1)
			for(j = i; j <=i+n-2; j++)
				if(a[j] == 0 && a[j+1] != 0)
					return 0;
	return 1;
}

/*
void inKetQua(int a[], int n, int m, int count){
	int i, j;
	printf("[%d]:", count+1);
	for(i = 1; i<=m*n; i++){
		printf("\thop %d: ", i);
		for(j=1; j<=n; j++)
			if(a[i] == j)
				printf("%d ", j);
			puts("");
		}
	puts("");
}
*/
void inKetQua(int a[], int n, int m, int count){
	int i,j;
	printf("[%d]", count+1);
	for(i=0; i<m; i++){
		printf("\thop %d: ", i+1);
		for(j = i*n+1; j<=(i+1)*n; j++)
			if(a[j] != 0)
				printf("%d ", a[j]);
		puts("");
	}
	puts("");
}

int main(){
	int a[100], d[100];
	int i, n, m, count = 0;
	
	puts("******* Bai toan xep dat 3 *********");
	printf("nhap so do vat: n = ");
	scanf("%d", &n);
	printf("nhap so hop: m = ");
	scanf("%d", &m);
	
	for(i = 1; i<=m*n; i++){
		d[i] = 0;
		a[i] = 0;
	}
	printf("\ncac cach xep %d do vat vao %d hop sao cho moi hop chua 1 day co thu tu cac vat la:\n\n", n, m);
	xepDat3(a, n, m, 1, &count, d);
	getch();
	return 0;
}
