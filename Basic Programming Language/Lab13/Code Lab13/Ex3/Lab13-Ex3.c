#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*  */
    FILE *fp;

    char ch;
    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(0);
    }
    printf("File opened successfully. Reading file contents character by character. \n\n");

    do
    {
        /* Đọc ký tự đơn trong file */
        ch = fgetc(fp);

        /* In ra ký tự đơn ra màn hình */
        putchar(ch);

    } while (ch != EOF); /* Lặp lại nếu ký tự đọc được ko phải EOF */

    fclose(fp);

    return 0;
}