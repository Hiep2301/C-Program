#include <stdio.h>
int fibonacci(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}

int fibonacci(int n)
{
    int a = 0, b = 1;
    printf("%d %d ", a, b);
    for(int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}
