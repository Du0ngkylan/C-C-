/*thuat toan tham lam: sap xep hoat dong su dung tai nguyen
  Bai toan: n hoat dong cung su dung 1 tai nguyen. 
  Moi hoat dong dien ra trong thoi gian s_i toi f_i(s_i<f_i) va  
toan quyen su dung tai nguyen trong thoi gian da xep.
  Tim day nhieu nhat cac hoat dong xep duoc
*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
int n;
//dung cau truc de bieu dien cac hoat dong, 1 hoat dong a_i gom thoi gian bat dau s_i va thoi gian ket thuc f_i
typedef struct hoatdong
{
        int s;//start
        int f;//finish
}hoatdong;
hoatdong *nhap()
{
     hoatdong *a;
     int i;   
     FILE *f1;
     char s[200];
     f1=fopen("tainguyen_input.dat","r");
     if(!f1)
     {
           printf("Loi mo lep!");   getch();  exit(0);
     }
     fscanf(f1,"%d",&n);
     fgets(s,200,f1);   
     a=(hoatdong *)malloc(n* sizeof(hoatdong));
     for(i=1;i<=n;i++)
     {
           fscanf(f1,"%d%d",&a[i].s,&a[i].f);
           fgets(s,200,f1);
           if(a[i].s>=a[i].f)
           {
               printf("Error file: Thoi gian bat dau phai nho hon thoi gian ket thuc!!!");    
               getch();      exit(0);
           }
           
     }
     fclose(f1);
     return a;
}
void in(hoatdong *a,int n)
{
     int i;
     FILE *f1;
     f1=fopen("tainguyen_output.dat","w");
     fprintf(f1,"%d%s\n",n," //so hoat dong duoc chon");
     for(i=1;i<=n;i++)
     {
           printf("Hoat dong thu %d:\tstart=%d\tfinish=%d\n",i,a[i].s,a[i].f);
           fprintf(f1,"%d\t%d\n",a[i].s,a[i].f);  
     }
     fclose(f1);
}
void swap(hoatdong *a,hoatdong *b)
{
     hoatdong temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
void quicksort(hoatdong *a,int l,int r)
{
	int i,j,m;
	m=(l+r)/2;
	i=l;
	j=r;
	while(i<j)
	{
		while(a[i].f<a[m].f)
			i++;
		while(a[j].f>a[m].f)
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
//thuat toan tham 
void Activity_Selector(hoatdong *input,hoatdong *output,int *m,int n)
{
     output[1]=input[1];
     int i,j=1;
     for(i=2;i<=n;i++)
     {
           if(input[i].s>=input[j].f)
           {
                  *m=*m+1;
                  output[*m]=input[i];
                  j=i;
           }
     }
}
int main()
{
    int m=1;//n la so hoat dong co, m la so hoat dong toi da xep duoc
    hoatdong *input,*output;  
    output=(hoatdong *) malloc (n*sizeof(hoatdong));
    input=nhap();
    printf("\n..........................Ket qua.....................................\n");
    //sap xep cac hoat dong theo thoi gian ket thuc tang dan
    quicksort(input,1,n);
    Activity_Selector(input,output,&m,n);
    printf("Co toi da %d hoat dong duoc them vao la:\n",m);
    in(output,m);
    printf("\n>>>>>>>>>KET QUA DA IN RA TEP 'TAINGUYEN_OUTPUT.DAT'<<<<<<<<<<\n");
    getch();
}
