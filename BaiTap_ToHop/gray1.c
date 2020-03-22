/*
  sinh cac tap con cua tap n phan tu bang thuat toan gray (de quy)
*/

#include<stdio.h>
#include<conio.h>
#include "tapCon.h"

//n = do dai chuoi nhi phan
//k = so day nhi phan ban dau
void copyAndRevers(int a[][1000], int n, int k){
    int i, j;
    for(i = 1; i<=k; i++)
        for(j = 1; j<=n; j++)
            a[k+i][j] = a[k-i+1][j];
}

void gray1(int a[][1000], int n){
    int i, j, k;
    k = 1;
    for(i = 1; i<=n; i++){
        copyAndRevers(a, i, k);
        for(j = 1; j<=k; j++)
            a[j][i] = 0;
        for(j = k+1; j<=2*k; j++)
            a[j][i] = 1;
        k = k*2;
    }
}

int main(){
	int i, j, n;
	int a[100][1000];
	
	n = 10;
	for(i = 1; i<=n; i++)
		for(j = 1; j<=n; j++)
        	a[i][j] = 0;
    
    gray1(a, n);
    
    for(i = 1; i<=power(2, n); i++){
		printf("%d:", i);
		for(j = 1; j<=n; j++)
    		printf("%d ", a[i][j]);
    	puts("");
	}
	
    getch();
    return 0;
}
