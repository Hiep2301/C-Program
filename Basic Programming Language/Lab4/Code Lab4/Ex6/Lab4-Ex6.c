#include <stdio.h>
int main(int argc, char const *argv[])
{
    char kiTu;
    printf("Nhap ki tu: ");
    scanf("%c", &kiTu);
    if((kiTu >= 'a' && kiTu <= 'z') || (kiTu >= 'A' && kiTu <= 'Z')) {
        printf("Ki tu vua nhap nam trong bang chu cai\n");
    switch (kiTu) {
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
			printf("ki tu nhap la nguyen am");
			break;
		default:
			printf("ki tu nhap la phu am");
			break;
    }
    } else {
        printf("Ki tu vua nhap khong nam trong bang chu cai");
    }
    return 0;
}
