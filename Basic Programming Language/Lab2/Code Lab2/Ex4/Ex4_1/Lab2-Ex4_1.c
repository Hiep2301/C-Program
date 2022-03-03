#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    int S = 0;
    for(int i = 1; i <= n; i++) {
        S += i;
        if(S <= n) {
            printf("%d ", i);
        }
    }
    return 0;
}
