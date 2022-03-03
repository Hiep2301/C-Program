#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2;

    printf("Nhap num1: ");
    scanf("%d", &num1);
    printf("Nhap num2: ");
    scanf("%d", &num2);

    //Khai bao bien trung gian temp va thuc hien hoan vi
    int temp = num1;
    num1 = num2;
    num2 = temp;

    printf("num1 va num2 sau khi thuc hien hoan vi:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    //Tang gia tri cua moi bien len 1 don vi
    num1++; 
    num2++;

    printf("num1 va num2 sau khi thuc hien tang gia tri len 1 don vi:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}
