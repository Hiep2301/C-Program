#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char str1[20];
    char str2[20];
    char str3[50];

    printf("Nhap chuoi thu nhat: ");
    gets(str1);
    printf("Nhap chuoi thu hai: ");
    gets(str2);

    // strcat(str1, str2);
    // printf("Chuoi thu nhat sau khi noi: %s", str1);

    // printf("\nSo sanh 2 chuoi: ");
    // int result = strcmp(str1, str2);
    // if(result < 0)
    // {
    //     printf("%s < %s", str1, str2);
    // }
    // else if (result == 0)
    // {
    //     printf("%s = %s", str1, str2);
    // }
    // else
    // {
    //     printf("%s > %s", str1, str2);
    // }

    // strcpy(str1, str2);
    // printf("Chuoi 1: %s", str1);

    printf("Do dai chuoi 1: %d", strlen(str1));
    

    return 0;
}
