#include <stdio.h>
#include<stdlib.h>

#include "Menu.c"

int menu(const char *title, int menuItemCount, char *menuItem[]);
void clearKeyboardBuffer();

int main(int argc, char const *argv[])
{
    int mainChoice, subChoice;
    mainChoice = menu("VTC Academy Bank", 3, mainMenu);
    switch (mainChoice)
    {
        case 1:
            printf("Tao the ATM");
            break;
        case 2:
            subChoice = menu("ATM Machine", 5, subMenu);
            break;
        default:
            break;
    }

    return 0;
}

int menu(const char *title, int menuItemCount, char *menuItem[])
{
    system("@cls||clear"); //Hàm này để xóa màn hình cho đẹp
    int i = 0;
    printf("==============================\n");
    printf(" %s\n", title);
    printf("==============================\n");
    for (; i < menuItemCount; i++)
    {
        printf(" %d. %s \n", i + 1, menuItem[i]);
    }
    printf("==============================\n");
    int choice = 0;
    do
    {
        printf("Your choice: ");
        clearKeyboardBuffer();
        scanf("%d", &choice);
    } while (choice <= 0 || choice > menuItemCount);
    return choice;
}

void clearKeyboardBuffer()
{
    //clear keyboard buffer on UNIX
    // fseek(stdin, 0, SEEK_END);
    // clear keyboard buffer on Windows
    fflush(stdin);
}