
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define OX7FFFFFFF 37800

int d[100], n, m, c[100][100];
void nhap()
{
     int i;
     printf("nhap luong tien can chuyen = ");
     scanf("%d",&m);
     
     printf("nhap loai tien = ");
     scanf("%d",&n);
     for(i=1;i<=n;i++){
                       printf("D[%d] = ",i);
                       scanf("%d",&d[i]);
                       }
}



void bangphuongan(){
     int i,j;
	for( i=0; i<=m; i++)
		c[0][i] = OX7FFFFFFF;
	for( i=0; i<=n; i++)
		c[i][0] = 0;					 
	for( i=1; i<=n; i++){
		for( j=1; j<=m; j++){
			c[i][j] = c[i-1][j];
			if(d[i]<=j){
				if((c[i][j - d[i]]+1) < c[i][j])
				 c[i][j] = c[i][j -d[i]]+1;
			}
		}		
    }	
}

void truyVet(){
	if(c[n][m] < OX7FFFFFFF){
		printf("|LOAI TIEN | SO LUONG TIEN \n");		
		int i=n, j=m, count=0;
		while(j>0){
			if(c[i][j] == c[i-1][j]){
				if(count>0)
			 		printf("| %3d | %3d \n", d[i], count);				
				count = 0;
				i--;
			} else{
				count++;				
				j -= d[i];
			}
		}	
		if(count>0)
			printf("| %3d | %3d \n", d[i], count);		
		printf("so to tien it nhat  = %3d \n",c[n][m]);
	} else
		printf("khong co phuong an nao phu hop");
}

int main(){
    nhap();
    bangphuongan();
    truyVet();
   	getch();
	return 0;
}
