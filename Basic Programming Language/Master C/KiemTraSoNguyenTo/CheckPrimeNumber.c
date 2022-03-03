#include<stdio.h>
#include<math.h>

int IsPrimeNumber(int n);

int main(int argc, char const *argv[])
{
    int arrNumber[] = {12, 11, 6, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        int resultCheckPrime = IsPrimeNumber(arrNumber[i]);

        if (resultCheckPrime == 1)
        {
            printf("%d\t", arrNumber[i]);
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