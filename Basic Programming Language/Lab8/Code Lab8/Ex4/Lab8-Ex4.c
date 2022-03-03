#include <stdio.h>
#include <string.h>
char checkPalindrome(char c[100]);

char checkPalindrome(char c[100])
{
    for (int i = 0; i < strlen(c) / 2; i++)
    {
        if (c[i] != c[strlen(c) - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char str[50];
    printf("Nhap chuoi: ");
    gets(str);
    printf("Chuoi sau nhap: ");
    puts(str);

    if (checkPalindrome(str) == 1)
    {
        printf("Day la chuoi palindrome");
    }
    else
        printf("Day khong phai la chuoi palindrome");

    return 0;
}
