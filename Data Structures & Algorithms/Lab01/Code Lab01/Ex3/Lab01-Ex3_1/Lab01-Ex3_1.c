// Tính tổng các số hạng của n trong 1 cấp số cộng
#include <stdio.h>

double sumOfAP(double a, double d, int n);

double sumOfAP(double a, double d, int n)
{
    if (n >= 1)
    {
        int result = a + (n - 1) * d;
        return result + sumOfAP(a, d, (n - 1));
    }
    return 0;
    // Công thức tổng quát: Un = U1 + (n - 1) * d
}

/*
    a = 3, n = 5, d = 2
    11 + sumOfAP(result = 9) | n = 4
         9 + sumOfAP(result = 7) | n = 3
             7 + sumOfAP(result = 5) | n = 2
                 5 + sumOfAP(result = 3) | n = 1
                     3
*/

int main(int argc, char const *argv[])
{
    double a, d;
    printf("Nhap so hang dau a = "); // Số hạng đầu
    scanf("%lf", &a);
    printf("Nhap cong sai d = "); // công sai
    scanf("%lf", &d);
    int n;
    printf("Nhap hang so n = "); // hằng số
    scanf("%d", &n);
    printf("Tong cap so cong = %.2lf", sumOfAP(a, d, n));
    return 0;
}
