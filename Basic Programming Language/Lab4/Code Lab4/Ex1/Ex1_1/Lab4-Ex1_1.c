#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    if(a == 0) {
        if(b == 0) {
            printf("Phuong trinh co vo so nghiem");
        } else {
            printf("Phuong trinh vo nghiem");
        }
    } else {
            printf("Phuong trinh co nghiem x = %.2f", (float)-b / a);
    }
    return 0;
}
