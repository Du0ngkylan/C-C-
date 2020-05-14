//Bai toan lap lich su dung cuoc hop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//dinh nghia kieu cau truc cuoc hop
typedef struct cuochop
{
	int start;
	int end;
}cuochop;
cuochop *pr;
int len;


int n, *dd, *L, Lm=0;//mang dd danh giau cac tien trnh duoc chon
//khoi tao cho mang dd & so luong cac tien trinh
void khoitao()
{
	int i;
	dd=(int*)malloc((n+1)*sizeof(int));
	L=(int*)malloc((n+1)*sizeof(int));
	for(i=1; i<=n; i++)
		dd[i]=0;
	len=n;
}
//doi cho 2 tien trinh
void swap(int i, int j)
{
	cuochop temp;
	temp = pr[i];
	pr[i] = pr[j];
	pr[j] = temp;
}
//thu tuc upheap
void upheap(int k)
{
	while(k>1)
	{
		if(pr[k].end> pr[k/2].end)
		{
			swap(k, k/2);
			k=k/2;
		}
		else
			break;
	}
}
//thu tuc downheap
void downheap(int k, int l)
 {
	int i;
	while(2*k<l)//phai nho hon do dai vi neu la 2*k<=l thi co the phan tu cuoi duoc sap xep roi nhung van bi doi cho
	{
		i=2*k;
		if(pr[i].end < pr[i+1].end)
		{
			i=i+1;
		}
		if(pr[k].end <= pr[i].end)
		{
			if(pr[k].end == pr[i].end)
			{
				if(pr[k].start < pr[i].start)
					swap(k, i);
			}
			else
				swap(k, i);
		}
		k=i;
	}
}
//sap xep cac cuoc hop su dung heap
void sapxepcuochop()
{
	int i;
	while(len>=2)
	{
		swap(1, len);
		len--;
		downheap(1, len);
	}	
}
//doc file
void readfile()
{
	FILE *f;
	int i;
	f=fopen("dscuochop.inp", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d\n", &n);// doc so luong tien trinh da cho
	pr = (cuochop*)malloc((n+1)*sizeof(cuochop));
	khoitao();
	for(i=1; i<=n; i++)
	{
		fscanf(f, "%d %d\n", &pr[i].start, &pr[i].end);
		upheap(i);
	}
	sapxepcuochop();
	fclose(f);
}

//lap lich cho cac tien trinh
void laplich()
{
	int i, j;
	for(i=1; i<=n; i++)
	{
		L[i]=1;
		for(j=1; j<=i; j++)
		{
			if(pr[j].end<pr[i].start && L[i]<L[j]+1)
			{
				L[i] = L[j]+1;
			}
		}
	}
	for(i=1; i<=n; i++)
	{
		if(Lm<L[i])
		{
			Lm=L[i];
		}
	}
	printf("\nSo cuoc hop toi da co the sap xep la %d", Lm);
}
void print()
{
	int i;
	printf("\nIn ra lich hop la\n");
	for(i=1; i<=n; i++)
	{
		if(dd[i]==1)
		{
			printf("%d->%d\n", pr[i].start, pr[i].end);
		}
	}
}
void truyvet(int k)
{
	int i;
	for(i=1; i<=n; i++)
	{
		if(dd[i]==0 && L[k]+1==L[i] && pr[k].end<pr[i].start)
		{
			dd[i]=1;
			if(L[i]==Lm)
			{
				print();
			}
			else
			{
				truyvet(i);
			}
			dd[i]=0;
		}
	}
}
//ham main
int main()
{
	readfile();
	laplich();
	dd[1]=1;
	truyvet(1);
	getch();
}
