#include"stdio.h"
#include"conio.h"
#define MAX 0x7fffffff;
typedef struct Point
{
    int x,y;
}Point;
//tinh khoang cach cua 2 diem
float distance(Point a,Point b)
{
	float d=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
	return d;
}
//doi vi tri 2 diem
void swap(Point *a,Point *b)
{
	Point temp;
	temp= *a;
	*a=*b;
	*b=temp;
}
//sap xep cac diem trong mang cac diem theo thu tu tang dan theo truc x
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
//nhap mang cac diem
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
//in mang cac diem
void in(Point a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("p[%d].x=%d\tp[%d].y=%d\n",i,a[i].x,i,a[i].y);
}
//tra lai mang chua 2 diem gan nhau nhat trong mang gom n diem
//(bai nay n=3,chi dung de tim mang 2 diem gan nhau nhat trong 3 diem vs thoi gian hang so)
Point *shortest(Point ps[],int n) 
{
	Point p1;
	Point p2; 
	Point *shorted;
	shorted=(Point *)malloc(2*sizeof(Point));
	int i,j;
	float newDistince;
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
						// update
						distance1 = newDistince;
						p1.x=ptemp1.x;          p1.y = ptemp1.y;
						p2.x= ptemp2.x;         p2.y = ptemp2.y;
					}
				}
			}
		}
	}
	//Point points[2];
	shorted[0].x=p1.x; shorted[0].y=p1.y;
	shorted[1].x=p2.x; shorted[1].y=p2.y;
	return shorted;//mang shorted chua 2 diem gan nhau nhat
}
/*tim ra cap diem gan nhau nhat trong do moi diem o 1 nua mat phang rieng(neu co)
p1: mang chua cac diem nam o nua mat phang thu nhat
p2: mang chua cac diem nam trong nua mat phang thu 2
n1:so diem trong nua mat phang thu nhat
n2:so diem trong nua mat phang thu hai
d : khoang cach gan nhat giua 2 diem da tinh dc
 voi:d=min(d1(khoang cach gan nhat giua 2 diem trong nua mat phang thu nhat),d2(k/c gan nhat giua 2 diem cua nua mat phang thu 2))
closest: mang chua 2 diem gan nhau nhat(2 diem gan nhau nhat cua nua mat phang 1 hoac 2)


*/
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
//tim ra 2 diem gan nhau nhat trong mat phang
//px: mang cac diem trong mat phang , n:so diem
Point   *findClosest(Point px[],int n)
 {
	// px must be sorted in x, then y
	int i,j;
	Point *Pclosest;//mang chua 2 diem gan nhau nhat
	Pclosest=(Point *)malloc(2*sizeof(Point));
	if (n <= 3)
	{
		Point *short1;
		short1=shortest(px,n);//tra lai cap diem gan nhau nhat trong 3 diem
		return short1; 
	}
	else 
	{
         //chia mang cac diem lam 2 nua theo truc x
		int left = n / 2;//so phan tu ben trai
		int right = n / 2 + n % 2;//so phan tu ben phai
		// sets
		Point Pleft[left];//mang chua cac phan tu o nua ben trai
		Point Pright[right];//mang chua cac phan tu o nua ben phai
		Point *Pleftmin,*Prighttmin;//mang chua cap 2 phan tu gan nhau nhat o ben trai va phai
		for (i = 0; i < left; i++)
			Pleft[i] = px[i];
		for (i = 0; i < right; i++)
			Pright[i] = px[i + left];
		Pleftmin = findClosest(Pleft,left);//return mang chua cap diem gan nhau nhat ben trai

		Prighttmin = findClosest(Pright,right);//return mang chua cap diem gan nhau nhat ben phai

		float d1=distance(Pleftmin[0], Pleftmin[1]);//khoang cach giua 2 diem gan nhau nhat ben trai
		float d2=distance(Prighttmin[0], Prighttmin[1]);//khoang cach giua 2 diem gan nhau nhat ben phai
		float d=d1>d2?d2:d1;
		Point *closest;
		if(d==d1)
			closest=Pleftmin;
		else
			closest=Prighttmin;
		Pclosest = mergePlanes(Pleft,left, Pright,right ,d,closest);//tim cap diem gan nhau nhat(moi diem nam o 1 nua mat phang neu co)
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
    //sap xep cac diem theo chieu tang dan theo truc x(thoi gianO(nlogn)
    quicksort(points,0,n-1);
    printf("tap diem sau khi xep:\n");
    in(points,n);
    //tim cap diem gan nhat
    closest = findClosest(points,n);
    printf("cap diem gan nhau nhat trong mat phang:\n");
    in(closest,2);
    getch();
    return 0;
}
