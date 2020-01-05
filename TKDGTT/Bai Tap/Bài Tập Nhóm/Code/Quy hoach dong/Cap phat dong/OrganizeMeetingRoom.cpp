/*
De bai:
	Co n cuoc hop bat dau tu thoi diem Ai va ket thuc tai thoi diem Bi
	Cac cuoc hop dien ra trong 1 phong hop nen khong duoc trung thoi gian
	Chon cach sap xep sao cho to chuc duoc nhieu cuoc hop nhat
	
Thuat giai:
	Xay dung bang:
		Sap xep cac cuoc hop tang dan theo Bi (neu Bi = nhau, xep theo Ai)		
		L[i] = so cuoc hop co the to chuc nhieu nhat neu i la cuoc hop cuoi cung
		Neu chon duoc 1 day cac cuoc hop dai nhat co thoi diem ket thuc cuoi cung <= Ai thi L[i] = "max"{L[1], ..., L[i-1]}}+1
		Neu khong thi chi co the xep 1 minh cuoc hop do, L[i] = 1
		
		L[1] = 1
		So cuoc hop nhieu nhat co the to chuc la max{L[1], ..L[n]}		
		
	Truy vet:
		Xet L[i], cuoc hop to chuc truoc cuoc hop i la cuoc hop j <=> Bj<=Ai && L[j] = L[i]-1
		Xet toi khi L[i]=1		
*/

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

/*
Sort meetings ascending by ending time
*/
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

/*
Print data
*/
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

/*
Find max value in L array which satisfies b[j] <= a[i+1]
*/
int max(int i){
    int max = 0;
    for(int j=1; j<=i; j++){
        if((l[j] > max) && (b[j]<=a[i+1]))    
            max = l[j];
    }        
    return max;
}

/*
Build solution table
*/
void buildSolution(){
    puts("Building solution table...");
    
    l[1] = 1;
    
    for(int i=2; i<=n; i++){
        l[i] = max(i-1)+1;    
    }
    
    puts("Finish!");
}

/*
Handle information, backtracking, print result
*/
void showSolution(){
    int k=1;
    for(int i=2; i<=n; i++)
        if(l[i]>l[k])
            k=i;
    int num = l[k];
             
    /*Backtracking, store result in a stack*/
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
    
    /*Display*/
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

/*
Main function
*/
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
