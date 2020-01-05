#include<conio.h>
#include<stdio.h>
#include<iostream.h>

int a[100],n,m;

void nhap(){
	cout<<"\nNhap so phan tu cua day : N = ";
	cin>>n;
	cout<<"\nNhap day so :\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	cout<<"\nSo phan tu can chuyen la : ";
	cin>>m;
}

void exchange(int b[100],int i,int j,int k){
	for(int t=0;t<k;t++){
		int c=b[i+t];
		b[i+t]=b[j+t];
		b[j+t]=c;
	}
}

void transpose(int a[100],int n, int m){
	int i=m,j=n-m;
	while(i!=j)
		if(i>j){
			exchange(a,m-i,m,j);
			i=i-j;
		}
		else {
			j=j-i;
			exchange(a,m-i,m+j,i);
		}
	exchange(a,m-i,m,i);
}

int main()
{
	nhap();
	if(m>=n) cout <<"\nKhong doi\n";
	else 
	{
		transpose(a,n,m);
		cout<<"\n\nIn lai day da dao \n";
		for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
		cout<<"\n";
	}
	getch();
	return 0;
}
