#include <stdio.h>
#include <conio.h>
int BinarySearch(int a[],int x,int L,int R)
{
          //T�m kiem phan tu x tr�n d�y a tu vi tr� L den R  
          if (L == R)  
          {
           if (a[L]==x) printf(" vi tri phan tu %d",L);
           else printf("khong co phan tu trong day");
          }           
          else        
          {
              int M = (L+R)/2;
              if (x ==a[M]) printf("vi tri phan tu %d", M);
		       else
		       {
                  if (x<a[M]) BinarySearch(a,x,L,M-1);
                  else BinarySearch(a,x,M+1,R) ;
               }  
         }    
}
int main()
{
    int a[100],n,i,y; 
    printf("Nhap so phan tu cua mang:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }  
    printf("nhap phan tu can tim:");
    scanf("%d",&y); 
    BinarySearch(a,y,0,n-1);
    getch();
    
}    
    
/* �? ph?c t?p thu?t to�n Binary Search 

+ N?u n=2r ph?n t? c?n t�m ? d?u ho?c cu?i danh s�ch ho?c r kh�ng n?m trong m?ng c?n t�m. V� v?y v?i tru?ng h?p n�y s? l?n chia nhi?u nh?t l� r=log2n ( v?i r l� s? l?n chia m?ng ra l�m d�i )
+N?u n != 2r s? nguy�n r nh? nh?t sao cho
2r-1 < n < 2r
<=> r-1< log2n<r
<=> r < log2n + 1 < r+1
=> s? l?n chia t?i da => danh s�ch g?m 1 ph?n t? kh�ng vu?t qu� r < log2n+ 1
V?y big 0 c?a binary_search l� log2n */             
