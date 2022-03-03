#include <stdio.h>
int main(int argc, char const *argv[])
{
    char kiTu;
    while (kiTu != ' ')
    {
        fflush(stdin);
        printf("Nhap ki tu: ");
        scanf("%c", &kiTu);
        if ((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z'))
        {
            printf("Ki tu vua nhap nam trong bang chu cai\n");
            switch (kiTu)
            {
            case 'u':
            case 'e':
            case 'o':
            case 'a':
            case 'i':
            case 'U':
            case 'E':
            case 'O':
            case 'A':
            case 'I':
                printf("ki tu nhap la nguyen am\n");
                break;
            default:
                printf("ki tu nhap la phu am\n");
                break;
            }
        }
        else if (kiTu >= '0' && kiTu <= '9')
        {
            printf("Ki tu vua nhap la chu so\n");
        }
        else
        {
            printf("Ki tu vua nhap la ki tu dac biet\n");
        }
    }
    return 0;
}
