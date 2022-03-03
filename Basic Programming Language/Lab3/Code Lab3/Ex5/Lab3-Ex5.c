#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main(int argc, char const *argv[])
{
    float r, h, Sxq, Stp, V; 
    printf("Ban kinh r = ");
    scanf("%f", &r);
    printf("Chieu cao h = ");
    scanf("%f", &h);
    Sxq = 2 * PI * r * h;
    Stp = Sxq + 2 * PI * r * r;
    V = PI * r * r * h;
    printf("Dien tich xung quanh hinh tru la: %f\n", Sxq);
    printf("Dien tich toan phan hinh tru la: %f\n", Stp);
    printf("The tich hinh tru la: %f", V);
    return 0;
}
