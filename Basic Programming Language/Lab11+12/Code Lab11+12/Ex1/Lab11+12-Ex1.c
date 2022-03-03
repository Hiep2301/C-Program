#include <stdio.h>
#include <string.h>

struct Mark InputInformation();
void PrintInformation(struct Mark mark);

struct Mark
{
    char subject[50];
    double theoreticaltest;
    double practicaltest;
};

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhap so mon hoc: ");
    scanf("%d", &n);
    printf("------------------\n");
    struct Mark mark[n];
    for (int i = 0; i < n; i++)
    {
        printf("Mon hoc thu %d\n", i + 1);
        mark[i] = InputInformation();
        printf("------------------\n");
    }
    printf("Danh sach diem cac mon hoc\n");
    for (int i = 0; i < n; i++)
    {
        PrintInformation(mark[i]);
    }
    return 0;
}

struct Mark InputInformation()
{
    struct Mark mark;
    printf("Ten mon hoc: ");
    fflush(stdin);
    scanf("%s", &mark.subject);

    printf("Diem ly thuyet: ");
    fflush(stdin);
    scanf("%lf", &mark.theoreticaltest);

    printf("Diem thuc hanh: ");
    fflush(stdin);
    scanf("%lf", &mark.practicaltest);

    return mark;
}

void PrintInformation(struct Mark mark)
{
    printf("Mon %s\n", mark.subject);
    printf("Diem ly thuyet: %.1lf\n", mark.theoreticaltest);
    printf("Diem thuc hanh: %.1lf\n", mark.practicaltest);
    printf("\n");
}
