#include <stdio.h>
#include <math.h>
int inputNumber();
int checkNumber(int num);

int main(int argc, char const *argv[])
{
    inputNumber();

    int n;
    printf("\nn = ");
    scanf("%d", &n);
    if(checkNumber(n) == 0) {
        printf("%d khong la so nguyen to", n);
    } else {
        printf("%d la so nguyen to", n);
    }
    return 0;
}

int inputNumber()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("Gia tri vua nhap = %d", n);
}

int checkNumber(int num)
{
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return 0;
        }
    }
}
