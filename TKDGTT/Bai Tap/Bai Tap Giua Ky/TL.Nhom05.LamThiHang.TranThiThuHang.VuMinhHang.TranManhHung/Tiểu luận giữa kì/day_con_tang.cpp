#include<stdio.h>
#include<conio.h>

void nhap(int a[], int n){
	int i;
	for(i=1;i<=n;i++){
		printf("Nhap a[%d]=   ",i);
		scanf("%d",&a[i]);
	    }
	}
	
void in(int a[], int n){
	int i;
	for(i=1;i<=n;i++)
		printf("%4d",a[i]);
	printf("\n");
	}
	
int tang(int a[], int n, int i){
	int k;
	k = 1;
	while(a[i]<=a[i+1] && i<n){
		k++;
		i++;
		}
	return k;
	}
	
int main(){
	int a[50],n,i,j,max;
	printf("Nhap do dai day n=  ");
	scanf("%d",&n);
	nhap(a,n);
	printf("Day da nhap: \n");
	in(a,n);
	printf("Day con lien tiep tang dai nhat: \n");
	max = 0;
	for(i=1;i<=n;i++)
		if(tang(a,n,i)>max)  max = tang(a,n,i);
	for(i=1;i<=n;i++)
		if(tang(a,n,i)==max){
			for(j=i;j<(i+max);j++){
				printf("%4d",a[j]);
			}
			printf("\n");
		}
	getch();
	return 0;
	}
