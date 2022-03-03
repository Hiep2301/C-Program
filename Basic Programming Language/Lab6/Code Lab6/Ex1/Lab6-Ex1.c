#include <stdio.h>
int power(int a, int n);

int main(int argc, char const *argv[])
{
    int a, n;
    printf("a = ");
    scanf("%d", &a);
    printf("n = ");
    scanf("%d", &n);

    printf("%d mu %d = %d", a, n, power(a, n));
    return 0;
}

int power(int a, int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p *= a;
    }
    return p;
}