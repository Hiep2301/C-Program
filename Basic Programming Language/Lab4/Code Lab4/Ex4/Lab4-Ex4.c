#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b, c;
    printf("Nhap canh a = ");
    scanf("%f", &a);
    printf("Nhap canh b = ");
    scanf("%f", &b);
    printf("Nhap canh c = ");
    scanf("%f", &c);

    if((a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Ba canh a, b, c la ba canh cua tam giac\n");
        if((a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c== a*a+b*b)) {
            printf("Day la tam giac vuong");
        } else if ((a == b) && (b == c)) {
            printf("Day la tam giac deu");
        } else if((a == b) || (a == c) || (b == c)) {
            printf("Day la tam giac can");
        } else if((a*a > b*b+c*c) || (b*b > a*a+c*c) || (c*c > a*a+b*b)) {
            printf("Day la tam giac tu");
        } else {
            printf("Day la tam giac nhon");
        }
    } else {
        printf("Ba canh a, b, c khong phai la ba canh cua tam giac");
    }
    return 0;
}
