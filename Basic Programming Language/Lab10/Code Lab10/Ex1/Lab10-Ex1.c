#include <stdio.h>

void swap(int *num1, int *num2);

int main(int argc, char const *argv[])
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("a = %d, b = %d", a, b);
    return 0;
}

void swap(int *num1, int *num2){
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
