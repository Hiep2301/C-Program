#include <stdio.h>
int main(int argc, char const *argv[])
{
    while (1)
    {
        int a, b;
        printf("a = ");
        scanf("%d", &a);
        printf("b = ");
        scanf("%d", &b);
        if (a == 0 && b == 0)
        {
            printf("Phuong trinh vo so nghiem\n");
        }
        else if (a == 0 && b != 0)
        {
            printf("Phuong trinh vo nghiem\n");
        }
        else if (a != 0)
        {
            printf("Phuong trinh co nghiem la: x = %.2f\n", (float)-b / a);
        }
    }

    return 0;
}
