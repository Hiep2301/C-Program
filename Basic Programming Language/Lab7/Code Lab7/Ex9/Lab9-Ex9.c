#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j;
    int a[50][50];

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == 0)
                a[i][0] = 1;
            else
                a[i][j] = 0;
        }
    }

    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (a[i][j] != 0)
                printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
