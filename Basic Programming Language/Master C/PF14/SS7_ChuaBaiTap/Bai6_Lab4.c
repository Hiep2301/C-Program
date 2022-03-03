#include <stdio.h>

int main(int argc, char const *argv[])
{
    char kiTu;
    printf("Nhap mot ki tu bat ki tu ban phim: ");
    scanf("%c", &kiTu);

    if (('a' <= kiTu && kiTu <= 'z') || ('A' <= kiTu && kiTu <= 'Z'))
    {
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
                printf("Ki tu nhap vao la nguyen am");
                break;
            default:
                printf("Ki tu nhap vao la phu am");
                break;
        }
    }
    else
    {
        printf("Ki tu nhap vao ko thuoc bang chu cai!");
    }

    return 0;
}
