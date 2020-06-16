// Liet ke duong don giua 2 dinh

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define hs 50
int n, m,co, dau[hs], cuoi[hs], dd[hs], xp, dich, b[hs], q[hs],M[hs][hs],v[hs];

void nhap()
{
    int i,j,k;
    FILE *f;
    f = fopen("data1.1.txt","r");
    if(!f)
    {
        printf("Loi mo tep");
        exit(0);
    }
    fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            M[i][j] = 0;
        }
    for(k=1;k<=m;k++)
    {
        fscanf(f,"%d %d",&i,&j);
        M[i][j] = 1;
    }
     
     fclose(f);
}	

void khoitao()
{
	int i;
	for(i=1;i<=n;i++) b[i] = 1;
}

int cung(int i, int j)
{
	return M[i][j]==1;
}

void Induong(int k)
{
	int i;
	for (i=1;i<k;i++)
	{
		printf("%d ---> ", v[i]);
	}
	printf("%d\n",dich);
	co = 1;
}
void lietke(int k)
{
	int i; 
	if (k>n) return;
	if (v[k]==dich) 
	{
		Induong(k); return;
	}
	for (i=1;i<=n;i++)
		if (b[i]==1)
			if (cung(v[k],i))
			{
				v[k+1]=i; 
				b[i]=0; 
				lietke(k+1);
				b[i]=1;
			}		
}

int main()
{
	nhap();
	co = 0; 
	khoitao();
	printf("\nNhap dinh xp =  ");
	scanf("%d",&xp);
	printf("\nNhap dinh dich =  ");
	scanf("%d",&dich);
	v[1]=xp;
	b[xp]=0;
	lietke(1);
	if (!co) printf("Khong co duong");
	getch();

}
