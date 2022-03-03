#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b, c, d;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);
    printf("d = ");
    scanf("%f", &d);
    // MAX
    if(a >= b && a >= c && a >= d) {
        printf("a = %.2f la so lon nhat\n", a);
    } else if(b >= c && b >= d) {
        printf("b = %.2f la so lon nhat\n", b);
    } else if (c >= d) {
        printf("c = %.2f la so lon nhat\n", c);
    } else {
        printf("d = %.2f la so lon nhat\n", d);
    }
    // MIN
    if(a <= b && a <= c && a <= d) {
        printf("a = %.2f la so nho nhat", a);
    } else if(b <= c && b <= d) {
        printf("b = %.2f la so nho nhat", b);
    } else if (c <= d) {
        printf("c = %.2f la so nho nhat", c);
    } else {
        printf("d = %.2f la so nho nhat", d);
    }
    return 0;
}
