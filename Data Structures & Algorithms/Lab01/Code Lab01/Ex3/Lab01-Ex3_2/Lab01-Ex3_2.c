#include <stdio.h>

// Giai thừa sử dụng vòng lặp
int factUsingLoop(int n);
// Giai thừa sử dụng đệ quy
int factUsingRecursion(int n);

int factUsingLoop(int n)
{
    int giaiThua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaiThua *= i;
    }
    return giaiThua; // giaiThua trả về là một số nên sử dụng hàm kiểu int và trả về chính giaiThua
}

int factUsingRecursion(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factUsingRecursion(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("Giai thua cua %d su dung de quy: %d\n", n, factUsingRecursion(n));
    printf("Giai thua cua %d su dung vong lap: %d", n, factUsingLoop(n));
    return 0;
}