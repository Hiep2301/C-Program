#include <stdio.h>

int main(int argc, char const *argv[])
{
    //giai thua chan
    int n;
    printf("n = ");
    scanf("%d", &n);
    int fact1 = 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            fact1 *= i;
        }
    }
    printf("giai thua chan cua %d la: %d\n", n, fact1);

    //giai thua le
    int m;
    printf("m = ");
    scanf("%d", &m);
    int fact2 = 1;
    for(int j = 1; j <= n; j++) {
        if(j % 2 != 0) {
            fact2 *= j;
        }
    }
    printf("giai thua le cua %d la: %d", m, fact2);
    return 0;
}
