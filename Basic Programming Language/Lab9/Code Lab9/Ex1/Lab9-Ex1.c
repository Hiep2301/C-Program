#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int n, a[1000];
    printf("n = ");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101;
    }
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep tu be den lon: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
