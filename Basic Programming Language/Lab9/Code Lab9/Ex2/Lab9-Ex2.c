#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a[10][10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = rand() % 1001;
        }
    }
    printf("Mang ban dau: \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    //Sắp xếp từ bé đến lớn
    for (int i = 0; i < 100 - 1; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (a[i / 10][i % 10] > a[j / 10][j % 10]) // chia cho cột để biết xem giá trị phần tử ở vị trí hàng bn, cột bn (ở đây là 10 cột)
            {
                int temp = a[i / 10][i % 10];
                a[i / 10][i % 10] = a[j / 10][j % 10];
                a[j / 10][j % 10] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep tu be den lon: \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
