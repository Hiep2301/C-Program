#include<stdio.h>
int main(int argc, char const *argv[])
{
    float a, b, c;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("b = ");
    scanf("%f", &c);
    if(a >= b & a >= c) {
        printf("a = %.2f la so lon nhat", a);
    } else if (b >= c) {
        printf("b = %.2f la so lon nhat", b);
    } else {
        printf("c = %.2f la so lon nhat", c);
    }
    return 0;
}
