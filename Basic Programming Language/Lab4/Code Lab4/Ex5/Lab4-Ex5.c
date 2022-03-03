#include <stdio.h>
int main(int argc, char const *argv[])
{
    int xA, xB, xC, yA, yB, yC;
    printf("Toa do diem A:\n");
    printf("xA = ");
    scanf("%d", &xA);
    printf("yA = ");
    scanf("%d", &yA);

    printf("Toa do diem B:\n");
    printf("xB = ");
    scanf("%d", &xB);
    printf("yB = ");
    scanf("%d", &yB);

    printf("Toa do diem C:\n");
    printf("xC = ");
    scanf("%d", &xC);
    printf("yC = ");
    scanf("%d", &yC);
    
    int a = xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB);
    if(a == 0) {
        printf("Ba diem A(%d, %d), B(%d, %d), C(%d, %d) thang hang", xA, yA, xB, yB, xC, yC);
    } else {
        printf("Ba diem A(%d, %d), B(%d, %d), C(%d, %d) khong thang hang", xA, yA, xB, yB, xC, yC);
    }
    return 0;
}
