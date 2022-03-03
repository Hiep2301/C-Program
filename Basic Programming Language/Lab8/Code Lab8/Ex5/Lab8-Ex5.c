#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str_1[100];
    printf("Nhap chuoi 1: ");
    gets(str_1);
    printf("Chuoi 1 vua nhap: ");
    puts(str_1);
    printf("------------------\n");
    char str_2[100];
    printf("Nhap chuoi 2: ");
    gets(str_2);
    printf("Chuoi 2 vua nhap: ");
    puts(str_2);
    printf("------------------\n");
    int count = 0;
    for (int i = 0; i <= strlen(str_1); i++)
    {
        if (str_1[i] != str_2[i])
        {
            if (str_1[i] > str_2[i])
            {
                count = 1;
            }
            else
            {
                count = 2;
            }
        }
    }

    if (count == 0)
    {
        printf("2 chuoi bang nhau");
    }
    else if (count == 1)
    {
        printf("Chuoi 1 lon hon chuoi 2");
    }
    else
    {
        printf("Chuoi 2 lon hon chuoi 1");
    }
    return 0;
}
