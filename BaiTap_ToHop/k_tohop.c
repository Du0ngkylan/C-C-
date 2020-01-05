/*
	sinh tap con gom k phan tu cua tap gom n phan tu, tam giac pascal
*/

#include<stdio.h>
#include<conio.h>

void tamGiac(int a[][100], int n);
void lietke(int a[], int n, int k);

void tamGiac(int a[][100], int n){
	int i, j, k;

	for(i = 0; i<=n; i++)
		for(j = 0; j<=n; j++)
			a[i][j] = 0;
			
	for(i = 0; i<=n; i++)
		a[i][0] = 1;

	for(i = 1; i<=n; i++)
		for(j = 1; j<=n; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j];

	for(i = 0; i<=n; i++){
		for(j = 0; j<=n; j++)
			if(a[i][j])
				printf("%d\t", a[i][j]);
		puts("");
	}
}

void lietke(int a[], int n, int k){
	int i, j, count;
	count = 1;
	for(i = 1; i<=k; i++)
		a[i] = i;
	while(a[k]<=n){
		printf("%d: ", count++);
		for(i = 1; i<=k; i++)
			printf("%d ", a[i]);
		puts("");
		
		i = k;
		while(a[i] == n-k+i && i>0)
			i--;
		if(i == 0)
			break;
		a[i] = a[i] + 1;
		for(j = i+1; j<=k; j++)
			a[j] = a[j-1] + 1;
	}
}

int main(){
	int n, k, b[100][100], a[100];
	do{
		puts("nhap gia tri n > k");
		printf("n = ");
		scanf("%d", &n);
		printf("k = ");
		scanf("%d", &k);
	}
	while(k>n);
//	printf("so tap con chua %d phan tu cua tap gom %d phan tu:\n", k, n);
//	lietke(a, n, k);

	puts("\ntam giac pascal:");
	tamGiac(b, n);
/*	
	puts("\nkhai trien:");
	printf("(x + y)^%d = ", n);
	for(i = 0; i<n; i++)
		printf("%d.x^%d.y^%d + ", b[n][i], i, n-i);
	printf("%d.x^%d.y^%d + ", b[n][n], i, 0);
*/

	puts("nhap gia tri n > k");
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("to hop chap %d cua %d = %d", k, n, b[n][k]);

	getch();
	return 0;
}
