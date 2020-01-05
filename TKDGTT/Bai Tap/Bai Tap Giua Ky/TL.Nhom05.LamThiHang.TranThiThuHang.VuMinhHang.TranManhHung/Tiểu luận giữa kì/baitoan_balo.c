#include <stdio.h>
#include <conio.h>
#define max 100

int v[max], w[max], a[max];
int n, wmax;
void nhap()
{
    FILE *f;
    int i;
    f = fopen("balo.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &wmax);
    for(i=0; i<n; i++)
    {
        fscanf(f, "%d", &w[i]);
        fscanf(f, "%d", &v[i]);
    }
    fclose(f);
}
void main()
{
    int vmax=0;
    int i,d;
    nhap();
    int kq[n];
    for( i=0;i<n;i++)
        a[i]=0;
    while(i>=0)
    {
        int v1=0, w1=0;
        for(i=0;i<n;i++)
		{
			v1=v1+v[i]*a[i];
			w1=w1+w[i]*a[i];
		}
		if((w1<wmax)&&(v1>vmax))
		{
			vmax=v1;
			for(i=0;i<n;i++)
				kq[i]=a[i];
        }	
        i=n-1;
        while(i>=0&&a[i]==1)
            i--;
        if(i>=0)
        {
            a[i]=1;
            for( d=0;d<n-i;d++)
                a[i+d]=0;
        }
    }
    for(i=0;i<n;i++)
		if(kq[i]!=0) printf("%d\t", i+1);
    getch();
}
