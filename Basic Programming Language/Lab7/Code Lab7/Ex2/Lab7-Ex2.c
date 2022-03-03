#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("a[10] = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    float b[5];
    for (int i = 0; i < 5; i++)
    {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }

    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        a[i] = 0;
        if (i % 2 != 0)
        {
            a[i] = b[j];
            j++;
        }
    }
    printf("a[10] = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
