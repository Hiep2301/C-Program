#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int a, b, c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    if(a == 0) {
        if(b == 0) {
            if (c == 0) {
                printf("Phuong trinh vo so nghiem");
            } 
            else {
                printf("Phuong trinh vo nghiem");
            }
        } 
        else {
            printf("Phuong trinh co nghiem x = %.2lf", (double)-c / b);
        }
    } 
    else {
        int delta = b*b - 4*a*c;
        if(delta < 0) {
            printf("Phuong trinh vo nghiem");
        } 
        else if (delta == 0) {
            printf("Phuong trinh co nghiem kep x1 = x2 = %.2lf", (double)-b / (2 *a));
        } 
        else if (delta > 0) {
            double x1, x2;
            x1 = (-b + sqrt(delta)) / (2*a);
            x2 = (-b - sqrt(delta)) / (2*a);
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf", x2);
        }
    }
    return 0;
}
