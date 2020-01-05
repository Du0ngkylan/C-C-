#include<stdio.h>
#include<conio.h>
#define hs 50

int a[hs][hs],iBest[hs],jBest[hs];
int m,n,max;

void nhap(){
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			printf("Nhap a[%d][%d] =   ",i,j);
			scanf("%d",&a[i][j]);
	    }
	}
	
void in(){
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
		}
	printf("\n");
	}
	
void duong_di(int i, int j){
	int h,l,k;
	if(i==m & j==n){
		if(a[i][j]>max){
			max = a[i][j];
			for(h=1;h<=i;h++)
				for(l=1;l<=j;l++)
					for(k=2;k<=(max+1);k++){
						if(a[h][l]==k){
							iBest[k] = h;
							jBest[k] = l;
							}
					}
		}
	}
    if(a[i-1][j]==1 && i>1){
		a[i-1][j] = a[i][j] + 1;
		duong_di(i-1,j);
		a[i-1][j] = 1;
		}
	if(a[i][j+1] == 1 && j<m){
		a[i][j+1] = a[i][j] + 1;
		duong_di(i,j+1);
		a[i][j+1] = 1;
		}
	if(a[i+1][j]==1 && i<m){
		a[i+1][j] = a[i][j] + 1;
		duong_di(i+1,j);
		a[i+1][j] = 1;
		}
}

int main(){
	int k;
	printf("Nhap so hang m=  ");
	scanf("%d",&m);
	printf("Nhap so cot n=   ");
	scanf("%d",&n);
	nhap();
	printf("Bang so:\n");
	in();
	max = 0;
	a[1][1] = 2;
	duong_di(1,1);
	if(max>0){
    	printf("Do dai duong di lon nhat %d qua:  \n",max-1);
    	for(k=2;k<max;k++){
    		printf("a[%d][%d]--->",iBest[k],jBest[k]);
    		}
    	printf("a[%d][%d].\n",m,n);
        } 
	else printf("Khong ton tai duong di.\n");
	getch();
	return 0;
	}
