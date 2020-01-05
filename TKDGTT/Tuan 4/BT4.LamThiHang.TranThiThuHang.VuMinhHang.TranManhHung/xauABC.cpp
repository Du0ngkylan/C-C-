#include<stdio.h>
#include<conio.h>

char x[100],xBest[100];
int n,cmin;

void khoi_tao(){
	int i;
	for(i=0;i<n;i++){
		x[i] = 0;
		xBest[i] = 0;
		}
	x[0] = 65;
	cmin = n;
	}

int same(int i, int l){
	int k;
	for(k=0;k<l;k++)
		if(x[i-k] != x[i-l-k])
			return 0;
		return 1;
	}
	
int kiem_tra(int i){
	int k;
	for(k=1;k<=(i+1)/2;k++)
		if(same(i,k))
			return 0;
		return 1;
	}
	
void Try(int i, int s){
	int v,j,t;
	for(v='A';v<='C';v++){
		x[i] = v;
		if(kiem_tra(i)){
			t = (v=='C')?s+1:s;
			if((t+(n-i)/4)<cmin){
				if(i==(n-1)){
					cmin = t;
					for(j=0;j<n;j++)
						xBest[j] = x[j];
				}else Try(i+1,t);
			}
		}
	}
}
	
int main(){
	int i;
	printf("Nhap n =  ");
	scanf("%d",&n);
	khoi_tao();
	Try(1,0);
	for(i=0;i<n;i++)
		printf("%c",xBest[i]);
	printf("\nSo ki tu C: %d",cmin);
	getch();
	return 0;
	}
