#include <stdio.h>
#include <string.h>

typedef struct student
{
    char hoten[50];
    int tuoi;
    char lop[6];
} student;

void printAllInfor();
void inputInfor();

void printAllInfor()
{
    FILE *students = fopen("studentsInfor.dat", "rb");
    if (students == NULL)
    {
        printf("Error opened file");
    }

    student infor;

    while (fread(&infor, sizeof(student), 1, students) == 1)
    {
        printf("Ten: ");
        puts(infor.hoten);
        printf("Tuoi: %d\n", infor.tuoi);
        printf("Lop: ");
        puts(infor.lop);
        printf("--------------------------\n");
    }
    fclose(students);
}

void inputInfor()
{
    FILE *students = fopen("studentsInfor.dat", "ab+");
    if (students == NULL)
    {
        printf("Error opened file");
    }

    student infor;

    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(infor.hoten);

    printf("Nhap tuoi: ");
    scanf("%d", &infor.tuoi);

    printf("Nhap lop: ");
    fflush(stdin);
    gets(infor.lop);

    fwrite(&infor, sizeof(student), 1, students);
    fclose(students);
}

int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            inputInfor();
            break;
        case 2:
            printAllInfor();
            break;
        case 3:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}
