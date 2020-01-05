/*
 * soPhuc.c
 *
 *  Created on: Oct 4, 2012
 *      Author: NgoHuong
 *khai bao cau truc cua 1 so phuc
 *nhap vao 2 so phac do
 *tinh va in ra gia tri a+b va a*b
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct so_phuc
{
	int x;
	int y;
};

void nhap(so_phuc *a)
{
	printf("\nNhap phan thuc:");scanf("%d", &(a->x));
	printf("\nNhap phan ao:");scanf("%d", &(a->y));
}

void nhap_2sophuc(so_phuc *a, so_phuc *b)
{
	printf("\nNhap so phuc thu nhat:\n");
	nhap(a);
	printf("\nNhap so phuc thu hai:\n");
	nhap(b);
}

int tinh_tong(so_phuc a, sp_phuc b)
{

}
