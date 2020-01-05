#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100],b[100],L[100],n;
void nhap()
{
     int i;
     printf("nhap so cuoc hop  = ");
     scanf("%d",&n);
     printf("mot cuoc hop bat dau tu a[i] ket thuc b[i]\n");
     for(i=1;i<=n;i++){
                       printf("a[%d] = ",i);
                       scanf("%d",&a[i]);
                       printf("b[%d] = ",i);
                       scanf("%d",&b[i]);
                       }
}
void in()
{
     int i;
     printf("+**************************+\n");
     printf("+cuochop||batdau||ketthuc**+\n");
     printf("+**************************+\n");
     for(i=1;i<=n;i++){
                       printf("%d\t||%5d\t||%5d\n",i,a[i],b[i]);
                       }
      printf("+**************************+\n");
}
void swap(int *x,int *y)
{
     int t = *x;
     *x = *y;
     *y = t;
}
void sapxep()
{
     int i,j;
     for(i=1;i<=n;i++){
                       for(j=i+1;j<=n;j++){
                                         if(b[j] < b[i]){
                                                 swap(&b[i],&b[j]);
                                                 swap(&a[i],&a[j]);
                                                 }
                                         else if(b[i] == b[j]){
                                              if(a[j]<a[i]){
                                                           swap(&a[i],&a[j]);
                                                           swap(&b[i],&b[j]);
                                                           }
                                                           }
                                                           }
                                                           }
}
int max(int i)
{
    int j,max = 0;
    for(j=1;j<=i;j++){
                      if(L[j] > max && b[j] <= a[i+1])
                              max = L[j];
                              }
    return max;
}
                     
    
void bangphuongan()
{
     int i;
     L[1] = 1;
     for(i=2;i<=n;i++){
                       L[i] = max(i-1)+ 1;
                       }
}
void truyvet()
{
     int k=1;
     for(int i=2; i<=n; i++)
        if(L[i]>L[k])
            k=i;
            int maxi = L[k];
//quay lui dua ket qua vao stack
     int x[100];
     int t = maxi - 1;
    while(L[k] != 1 && t>=0){
        x[t] = k;      
        t--;
        for(int i = k-1; i>0; i--){
            if(L[i]+1 == L[k] && b[i]<=a[k]){
                k = i;
                break;         
            }       
        }
    }
    x[t] = k;
    printf("\nSO CUOC HOP MAX DUOC TO CHUC: %d\n", maxi);
	printf("+********************************+\n");
	printf("| cuochop || batdau ||  ketthuc |+\n");
	printf("+********************************+\n");
	for(int i=0; i<maxi; i++){
		printf("| %d\t|| %5d \t|| %5d |\n", i+1, a[x[i]], b[x[i]]);	 
	}
	printf("+********************************+\n");
     
}                       
     
     
int main()
{
    nhap();
    sapxep();
    in();
    bangphuongan();
    truyvet();
    getch();
    return 0;
}
     
     
