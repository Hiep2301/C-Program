#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a, n;
    printf("a = ");
    scanf("%d", &a);
    printf("n = ");
    scanf("%d", &n);
    int result = 1;
    for (int i = 1; i <=n; i++)
    {
        result *= a; //result = result * a
    }
    
    printf("%d^%d = %d", a, n, result);
    return 0;
}
