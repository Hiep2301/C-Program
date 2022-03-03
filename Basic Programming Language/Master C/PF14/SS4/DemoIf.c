#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    printf("Nhap mot so nguyen bat ki: ");
    scanf("%d", &num);

    int r = num % 2;

    //Su dung cau truc dieu kien
    if (r == 0)
    {
        printf("%d la so chan", num);
    }
    else
    {
        printf("%d la so le", num);
    }
    
    return 0;
}
