#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num = 123456;

    int n1 = num % 10; //6
    num = num / 10;   //12345

    int n2 = num % 10; //5
    num = num / 10;

    int n3 = num % 10;
    num = num / 10;

    int n4 = num % 10;
    num = num / 10;
    
    int n5 = num % 10;
    num = num / 10;

    int n6 = num % 10;

    printf("%d%d%d%d%d%d", n1, n2, n3, n4, n5, n6);
    return 0;
}
