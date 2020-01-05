#include"stdio.h"
#include"conio.h"
#include"math.h"
#include"stdlib.h"
#define MAX 0x7fffffff;
typedef struct P
{
    int x,y;
}P;
//tinh khoang cach cua 2 diem
float distance(P a,P b)
{
	float d=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
	return d;
}
//doi vi tri 2 diem
void swap(P *a,P *b)
{
	P temp;
	temp= *a;
	*a=*b;
	*b=temp;
}
//sap xep cac diem trong mang cac diem theo thu tu tang dan
void quicksort(P a[],int l,int r)
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
void nhap(P a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("----------------------\n");
		printf("p[%d].x=",i);scanf("%d",&a[i].x);
		printf("p[%d].y=",i);scanf("%d",&a[i].y);
	}
}
//in mang cac diem
void in(P a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("p[%d].x=%d\tp[%d].y=%d\n",i,a[i].x,i,a[i].y);
}
//tra lai mang chua 2 diem gan nhau nhat trong mang voi n<= 3 diem
P *shortest(P ps[],int n) 
{
	P p1;
	P p2; 
	P *shorted;
	shorted=(P *)malloc(2*sizeof(P));
	int i,j;
	float newDistince;
	float distance1 = MAX;
	for ( i = 0; i <n; i++)
	{
		for ( j = 0; j < i; j++)
		{
			if (i != j)
			{   
				P ptemp1,ptemp2;
				ptemp1.x=ps[i].x;
				ptemp1.y=ps[i].y;
				ptemp2.x=ps[j].x;
				ptemp2.y=ps[j].y;
				if (ptemp1.x!=ptemp2.x || ptemp1.y==ptemp2.y)
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
	shorted[0].x=p1.x; shorted[0].y=p1.y;
	shorted[1].x=p2.x; shorted[1].y=p2.y;
	return shorted;
}
//tim diem gan nhau nhat nam trong 2 nua mat phang khac nhau
P *mergePlanes(P p1[],int n1,P p2[],int n2,float d,	P *closest)
{
	int i,j;
	for (i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p1[i].x + d>p2[j].x)
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
P *findClosest(P px[],int n)
 {
	int i,j;
	P *Pclosest;//mang chua 2 diem gan nhau nhat
	Pclosest=(P *)malloc(2*sizeof(P));
	if (n <= 3)
	{
		P *short1;
		short1=shortest(px,n);
		return short1; 
	}
	else 
	{
         //chia mang cac diem lam 2 nua theo truc x
		int left = n / 2;//so phan tu ben trai
		int right = n / 2 + n % 2;//so phan tu ben phai
		P Pleft[left];//mang chua cac phan tu o nua ben trai
		P Pright[right];//mang chua cac phan tu o nua ben phai
		P *Pleftmin,*Prighttmin;//mang chua cap 2 phan tu gan nhau nhat o ben trai va phai
		for (i = 0; i < left; i++)
			Pleft[i] = px[i];
		for (i = 0; i < right; i++)
			Pright[i] = px[i + left];
		Pleftmin = findClosest(Pleft,left);//return mang chua tra lai cap diem gan nhau nhat ben trai

		Prighttmin = findClosest(Pright,right);//return mang chua cap diem gan nhau nhat ben phai

		float d1=distance(Pleftmin[0], Pleftmin[1]);//khoang cach giua 2 diem gan nhau nhat ben trai
		float d2=distance(Prighttmin[0], Prighttmin[1]);//khoang cach giua 2 diem gan nhau nhat ben phai
		float d=d1>d2?d2:d1;
		P *closest;
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
    P *closest;
    printf("nhap so diem trong mat phang n=");
    scanf("%d",&n);
    P points[n];
    nhap(points,n);
    quicksort(points,0,n-1);
    closest = findClosest(points,n);
    printf("cap diem gan nhau nhat trong mat phang:\n");
    in(closest,2);
    getch();
    return 0;
}
