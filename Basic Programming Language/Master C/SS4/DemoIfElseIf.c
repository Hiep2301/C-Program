#include <stdio.h>

int main(int argc, char const *argv[])
{
    double point;

    printf("Nhap diem cua hoc sinh: ");
    scanf("%lf", &point);

    if (0 <= point && point <= 10)
    {
        if (0 <= point && point < 5)
        {
            printf("Hoc luc yeu!");
        }
        else if (5 <= point && point < 6)
        {
            printf("Hoc luc trung binh!");
        }
        else if (6 <= point && point < 7)
        {
            printf("Hoc luc kha!");
        }
        else if (7 <= point && point < 9)
        {
            printf("Hoc luc gioi!");
        }
        else
        {
            printf("Hoc luc xuat sac!");
        }
    }

    return 0;
}
