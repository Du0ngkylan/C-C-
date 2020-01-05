#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define INPUT "BALO.INP"
#define OUTPUT "BALO.OUT"

typedef struct dovat
{
	int weight;
	int cost;
	int sl;
}dovat;

int n, m;
dovat *a;
int tt,	// Tong gia tri
	t;	// Khoi luong con lai

void init(int n)
{
	int i;
	a = (dovat *)malloc((n+1)*sizeof(dovat));
	for (i = 1; i <= n; i++)
		a[i].sl = 0;
}

void readFile()
{
	FILE *f;
	int i;
	f = fopen(INPUT, "r");
	if (!f)
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d %d", &n, &m);
	init(n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d %d", &a[i].weight, &a[i].cost);
	fclose(f);
}

void sort(int left, int right)
{
	int i, j;
	float x = ((float)a[left].cost/a[left].weight + 
			(float)a[right].cost/a[right].weight)/2;
	dovat temp;
	i = left;		j = right;
	do {
		while ((float)a[i].cost/a[i].weight > x)
			i++;
		while ((float)a[j].cost/a[j].weight < x)
			j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i < j);
	if (i < right)
		sort(i, right);
	if (left < j)
		sort(left, j);
}

void xepbalo()
{
	int i = 1;
	tt = 0;		t = m;
	while (i <= n && t > 0)
	{
		if (a[i].weight <= t)
		{
			a[i].sl++;
			tt = tt + a[i].cost;
			t = t - a[i].weight;
		}
		else
			i++;
	}
}

void writeFile()
{
	FILE *f;
	int i;
	f = fopen(OUTPUT, "w");
	if (!f)
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	for (i = 1; i <= n; i++)
		if (a[i].sl != 0)
			fprintf(f, "%d %d %d\n", a[i].weight, a[i].cost, a[i].sl);
	fprintf(f, "%d", tt);
	fclose(f);
}

void main()
{
	readFile();
	sort(1, n);
	xepbalo();
	writeFile();
	printf("\nComplete!");
	getch();
}