#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    float xA, xB, xC, xD, yA, yB, yC, yD;
    printf("Toa do diem A:\n");
    printf("xA = ");
    scanf("%f", &xA);
    printf("yA = ");
    scanf("%f", &yA);

    printf("Toa do diem B:\n");
    printf("xB = ");
    scanf("%f", &xB);
    printf("yB = ");
    scanf("%f", &yB);

    printf("Toa do diem C:\n");
    printf("xC = ");
    scanf("%f", &xC);
    printf("yC = ");
    scanf("%f", &yC);

    printf("Toa do diem D:\n");
    printf("xD = ");
    scanf("%f", &xD);
    printf("yD = ");
    scanf("%f", &yD);
    
    float a = xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB);
    if(a != 0) {
        printf("Ba diem A(%.1f, %.1f), B(%.1f, %.1f), C(%.1f, %.1f) khong thang hang\n", xA, yA, xB, yB, xC, yC);
        printf("Ba diem A, B, C thuoc tam giac");
    } else {
        printf("Ba diem A(%.1f, %.1f), B(%.1f, %.1f), C(%.1f, %.1f) thang hang\n", xA, yA, xB, yB, xC, yC);
        printf("Ba diem A, B, C khong thuoc tam giac");
        return 0;
    }
    //ABC
    float S = abs((xA*(yB-yC) + xB*(yC-yA) + xC*(yA-yB))) / (2.0);
    printf("\nDien tich tam giac ABC = %.2f", S);

    //DBC
    float S1 = abs((xD*(yB-yC) + xB*(yC-yD) + xC*(yD-yB))) / (2.0);
    printf("\nDien tich tam giac DBC = %.2f", S1);

    //DAC
    float S2 = abs((xA*(yD-yC) + xD*(yC-yA) + xC*(yA-yD))) / (2.0);
    printf("\nDien tich tam giac DAC = %.2f", S2);

    //DAB
    float S3 = abs((xA*(yB-yD) + xB*(yD-yA) + xD*(yA-yB))) / (2.0);
    printf("\nDien tich tam giac DAB = %.2f", S3);

    if(S == S1 + S2 + S3) {
        printf("\nToa do diem D(%.1f, %.1f) nam trong tam giac ABC", xD, yD);
    } else {
        printf("\nToa do diem D(%.1f, %.1f) khong nam trong tam giac ABC", xD, yD);
    }
    return 0;
}
