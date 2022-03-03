#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 101;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    int n;
    printf("\nn = ");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        if (n == a[i])
        {
            printf("%d nam trong day so cua mang o vi tri %d", n, i);
        } else {
            printf("%d khong nam trong day so cua mang", n);
            break;
        }
    }
    return 0;
}
