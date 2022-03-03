#include <stdio.h>
#include "menu.c"
int main(int argc, char const *argv[])
{
    int c;
    while (c != 5)
    {
        menu();
        printf("          Please Choose: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Doing menu 1...\n");
            break;
        case 2:
            printf("Doing menu 2...\n");
            break;
        case 3:
            printf("Doing menu 3...\n");
            break;
        case 4:
            printf("Doing menu 4...\n");
            break;
        case 5:
            printf("Exit\n");
            break;
        default:
            while (c > 5 || c < 1)
            {
                printf("Enter incorrectly, re-enter: ");
                scanf("%d", &c);
            }
            break;
        }
    }
    return 0;
}
