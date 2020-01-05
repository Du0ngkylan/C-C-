#include <stdio.h>
#include <conio.h>
#define m 6
#define n 6
 
 main()
{
    int max, kMax;
    int a [m+2][n] =
        {
            {0,  0,  0,   0,   0,  0  },
            {1,  10, 200, 50,  20, 20 },
            {2,  20, 5,   100, 50, 5  },
            {5,  5,  20,  5,   10, 200},
            {50, 20, 5,   20,  5,  20 },
            {5,  2,  2,   10,  1,  5  },
            {10, 5,  1,   50,  2,  200},
            {0,  0,  0,   0,   0,  0  },
        };
    int p[m + 2][n];
    int t[m + 2][n];
 
    for (int j = 0; j < n; j++) //chen gia tri 0 vào hàng o và hàng m+1
    {
        p[0][j] = 0; p[m + 1][j] = 0;
        t[0][j] = 0; t[m + 1][j] = 0;
    }
 
    for (int i = 1; i <= m; i++) //tính cot dau tiên cua bang p
    {
        p[i][0] = a[i][0]; t[i][0] = 0;
    }
 
    for (int j = 1; j < n; j++) //tinh lan luot cac cot con lai cua p (2-->n)
    {
        for (int i = 1; i <= m; i++)
        {
            max = 0;//tìm max
            kMax = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                if (max < p[k][j - 1])
                {
                    max = p[k][j - 1];
                    kMax = k;
                }
            }
            p[i][j] = max + a[i][j];
            t[i][j] = kMax - i + 1;
        }
    }
 
    max = 0; //chon o lon nhat cua cot n trong p
    int I = 0, J = n - 1;
    for (int i = 0; i <= m; i++)
    {
        if (max < p[i][n - 1])
        {
            max = p[i][n - 1];
            I = i;
        }
    }
 
    printf("Tong so tien lon nhat la %d\n", max); //in giá tri toi uu
    printf("Robot se di theo cac o sau:\n"); //truy vet tim lay duong di toi uu)
    for (int j = n - 1; j >= 0; j--) 
    {
        printf("o (%d,%d)\n",I, J);
        if (t[I][J] == 0) I--;
        else if (t[I][J] == 2) I++;
        J--;
    }
 
    printf("--------------------------------------------\n"); //in bang p
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n\n");
    }
    printf("--------------------------------------------\n"); //in bang t
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n\n");
    }
    printf("--------------------------------------------\n");
    getch(); //dung man hinh de xem ket qua
}