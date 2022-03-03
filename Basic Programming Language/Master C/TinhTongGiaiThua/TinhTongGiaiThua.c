/*
    Viết chương trình thực hiện tính biểu thức
    S(n) = 1 + 2! + 3! + ... + n! 
    với n > 0
*/

#include<stdio.h>

int TinhGiaiThua(int n);

int main(int argc, char const *argv[])
{
    int num, S = 0;
    printf("Nhap so nguyen duong bat ki: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        S += TinhGiaiThua(i);
    }
    
    printf("S(n) = %d", S);
    
    return 0;
}

int TinhGiaiThua(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return n * TinhGiaiThua(n - 1);
}
