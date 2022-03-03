#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x, y;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Nhap y: ");
    scanf("%d", &y);
    int ex = x*x*x + 3 * x * x + 3 *x *y *y + y*y*y;

    printf("Gia tri bieu thuc: x^3 + 3x^2 + 3xy^2 + y^3 = %d\n", ex);
    return 0;
}
