/*
De bai:
   Cho 1 day cac so nguyen
   1 day con la 1 tap hop cac phan tu giu dung thu tu trong day
   Chi ra 1 cach chon day con tang dai nhat
   
Thuat giai:
	Xay dung bang:
		L[i] = do dai max khi chon i vao day dai nhat truoc do
		Neu chon duoc 1 day co san voi phan tu cuoi cung la aj ma aj<ai thi Li = Lj+1;
		Neu khong chon duoc day nao thoa man thi Li = 1   
		
		L[1] = 1
		Do dai lon nhat: gia tri lon nhat trong cac L[i]
		
	Truy vet:
		Xet L[i], phan tu dung truoc ai la aj <=> L[j] = L[i]-1 && aj < ai
		Xet toi khi L[i] = 1.			
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *a=NULL, n, *l, *x;

/*
Generate randomly an array
*/
void generate(){
     if(a==NULL)
      puts("Error! Array was not initialize!");
     else{
      int min, max;          
      printf("Minimum value = ");
      scanf("%d", &min);          
      printf("Maximum value = ");
      scanf("%d", &max);		
      for(int i=1; i<=n; i++){  
        a[i] = rand()%(max-min+1)+min;
      }
     } 
}

/*
Enter value of each elements in the array
*/
void input(){
     for(int i=1; i<=n; i++){
      printf("a[%d] = ", i);             
      scanf("%d", a+i);                     
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
     l[1] = 1;
     for(int i=2; i<=n; i++){
      l[i] = 0;
      for(int j=i-1; j>0; j--){
       if((l[i] < l[j]) && (a[j] < a[i]))        
        l[i] = l[j];
      }
      l[i] += 1;
     }
}

/*
Handle information, backtracking, print result
*/
void showSolution(){
     /*Find max length*/
     int k = n;
     for(int i=n-1; i>0; i--){
      if(l[k] < l[i])
       k = i;        
     }    
     printf("\nLongest ascending subsequence length: %d\nElements: ", l[k]);
     int max = l[k];
     
     /*Backtracking, store result in a stack*/
     x = (int *)calloc(l[k], sizeof(int));
     int t = l[k] - 1;
     while(l[k] != 1 && t>=0){
      x[t] = a[k];      
      t--;
      for(int i = k-1; i>0; i--){
       if(l[i]+1 == l[k] && a[i] < a[k]){
        k = i;
        break;         
       }       
      }
     }
     x[t] = a[k];
     
     /*Print result*/
     printArray(x, 0, max);
}

/*
Main function
*/
int main(){
    printf("Please enter number of elements in the array: ");
    scanf("%d", &n);
    a = (int *)calloc(n+1, sizeof(int));
    l = (int *)calloc(n+1, sizeof(int));    
    printf("Do you want to generate randomly value of each element?\n");
    printf("\tPress 'Y' to auto generate randomly.\n");
    printf("\tPress any key to enter each element in the array.\n");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y')
     generate();
    else
     input();   
    
    puts("Array:");
    printArray(a, 1, n);
    
    buildSolution();
    
    showSolution();
    
    getch();
    return 0;
}
