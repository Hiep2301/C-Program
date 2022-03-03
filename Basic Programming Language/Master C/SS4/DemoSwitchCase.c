#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("------VTC Menu------\n");
    printf("1. Tra dao\n");
    printf("2. Tra chanh\n");
    printf("3. Tra tac\n");
    printf("4. Tra nhai\n");
    printf("---------------------\n");

    printf("Moi nhap lua chon cua ban: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Ban da chon TRA DAO");
        break;
    case 2:
        printf("Ban da chon TRA CHANH");
        break;
    default:
        printf("O! Khong uong gi a?!");
        break;
    }
    return 0;
}
