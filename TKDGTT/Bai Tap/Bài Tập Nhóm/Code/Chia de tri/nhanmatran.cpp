#include<stdio.h>
#include<conio.h>
#include<math.h>

//Nhan hai ma tran
int nhan(float a[][100], float b[][100], float c[][100])
{
    float m1,m2,m3,m4,m5,m6,m7;
    m1= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
    m2= (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    m3= (a[0][0]-a[1][0])*(b[1][0]+b[0][1]);
    m4= (a[0][0]+a[0][1])*b[1][1];
    m5 = a[0][0]*(b[0][1]-b[1][1]);
    m6= a[1][1]*(b[1][0]-b[0][0]);
    m7= (a[1][0]+a[1][1])*b[0][0];
    c[0][0]=m1+m2-m4+m6;
    c[0][1]= m4+m5;
    c[1][0]= m6+m7;
    c[1][1]= m2 -m3 +m5-m7;
    
	return 1;
}

//Tach thanh 4 ma tran con
int tach(float a[][100], float a11[][100], float a12[][100],float a21[][100],float a22[][100], int n)
{
	for(int i=0;i<(n/2);i++)
			for(int j=0;j<(n/2);j++)
			{
				a11[i][j]=a[i][j];
				a12[i][j]=a[i][j+n/2];
				a21[i][j]=a[i+n/2][j];
				a22[i][j]=a[i+n/2][j+n/2];
			}
	return 1;
}

//Cong hai ma tran
int cong(float a[][100], float b[][100], float c[][100], int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=a[i][j]+b[i][j];
	return 1;
}


//Hop 4 ma tran thanh ma tran
int hop(float a[][100], float a11[][100], float a12[][100],float a21[][100],float a22[][100], int n)
{
	for(int i=0;i<n/2;i++)
		for(int j=0;j<n/2;j++)
			a[i][j]=a11[i][j];
	for(int i=0;i<n/2;i++)
		for(int j=n/2;j<n;j++)
			a[i][j]=a12[i][j-n/2];
	for(int i=n/2;i<n;i++)
		for(int j=0;j<n/2;j++)
			a[i][j]=a21[i-n/2][j];
	for(int i=n/2;i<n;i++)
		for(int j=n/2;j<n;j++)
			a[i][j]=a22[i-n/2][j-n/2];
	return 1;
}

/*Kiem tra luy thua 2*/
int kiemtra(int n)
{
	while(n>=2)
	{
		if(n%2)
			return 0;
		n=n/2;
	}
	return 1;
}

/*Tinh toan chia de tri*/
int strass(float ax[][100], float bx[][100], float cx[][100], int n)
{
	float a11[100][100],a12[100][100],a21[100][100],a22[100][100];
	float b11[100][100],b12[100][100],b21[100][100],b22[100][100];
	float c11[100][100],c12[100][100],c21[100][100],c22[100][100];
	float d1[100][100],d2[100][100];
	if(n==2)
		nhan(ax,bx,cx);
	else
	{
		tach(ax,a11,a12,a21,a22,n);
		tach(bx,b11,b12,b21,b22,n);
		tach(cx,c11,c12,c21,c22,n);
		
		strass(a11,b11,d1,n/2);
		strass(a12,b21,d2,n/2);
		cong(d1,d2,c11,n/2);
		
		strass(a11,b12,d1,n/2);
		strass(a12,b22,d2,n/2);
		cong(d1,d2,c12,n/2);
		
		strass(a21,b11,d1,n/2);
		strass(a22,b21,d2,n/2);
		cong(d1,d2,c21,n/2);
		
		strass(a21,b12,d1,n/2);
		strass(a22,b22,d2,n/2);
		cong(d1,d2,c22,n/2);
		
		hop(cx,c11,c12,c21,c22,n);
	}
	return 1;
}

int nhap(float a[][100], float b[][100], int n)
{
	printf("\nNhap A: \n");
	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				printf("\nA[%d][%d]=  ",i,j);
				scanf("%f",&a[i][j]);
			}
	printf("\nNhap B: \n");
	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				printf("\nB[%d][%d]=  ",i,j);
				scanf("%f",&b[i][j]);
			}
}

int main()
{
	float a[100][100],b[100][100],c[100][100];
	int n;
	printf("\nCap cua ma tran:  ");
	scanf("%d",&n);
	while(kiemtra(n)==0)
	{
		printf("\nCap ma tran (luy thua 2):  ");
		scanf("%d",&n);
	}
	nhap(a,b,n);
	strass(a,b,c,n);
	printf("\nKET QUA: \n");
	for(int i=0;i<n;i++)
	{
		printf("\n\n\n");
		for(int j=0;j<n;j++)
			printf("%6.0f",c[i][j]);
	}
	printf("\n\n");
}
