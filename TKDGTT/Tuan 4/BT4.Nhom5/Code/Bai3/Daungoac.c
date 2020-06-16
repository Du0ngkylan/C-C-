/* Voi hai so n, k cho truoc, Hay liet ke tat ca day dau ngoac hop le 
do dai n va do sau k */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char *a;
int n, k, co = 0;

void printResult()
{
	int i;
	FILE *f;
	f = fopen("output.out","a");
	for (i = 1; i <= n; i++)
		fprintf(f,"%c", a[i]);
	fprintf(f,"%c", '\n');
	fclose(f);
	co = 1;
}

int dem(int t)		// dem ki tu '('
{
	int i, d = 0;
	for (i = 1; i <= t; i++)
		if (a[i] == '(')
			d++;
	return d;
}

int kt1(int t)
{
	int dem1 = 0, dem2;
	dem1 = dem(t);
	dem2 = t-dem1;
	if (dem1 >= dem2 && (dem1 - dem2) <= (n-t))
		return 1;
	else
		return 0;
}

/* Tinh do sau hien tai cua day */
int kt2(int t)
{
	int i = 2, tong = 0, sau = 1, dem1, dem2;
	while (1)
	{
		if (i > t)
			break;
		dem1 = dem(i-1);	dem2 = i-1-dem1;
		if (a[i] == '(' && a[i-1] != ')' && dem1 > dem2)
			sau++;
		if (dem1 == dem2 || i == t)
		{
			tong = (tong > sau) ? tong : sau;
			if (a[i] == '(')
				sau = 1;
			else
				sau = 0;
		}
		i++;
	}
	if (tong > sau)
		sau = tong;
	return sau;
}

void braces(int t)
{
	char i;
	for (i = '('; i <= ')'; i++)
	{
		if (t > n)
			return;
		a[t] = i;
		if (kt1(t))
			if (kt2(t) + (n-2*dem(t))/2 >= k)
			{
				if (t == n && kt2(t) == k)
					printResult();
				else
					braces(t+1);
			}
	}
}

int main()
{
	FILE *f;
	if (!(f = fopen("input.inp","r")))
	{
		printf("\nFile not found");
		getch();
		exit(0);
	}
	fscanf(f,"%d %d", &n, &k);
	fclose(f);
	if (n%2 == 1)
		printf("\nGia tri n phai chan");
	else
	{
		a = (char *)malloc((n+1)*sizeof(char));
		remove("output.out");
		braces(1);
		printf("\nDone");
		if (co == 0)
		{
			f = fopen("output.out","w");
			fprintf(f,"%s", "Not have result");
			fclose(f);
		}
	}
	getch();
}