#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    int num1, num2, num3, num4, num5, num6;
    printf("Nhap vao mot so nguyen co 6 chu so: ");
    scanf("%d", &num);

    //Input: 123456
    //       123450
    num1 = num / 100000; //1
    num2 = (num - num1 * 100000) / 10000; //2
    num3 = (num - num1 * 100000 - num2 * 10000 ) / 1000; //3
    num4 = (num - num1 * 100000 - num2 * 10000 - num3 * 1000) / 100; //4
    num5 = (num - num1 * 100000 - num2 * 10000 - num3 * 1000 - num4 * 100) / 10; //5
    num6 = num - num1 * 100000 - num2 * 10000 - num3 * 1000 - num4 * 100 - num5 * 10; //6

    printf("So ban nhap vao: %d\n", num);
    printf("So dao nguoc   : %d%d%d%d%d%d", num6, num5, num4, num3, num2, num1);


    return 0;
}
