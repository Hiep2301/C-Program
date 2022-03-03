#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int decimalNumber;
    printf("Nhap mot so nguyen duong bat ki: ");
    scanf("%d", &decimalNumber);
    long long binaryNumber = 0;
    int p = 0;
    while (decimalNumber > 0)
    {
        binaryNumber += (decimalNumber % 2) * pow(10, p);
        ++p;
        decimalNumber /= 2;
    }

    printf("%d", binaryNumber);
    return 0;
}
