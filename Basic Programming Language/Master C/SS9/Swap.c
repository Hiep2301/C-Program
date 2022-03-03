#include<stdio.h>

void Swap(int *num1, int *num2);

int main(int argc, char const *argv[])
{
    int a = 1, b = 2;

    Swap(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}

void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}