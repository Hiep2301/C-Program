#include <stdio.h>
#include <math.h>
int snt(int n);

int snt(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        re_enter:
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        if (snt(a[i]) == 0)
        {
            printf("re-entering\n");
            // i--;
            goto re_enter;
        }
    }

    return 0;
}
