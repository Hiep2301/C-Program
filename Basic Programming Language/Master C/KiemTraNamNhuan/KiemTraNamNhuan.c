#include<stdio.h>

int main(int argc, char const *argv[])
{
    
    int nam;
    printf("Nhap so nam bat ki: ");
    scanf("%d", &nam);

    // nam % 4 == 0 -> năm chia hết cho 4
    // nam % 4 != 0 -> năm không chia hết cho 4
    // nam % 400 == 0 -> năm chia hết cho 400
    // &&: toán tử quan hệ VÀ (AND)
    // ||: toán tử quan hệ HOẶC (OR)
    if((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
    {
        printf("%d la nam nhuan.", nam);
    }
    else
    {
        printf("%d khong phai la nam nhuan.", nam);
    }
    
    return 0;
}
