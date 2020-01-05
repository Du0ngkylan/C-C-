/*
Bai 1.3:
Liet ke day nhi phan co do dai n.

Phan tich:
     + Day nhi phan (x1 x2 ... xn) trong do xi = 0 or 1
     + Dung thuat giai Try(i) de sinh gia tri xi
     + Neu i = n thi in gia tri nghiem, nguoc lai sinh tiep xi + 1 bang Try(i+1)
*/

#include<stdio.h>
#include<conio.h>

/*Khai bao chung*/
int x[100], n;

/*In day so nhi phan*/
void printResult()
{
	int  i;
	printf("\n");
	for(i = 1; i <= n; i++)
		printf(" %d", x[i]);			
}

/*Sinh so nhi phan*/
void Try(int i)
{
	int v;
    for(v = 0; v <= 1; v++)//v nhan gia tri 0 hoac 1
	{
		x[i] = v;		  //Gan x[i] bang cac gia tri co the co(0 hoac 1)
		if(i == n) 	      //Neu i == n thi co 1 nghiem thoa man 
			printResult();//in nghiem
		else 
			Try(i+1);     //sinh thanh phan tiep theo cua so nhi phan neu i < n
    }
}

/*Chuong trinh chinh*/
main()
{
	printf("Nhap vao do dai cua day nhi phan: n = ");
	scanf("%d", &n);
	
	printf("\nCac so nhi phan co do dai %d la: ", n);
	Try(1);
	
	getch();	
}
