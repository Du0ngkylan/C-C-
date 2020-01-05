#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int s[100],f[100],n,L[100],Q[100],Lmax,Imax;

void nhap()
{
     FILE *k;
     int t,i;
     k=fopen("phonglamviec.txt","r");
     if(!t)
     {
        puts("Loi mo tep: ");
        getch();
        exit(0);
     }
     fscanf(k,"%d",&n);
     for(i=1;i<=n;i++)
     {
        fscanf(k,"%d  %d",&s[i],&f[i]);
     }
     fclose(k);
}

void in()
{
     int i;
     printf("\nSo cac hoat dong la:   %d",n);
     printf("\nCac hoat dong cu the la: ");
     for(i=1;i<=n;i++)
     {
        printf("\nHoat dong %d bat dau tu %d den %d",i,s[i],f[i]);
     }
}
     

void swap(int *m,int *n)
{
     int temp;
     temp=*m;
     *m=*n;
     *n=temp;
}

void Sapxep(){
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(f[j] < f[i]){
				swap(f+i, f+j);
				swap(s+i, s+j);
			} else if(f[i] == f[j]){
				if(s[j] < s[i]){
					swap(f+i, f+j);
					swap(s+i, s+j);
				}
			}
		}
	}
}

void TruyVet(int i, int Lc, int sau){
          if(i == 0) return;
          if(L[i] == Lc && f[i] <= s[sau])
             {
               TruyVet(i - 1, Lc - 1, i);
                printf("%d %d\n ", s[i],f[i]);
              }
              else   TruyVet(i - 1, Lc, sau);
}

void BoTriPhongHop()
{
    int i, k;
     for(i = 0; i < n; i++)
        {
             L[i] = 1;
             for(k = 0; k < i; k++)
                      if(f[k] <= s[i] && L[i] < L[k] + 1)
                         L[i] = L[k] + 1;
         }
         Lmax = 0;
         for(i = 0; i < n; i++)
                 if(L[i] >= Lmax)
                       {
                         Lmax = L[i];
                         Imax = i;
                       }
         TruyVet(Imax-1, Lmax-1, Imax);
         printf("%d %d",s[Imax],f[Imax]);
 }
 


int main()
{
    int l[100];
    nhap();
    in();
    Sapxep();
    printf("\n");
    BoTriPhongHop();
    getch();
    return 0;
}

