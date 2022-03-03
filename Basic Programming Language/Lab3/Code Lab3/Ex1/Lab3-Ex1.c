#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num1, num2;
    printf("num1 = ");
    scanf("%d", &num1);
    printf("num2 = ");
    scanf("%d", &num2);
    int c = num1;
    num1 = num2;
    num2 = c;
    num1++;
    num2++;
    printf("num1 = %d, num2 = %d", num1, num2);
    return 0;
}
