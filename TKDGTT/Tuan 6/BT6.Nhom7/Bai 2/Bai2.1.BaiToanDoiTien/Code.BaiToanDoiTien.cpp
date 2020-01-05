/*
Bai 2.1: Bai toan doi tien 
Phuong phap: Quy hoach dong
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define VC 10000
#define HS 100

int n, m, c[HS][HS], p[HS];
//n-so loai tien
//m-so tien can doi

 
void nhap(){
	int i;
	for(i=1; i<=n; i++){
		printf("D[%d] = ", i);
		scanf("%d", &p[i]);	
	}
}

void in(){
	int i;
	for(i=1; i<=n; i++)
		printf("%d  ", p[i]);	
}

void bangPhuongAn(){
	int i, j;
	//co so quy hoach dong
	for(i=0; i<=n; i++)	
		c[i][0] = 0;
	for(j=0; j<=m; j++)
		c[0][j] = VC;
		
	for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            c[i][j] = c[i-1][j];
            if(p[i] <= j){
                if(c[i][j-p[i]]+1 < c[i-1][j]){    
                    c[i][j]= c[i][j-p[i]]+1;
                }
            }
        }        
    }    
}

void truyVet(){
    int i = n, j = m, count = 0;
    if(c[n][m] < VC){
		printf("\n\nTruy vet tim nghiem:\n");
        while(j>0){
            if(c[i][j] == c[i-1][j]){
                if(count > 0)
                 	printf("\n%d  |  %d\n", p[i], count);
				count = 0; 
			i--;
            } 
            else
            {
				count++;
				j -= p[i];	
			}
        }
        
        if(count > 0)
        	printf("\n%d  |  %d\n", p[i], count);
        printf("\nSo to tien it nhat la: %d\n", c[n][m]);
    } 
    else printf("\nKhong doi duoc!");
    
}

/*Chuong trinh chinh*/
main(){
	printf("\nNhap so tien can doi m = ");
	scanf("%d", &m);
	
	printf("\nNhap so loai tien n = ");
	scanf("%d", &n);
	nhap();
	
	printf("\nMenh gia cua %d loai tien la:\n", n);
	in();
	
	bangPhuongAn();
	
	truyVet();
	
	getch();	
}
