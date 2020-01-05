//Bai Toan: Nguoi Ban Hang

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100				
#define VoCung 10000	

int n,TongChiPhi;		
int a[MAX][MAX];		
int flag[MAX];		//mang danh dau thanh pho da den hay chua.
int HanhTrinh[MAX];		

void Input(){
	FILE *f;
	f = fopen("data2.txt","r");
	if(f != NULL){
		int i,j;
		fscanf(f,"%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(f,"%d",&a[i][j]);
		fclose(f);
	}
	else{
		printf("\nLoi Mo Tep!");
		getch();
		exit(1);
	}
}
//Ham khoi tao ban dau,cac thanh pho deu chua den.
void KhoiTao(){
	int i;
	for(i=0;i<n;i++)
		flag[i] = 0;
}

//Tim thanh pho tiep theo de di den tu thanh pho i voi chi phi thap nhat.
int TimCityNext(int v){
	int u;						//chi so de duyet tat ca cac thanh pho.
	int min = VoCung;			
	int j;						//bien luu lai thanh pho tiep theo tu u den v ma chi phi nho nhat.
	for(u=0;u<n;u++)
		if(flag[u] == 0 && a[u][v] < min && a[u][v] != 0){
			min = a[u][v];
			j = u;
		}
	return j;
}

//In ra lo trinh 
void LoTrinh(){
	int i;
	printf("\nLo Trinh : ");
	for(i=0;i<=n;i++)
		printf("%5d",HanhTrinh[i]+1);
}

void Greedy(){
	TongChiPhi = 0;		
	flag[0] = 1;		//Xuat phat tu dinh 0 nen danh dau la dinh 0 da den.
	HanhTrinh[0] = 0;	//Dinh dau tien trong hanh trinh la dinh 0.
	HanhTrinh[n] = 0;	//Danh dau dinh cuoi cung can den la dinh 0.
	int i=0;			//i: thanh pho dang dung,xuat phat tu dinh 0.
	int dem = 1;		//Danh dau thanh pho tiep theo den.
	while(dem <n){									//Neu chua danh dau duoc n-1 thanh pho can den
		int j = TimCityNext(i);						//j: dinh tiep theo se den.
		HanhTrinh[dem] = j;							//Danh dau thanh pho den tiep theo la j
		flag[j] = 1;								//Danh dau dinh j da den.
		TongChiPhi = TongChiPhi + a[i][j];			//Cong don vao tong chi phi.
		i = j;										//Lai xuat phat tu dinh i de di tiep
		dem ++;										//Tang chi so danh dau len 1
	}
	TongChiPhi = TongChiPhi + a[i][0];
	printf("\nChi phi cua hanh trinh la: %d",TongChiPhi);
	LoTrinh();
}

int main(){
	Input();
	KhoiTao();
	Greedy();
    getch();
    return 0;
}
