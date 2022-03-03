#include <stdio.h>
#include <stdlib.h>

void nhapMang(int x[], int n)
{
    do
    {
        printf("\nNhap vao n:");
        scanf("%d", &n);
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        printf("\nX[%d]=", i);
        scanf("%d", &x[i]);
    }
}

void xuatMang(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nX[%d]=%d", i, x[i]);
    }
}

void xuatFile(int x[], int n, char tenFile[50])
{
    FILE *f;
    f = fopen(tenFile, "w");
    if (f == NULL)
    {
        printf("\n Loi mo file");
        return;
    }
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d\n", x[i]);
    }
    fclose(f);
}

void nhapFile(int x[], int n, char tenFile[50])
{
    FILE *f;
    f = fopen(tenFile, "r");
    if (f == NULL)
    {
        printf("\n Loi mo file");
        return;
    }
    fscanf(f, "%d", &n);
    printf("%d", n);
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &x[i]);
    }
    fclose(f);
}

int main()
{
    int a[10], temp, n;
    nhapMang(a, n);
    xuatMang(a, n);
    nhapFile(a, n, "data.txt");
    xuatFile(a, n, "data.txt");

    /* Sắp xếp mảng */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    nhapFile(a, n, "sorteddata.txt");
    xuatFile(a, n, "sorteddata.txt");
}