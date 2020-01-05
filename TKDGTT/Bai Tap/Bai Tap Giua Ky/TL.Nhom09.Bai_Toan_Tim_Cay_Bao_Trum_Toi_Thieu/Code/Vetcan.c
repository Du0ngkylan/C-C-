#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define INPUT	"CBTNN.INP"
#define	OUTPUT	"CBTNN.OUT"

int n,		// So dinh cua do thi
	m,		// So cung cua do thi
	max,	// Chi phi hien tai
	*dau, *cuoi,	// danh sach cung
	*w,		// trong so
	*v,		// Luu cac cung cua cay bao trum khi duyet
	*best,	// Luu cay bao trum nho nhat
	*dc;	// Danh dau cung da duyet

void readFile();	// doc file
void writeFile();	// ghi ket qua
void init(int );	// khoi tao cho bien
void Try(int );		// tim cay bao trum
int cost();			// tim chi phi cua mot cay bao trum bat ki
int checkBT();		// kiem tra tinh chat cay bao trum

int main()
{
	readFile();
	max = 10000;
	Try(1);
	writeFile();
	printf("\nComplete!\n");
	getch();
	return 0;
}

void readFile()
{
	FILE *f;
	int i;
	if (!(f = fopen(INPUT, "r")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d %d", &n, &m);
	init(n);
	for (i = 1; i <= m; i++)
	{
		fscanf(f, "%d %d %d", &dau[i], &cuoi[i], &w[i]);
		printf("\n%2d. %d %d %d", i,  dau[i], cuoi[i], w[i]);
	}
	fclose(f);
}


void init(int n)
{
	int i;
	dau = (int *)malloc((n+1)*sizeof(int));
	cuoi = (int *)malloc((n+1)*sizeof(int));
	w = (int *)malloc((m+1)*sizeof(int));
	dc = (int *)malloc((m+1)*sizeof(int));
	for (i = 1; i <= m; i++)
		dc[i] = 0;

	// Khai bao mang chua cung cua cay bao trum
	v = (int *)malloc(n*sizeof(int));
	best = (int *)malloc(n*sizeof(int));
}


void Try(int k)
{
	int i, value, j;
	if (k >= n)
		return;
	for (i = 1; i <= m; i++)
		if (dc[i] == 0)
		{
			v[k] = i;
			if (k == n-1)
			{
				if (checkBT() == 1)
				{
					value = cost();
					if (value < max)
					{
						for (j = 1; j < n; j++)
							best[j] = v[j];
						max = value;
					}
				}
			}
			else
			{
				dc[i] = 1;
				Try(k+1);
				dc[i] = 0;
			}
		}
}


int cost()
{
	int i, value = 0;
	for (i = 1; i < n; i++)
		value += w[v[i]];
	return value;
}


void writeFile()
{
	int i;
	FILE *f;
	if (!(f = fopen(OUTPUT, "w")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fprintf(f, "Cac cung cua cay bao trum:\n");
	for (i = 1; i < n; i++)
		fprintf(f, "%d %d\n", dau[best[i]], cuoi[best[i]]);
	fprintf(f, "Chi phi: %d", max);
	fclose(f);
}

int checkBT()
{
	int *dd, i;
	dd = (int *)malloc((n+1)*sizeof(int));
	for (i = 1; i <= n; i++)
		dd[i] = 0;
	for (i = 1; i < n; i++)
	{
		dd[dau[v[i]]] = 1;
		dd[cuoi[v[i]]] = 1;
	}
	for (i = 1; i <= n; i++)
		if (dd[i] == 0)
			return 0;
	return 1;
}