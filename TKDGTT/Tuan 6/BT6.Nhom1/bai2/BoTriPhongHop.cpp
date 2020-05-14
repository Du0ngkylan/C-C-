/*
  Name:  Bo Tri Phong Tro
  Author: Nhom 12
  Date: 23/04/12 06:43
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int n, a[50], b[50], max[50], kq[50], x[50];

void DocDL()
{
    FILE *f;
    f = fopen("PhongHop.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    
    fscanf(f, "%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        fscanf(f, "%d", &a[i]);
        fscanf(f, "%d", &b[i]);
    }
    fclose(f);
}

void InDL()
{
    int i;
    printf("\n----------------------------------------\n");
    printf("\n--------------CAC PHONG HOP-------------\n");
    printf("So phong hop :%d.\n",n);
    for (int i = 1;i <= n;i ++)
    {
       printf("%d)   %d     %d\n",i,a[i],b[i]);    
    }     
    printf("\n----------------------------------------\n");
    printf("\n\n");
}

void swap(int *a, int*b){
	int temp;
    temp = *a;
	*a =  *b;
	*b = temp;
}

/*
    Sap xep phong hop : 
    - Theo chieu tang B[i]
    - Neu B[i] bang nhau ta se so sanh A[i]
*/

void SapXep()
{
	for(int i=1; i<n; i++)
    {
		for(int j=i+1; j<=n; j++)
        {
			if(b[j] < b[i])
            {
				swap(b+i, b+j);
				swap(a+i, a+j);
			} 
            else if(b[i] == b[j])
            {
				if(a[j] < a[i])
                {
					swap(b+i, b+j);
					swap(a+i, a+j);
				}
			}
		}
	}
}


/*
     Tim so phong hop lon nhat co the bo tri 
     k = max{max[1], ....., max[n]}
     max[i] la so phong tro lon nhat co the bo tri neu i la phong hop cuoi cung
*/

int TimMax(int i)
{
    int maxTemp = 0;
    for(int j=1; j<=i; j++)
    {
        if((max[j] > maxTemp) && (b[j]<=a[i+1]))    
            maxTemp = max[j];
    }        
    return maxTemp;
}


int PhongHopMax()
{
    int csMaxRoom = 1,maxTemp = 1;
    max[1] = 1;
    for(int i=2; i<=n; i++){
        max[i] = TimMax(i-1)+1;  
    }
    
    for (int j = 1;j <= n;j ++)
    {
        if (max[j] > maxTemp)
        {
          maxTemp = max[j];
          csMaxRoom = j;          
        }
        
    }
    return csMaxRoom;
}

/*
     Bo tri phong hop sao cho duoc nhieu
     phong hop nhat
*/

void BoTri()
{
   int csMaxRoom = PhongHopMax();
   int numMaxRoom = max[csMaxRoom];
             
   int t = numMaxRoom - 1;
   /*
       numMaxRoom  la so phong hop lon nhat co the bo tri
       x[i] la chi so phong thu i trong numMaxRoom phong
   */
    while(max[csMaxRoom] != 1 && t>=0)
    {
        x[t] = csMaxRoom;      
        t--;
        for(int i = csMaxRoom-1; i>0; i--)
        {
            if(max[i]+1 == max[csMaxRoom] && b[i]<=a[csMaxRoom])
            {
                csMaxRoom = i;
                break;         
            }       
        }
    }
    x[t] = csMaxRoom;
    
    printf("\n----------------------------------------\n");
    printf("\n----------CACH BO TRI PHONG HOP---------\n");
    printf("So phong hop lon nhat co the bo tri : %d\n\n",numMaxRoom);
    for (int i = 0;i <= numMaxRoom-1;i ++)
    {
       printf("%d)   %d     %d\n",i+1,a[x[i]],b[x[i]]);    
    }     
    printf("\n----------------------------------------\n");
}


int main()
{
    DocDL();
    printf("Du lieu dau vao : \n");
    InDL();
    
    printf("Du lieu sau khi sap xep :\n");
    SapXep();
    InDL();
    
    BoTri();
    getch();
}
