#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int *nhap_mang(int n);
void in_mang(int *a, int n);
int sapxeptang(int *a, int n);
int timso(int *a, int n);

int main()
{
    int *a, n;
    printf("nhap kich thuoc cua mang:\t");
    scanf("%d", &n);
    a = nhap_mang(n);
    printf("mang da nhap la:\n");
    in_mang(a, n);
    timso(a, n);
    
    getch();
    return 1;
}

int *nhap_mang(int n)
{
	int i;
	int *a;

	a = (int *) malloc (n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d:\t",i + 1);
		scanf("%d",a + i);
	}

	return a;
}

void in_mang(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%5d\t",*(a + i));
	printf("\n");
}

int sapxeptang(int *a, int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
          for(j = 0; j <= i; j++)
          {
                if(*(a + i) < *(a+ j))
                {
                    temp = *(a + i);
                    *(a + i) = *(a + j);
                    *(a + j) = temp;
                }
          }
    printf("\nmang sau khi sap xep la:\n");
    for(i = 0; i < n; i++)
    {
          printf("%d\t", *(a + i)); 

    }
    return 0;
}

int timso(int *a, int n)
{
    int left, right, x, mid;
    printf("\nnhap so can tim: %d\t", x);
    scanf("%5d", &x);
    do
    {
                 mid=(left+right)/2;
                 if(x==a[mid]) 
                 {
                               printf("so da nhap co trong day\n");
                               break;
                 }
                 else
                     if(x<a[mid]) right=mid-1;
                     else left=mid+1;
    } while (left<=right);
    if(left<=right) return mid;
    else printf("so da cho khong co trong day\n");
}
  
