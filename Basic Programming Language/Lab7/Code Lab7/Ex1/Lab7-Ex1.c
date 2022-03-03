#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Gia tri cua phan tu co index chan la: ");
    for (int i = 0; i < 10; i++)
    {
        if(i % 2 == 0) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
