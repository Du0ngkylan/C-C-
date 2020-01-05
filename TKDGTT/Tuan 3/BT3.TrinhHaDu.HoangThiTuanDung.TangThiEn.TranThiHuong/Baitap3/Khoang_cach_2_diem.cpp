#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

struct Point
{
	float x;
	float y;
};

void nhap(Point *p)
{
	printf("\nNhap hoanh do: ");
	scanf("%f",&p->x);
	printf("\nNhap tung do: ");
	scanf("%f",&p->y);
}

void Input(Point p[],int &n)
{
	printf("\nNhap vao so diem cua mat phang: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nDiem %d: ",i+1);
		nhap((p+i));
	}
}

//Ham Tinh Binh Phuong 2 cua mot so.
float sqr(int x)
{
	return (float)x*x;
}

float CalculateDistance(Point p1,Point p2)
{
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

//Sap xep cac diem theo thu tu tang dan cua hoanh do.
void Swap(Point *p1,Point *p2)
{
	Point *p;
	p = p1;
	p1 = p2;
	p2 = p;
}

void Arrange(Point *p,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if((p+i)->x > (p+j)->y)
				Swap((p+i),(p+j));
}

void DisplayArrArrange(Point *p,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("(%f,%f)",(p+i)->x,(p+i)->y);
	}
}
//
int main()
{
	Point p[100];
	int n;
	Input(p,n);
	printf("\nKhoang cach giua 2 diem: %f",CalculateDistance(p[0],p[1]));
	Arrange(p,n);
	DisplayArrArrange(p,n);
    getch();
    return 0;
}
