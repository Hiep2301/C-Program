#include<stdio.h>

int main(int argc, char const *argv[])
{
    double point;
    printf("Nhap diem cua sv: ");
    scanf("%lf", &point);

    if(point > 0 && point <= 2)
    {
        printf("Hoc luc yeu!");
    }
    else if (point > 2 && point <= 5)
    {
        printf("Hoc luc trung binh!");
    }
    else if (point > 5 && point <= 7)
    {
        printf("Hoc luc kha!");
    }
    else if (point > 7 && point <= 9)
    {
        printf("Hoc luc gioi!");
    }
    else
    {
        printf("Hoc luc xuat cmn sac!");
    }
    
    
    
    return 0;
}
