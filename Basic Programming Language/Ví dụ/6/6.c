#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    unsigned long long int bignum;
    printf("bignum = ");
    scanf("%llu", &bignum);
    printf("Big number: %'llu\n", bignum);

    return 0;
}