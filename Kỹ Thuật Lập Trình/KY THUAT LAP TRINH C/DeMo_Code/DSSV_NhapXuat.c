
/*
 * Nhap vao 1 dssv bao gom; ho ten, diem toan, diem tin,
 * Tinh va them thong tin diem trung binh vao dssv
 * sx va in dssv theo thu tu diem trung binh giam dan
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char hoten[30];
	int toan, tin;
	float tb;
}sinhvien;

sinhvien *nhap_ds(int n)
{
	sinhvien *a;
	a = (sinhvien*)malloc(n*sizeof(sinhvien));
	int i;
	for (i=0; i<n; i++)
	{
		printf("\nNhap sinh vien thu %d", (i+1));
		printf("\nHo va ten sinh vien:");
		fflush(stdin);
		gets((a+i)->hoten);
		printf("\ndiem toan: ");
		scanf("%d", &(a+i)->toan);
		printf("\nDiem tin: ");
		scanf("%d", &(a+i)->tin);
		(a+i)->tb = ((a+i)->toan+(a+i)->tin)/2;
	}
	return a;
}

void in_ds(sinhvien *a, int n)
{
	int i;
	printf("\n--------------------DSSV---------------------------");
	printf("\n%30s %6s %6s %10s\n", "hovaten","toan","tin","tb");
	for (i=0; i<n; i++)
	{
		printf("%30s %6d %6d %10.1f", (a+i)->hoten, (a+i)->toan, (a+i)->tin, (a+i)->tb);
		printf("\n");
	}
}

void sapxep(sinhvien *a, int n)
{
	int i, j;
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++)
		{
			if ((a+i)->tb < (a+j)->tb)
			{
				sinhvien temp;
				temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}
}

int main()
{
	setbuf(stdout, NULL);
	int n;
	sinhvien *a;
	printf("\nNhap n= ");
	scanf("%d", &n);
	a = nhap_ds(n);
	in_ds(a, n);
	sapxep(a, n);
	printf("\nDanh sach sinh vien da sap xep la:\n");
	in_ds(a, n);
	return 0;
}
