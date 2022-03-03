#include <stdio.h>

int main(int argc, char const *argv[])
{
    //dãy số Fibonacci 
    int n;
    printf("n = ");
    scanf("%d", &n);
    int a = 0, b = 1, c;
    printf("%d %d ", a, b);
    for(int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    return 0;
}
