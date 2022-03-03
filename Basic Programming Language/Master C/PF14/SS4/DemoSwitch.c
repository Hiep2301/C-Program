#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;

    printf("------MENU-----\n");
    printf("1. Pho xao\n");
    printf("2. Com rang thap cam\n");
    printf("3: Com ran dua bo\n");
    printf("4. Pho tai nam\n");
    printf("5. Pho tai gau\n");
    printf("----------------\n");

    printf("Moi ban chon mon 1 - 5: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Ban chon pho xao!");
            break;
        case 2:
            printf("Ban chon com rang thap cam");
            break;
        default:
            printf("Moi chon trong khoang tu 1 den 5");
            break;
    }

    return 0;
}
