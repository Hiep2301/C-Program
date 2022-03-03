#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;

    a += 5;
    printf("a = %d\n", a);
    printf("%d", sizeof(a));
    return 0;
}
