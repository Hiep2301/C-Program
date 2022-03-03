#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2;

    printf("Nhap so nguyen thu nhat: ");
    scanf("%d", &num1);
    printf("Nhap so nguyen thu hai: ");
    scanf("%d", &num2);

    //MENU
    printf("-----MENU-----\n");
    printf("+\n");
    printf("-\n");
    printf("*\n");
    printf("/\n");
    printf("--------------\n");
    printf("Chon phep tinh: ");
    char choice;
    //Xoa bo dem de tranh hien tuong troi lenh
    fflush(stdin);
    scanf("%c", &choice);

    switch (choice)
    {
    case '+':
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;
    
    default:
        break;
    }
    return 0;
}
