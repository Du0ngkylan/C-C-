//Bai toan lap lich su dung tai nguyen
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//dinh nghia kieu cau truc tientrinh
typedef struct tientrinh
{
	int start;
	int end;
}tientrinh;

tientrinh *pr;
int len;


int n, *dd;//mang dd danh giau cac tien trnh duoc chon
//khoi tao cho mang dd & so luong cac tien trinh
void khoitao()
{
	int i;
	dd=(int*)malloc((n+1)*sizeof(int));
	for(i=1; i<=n; i++)
		dd[i]=0;
	len=n;
}
//doi cho 2 tien trinh
void swap(int i, int j)
{
	tientrinh temp;
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
		if(pr[k].end < pr[i].end)
		{
				swap(k, i);
		}
		k=i;
	}
}
//sap xep cac tien trình su dung heap
void sapxeptientrinh()
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
	f=fopen("process.inp", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d\n", &n);// doc so luong tien trinh da cho
	pr = (tientrinh*)malloc((n+1)*sizeof(tientrinh));
	khoitao();
	for(i=1; i<=n; i++)
	{
		fscanf(f, "%d %d\n", &pr[i].start, &pr[i].end);
		upheap(i);
	}
	sapxeptientrinh();
	fclose(f);
}

/*void sapxeptientrinh()
{
	int i, j;
	tientrinh temp;
	for(i=1; i<=n-1; i++)
	{
		for(j=i+1; j<=n; j++)
		{
			if(pr[i].end>pr[j].end)
			{
				temp.start =pr[i].start;
				temp.end =pr[i].end;
				pr[i].start=pr[j].start;
				pr[i].end=pr[j].end;
				pr[j].start=temp.start;
				pr[j].end=temp.end;
			}
		}
	}
}*/
//lap lich cho cac tien trinh
void laplich()
{
	int i, j;
	dd[1]=1;
	j=1;
	for(i=2; i<=n; i++)
	{
		if(pr[i].start > pr[j].end)
		{
			dd[i]=1;
			j=i;
		}
	}
	printf("Cac tien trinh duoc chon la ->");
	for(i=1; i<=n; i++)
	{
		if(dd[i]==1)
		{
			printf("%d ", i);
		}
	}
}
//ham main
int main()
{
	readfile();
	sapxeptientrinh();
	laplich();
	getch();
}
