#include <stdio.h>
int main()
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    // AND
    printf("a & b = %d\n", a & b);
    // OR
    printf("a | b = %d\n", a | b);
    // XOR
    printf("a ^ b = %d\n", a ^ b);
    // NOT
    printf("~a = %d\n", a = ~a);
    printf("~b = %d\n", b = ~b);
    return 0;
}