#include <stdio.h>

int fibonacci(int n);

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(int argc, char const *argv[])
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("Day Fibonacci %d phan tu: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
