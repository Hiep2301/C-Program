#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    if(a == 0)
    {
        if (b == 0)
        {
            printf("Phuong trinh co vo so nghiem");
        }
        else
        {
            printf("Phuong trinh vo nghiem");
        }  
    }
    else
    {
        double x = (double)-b/a;
        printf("Nghiem cua phuong trinh la x = %.2lf", x);
    }
    
    return 0;
}
