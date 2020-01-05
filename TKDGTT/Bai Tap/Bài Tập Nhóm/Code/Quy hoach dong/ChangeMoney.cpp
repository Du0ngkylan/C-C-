/*
De bai:
	Trong ngan hang co n loai tien menh gia D1...Dn
	Doi m don vi tien sao cho so to tien la it nhat
	
Thuat giai:
	Xay dung bang:
		C[i,j] = so to tien it nhat khi doi j don vi tien chi dung cac loai tien menh gia D1..Di
		Neu khi doi j don vi, dung them 1 to tien i menh gia Di thi C[i,j] = C[i,j-Di]+1
		Neu khong dung thi C[i,j] = C[i-1,j]
		
		C[i,0]=0
		C[0,j]=INFINITY
		So to tien nho nhat la C[n,m]
		
	Truy vet:
		C[i,j]=C[i-1,j]	thi khong dung to tien menh gia i
		Nguoc lai la co dung.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INFINITY 37800

int *d, n, m, *c;

/*
Enter value of each elements in the array
*/
void input(){
	for(int i=1; i<=n; i++){
		printf("D[%d] = ", i);             
		scanf("%d", d+i);                     
  	}
}

/*
Print an array
*/
void printArray(int *array, int start, int length){
    for(int i=start;i<start+length; i++){
     printf("%d ", array[i]);                   
    }        
    puts("");
}

/*
Build solution table
*/
void buildSolution(){
	puts("\nBuilding solution table...");
	/*Prepare*/
	for(int i=0; i<=m; i++)
		c[i] = INFINITY;
	for(int i=0; i<=n; i++)
		c[i*(m+1)] = 0;
		
	/*Build solution table*/					 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			c[i*(m+1)+j] = c[(i-1)*(m+1)+j];
			if(d[i]<=j){
				if(c[i*(m+1)+j-d[i]]+1 < c[(i-1)*(m+1)+j])
				 c[i*(m+1)+j] = c[i*(m+1)+j-d[i]]+1;
			}
		}		
	}
	puts("Finish!");	
}

/*
Handle information, backtracking, print result
*/
void showSolution(){
	if(c[n*(m+1)+m] < INFINITY){
		puts("\n+-------+----------+");
		puts("| Value | Quantity |");
		puts("+-------+----------+");		
		int i=n, j=m, count=0;
		while(j>0){
			if(c[i*(m+1)+j] == c[(i-1)*(m+1)+j]){
				if(count>0)
			 		printf("| %-5d | %-8d |\n", d[i], count);				
				count = 0;
				i--;
			} else{
				count++;				
				j -= d[i];
			}
		}	
		if(count>0)
			printf("| %-5d | %-8d |\n", d[i], count);		
		puts("+-------+----------+");
		printf("|       | %-8d |\n",c[n*(m+1)+m]);
		puts("+-------+----------+");
	} else
		puts("No solution!");
}

int main(){
    printf("Please enter amount of money want to change: ");
    scanf("%d",&m);	
    printf("Please enter types of money: ");
    scanf("%d", &n);
    d = (int *)calloc(n+1, sizeof(int));
	c = (int *)calloc((n+1)*(m+1), sizeof(int));
	input();
    
    puts("\nTypes of money:");
    printArray(d, 1, n);
    
    buildSolution();
    
    showSolution();    

	puts("\nDone!");
	
	getch();
	return 0;
}
