#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    if (n < m)
    {
        for (int i = n; i <= m; i++)
        {
            if (i % 7 == 0)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        for (int i = m; i <= n; i++)
        {
            if (i % 7 == 0)
            {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
