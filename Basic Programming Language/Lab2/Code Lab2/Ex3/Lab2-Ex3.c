#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    if(a == 0 && b == 0) {
        printf("Phuong trinh vo so nghiem");
    } else if(a == 0 && b != 0) {
        printf("Phuong trinh vo nghiem");
    } else if(a != 0) {
        printf("Phuong trinh co nghiem la: x = %.2f", (float) -b / a);
    }
    return 0;
}
