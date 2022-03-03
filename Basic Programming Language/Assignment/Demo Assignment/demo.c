#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ACCOUNT_NO 15
#define PIN_CODE 7
#define ACCOUNT_NAME 99
#define FILE_NAME "account-number.dat"
#define MAX_WIDTH 35

typedef struct ACCOUNT
{
    char account_no[ACCOUNT_NO];
    char pin_code[PIN_CODE];
    char account_name[ACCOUNT_NAME];
    double balance;
} Card;

#pragma region

Card newCard();
void writeFile(Card *cards, int count);
void readFile(Card *cards, int count);
int showMenuAndGetChoice(char **menu, char *name, int numberChoices);
void bigLine();
void smallLine();
void withdrawal(Card *card);

void mainMenu(Card *card);

//---
void showCard(Card card);

#pragma endregion

int main(int argc, char const *argv[])
{
    Card card;
    card.balance = 50000001;

    mainMenu(&card);
    return 0;
}

void bigLine()
{
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        printf("=");
    }
    printf("\n");
}
void smallLine()
{
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        printf("-");
    }
    printf("\n");
}

Card newCard()
{
    Card card;
    printf("Input Account Name: ");
    fflush(stdin);
    gets(card.account_name);
    do
    {
        printf("Input Account No  : ");
        fflush(stdin);
        scanf("%s", card.account_no);
    } while (strlen(card.account_no) != ACCOUNT_NO - 1);

    printf("Input Pin Code   : ");
    fflush(stdin);
    scanf("%s", card.pin_code);

    printf("Input Balance    : ");
    fflush(stdin);
    scanf("%lf", &card.balance);

    return card;
}

void showCard(Card card)
{
    printf("Account name: %s\n", card.account_name);
    printf("Account no  : %s\n", card.account_no);
    printf("Pin code    : %s\n", card.pin_code);
    printf("Balance     : %lf\n", card.balance);
}

void writeFile(Card *cards, int count)
{
    FILE *ptr = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(ptr, "%s\n", cards[i].account_no);
        fprintf(ptr, "%s\n", cards[i].pin_code);
        fprintf(ptr, "%s\n", cards[i].account_name);
        fprintf(ptr, "%.0lf\n", cards[i].balance);
    }
    fclose(ptr);
}

void readFile(Card *cards, int count)
{
    FILE *ptr = fopen(FILE_NAME, "r");
    for (int i = 0; i < count; i++)
    {
        fscanf(ptr, "%s\n", cards[i].account_no);
        fscanf(ptr, "%s\n", cards[i].pin_code);
        fscanf(ptr, "%s\n", cards[i].account_name);
        fscanf(ptr, "%.0lf\n", cards[i].balance);
    }
    fclose(ptr);
}

int showMenuAndGetChoice(char **menu, char *name, int numberChoices)
{
    system("cls");
    bigLine();
    printf("          VTC ACADEMY BANK\n");
    bigLine();

    int space = MAX_WIDTH / 2 - strlen(name) / 2;
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }

    printf("%s\n", name);

    smallLine();

    for (int i = 0; i < numberChoices; i++)
    {
        printf("%d. %s\n", i + 1, menu[i]);
    }

    smallLine();

    int choice = 0;

    while (choice < 1 || choice > numberChoices)
    {
        printf(" Your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        if (choice < 1 || choice > numberChoices)
        {
            printf(" - Your choice invalid!\n");
        }
    }

    smallLine();
    return choice;
}

void mainMenu(Card *card)
{
    char *menu[5] = {"Checking account balance", "Withdrawal", "Transfers", "Change PIN", "End of transaction"};
    char *name = "ATM Machine";

    int choice;

    do
    {
        choice = showMenuAndGetChoice(menu, name, 5);
        switch (choice)
        {
        case 1:
            printf("balance: %.0lf", card->balance);
            break;
        case 2:
            withdrawal(card);
            break;
        case 3:
            printf("do something 3\n");
            break;
        case 4:
            printf("do something 4\n");
            break;
        case 5:
            break;
        }
        printf("press enter to continue....");
        fflush(stdin);
        getchar();
    } while (choice != 5);
}

void withdrawal(Card *card)
{
    char *menu[6] = {"  100.000", "  200.000", "  500.000", "1.000.000", "2.000.000", "Other number"};
    char *name = "ATM Machine - Withdrawal";

    int choice;

    choice = showMenuAndGetChoice(menu, name, 6);
    switch (choice)
    {
    case 1:
        printf("100.000\n");
        break;
    case 2:
        printf("200.000\n");
        break;
    case 3:
        printf("500.000\n");
        break;
    case 4:
        printf("1.000.000\n");
        break;
    case 5:
        printf("2.000.000\n");
        break;
    case 6:
        break;
    }
    printf("press enter to continue....");
    fflush(stdin);
    getchar();
}