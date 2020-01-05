/*
De bai:
    Cho 2 xau X(len=M), Y(len=N)
    Tim day con chung dai nhat cua 2 xau nay.

Thuat giai:
    Xay dung bang phuong an:
        Goi F[i, j] la do dai day con dai nhat neu xet X1...Xi va Y1...Yj
        Neu Xi=Yj thi F[i, j] = F[i-1, j-1]+1
        Neu khong thi chon F = max {F[i, j-1], F[i-1, j]}
        
    Co so:
        F[0, j] = F[i, 0] = 0
        
    Truy vet:
        Ket qua cua bai toan la F[M, N]  
        Xet F[i, j]
            Neu Xi=Yj thi luu Xi vao ngan xep
            Neu ko, chon 1 trong 2 o F[i-1, j] hoac F[i, j-1] co gia tri bang
        Xet toi khi i hoac j = 0            
        
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char x[200],y[200];
int m,n, *f;

/*
Shift string to right by 1
*/
void shift(char *a){
	int k = strlen(a);
	while(k>0){
		a[k] = a[k-1];		
		k--;
	}	
	a[0] = ' ';
}

void buildSolution(){
    /*Prepare*/        
    for(int i=0; i<=m; i++)
        f[i*(n+1)]=0;
    for(int j=0; j<=n; j++)
        f[j] = 0;
    
    /*Build solution table*/        
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i] == y[j])
                f[i*(n+1)+j] = f[(i-1)*(n+1)+j-1] + 1;
            else{
                if(f[i*(n+1)+j-1] > f[(i-1)*(n+1)+j])    
                    f[i*(n+1)+j] = f[i*(n+1)+j-1];
                else
                    f[i*(n+1)+j] = f[(i-1)*(n+1)+j];
            }                
        }    
    }
}

void showSolution(){
    printf("Max length same subsequence: %d\n", f[m*(n+1)+n]);
    char *stack;
    stack = (char *)calloc(f[m*(n+1)+n], sizeof(char));
    int i=m, j=n, t=0;
    while(i>0 && j>0){
        if(x[i] == y[j]){    
            stack[t++] = x[i];
            i--;
            j--;  
        } else if(f[i*(n+1)+j] == f[i*(n+1)+j-1])
            j--;
        else
            i--;            
    }
    
    puts("Subsequence:");
    while(t>=0){
        printf("%c", stack[t]);
        t--;
    }
    puts("\n");
}

int main(){
    printf("Please enter the first string (X) (length<100): ");
	gets(x);	
	m=strlen(x);	
	fflush(stdin);
	printf("Please enter the second string (Y) (length<100): ");
	gets(y);
	n = strlen(y);
	
	/*Shift string to get easier in handling (make it "begin" from 1)*/
	shift(x);
	shift(y);

	f = (int *)calloc((n+1)*(m+1), sizeof(int));

    buildSolution();

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++)
            printf("%3d ", f[i*(n+1)+j]);    
        puts("");            
    }

    showSolution();

    puts("Done!");
    getch();
    return 0;
}
