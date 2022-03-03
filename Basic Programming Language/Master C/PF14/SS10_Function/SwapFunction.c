#include<stdio.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(int argc, char const *argv[])
{
    int a = 1, b = 2;
    //swap(a, b); //Truyền bằng tham trị

    swap(&a, &b); //Truyền bằng tham chiếu
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}
