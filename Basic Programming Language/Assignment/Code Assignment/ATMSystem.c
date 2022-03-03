#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "Menu.c"

typedef struct ATM
{
    char accName[50];
    char accNum[15];
    char pinCode[7];
    unsigned long long int accBalance; // 8 bytes : 0 - 18,446,744,073,709,551,615
} ATM;

int menu_1(const char *title, int menuItemCount, char *menuItem[]);
void menu_2(const char *topic);
void subMenu(char *user);

// Hàm tạo tài khoản
void createNewAccount();

// Hàm đăng nhập
void login();

// Hàm kiểm tra số dư
void checkBalance(char *user); // char * dùng để tạo 1 mảng chuỗi 1 chiều (1 con trỏ tương đương với 1 mảng 1 chiều) <=> char user[]

// Hàm rút tiền
void withdrawal(char *user);

// Hàm thực hiện việc rút tiền
void Make_A_Withdrawal(char *user, unsigned long long int money);

// Biên lai
void bills(char *user, unsigned long long int money);

// Hàm chuyển tiền (nhập số tiền cần chuyển)
void transfers(char *user);

// Hàm thực hiện việc chuyển tiền
void Make_A_Transfers(char *user, double balance, char *user_recipient);

// Hàm đổi mã PIN
void changePin(char *user);

int main()
{
    setlocale(LC_ALL, "");

    int mainChoice;
    while (mainChoice != 3)
    {
        mainChoice = menu_1("VTC Academy Bank", 3, MainMenu);
        printf("Your choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
        case 1:
            createNewAccount();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid Option, Please Enter Right Option!\n");
        }
    }
    return 0;
}

int menu_1(const char *title, int menuItemCount, char *menuItem[])
{
    system("@cls||clear");
    int i = 0;
    printf("===============================\n");
    printf("%s\n", title);
    printf("===============================\n");
    for (; i < menuItemCount; i++)
    {
        printf("%d. %s\n", i + 1, menuItem[i]);
    }
    printf("===============================\n");
}

void menu_2(const char *topic)
{
    system("@cls||clear");
    printf("===============================\n");
    printf("VTC Academy Bank\n");
    printf("===============================\n");
    printf("%s\n", topic);
    printf("-------------------------------\n");
}

void subMenu(char *user)
{
    int subChoice;
    while (1)
    {
        subChoice = menu_1("ATM Machine", 5, SubMenu);
        printf("Your choice: ");
        scanf("%d", &subChoice);
        switch (subChoice)
        {
        case 1:
            checkBalance(user);
            break;
        case 2:
            withdrawal(user);
            break;
        case 3:
            transfers(user);
            break;
        case 4:
            changePin(user);
            break;
        case 5:
            printf("\nEnd of transaction\n");
            printf("\nPress any key to continue...");
            getch();
            main();
            break;
        default:
            printf("\nInvalid Option, Please Enter Right Option!\n");
        }
    }
}

void createNewAccount()
{
    FILE *fp = fopen("account-number.dat", "ab+");

    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card, tmpcard;
    char option;

    menu_2("Create ATM cards");
    printf("Input Account Name: ");
    fflush(stdin);
    gets(tmpcard.accName);
    int len = strlen(tmpcard.accName);
    for (int i = 0; i < len; i++)
    {
        if (tmpcard.accName[i] == ' ' && tmpcard.accName[i + 1] == ' ')
        {
            for (int j = i; j < len; j++)
            {
                tmpcard.accName[j] = tmpcard.accName[j + 1];
            }
            i--;
            len--;
        }
    }
    strupr(tmpcard.accName);

re_accNum:
    printf("Input Account No  : ");
    fflush(stdin);
    scanf("%s", tmpcard.accNum);
    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(tmpcard.accNum, card.accNum) == 0)
        {
            printf("\nAccount number already in use!");
            printf("\nPress any key to create again...");
            getch();
            printf("\n\n");
            goto re_accNum;
        }
    }
    strcpy(card.accName, tmpcard.accName);
    strcpy(card.accNum, tmpcard.accNum);

    printf("Input Pin Code    : ");
    fflush(stdin);
    scanf("%s", card.pinCode);
re_Pin:
    printf("Confirm Pin Code  : ");
    fflush(stdin);
    scanf("%s", tmpcard.pinCode);
    if (strcmp(card.pinCode, tmpcard.pinCode) != 0)
    {
        printf("\nConfirm failed, please try again!\n");
        goto re_Pin;
    }

    printf("Input Balance     : ");
    scanf("%llu", &card.accBalance);

    printf("-------------------------------\n");

    int count_1;
    int count_2;

    for (int i = 0; i < strlen(card.accNum); i++)
    {
        if (card.accNum[i] >= '0' && card.accNum[i] <= '9')
        {
            count_1 = 0;
        }
        else
        {
            count_1 = -1;
            break;
        }
    }

    for (int i = 0; i < strlen(card.pinCode); i++)
    {
        if (card.pinCode[i] >= '0' && card.pinCode[i] <= '9')
        {
            count_2 = 0;
        }
        else
        {
            count_2 = -1;
            break;
        }
    }

    if (strlen(card.accNum) == 14 && strlen(card.pinCode) == 6 && count_1 == 0 && count_2 == 0)
    {
        if (card.accBalance >= 50000)
        {
            fwrite(&card, sizeof(ATM), 1, fp);
            menu_2("Create ATM cards");
            printf("Account Name   : %s\n", card.accName);
            printf("Account No     : %s\n", card.accNum);
            printf("Pin code       : %s\n", card.pinCode);
            printf("Account Balance: %'llu VND", card.accBalance);
            printf("\n--------------------------------\n");
            printf("Create ATM complete!\n");
            do
            {
                printf("\nDo you want to create new ATM Card? (Y/N): ");
                fflush(stdin);
                scanf("%c", &option);
                if (option == 'y' || option == 'Y')
                {
                    fclose(fp);
                    createNewAccount();
                }
                else if (option == 'n' || option == 'N')
                {
                    fclose(fp);
                    main();
                }
            } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
        }
        else
        {
            printf("Minimum balance in ATM card must be over 50.000 VND\n");
            do
            {
                printf("\nDo you want to create ATM Card again? (Y/N): ");
                fflush(stdin);
                scanf("%c", &option);
                if (option == 'y' || option == 'Y')
                {
                    fclose(fp);
                    createNewAccount();
                }
                else if (option == 'n' || option == 'N')
                {
                    fclose(fp);
                    main();
                }
            } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
        }
    }
    else
    {
        printf("Your account number or pin code invalid, please try again!\n");
        do
        {
            printf("\nDo you want to create ATM Card again? (Y/N): ");
            fflush(stdin);
            scanf("%c", &option);
            if (option == 'y' || option == 'Y')
            {
                fclose(fp);
                createNewAccount();
            }
            else if (option == 'n' || option == 'N')
            {
                fclose(fp);
                main();
            }
        } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
    }
}

void login()
{
    FILE *fp = fopen("account-number.dat", "rb");

    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card, tmpcard;
    char option;

    menu_2("ATM Machine - Login");
    printf("Enter your account number: ");
    fflush(stdin);
    scanf("%s", tmpcard.accNum);
    printf("Enter your pin code: ");
    fflush(stdin);
    scanf("%s", tmpcard.pinCode);
    printf("-------------------------------\n");

    // Kiểm tra xem accNum và pinCode có tồn tại trong file không?
    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(tmpcard.accNum, card.accNum) == 0 && strcmp(tmpcard.pinCode, card.pinCode) == 0)
        {
            printf("You are successfully logged in\n");
            printf("\nPress any key to continue...");
            getch();
            fclose(fp);
            subMenu(tmpcard.accNum);
        }
    }

    printf("Your account number or pin code is incorrect\n");
    do
    {
        printf("\nDo you want to login again? (Y/N): ");
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'y' || option == 'Y')
        {
            fclose(fp);
            login();
        }
        else if (option == 'n' || option == 'N')
        {
            fclose(fp);
            main();
        }
    } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
}

void checkBalance(char *user)
{
    FILE *fp = fopen("account-number.dat", "rb");

    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card;

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user, card.accNum) == 0) // Kiểm tra số dư của tài khoản đăng nhập
        {
            menu_2("ATM Machine - Check Balance");
            printf("Account No     : %s\n", card.accNum);
            printf("Pin code       : ");
            for (int i = 0; i < strlen(card.pinCode); i++)
            {
                printf("*");
            }
            printf("\n");
            printf("Account Name   : %s\n", card.accName);
            printf("Account Balance: %'llu VND", card.accBalance);
            printf("\n-------------------------------\n");
        }
    }

    fclose(fp);

    printf("\nPress any key to comeback...");
    getch();
    subMenu(user);
}

void withdrawal(char *user)
{
    FILE *fp = fopen("account-number.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card, tmpcard;
    int choice;
    char option;

    menu_2("ATM Machine - Withdrawal");
    printf("1.   100.000 VND\n");
    printf("2.   200.000 VND\n");
    printf("3.   500.000 VND\n");
    printf("4. 1.000.000 VND\n");
    printf("5. 2.000.000 VND\n");
    printf("6. Other number\n");
    printf("-------------------------------\n");

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user, card.accNum) == 0)
        {
            printf("Your choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, 100000);
            }
            else if (choice == 2)
            {
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, 200000);
            }
            else if (choice == 3)
            {
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, 500000);
            }
            else if (choice == 4)
            {
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, 1000000);
            }
            else if (choice == 5)
            {
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, 2000000);
            }
            else if (choice == 6)
            {
                printf("\nEnter the amount you want to withdrawal: ");
                scanf("%llu", &tmpcard.accBalance);
                fclose(fp);
                fclose(temp);
                Make_A_Withdrawal(user, tmpcard.accBalance);
            }
        }
        else
        {
            fwrite(&card, sizeof(ATM), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    printf("\nPress any key to comeback...");
    getch();
    subMenu(user);
}

void Make_A_Withdrawal(char *user, unsigned long long int money)
{
    FILE *fp = fopen("account-number.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card;
    int choice;
    char option;

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user, card.accNum) == 0)
        {
            if (card.accBalance >= money)
            {
                do
                {
                    printf("\nDo you want to withdrawal? (Y/N): ");
                    fflush(stdin);
                    scanf("%c", &option);
                    if (option == 'y' || option == 'Y')
                    {
                        card.accBalance -= money;
                        if (card.accBalance >= 50000)
                        {
                            printf("\nWithdrawal successfully!\n");
                            fwrite(&card, sizeof(ATM), 1, temp);
                            break;
                        }
                        else
                        {
                            printf("\nMinimum balance in ATM card must be over 50.000 VND\n");
                            fclose(fp);
                            fclose(temp);
                            remove("temp.dat");
                            printf("\nPress any key to comeback...");
                            getch();
                            subMenu(user);
                        }
                    }
                    else if (option == 'n' || option == 'N')
                    {
                        fclose(fp);
                        fclose(temp);
                        remove("temp.dat");
                        subMenu(user);
                    }
                } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
            }
            else
            {
                printf("\nInsufficient Balance!\n");
                fwrite(&card, sizeof(ATM), 1, temp);
            }
        }
        else
        {
            fwrite(&card, sizeof(ATM), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("account-number.dat");
    rename("temp.dat", "account-number.dat");

    do
    {
        printf("\nDo you want to print bill? (Y/N): ");
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'y' || option == 'Y')
        {
            bills(user, money);
            break;
        }
        else if (option == 'n' || option == 'N')
        {
            printf("\nPress any key to comeback...");
            getch();
            subMenu(user);
        }
    } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
}

void bills(char *user, unsigned long long int money)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    FILE *fp = fopen("account-number.dat", "rb");

    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }
    ATM card;

    menu_2("ATM Machine - Bill");
    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user, card.accNum) == 0)
        {
            printf("Date: %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            printf("     Time: %d:%d\n", tm.tm_hour, tm.tm_min);
            printf("Account no:      %s\n", card.accNum);
            printf("Withdrawal amount:  %'llu VND\n", money);
            printf("Content:   Withdraw cash at ATM\n");
            printf("-------------------------------\n");
            printf("Balance:              %'llu\n", card.accBalance);
            printf("-------------------------------\n");
            printf("Thank you for using our service\n");
            printf("-------------------------------\n");
        }
    }
    fclose(fp);
    printf("\nPress any key to comeback...");
    getch();
    subMenu(user);
}

void transfers(char *user)
{
    FILE *fp = fopen("account-number.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card, tmpcard;
    char option;

    menu_2("ATM Machine - Transfer");
    printf("Enter the beneficiary's account number: ");
    fflush(stdin);
    scanf("%s", tmpcard.accNum);

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(tmpcard.accNum, user) == 0)
        {
            printf("\nPlease enter the beneficiary's account number again!\n");
            printf("\nPress any key to try again...");
            getch();
            fclose(fp);
            fclose(temp);
            transfers(user);
        }
        else if (strcmp(tmpcard.accNum, card.accNum) == 0)
        {
            printf("The beneficiary's account name: %s\n", card.accName);
            printf("\nEnter the amount you want to transfer: ");
            scanf("%llu", &tmpcard.accBalance);
            fclose(fp);
            fclose(temp);
            Make_A_Transfers(user, tmpcard.accBalance, tmpcard.accNum);
        }
    }
    printf("\nAccount number does not exist, please enter the beneficiary's account number again!\n");
    do
    {
        printf("\nDo you want to transfer again? (Y/N): ");
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'y' || option == 'Y')
        {
            fclose(fp);
            fclose(temp);
            transfers(user);
        }
        else if (option == 'n' || option == 'N')
        {
            fclose(fp);
            fclose(temp);
            remove("temp.dat");
            subMenu(user);
        }
    } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
}

void Make_A_Transfers(char *user, double balance, char *user_recipient)
{
    FILE *fp = fopen("account-number.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card;
    char option;

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user_recipient, card.accNum) == 0 || strcmp(user, card.accNum) == 0)
        {
            if (strcmp(user_recipient, card.accNum) == 0)
            {
                card.accBalance += balance;
                fwrite(&card, sizeof(ATM), 1, temp);
            }

            if (strcmp(user, card.accNum) == 0)
            {
                if (card.accBalance >= balance)
                {
                    do
                    {
                        printf("\nDo you want to transfer? (Y/N): ");
                        fflush(stdin);
                        scanf("%c", &option);
                        if (option == 'y' || option == 'Y')
                        {
                            card.accBalance -= balance;
                            if (card.accBalance >= 50000)
                            {
                                printf("\nTransfer successfully!\n");
                                printf("\nCurrent Balance after transfer: %'llu VND\n", card.accBalance);
                                fwrite(&card, sizeof(ATM), 1, temp);
                                break;
                            }
                            else
                            {
                                printf("\nMinimum balance in ATM card must be over 50.000 VND\n");
                                fclose(fp);
                                fclose(temp);
                                remove("temp.dat");
                                printf("\nPress any key to comeback...");
                                getch();
                                subMenu(user);
                            }
                        }
                        else if (option == 'n' || option == 'N')
                        {
                            fclose(fp);
                            fclose(temp);
                            remove("temp.dat");
                            subMenu(user);
                        }
                    } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
                }
                else
                {
                    printf("\nInsufficient Balance!\n");
                    fclose(fp);
                    fclose(temp);
                    remove("temp.dat");
                    printf("\nPress any key to comeback...");
                    getch();
                    subMenu(user);
                }
            }
        }
        else
        {
            fwrite(&card, sizeof(ATM), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("account-number.dat");
    rename("temp.dat", "account-number.dat");

    printf("\nPress any key to comeback...");
    getch();
    subMenu(user);
}

void changePin(char *user)
{
    FILE *fp = fopen("account-number.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
    }

    ATM card, tmpcard;
    char option;

    menu_2("ATM Machine - Change PIN");
    printf("Enter your old pin code: ");
    scanf("%s", tmpcard.pinCode);

    while (fread(&card, sizeof(ATM), 1, fp) == 1)
    {
        if (strcmp(user, card.accNum) == 0)
        {
            if (strcmp(card.pinCode, tmpcard.pinCode) == 0)
            {
                printf("Enter your new pin code: ");
                scanf("%s", tmpcard.pinCode);
                if (strlen(tmpcard.pinCode) != 6)
                {
                    printf("\nYour new pin code invalid, please try again!\n");
                    printf("\nPress any key to change PIN again...");
                    getch();
                    fclose(fp);
                    fclose(temp);
                    changePin(user);
                }
                else
                {
                    do
                    {
                        printf("\nDo you want to change PIN? (Y/N): ");
                        fflush(stdin);
                        scanf("%c", &option);
                        if (option == 'y' || option == 'Y')
                        {
                            strcpy(card.pinCode, tmpcard.pinCode);
                            fwrite(&card, sizeof(ATM), 1, temp);
                            printf("\nChange pin code successfully!\n");
                            break;
                        }
                        else if (option == 'n' || option == 'N')
                        {
                            fclose(fp);
                            fclose(temp);
                            remove("temp.dat");
                            subMenu(user);
                        }
                    } while (option != 'y' || option != 'Y' || option != 'n' || option != 'N');
                }
            }
            else
            {
                printf("\nPIN failed, please try again...");
                getch();
                fclose(fp);
                fclose(temp);
                changePin(user);
            }
        }
        else
        {
            fwrite(&card, sizeof(ATM), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("account-number.dat");
    rename("temp.dat", "account-number.dat");

    printf("\nPress any key to comeback...");
    getch();
    subMenu(user);
}