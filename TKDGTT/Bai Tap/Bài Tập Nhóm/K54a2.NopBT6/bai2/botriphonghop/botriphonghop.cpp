
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *a, *b, *l, n, *x;
bool input = true;

void swap(int *x, int*y){
	int t=*x;
	*x = *y;
	*y = t;
}
void sort(){
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(b[j] < b[i]){
				swap(b+i, b+j);
				swap(a+i, a+j);
			} else if(b[i] == b[j]){
				if(a[j] < a[i]){
					swap(b+i, b+j);
					swap(a+i, a+j);
				}
			}
		}
	}
}

void printData(){
	puts("\n+-------------------+");
	puts("|Meeting time       |");	
	puts("+---+-------+-------+");
	puts("| # | Begin |  End  |");
	puts("+---+-------+-------+");	
	for(int i=1; i<=n; i++){
		printf("| %-2d| %-5d | %-5d |\n", i, a[i], b[i]);	 
	}
	puts("+---+-------+-------+");	
}

int max(int i){
    int max = 0;
    for(int j=1; j<=i; j++){
        if((l[j] > max) && (b[j]<=a[i+1]))    
            max = l[j];
    }        
    return max;
}

void buildSolution(){
    puts("Building solution table...");
    
    l[1] = 1;
    
    for(int i=2; i<=n; i++){
        l[i] = max(i-1)+1;    
    }
    
    puts("Finish!");
}

void showSolution(){
    int k=1;
    for(int i=2; i<=n; i++)
        if(l[i]>l[k])
            k=i;
    int num = l[k];
    x = (int *)calloc(num, sizeof(int));
    int t = num - 1;
    while(l[k] != 1 && t>=0){
        x[t] = k;      
        t--;
        for(int i = k-1; i>0; i--){
            if(l[i]+1 == l[k] && b[i]<=a[k]){
                k = i;
                break;         
            }       
        }
    }
    x[t] = k;
    printf("\nMax meeting can be organized: %d\n", num);
	puts("+-------------------+");
	puts("|Solution           |");	
	puts("+---+-------+-------+");
	puts("| # | Begin |  End  |");
	puts("+---+-------+-------+");	
	for(int i=0; i<num; i++){
		printf("| %-2d| %-5d | %-5d |\n", i+1, a[x[i]], b[x[i]]);	 
	}
	puts("+---+-------+-------+");	
}
int main(){
	printf("Please enter number of meetings: ");
	scanf("%d", &n);
	a = (int *)calloc(n+1, sizeof(int));
	b = (int *)calloc(n+1, sizeof(int));
	puts("Please enter beginning(A) and ending(B) time of each meeting.");
	for(int i=1; i<=n; i++){
		printf("A[%d] = ", i);
		scanf("%d", a+i);
		printf("B[%d] = ", i);
		scanf("%d", b+i);
		if(b[i]<a[i]){
            input = false;
            break;    
        }
	}
		
	if(input == true){
    	l = (int *)calloc(n+1, sizeof(int));
	   
    	sort();
        printData();
	
        buildSolution();

        showSolution();
	}
	else
	   puts("Invalid data! (A meeting cannot end before beginning)");
	
	puts("Done!");
	
	getch();
	return 0;
}
