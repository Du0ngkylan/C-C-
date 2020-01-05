/*
De bai:
	Co 3 phep bien doi xau:
		Chen vao vi tri i 1 ky tu C
		Thay the ky tu tai vi tri i bang ky tu C
		Xoa ky tu tai vi tri i
	Cho 2 xau ky tu X(X1..Xm) va Y(Y1..Yn)
	Chon cach bien doi X thanh Y sao cho so lan bien doi la it nhat
	
Thuat giai:
	Xay dung bang:
		F[i,j] = so phep bien doi it nhat khi bien doi X1..Xi thanh Y1..Yi
		Neu Xi = Yj <=> F[i,j] = F[i-1,j-1]			
		Neu khong, chon 1 trong 3 cach sao cho be nhat
			Chen Yj vao sau Xi -> F[i,j]=F[i,j-1]+1
			Thay the Xi bang Yj -> F[i,j]=F[i-1,j-1]+1
			Xoa Xi -> F[i,j]=F[i-1,j]+1
	
		F[i,0]=i
		F[0,j]=j
		So phep bien doi it nhat de bien X thanh Y la F[m,n]		
	
	Truy vet:
		Tai F[i,j]
		Neu Xi=Yj thi khong can phep bien doi nao, xet o F[i-1,j-1]
		Neu khong
			Neu F[i,j]=F[i,j-1]+1 -> dung phep chen Yj vao sau vi tri Xi
			Neu F[i,j]=F[i-1,j-1]+1 -> dung phep thay Xi bang Yj
			Neu F[i,j]=F[i-1,j] -> dung phep xoa Xi
		Toi khi den o (0, 0)
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

/*
Find min in 3 value
*/
int minIn3(int a1, int a2, int a3){
	int min = a1;
	if(min>a2)
		min=a2;
	if(min>a3)		
		min=a3;
	return min;		
}

/*
Insert letter c at position i of string a
*/
void insert(char *a, int i, char c){
	int k = strlen(a);
	while(k>i){
		a[k+1] = a[k];
		k--;
	}
	a[i+1] = c;
}

/*
Replace letter at position i of string a by letter c
*/
void replace(char *a, int i, char c){
	a[i] = c;
}

/*
Delete letter at position i of string a
*/
void del(char *a, int i){
	int k = strlen(a)-1;
	while(i<k){
		a[i] = a[i+1];
		i++;
	}
	a[k]=0;
}

void printTable(){
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			printf("%2d ", f[i*(n+1)+j]);
		}
		puts("");
	}
}

/*
Build solution table
*/
void buildSolution(){
	puts("\nBuilding solution table...");	
	/*Prepare*/	
	for(int i=0; i<=m; i++)
 		f[i*(n+1)] = i;
	for(int i=0; i<=n; i++) 		
		f[i] = i;
	
	/*Build solution table*/
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(x[i]==y[j])
		 		f[i*(n+1)+j] = f[(i-1)*(n+1)+j-1];
			else{
				f[i*(n+1)+j] = minIn3(f[i*(n+1)+j-1], f[(i-1)*(n+1)+j], f[(i-1)*(n+1)+j-1])+1;
			}		 		
		}
	}
	puts("Finish!");
}

/*
Handle information, backtracking, print result
*/
void showSolution(){
	printf("\nTransform process (minimum step: %d) :\n", f[m*(n+1)+n]);
	printf("Start: X = \"%s \", Y = \"%s \"\n", x, y);
	int i=m, j=n, count=0;
	while(i>0 || j>0){
//		printf("Go to %d, %d\n", i, j);
		if(x[i]==y[j]){
			if(i>0)
				i--;
			if(j>0)
				j--;
		} else{
			count++;
			printf("%3d. ", count);
			int k = f[i*(n+1)+j];
			if(i>0){					
				if(f[(i-1)*(n+1)+j] == k-1){
					printf("Delete '%c' at position %d: ", x[i], i);
					del(x, i);
					i--;
				}	
				else if(j>0){
					if(f[(i-1)*(n+1)+j-1] == k-1){
						printf("Replace '%c' at position %d by '%c': ",x[i], i, y[j]);	
						replace(x, i, y[j]);
						j--;
						i--;
					}
					else if(f[i*(n+1)+j-1] == k-1){
						printf("Insert '%c' after position %d: ", y[j], i);
						insert(x, i, y[j]);
						j--;	
					}
				}
			} else{
				printf("Insert '%c' after position %d: ", y[j], i);
				insert(x, i, y[j]);
				if(j>0)
					j--;
			}
			printf("X = \"%s \"\n", x);
		}
	}
}

/*
Main function
*/
int main(){
	printf("Please enter string want to transform (X) (length<100): ");
	gets(x);	
	m=strlen(x);	
	fflush(stdin);
	printf("Please enter string want to get (Y) (length<100): ");
	gets(y);
	n = strlen(y);
	
	/*Shift string to get easier in handling (make it "begin" from 1)*/
	shift(x);
	shift(y);

	f = (int *)calloc((n+1)*(m+1), sizeof(int));

	buildSolution();

	showSolution();
	
	puts("Done!");
	
	getch();
	return 0;
}

