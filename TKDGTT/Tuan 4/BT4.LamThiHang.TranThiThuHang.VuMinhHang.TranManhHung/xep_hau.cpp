#include<stdio.h>
#include<conio.h>
int dem = 0;
void printResult( int x[]){
	int i;
	for(i=1;i<=8;i++)
		printf("%d",x[i]);
	printf("\n");
	}

void Try(int i, int x[], int cot[], int dcc[], int dcp[]){
	int j;
	for(j=1;j<=8;j++){
		if((cot[j]==0)&&(dcc[i-j]==0)&&(dcp[i+j]==0)){
			x[i] = j;
			cot[j] = 1;
			dcc[i-j] = 1;
			dcp[i+j] = 1;
			if(i==8){
				printf("%d\n",dem++);
				printResult(x);
				}
			else Try(i+1,x,cot,dcc,dcp);
			cot[j] = 0;
			dcc[i-j] = 0;
			dcp[i+j] = 0;
			}
		}
	}
	
int main(){
	int x[8],cot[8],dcc[17],dcp[17];
	int i,dem;
	dem = 0;
	for(i=0;i<8;i++){
		cot[i] = 0;
		}
	for(i=0;i<20;i++){
		dcc[i] = 0;
		dcp[i] = 0;
		}
	printf("Cac cach xep quan hau: \n");
	Try(1,x,cot,dcc,dcp);
	
	getch();
	return 0;
	}
