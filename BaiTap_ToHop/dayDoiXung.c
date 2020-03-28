/* Yeu cau nhap mot day co do dai n
 * va kiem tra xem day do co phai la doi xung hay khong
 */

#include<stdio.h>
#include<stdlib.h>

int n; // So phan tu cua day
int a[100];

//Nhap so phan tu va cac phan tu tu ban phim
void nhap() {
	printf("Nhap so phan tu n = ");
	scanf("%d", &n);
	printf("Nhap cac phan tu trong day \n");
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

//In day
void inDay() {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%3d", a[i]);
	}
}

//Doi gia tri cua a va b cho nhau
void swap(int * a, int * b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

//Kiem tra xem day co doi xung, neu co thi sap xep lai thanh day doi xung
void kiemTra() {

	if (n % 2 == 0) { //Truong hop so phan tu cua mang la so le
		//Sap cac phan tu theo tung cap doi xung nhau hai ben thoa man: a[i]=a[n-1-i]
		for (int i = 0; i < n / 2; i++) {
			if (a[i] != a[n - 1 - i]) {
				int j = i + 1;
				while ((j <= n - 2 - i) && (a[j] != a[i])) {
					j++;
				}
				if (j == n - 1 - i) {
					printf("\nDay da cho khong doi xung");
					return;
				} else {
					swap(&a[j], &a[n - 1 - i]);
				}
			}
		}
	} else { //Truong hop so phan tu cua mang la so chan
		//Sap phan tu o giua
		int soLanLap = 0;
		int i = 0;
		//Tim phan tu dau tien co so lan lap le
		while ((soLanLap % 2 == 0) && (i < n)){
			soLanLap = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] == a[i]) {
					soLanLap++;
				}
			}
			i++;
		}
		//Cho phan tu co so lan lap le (neu co) vao giua day
		if (soLanLap %2 == 1) {
			swap(&a[i-1], &a[n / 2]);
		}

		//Sap cac phan tu theo tung cap doi xung nhau hai ben thoa man: a[i]=a[n-1-i]
		for (int i = 0; i < n / 2; i++) {
			if (a[i] != a[n - 1 - i]) {
				int j = i + 1;
				while ((j <= n - 2 - i) && (a[j] != a[i])) {
					j++;
					if (j == (n/2)) {
						j++;
					}
				}
				if (j == n - 1 - i) {
					printf("\nDay da cho khong doi xung");
					return;
				} else {
					swap(&a[j], &a[n - 1 - i]);
				}
			}
		}

	}

	printf("\nDay sau khi sap xep doi xung la:");
	inDay();
}

int main() {

	nhap();
	printf("Day vua nhap la: ");
	inDay();
	kiemTra();

	return 0;
}
