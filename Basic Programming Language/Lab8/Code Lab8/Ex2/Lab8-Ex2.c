#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Nhap chuoi: ");
    gets(str);
    printf("Chuoi sau nhap: %s", str);
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            n--;
        }
    }
    strlwr(str);
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= 32;
    }
    for (int i = 1; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ')
        {
            str[i] -= 32;
        }
    }
    printf("\nChuoi sau chuan hoa: %s", str);
    return 0;
}
