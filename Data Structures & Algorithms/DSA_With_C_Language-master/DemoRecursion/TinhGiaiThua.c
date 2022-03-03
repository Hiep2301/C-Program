#include<stdio.h>

int TinhGiaiThua(int num);

int main(int argc, char const *argv[])
{
    int num;
    printf("Nhap mot so nguyen duong nho hon 20: ");
    scanf("%d", &num);

    int giaiThua = TinhGiaiThua(num);
    printf("%d! = %d\n", num, giaiThua);
    return 0;
}


int TinhGiaiThua(int num)
{
    if(num <= 1)
    {
        return 1;
    }

    return num * TinhGiaiThua(num - 1);
}