/*
 * bai2.c
 *
 *  Created on: Dec 3, 2012
 *      Author: NgoHuong
 */
/*chuan hoa xau, cho 1 xau hay chuan hoa chung theo dung dinh dangh
 * 2 ki tu kien nhau k giong nhau
 * vd: abccccddde
 * ->abcde
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chuan_hoa(char s[])
{
	int n = strlen(s);
	int i, j;
	for (i=0; i<n-1; i++)
	{
		while( s[i] == s[i+1])
		{
			for (j=i+1; j<n; j++)
			{
				s[j] = s[j+1];
			}
			n--;
			i--;
		}
	}
}
/*void chuan_hoa(char *str)
{
    int n = strlen(str) ;
    int i , j ;
    for(i=0;i<n-1;i++)
    {
        while(str[i]==str[i+1])
        {
            for(j=i+1;j<n;j++)
                str[j] = str[j+1] ;

            n--;
            i--;
        }
    }
}*/


int main()
{
	setbuf(stdout, NULL);
	char s[100];
	printf("\nNhap vao 1 xau can chuan hoa:\n");
	fflush(stdin);
	gets(s);
	chuan_hoa(s);
	printf("\nXau sau khi chuan hoa la: %s", s);
	return 0;

}
