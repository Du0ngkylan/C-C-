/*
De bai:
   Co n do vat.
   Moi do vat co trong luong Pi va gia tri Vi.
   Mot cai tui co gioi han trong luong W.
   Chi ra 1 cach chon cac do vat sao cho khong vuot qua gioi han ma tong gia tri la lon nhat.          
   
Thuat giai:
	Xay dung bang:
		C[i,j] = gia tri lon nhat co the chon tu cac do vat 1..i va gioi han trong luong la j   
		Neu khong chon do vat i, C[i,j] = C[i-1,j]
		Neu co chon do vat i, C[i,j] = C[i-1,j-p[i]] + v[i]
		-> C[i,j] = max {C[i-1,j], C[i-1,j-p[i]] + v[i]};
		
		C[i,0]=C[0,j]=0
		Gia tri lon nhat: C[n, w]
		
	Truy vet:
		C[i,j]=C[i-1,j] thi do vat i khong duoc chon, chuyen sang xet C[i-1,j]
		Nguoc lai thi do vat i co duoc chon, chuyen sang xet C[i-1,j-p[i]]
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *p, *v, w, n, *c;

/*
Generate randomly an array
*/
void generate(int *array, int start, int length){
     if(array==NULL)
      puts("Error! Array was not initialize!");
     else{
      int min, max;          
      printf("Minimum value = ");
      scanf("%d", &min);          
      printf("Maximum value = ");
      scanf("%d", &max);
      for(int i=start; i<start+length; i++){     
       array[i] = rand()%(max-min+1)+min;
      }
     } 
}

/*
Get weight from user
*/
void getWeight(){
	for(int i=1; i<=n; i++){
		printf("v[%d] = %d, p[%d] = ", i, v[i], i);             
		scanf("%d", p+i);                     
  	}
}

/*
Get value from user
*/
void getValue(){
	for(int i=1; i<=n; i++){
		printf("p[%d] = %d, v[%d] = ", i, p[i], i);             
		scanf("%d", v+i);                     
	}
}

/*
Get data from user
*/
void getData(){
	for(int i=1; i<=n; i++){
	 	printf("p[%d] = ", i);
	 	scanf("%d", p+i);
	 	printf("v[%d] = ", i);
	 	scanf("%d", v+i);
	}
}

/*
Print data
*/
void printData(){
	puts("\n+--------------------+");
	puts("|Data                |");	
	puts("+---+--------+-------+");
	puts("| # | Weight | Value |");
	puts("+---+--------+-------+");	
	for(int i=1; i<=n; i++){
		printf("| %-2d| %-6d | %-5d |\n", i, p[i], v[i]);	 
	}
	puts("+---+--------+-------+");	
}

/*
Print table solution
*/
void printTable(){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=w; j++)
			printf("%d ", c[i*(w+1)+j]);
		puts("");			
	}		
	puts("");
}


/*
Build solution table
*/
void buildSolution(){
	puts("\nBuilding solution table...");
	/*Prepare*/		
	for(int i=1; i<=n; i++){
		c[i*(w+1)] = 0;
	}
	for(int i=1; i<=w; i++){
		c[i] = 0;
	}

	/*Build table*/
	for(int i=1; i<=n; i++){
		for(int j=1; j<=w; j++){
			c[i*(w+1)+j] = c[(i-1)*(w+1)+j];
			if(p[i]<=j){
				if(c[i*(w+1)+j]<c[(i-1)*(w+1)+j-p[i]]+v[i])
		 			c[i*(w+1)+j] = c[(i-1)*(w+1)+j-p[i]]+v[i];
			}
		}
	}
	puts("Finish!");
}

/*
Handle information, backtracking, print result
*/
void showSolution(){
	if(c[n*(w+1)+w]>0){
		int i=n, j=w, k=0;
		puts("\n+--------------------+");
		puts("|Chosen objects      |");
		puts("+---+--------+-------+");
		puts("| # | Weight | Value |");
		puts("+---+--------+-------+");			
		while(i>0 && j>0){
			if(c[i*(w+1)+j]!=c[(i-1)*(w+1)+j]){
				printf("| %-2d| %-6d | %-5d |\n",i, p[i], v[i]);
				j -= p[i];
				k += p[i];
			}		
			i--;					
		}		 
		puts("+---+--------+-------+");			
		printf("|   | %-6d | %-5d |\n", k, c[n*(w+1)+w]);
		puts("+---+--------+-------+");	
		printf("(Limit weight is %d)\n", w);				
	} else puts("No solution!");
}

/*
Main function
*/
int main(){
	printf("Please enter number of objects: ");
	scanf("%d", &n);
	printf("Please enter limit weight: ");
	scanf("%d", &w);
	p = (int *)calloc(n+1, sizeof(int));
	v = (int *)calloc(n+1, sizeof(int));	
	c = (int *)calloc((n+1)*(w+1), sizeof(int));
	printf("Press '1' to generate randomly both weight and value of all objects.\n");
	printf("Press '2' to generate randomly weight of all objects and enter value by hand.\n");
	printf("Press '3' to generate randomly value of all objects and enter weight by hand.\n");
	printf("Press any key to enter both weight and value by hand.\n");
	char choice;
	fflush(stdin);
	scanf("%c", &choice);
	if(choice == '1'){
	 puts("Generate weight:");		
	 generate(p, 1, n);	
	 puts("Generate value:");	
	 generate(v, 1, n);
	} else if(choice == '2'){
	 puts("Generate weight:");				
	 generate(p, 1, n);
	 getValue();
	} else if(choice == '3'){
	 puts("Generate value:");			
	 generate(v, 1, n);
	 getWeight();
	} else
	 getData();
	
	printData();
	
	buildSolution();
	
	showSolution();	
	
	puts("Done!");
	
    getch();
    return 0;
}

/*
Notice:
	This is "KNAPSACK 0,1" problem means each object just have 1.
	Question:
		Understand why an object is not chosen many times?
	Answer:
		Note that if we want to choose object i, we only can do it in row i.
		If we want to choose i, we must compare C[i][..] with C[i-1][..]+Va.
		But in row i-1, we didn't choose i.
		So, suppose that we can choose i at this step, it will be the 1st time.				
*/
