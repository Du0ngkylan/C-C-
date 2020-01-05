#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int n;
float x[100];// mang cac toa do X
float y[100];// mang cac toa do Y
float dmin; 
int Imin,Jmin; 

// Nhap Du Lieu Tu Ban Phim
void NhapDuLieu()
{
     printf("Nhap so diem n : ");
     scanf("%d", &n);
     
     for(int i = 1; i <= n; i++)
     {
             printf("Nhap toa do diem thu %d (nhap ca X va Y: Vd: 2 3) : ", i);
             scanf("%f %f",&x[i], &y[i]);
     }
}

//In danh sach cac diem
void InDSDiem(){
	for (int i=1; i<=n;i++)
		printf("Diem thu %d : %f %f \n",i, x[i], y[i]);
	
    printf("\n");
	
}

//Thuat Toan Doi cho 
void Swap(int i, int j){  
     float t;

     t=x[i];
     x[i]=x[j];
     x[j]=t;
     t=y[i];
     y[i]=y[j];
     y[j]=t;

}
//Thuat Toan Sap Xep QuickSort
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





float KhCach(int i, int j){ 
     float kc;
     kc=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
     return kc;
}

//Tim khoang cach nho nhat giua cac diem nam tu diem[L] den diem[R]
float KCNN(int L, int R, int* imin, int* jmin){ 
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
	   if (d>d2){
        d=d2;
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

    
    NhapDuLieu();
    QuickSort(x,1,n);
    
    printf("\nCac diem vua nhap(da sap xep): \n");
    InDSDiem();
    
    dmin = KCNN(1,n,&Imin,&Jmin);
    printf("\nKhoang cach nho nhat la: %f",dmin);
    printf("\nCap diem gan nhat la %d  va %d",Imin, Jmin);
    getch();
    return 0;
}
