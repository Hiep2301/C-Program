#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isChar(char c);
bool isNum(char c);
bool isValid(char c[]);

int main(int argc, char const *argv[])
{
    char str[100];
re_enter:
    printf("Nhap email: ");
    gets(str);
    printf("Email: ");
    puts(str);
    if (isValid(str))
    {
        printf("Valid");
    }else {
        printf("Invalid, please try again\n");
        goto re_enter;
    }
    return 0;
}

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isNum(char c)
{
    return (c >= '0' && c <= '9');
}

bool isValid(char c[])
{
    if (!isChar(c[0]))
    {
        return 0;
    }
    int At = 0, Dot = 0;
    for (int i = 0; c[i] != ' ' && c[i] != '\0'; i++)
    {
        if (c[i] == '@') 
        {
            At = i;
        } else if (c[i] == '.') {
            Dot = i;
        }
    }
    if (At == 0 && Dot == 0)
    {
        return 0;
    }
    if (At > Dot) // '.' trước rồi đến '@'
    {
        return 0;
    }
    if (Dot >= (strlen(c) - 1)) // '.' ở cuối thì sai
    {
        return 0;
    }
}
