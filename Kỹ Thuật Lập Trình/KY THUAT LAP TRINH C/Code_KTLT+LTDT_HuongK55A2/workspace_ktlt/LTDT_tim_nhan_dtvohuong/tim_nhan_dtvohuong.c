/*
 * bai tap:
 *
 * Tim nhan do thi vo huong
 *
 * NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

#define hs 100

int a[hs][hs];
int q[hs];
int n, m, c;

void doctep()
{
	int i, j, k;
	FILE *f;
	f = fopen("dulieu.txt", "r");
	if (!f)
	{
		printf("Loi mo tep");
		exit(0);
	}
	fscanf(f, "%d%d", &n, &m);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			a[i][j] = 0;
	for (k=0; k<m; k++)
	{
		fscanf(f, "%d%d", &i, &j);
		a[i][j] = 1;
	}
	fclose(f);
}

int ke(int i, int j)
{
	return a[i][j] + a[j][i] > 0;
}

void nhan()
{
	int i, k, kt, tiep;
	c = 1;
	q[1] = 3;
	tiep = 1;
	while (tiep)
	{
		tiep = 0;
		for (i=1; i<=n; i++)
		{
			kt = 1;
			for (k=1; k<=c; k++)
			{
				if (q[k] == i || ke(q[k], i))
				{
					kt = 0;
					break;
				}
			}
			if (kt)
			{
				c++;
				q[c] = i;
				tiep = 1;
			}
		}
	}
	printf("\nMot nhan cua do thi la:\n");
	for (i=1; i<=c; i++)
		printf("%d ", q[i]);
	puts (" ");
}

int main()
{
	setbuf(stdout, NULL);
	doctep();
	nhan();
	return 0;
}
