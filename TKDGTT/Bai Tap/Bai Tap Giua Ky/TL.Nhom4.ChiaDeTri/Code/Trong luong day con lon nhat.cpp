// cho day a co n phan tu a[1....n].day  a[p...q] la day con cua day ban dau . tim trong luong cua day con lon nhat cua day da cho
// trong luong mang bang tong cac phan tu cua mang

#include<stdio.h>
#include<conio.h>
float Max(float a,float b,float c){
      float y;
      y = (a > b) ? a : c;
      return ((y > c) ? y : c );
}
float MaxLeftVector(float a[],int i,int j){
       float MaxSum = 0 ; 
       float Sum = 0;
       for (int k = j; k >= i ; k --)
       {
           Sum = Sum + a[k];
           if(Sum > MaxSum)
               MaxSum = Sum;
       }
       return  MaxSum;
}

float MaxRightVector(float a[],int i,int j){
      float MaxSum = 0 ;
      float Sum = 0;
      for (int k = i ; k <= j; k++)
      {
          Sum = Sum + a[k];
          if(Sum > MaxSum)
              MaxSum = Sum;
      }
      return MaxSum;
}
float MaxSubVector(float a[],int i,int j)
{
      int m;
      float WL,WR,WM;
      if ( i == j)   return   a[i];
      else
      {
           m   = (i+j)/2;
           WL   = MaxSubVector(a,i,m);
           WR   = MaxSubVector(a,m+1,j);
           WM  = MaxLeftVector(a,i,m) + MaxRightVector(a,m+1,j);
           return   Max(WL, WR, WM );
      }
}

int main(){
    float a[100];
    int n;
    int i;
    printf("Nhap vao do dai day n = ");
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++)
    {
          printf("a[%d] = ",i);
          scanf("%f",&a[i]);
    }
    printf("\nMang da nhap la \n");
    for(i = 0 ; i < n ; i ++)
        printf("%.3f\t",a[i]);
    printf("\n\nDay con co trong luong lon nhat la: %.3f \n",MaxSubVector(a,1,3));
    getch();
    return 0;
}
