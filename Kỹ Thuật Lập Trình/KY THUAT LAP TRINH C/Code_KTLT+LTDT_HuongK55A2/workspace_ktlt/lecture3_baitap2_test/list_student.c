/*
 * list_student.c
 *
 *  Created on: Oct 24, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[50] ;
    struct node *next ;
} node ;


node * AddNode(node *list , char str[])
{
    node *p = (node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("\n Cap phat that bai ! Kiem tra lai dung luong bo nho !");

        exit(2);
    }

    strcpy(p->name , str);
    p->next = list ;
    list = p ;
    return list ;
}


node * Reader(node *list, char filename[])
{
    FILE *f = fopen(filename, "rt");
    if(f==NULL)
    {
        printf("\n Loi mo tep ! Kiem tra lai !");
        getch();
        exit(1);
    }

    int i , n ;
    fscanf(f,"%d\n",&n);
    for( i = 0 ; i < n ;i++)
    {
        char ten[50] ;
        fgets(ten,50,f);
        ten[strlen(ten)-1] = '\0' ;
        list = AddNode(list,ten);
    }

    fclose(f);

    return list ;
}
void ShowList(node *list)
{
    if(list == NULL)
    {
        printf("\n Danh sach rong...");
        return ; // de thoat khoi ham nay
    }

    node *p ;
    for(p = list ; p!=NULL ; p = p->next)
    {
        printf("\n %s " , p->name);
    }
}

void SwapSort(node *list)
{
    if(list == NULL)
    {
        printf("\n Danh sach rong...");
        return ;
    }
    node *p , *q ;
    for(p = list ; p->next !=NULL ; p=p->next)
        for(q=p->next ; q!=NULL ; q=q->next)
            if(strcmp(p->name,q->name)==1)
            {
                char temp[50] ;
                strcpy(temp , p->name) ;
                strcpy(p->name , q->name);
                strcpy(q->name , temp);
            }
}

node * InsertName(node *list)
{
    char ten[50];
    printf("\n\n* Nhap vao 1 ten :");
    fflush(stdin);
    gets(ten);
    ten[strlen(ten)-1] = '\0' ;
    //tao node moi co gia tri la ten nhap vao

    node *k = (node*)malloc(sizeof(node));
    strcpy(k->name,ten);

    node *p ;
    for(p=list ; p->next !=NULL ; p = p->next)
    {
//      1- Neu ten[] ma nho hon phan tu dau tien thì chen vao dau danh sach
        if(strcmp(ten,p->name) == -1)
        {
            list = AddNode(list,ten) ;
            return list ;
        }
//      2- Neu gap vi tri thoa man p->name  < ten < p->next->name thi chen node moi vao
        if(strcmp(ten,p->name)>= 0 && strcmp(ten,p->next->name) <= 0 )
        {
            k->next = p->next ;
            p->next = k ;
            return list ;
        }
    }
    // sau khi ket thuc vong for (p->next = NULL ) tuc la p dang o vi tri phan tu cuoi cung) ma ko gap TH nao thi duong nhien chi có the chen vao cuoi danh sach
    k->next = NULL ;
    p->next = k ;
    return list ;
}

node * Search(node *list)
{
    if(list==NULL)
    {
        printf("\n Danh sach rong...");
        return NULL;
    }
    char ten[50];
    printf("\n\n*Nhap vao 1 ten : ");
    fflush(stdin);
    gets(ten);

    node *p ;
    for(p=list;p!=NULL;p=p->next)
        if(strcmp(ten,p->name)==0)
            return p ;

    return NULL ;
}

node *DeleteName(node *list)
{
    if(list == NULL)
    {
        printf("\n Danh sach rong...");
        return list;
    }
    char ten[50];
    printf("\n\n*Nhap vao 1 ten : ");
    fflush(stdin);
    gets(ten);

    //if(Search(list)==NULL) // Xu li them cho TH ko co sv nao dc tim thay
        //printf("\n Khong co sinh vien nao co ten %s ",ten) ;


//  1- Xu li cho TH ten tim thay o dau danh sach .se xoa het cac node lien tiep co ten trung voi ten nhap vao
//      vi danh sach da sap xep nen cac ten giong nhau lien tiep
    while(strcmp(ten,list->name)==0)
    {
        printf("\n OK") ;
        node *p = list ;
        list = list->next ; // list = p->next ;
        free(p);
    }
//  return list ;  Co the cho lenh nay dung o day dc ko ? vi sao ?

//  2-TH con lai
    node * p = list ;
    for(p=list ; p->next !=NULL; )
    {
        if(strcmp(ten,p->next->name)==0)
        {
            node *q = p->next ;
            p->next = q->next ;
            free(q);
        }
        else //  Giai thich cho nay nhe
            p = p->next ;
    }
    return list ;
}

// Ham huy danh sach tu viet nhe !



int main()
{
	setbuf(stdout, NULL);
    node *list = NULL ; // Khoi tao ngay = NULL nhe
    list = Reader(list,"sinhvien.txt");
    printf("\n\n*Danh sach lay tu file la :\n");
    ShowList(list) ;

    printf("\n\n*Danh sach da sap xep la :\n");
    SwapSort(list);
    ShowList(list);

    list = InsertName(list);
    printf("\n\n*Danh sach sau khi bo sung la :\n");

    ShowList(list);

    node *viTri = Search(list) ;//co the lam cach khac
    if(viTri==NULL)
        printf("\n Khong tim thay bat cu sinh vien nao co ten nhu tren ");
    else
        printf("\n Con tro viTri dang tro toi sinh vien \"%s\" dau tien duoc tim thay",viTri->name);

    list = DeleteName(list);
    printf("\n\n*Danh sach sau khi xoa la :\n");
    ShowList(list);

    printf("\n\n*An phim bat ki de thoat ....");

    return 0 ;
}
