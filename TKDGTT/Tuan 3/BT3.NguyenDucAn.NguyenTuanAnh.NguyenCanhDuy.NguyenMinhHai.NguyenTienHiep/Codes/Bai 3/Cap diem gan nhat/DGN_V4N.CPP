/*Author: Nhom 1
Date: 2012 Mar 09*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int n;
float x[100];
float y[100];
float dmin; //Khoang cach nho nhat
int Imin,Jmin; //I,J la chi so cua cap diem gan nhau nhat

//Doc du lieu tu file inputDGN.txt
void DocFile(){
    FILE *f;
    f = fopen("inputDGN.txt", "r");
    if(!f)
    {
	printf("\n Loi mo file");
	exit(0);
    }
    fscanf(f, "%d", &n);
    cout<<endl<<"n la "<<n<<endl;
    for(int i = 1; i <= n; i++) fscanf(f, "%f %f", &x[i], &y[i]);
    cout<<"Cac diem vua doc tu file la: "<<endl;
    for(i = 1; i <= n; i++) printf("\n %f %f", x[i], y[i]);
}

//Doan ma tiep theo mo ta sap xep cac diem theo thu tu tang dan cua x[]
void Swap(int i, int j){  //Doi cho hai diem i va j
     float t;

     t=x[i];
     x[i]=x[j];
     x[j]=t;
     t=y[i];
     y[i]=y[j];
     y[j]=t;

}

int PivotList(float list[], int first, int last)
{
	int lower=first;
	int upper=last+1;
	float pivotvalue=list[first];
	do
	{
		do
		{
			upper--;
		}
		while (list[upper]>pivotvalue);
		do
		{
			lower++;
		}
		while (list[lower]<pivotvalue);
		Swap(upper, lower);
	}
	while (lower<upper);
	Swap(upper, lower);
	Swap(first, upper);
	return upper;
}


void QuickSort(float list[], int first, int last)
{
	if (first<last)
	{
		int pivot=PivotList(list,first,last);
		QuickSort(list, first, pivot-1);
		QuickSort(list,pivot+1,last);
	}
}
//Het doan ma sap xep QuickSort

void InDSDiem(){//In danh sach cac diem kem theo toa do cua no
	for (int i=1; i<=n;i++)
		cout<<endl<<"Diem thu "<<i<<" "<<x[i]<<" "<<y[i];
	cout<<endl;
}



float KhCach(int i, int j){ //Tim khoang cach giua diem i va diem j
     float kc;
     kc=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
     return kc;
}

float KCNN(int L, int R, int* imin, int* jmin){ //Tim khoang cach nho nhat giua cac diem nam tu diem[L] den diem[R]
      float d,d1,d2,d3;
      int L1,R1,M;
      int imin1;
      int imin2;
      int imin3;
      int jmin1;
      int jmin2;
      int jmin3;

      if ((R-L)==1) {//Truong hop suy bien
		    d = KhCach(L,R);
		    *imin = L;
		    *jmin = R;
		    }
      else {
		M = (int)((L+R)/2);
	    d1 = KCNN(L,M,&imin1,&jmin1);//Tim khoang cach nho nhat o nua ben trai
		d2 = KCNN(M,R,&imin2,&jmin2);//Tim khoang cach nho nhat o nua ben phai

       //Gan d la khoang khoang cach nho nhat trong 2 khoang cach d1 va d2
	   d=d1;
	   *imin=imin1;
	   *jmin=jmin1;
	   if (d>d2){d=d2;
		*imin=imin2;
		*jmin=jmin2;
			}

	   //Tim cac diem co hoanh do roi vao khoang (x[M]-d,x[M]+d)
       int i;
	   i=L+1;
	   while ((x[M]-x[i])>d) i++;
	   L1=i;


	   i=R-1;
	   while ((x[i]-x[M])>d) i--;
       R1=i;

	   if ((R1-L1)>1){
		      d3 = KCNN(L1,R1,&imin3,&jmin3);
		      if (d>d3) {
				    d=d3;
				    *imin=imin3;
				    *jmin=jmin3;
				    }
		     }
	   }
      return d;
}

int main(){

    DocFile();
    QuickSort(x,1,n);
    cout<<endl<<"Cac diem sau khi da sap xep la: ";
    InDSDiem();
    
    dmin = KCNN(1,n,&Imin,&Jmin);
    cout<<endl<<"Khoang cach nho nhat la: "<<dmin;
    cout<<endl<<"Cap diem thoa man la diem "<<Imin<<" va diem "<<Jmin;
    getch();
    return 0;
}
