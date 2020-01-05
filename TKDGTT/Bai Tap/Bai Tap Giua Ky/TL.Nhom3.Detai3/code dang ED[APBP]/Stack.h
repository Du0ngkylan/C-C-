int Top = -1;
char a[100];

// ham thay so nguyen bang 1 ky tu
char MA_ASCII(int n)
{
     char c;
     c =  n;
     return c;
}

// ham kiem tra ngan xep rong
int isEmpty(int tg)
{
    Top = tg;
    if(Top<0)
       return 0;
    return 1;       
}

// ham kiem tra ngan xep day
int isFull(int tg)
{
    Top = tg;
    if(Top>100)
       return 0;
    return 1;       
}

// ham them phan tu vao ngan xep
void Push(char tg)
{
     if (Top>100)
        printf("ngan xep day, khong the them phan tu vao");
     else{
          Top = Top + 1;
          a[Top] = tg;
          }
}

// ham lay ra 1 phan tu tu ngan xep
char Pop(char tg)
{
     if (Top<0)
        printf("ngan xep rong, khong lay phan tu ra duoc");
     else{
          tg = a[Top];
          Top = Top - 1;
          return tg;
          }
}

