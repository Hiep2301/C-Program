#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int snt(int n);

int snt(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int a[20];
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        a[i] = rand() % 201;
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        if (snt(a[i]) != 0)
        {
            printf("%d la so nguyen to trong day so cua mang\n", a[i]);
        }
    }
    return 0;
}
