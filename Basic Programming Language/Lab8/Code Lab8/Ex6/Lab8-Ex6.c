#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Nhap chuoi: ");
    gets(str);
    printf("Chuoi sau nhap: ");
    puts(str);
    int count_chu_cai = 0;
    int count_chu_so = 0;
    int count_ky_tu_khac = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            count_chu_cai++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            count_chu_so++;
        }
        else
        {
            count_ky_tu_khac++;
        }
    }
    printf("Tong cac chu cai trong chuoi: %d", count_chu_cai);
    printf("\nTong cac chu so trong chuoi: %d", count_chu_so);
    printf("\nTong cac ky tu dac biet trong chuoi: %d", count_ky_tu_khac - 1); // - 1 ở đây là '\0'
    return 0;
}
