#include <stdio.h>

void printNumber(int n);
int printSumNumber(int n);

void printNumber(int n)
{
    if (n > 0)
    {
        printNumber(n - 1);
        printf("%d ", n);
    }
}

/*
    if(3 > 0) 
    {
        if (2 > 0) 
        {
            if (1 > 0) 
            {
                printNumber(0); // sai điều kiện -> thoát khỏi hàm
                printf("%d ", 1);
            }
            printf("%d ", 2);
        }
        printf("%d ", 3);
    }
*/

int printSumNumber(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + printSumNumber(n - 1);
}

/*
    5 + pSN(4)
        4 + pSN(3)
            3 + pSN(2)
                2 + pSN(1)
                    1 + pSN(0)
                        0
    0 + 1 + 2 + 3 + 4 + 5 = 15
*/

int main(int argc, char const *argv[])
{
    printNumber(10);
    printf("\n%d", printSumNumber(10));
    return 0;
}
