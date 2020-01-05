/*
	liet ke so cach xep n do vat khac nhau vao m hop
	va khong hop nao chua nhieu hon 1 vat(1 hop chua 1 vat)
	m > n: kq = m!/(m-n)!
*/

#include<stdio.h>
#include<conio.h>

void xepDat2(int a[], int n, int m, int k, int *count, int d[]);
void inKetQua(int a[], int n, int m, int count);

// a[]: mang cac vat, d[]: mang danh dau cac hop da dung
// a[k] = i: vat k duoc xep vao hop i
void xepDat2(int a[], int n, int m, int k, int *count, int d[]){
	if(k == n){
		inKetQua(a, n, m, *count);
		(*count)++;
		return;
	}
	else{
		int i;
		for(i = 0; i<m; i++)
			if(!d[i]){
				a[k] = i;
				d[i] = 1;
				xepDat2(a, n, m, k+1, count, d);
				d[i] = 0;
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
	int a[100], d[100];
	int i, n, m, count = 0;
	
	puts("******* Bai toan xep dat 2 *********");
	printf("nhap so do vat: n = ");
	scanf("%d", &n);
	printf("nhap so hop lon hon so do vat: m = ");
	scanf("%d", &m);
	
	for(i = 0; i<m; i++)
		d[i] = 0;
		
	printf("cac cach xep %d do vat vao %d hop sao cho moi hop chi chua 1 vat la:\n\n", n, m);
	xepDat2(a, n, m, 0, &count, d);
	getch();
	return 0;
}
