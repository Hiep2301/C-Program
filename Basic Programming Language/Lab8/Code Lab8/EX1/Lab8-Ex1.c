#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Nhap chuoi: ");
    gets(str);
    printf("Chuoi sau nhap: ");
    puts(str);
    char c;
    printf("Nhap ky tu: ");
    scanf("%c", &c);
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }
    if (count != 0)
    {
        printf("Ky tu %c xuat hien %d lan trong chuoi", c, count);
    } else {
        printf("Ky tu %c khong xuat hien trong chuoi", c);
    }

    return 0;
}
