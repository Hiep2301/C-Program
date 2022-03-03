#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[50];
    char name[] = "Dao Duc";

    //Nhập xuất string
    //Dùng printf() và scanf()
    //Dùng gets() và puts()
    // int a;
    // printf("a = ");
    // scanf("%d", &a);
    printf("Nhap ten cua ban: ");
    // scanf("%[^\n]s", str);
    fflush(stdin);
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 32)
        {
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
                i--;
            }
        }
    }    

    printf("Xin chao: ", str);

    return 0;
}
