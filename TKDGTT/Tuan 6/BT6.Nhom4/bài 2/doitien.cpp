#include <stdio.h>
#include<conio.h>
int main()
{
int i;
int j;
int k;
int dem,luu[3];
int tien;
printf("Nhap so tien=");
scanf("%d",&tien);
dem=tien;
printf("ket qua la:\n");
printf("||to 1 nghin\t||to 2 nghin\t||to 5 nghin\n");
for (i=0 ; i <= tien ; i=i+1)
  for (j=0 ; j <= tien/2 ; j=j+1)
   for  (k=0 ; k <= tien/5 ; k=k+1)
     if (i + 2*j + 5*k == tien) 
     {
           if(i+j+k<dem)
           {
                        dem=i+j+k;
                        luu[1]=i;
                        luu[2]=j;
                        luu[3]=k;
           }
     }
printf("%d\t\t%d\t\t%d",luu[1],luu[2],luu[3]);
getch();
}
