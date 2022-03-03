#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int *a;
    int n;
    printf("n = ");
    scanf("%d", &n);
    srand(time(NULL));
    //cấp phát khởi đầu
    a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = rand() % 101;
    }
    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                int tmp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = tmp;
            }
        }
    }
    printf("\nMang sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    //giải phóng
    free(a);
    return 0;
}
