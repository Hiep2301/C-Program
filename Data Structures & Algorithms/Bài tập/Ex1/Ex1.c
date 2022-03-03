#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *isAlphabet(char *name, char *result);
char *formatString(char *name);
char formatCurrencyInsert(char *currency, int pos, char ch);
char *formatCurrencyTick(char *currency);

int main(int argc, char const *argv[])
{
    char name[100];
    char result[100];
    char currency[100];
    time_t t;
    int choice;
    do
    {
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input name: ");
            fflush(stdin);
            gets(name);
            printf("Name after formating: ");
            printf("\"%s\"\n\n", isAlphabet(name, result));
            break;

        case 2:
            printf("Input money: ");
            fflush(stdin);
            gets(currency);
            printf("Currency after formating: ");
            printf("%s VND\n\n", formatCurrencyTick(currency));
            break;

        case 3:
            t = time(NULL);
            struct tm tm = *localtime(&t);
            printf("Current Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            printf("Current Time: %d:%d:%d\n\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
            break;

        case 0:
            return 0;
        default:
            break;
        }
    } while (choice >= 1 || choice <= 3);
}

char *isAlphabet(char *name, char *result)
{
    int pos = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')
        {
            strcpy(&result[pos], &name[i]);
            pos++;
        }
    }
    return formatString(result);
}

char *formatString(char *name)
{
    while (name[0] == ' ')
    {
        strcpy(&name[0], &name[1]);
    }

    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ' && name[i + 1] == ' ')
        {
            strcpy(&name[i], &name[i + 1]);
            i--;
        }
    }

    while (name[strlen(name) - 1] == ' ') // name[strlen(name)] = '\0' -> ký tự cuối là name[strlen(name) - 1]
    {
        name[strlen(name) - 1] = '\0';
    }

    strlwr(name);

    if (name[0] >= 'a' && name[0] <= 'z')
    {
        name[0] -= 32;
    }

    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z' && name[i - 1] == ' ')
        {
            name[i] -= 32;
        }
    }
    return name;
}

char formatCurrencyInsert(char *currency, int pos, char ch)
{
    for (int i = strlen(currency) + 1; i > pos; i--)
    {
        currency[i] = currency[i - 1];
        /*
            lần 1: i = 8, pos = 4
            lần 2: i = 9, pos = 1
        */
    }
    return currency[pos] = ch;
}

char *formatCurrencyTick(char *currency) // 1000000 (7 ký tự)
{
    for (int i = strlen(currency) - 3; i > 0; i = i - 3)
    {
        formatCurrencyInsert(currency, i, '.');
        /*
            Lần 1: i = 4 -> pos = 4
            lần 2: i = 1 -> pos = 1
        */
    }
    return currency;
}

        /*
            lần 1: 
            0 1 2 3 4 5 6   |   0 1 2 3 4 5 6 7
            -------------   |   ---------------               
            1 0 0 0 0 0 0   |           . 0 0 0

            lần 2: 
            0 1 2 3 4 5 6 7 8   |      0 1 2 3 4 5 6 7 8          
            -----------------   |      -----------------          
                      . 0 0 0   |      1 . 0 0 0 . 0 0 0 
        */