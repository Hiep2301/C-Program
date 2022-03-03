#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    char str[80];
    printf("Nhap chuoi: ");
    gets(str);
    printf("Chuoi sau nhap: %s", str);
    int n = strlen(str);

    //Chuẩn hóa
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                str[j] = str[j + 1];
            }
            n--;
            i--;
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

    //Số ký tự
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(str[i] != ' '){
            count++;
        }
    }
    printf("\nSo ky tu trong chuoi: %d", count);

    //Nguyên âm
    int count_nguyen_am = 0;
    for (int i = 0; i < n; i++)
    {
        if(str[i] == 'u' || str[i] == 'e' || str[i] == 'o' || str[i] == 'a' || str[i] == 'i' || str[i] == 'U' || str[i] == 'E' || str[i] == 'O' || str[i] == 'A' || str[i] == 'I') {
            count_nguyen_am++;   
        }
    }
    printf("\nSo ky tu nguyen am: %d", count_nguyen_am);
    float phan_tram = (float)count_nguyen_am / count;
    printf("\nKy tu nguyen am chiem %.2f%%", phan_tram * 100);
    return 0;
}
