#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* Khai báo biến */
    int num1, num2, tong, hieu, tich, thuong;
    printf("Nhap so nguyen thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so nguyen thu hai: ");
    scanf("%d", &num2);

    tong = num1 + num2;
    hieu = num1 - num2;
    tich = num1 * num2;
    thuong = num1 / num2;

    printf("%d + %d = %d\n", num1, num2, tong);
    printf("%d - %d = %d\n", num1, num2, hieu);
    printf("%d * %d = %d\n", num1, num2, tich);
    printf("%d / %d = %d\n", num1, num2, thuong);

    num1++;
    num2++;

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}
