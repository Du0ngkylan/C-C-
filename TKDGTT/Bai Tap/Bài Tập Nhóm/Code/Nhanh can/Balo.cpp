#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <fstream.h>
int n;
double V=0,M,v[100],w[100];
double s[100]; // mang luu tong gia tri cac vat tu vat thu i den n
int x[100],y[100];
void doctep(char * tep)// lay du lieu cua n,M va cac gia tri aij tu file ban dau
{
    ifstream f(tep,ios::in);
    int t; 
    if(!f)
    {     
          cerr<< "Loi mo tep" ; getch(); exit(0);  
    }
    f >> n >> M;    //lay gia tri n,M
    cout<<"Khoi luong lon nhat la:"<<M;
    for(t=1;t<=n;t++)// vong lap de lay gia tri cua moi cap (Xi,Yi) tuong ung
        {
            f >> v[t] >> w[t];
        }
    cout<<"\nDo vat\tGia tri\tKhoi luong\n";
    for(t=1;t<=n;t++)
               cout<<t<<"\t" << v[t] <<"\t"<< w[t]<<"\n";    
}
bool ktW(double m, int i) {
		for (int j = i + 1; j <= n; j++) {
			if (m + w[j] < M) {
				return true;
			}
		}
		return false;
}
bool ktV(int i, double value) {
		double sum = s[i] + value;
		if (sum < V) {
			return false;
		} else {
			return true;
		}
}
void xep(int i, double m, double value) {
		for (int j = i; j <= n; j++) {
			if ((m + w[j]) <= M && (x[j] == 0) && ktV(j,value)) {   
				x[j] = 1;
				if (ktW(m, j) == false) {
					if (value + v[j] > V) {
						V = value + v[j];
						for (int k = 1; k <= n; k++) {
							y[k] = x[k];
						}
					}
				} else {
					xep(j, m + w[j], value + v[j]);
				}
				x[j] = 0;
			}
		}
}
void print() {
		cout<<"\n";
        for (int i = 1; i <= n; i++) {
			if (y[i] == 1) {
				cout<<i <<"     ";
			}
		}
}
int main(){
        doctep("data.txt");
        for(int i=1;i<=n;i++){
                  for(int j=i;j<=n;j++)
                          s[i]+=v[i];   // Mang luu tong gia tri tu do vat thu i -> n                  
                  
        }        
        xep(1,0,0);
        if (V > 0) {
			cout<<"Cach xep voi tong gia tri lon nhat la:" << V;
			print();
		} else {
			cout<<"Khong co cach xep nao thoa man!";
        }
        getch();      
}
