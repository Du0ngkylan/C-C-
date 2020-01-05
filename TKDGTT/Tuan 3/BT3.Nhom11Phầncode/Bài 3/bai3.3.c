#include"stdio.h"
#include"conio.h"
#define MAX 0x7fffffff;
typedef struct Point
{
    int x,y;
}Point;
float distance(Point a,Point b)
{
	float x=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
	return d;
}
void swap(Point *x,Point *y)
{
	Point temp;
	temp= *x;
	*x=*y;
	*y=temp;
}
void quicksort(Point a[],int l,int r)
{
	int i,j,m;
	m=(l+r)/2;
	i=l;
	j=r;
	while(i<j)
	{
		while(a[i].x<a[m].x)
			i++;
		while(a[j].x>a[m].x)
			j--;
		if(i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
		if(l<j)
			quicksort(a,l,j);
		if(i<r)
			quicksort(a,i,r);
	}
}
void nhap(Point a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d.\n",i+1);
		printf("p[%d].x=",i);             scanf("%d",&a[i].x);
		printf("p[%d].y=",i);             scanf("%d",&a[i].y);
	}
}
void in(Point a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("p[%d].x=%d\tp[%d].y=%d\n",i,a[i].x,i,a[i].y);
}

Point *shortest(Point ps[],int n) 
{
	Point p1;
	Point p2; 
	Point *shorted;
	shorted=(Point *)malloc(2*sizeof(Point));
	int i,j;
	float newDist;
	float distance1 = MAX;
	for ( i = 0; i <n; i++)
	{
		for ( j = 0; j < i; j++)
		{
			if (i != j)
			{   
				Point ptemp1,ptemp2;
				ptemp1.x=ps[i].x;
				ptemp1.y=ps[i].y;
				ptemp2.x=ps[j].x;
				ptemp2.y=ps[j].y;
				
				if (ptemp1.x!=ptemp2.x || ptemp1.y!=ptemp2.y)
				{
					newDistince = distance(ptemp1, ptemp2);
					if (newDistince < distance1) 
					{
						distance1 = newDistince;
						p1.x=ptemp1.x;          p1.y = ptemp1.y;
						p2.x= ptemp2.x;         p2.y = ptemp2.y;
					}
				}
			}
		}
	}
	
	shorted[0].x=p1.x; shorted[0].y=p1.y;
	shorted[1].x=p2.x; shorted[1].y=p2.y;
	return shorted;
}

Point *mergePlanes(Point p1[],int n1,Point p2[],int n2,float d, Point closest[])
{
	
	int i,j;
	for (i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p1[i].x+d>p2[j].x)
			{
				if(distance(p1[i], p2[j])<d)
				{
					closest[0]=p1[i];
					closest[1]=p2[j];
					d=distance(p1[i], p2[j]);
				}
			}
		}
	}
	return closest;
	
}
Point   *findClosest(Point px[],int n)
 {
	int i,j;
	Point *Pclosest;
	Pclosest=(Point *)malloc(2*sizeof(Point));
	if (n <= 3)
	{
		Point *short1;
		short1=shortest(px,n);
		return short1; 
	}
	else 
	{
		int left = n / 2;
		int right = n / 2 + n % 2;
		Point Pleft[left];
		Point Pright[right];
		Point *Pleftmin,*Prighttmin;
		for (i = 0; i < left; i++)
			Pleft[i] = px[i];
		for (i = 0; i < right; i++)
			Pright[i] = px[i + left];
		Pleftmin = findClosest(Pleft,left);

		Prighttmin = findClosest(Pright,right);

		float d1=distance(Pleftmin[0], Pleftmin[1]);
		float d2=distance(Prighttmin[0], Prighttmin[1]);
		float d=d1>d2?d2:d1;
		Point *closest;
		if(d==d1)
			closest=Pleftmin;
		else
			closest=Prighttmin;
		Pclosest = mergePlanes(Pleft,left, Pright,right ,d,closest);
		return Pclosest;		
    }
}
int main()
{
    int n;
    Point *closest;
    do{
        printf("nhap so diem trong mat phang n=");
        scanf("%d",&n);
    }while(n<2);
    Point points[n];
    nhap(points,n);
    printf("tap diem truoc khi xep:\n");
    in(points,n);
    quicksort(points,0,n-1);
    printf("tap diem sau khi xep:\n");
    in(points,n);
    closest = findClosest(points,n);
    printf("cap diem gan nhau nhat trong mat phang:\n");
    in(closest,2);
    getch();
    return 0;
}
