#include<stdio.h>
#include<conio.h>

int p[50],w[50],v[50][50],n,cap;

int balo(int n, int cap)
{
	int a,b,m,c,k;
	if( (n==0) || (cap==0) )
	    v[n][cap]=0;
    else
    {
        m = cap - w[n];
        k = n - 1;
        c = cap;
        if(m<0)
            a = 0;
        else
            a = p[n] + balo(k,m);
        b = balo(k,c);
        if (a>b)
            v[n][cap] = a;
        else
            v[n][cap] = b;
    }
    return v[n][cap];
}

void nhap()
{
    int i;
    printf("\nSO LIEU VAO:\n");
	printf("So luong do vat: ");scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Do vat thu %d:\n",i);
		printf("\t trong luong: ");scanf("%d",&w[i]);
		printf("\t gia tri: ");scanf("%d",&p[i]);
	}
	printf("\nBa lo co the chua toi da: ");scanf("%d",&cap);
}

void khoitao()
{
    int i,j;
    for(i=0;i<=n;i++)
		for(j=0;j<=cap;j++)
			v[i][j]=0;
}

void inketqua()
{
    int i,j;
	i=n;
	j=cap;
	printf("\n______________________________\n");
	printf("\nKET QUA\n");
	while((j!=0) && (i!=0))
	{
		if(v[i][j] != v[i-1][j])
		{
			printf("\tVat thu %d co trong luong %d kg va gia tri %d $\n",i,w[i],p[i]);
			j=j-w[i];
			i=i-1;
		}
		else
			i=i-1;
	}
}

int main()
{
	int profit;
	nhap();
	khoitao();
	profit = balo(n,cap);
	inketqua();
    printf("Gia tri cao nhat tuong ung:  %d $",profit);
	
	getch();
}
