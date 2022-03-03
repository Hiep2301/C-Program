#include <stdio.h>
#include <math.h>

int IsPrimeNumber(int n);

int main(int argc, char const *argv[])
{
    int num;
    printf("Nhap mot so nguyen duong bat ki: ");
    scanf("%d", &num);

    printf("Cac so nguyen to nho hon hoac bang %d:\t", num);

    for (int i = 2; i <= num; i++)
    {
        if (IsPrimeNumber(i) == 1)
        {
            printf("%d\t", i);
        }
        
    }
    
    return 0;
}


int IsPrimeNumber(int n)
{
    if(n <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }

    return 1;
    
}