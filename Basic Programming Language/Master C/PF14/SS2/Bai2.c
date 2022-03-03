#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Khai bao 3 bien ngay, thang, nam
    int ngay, thang, nam;

    printf("Nhap ngay: ");
    scanf("%d", &ngay);

    printf("Nhap thang: ");
    scanf("%d", &thang);

    printf("Nhap nam: ");
    scanf("%d", &nam);

    printf("%d/%d/%d", ngay, thang, nam);
    return 0;
}
