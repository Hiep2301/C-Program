#include<stdio.h>

//Hàm cộng hai số nguyên
//Input: 2 số nguyên
//Output: 1 số nguyên là tổng của 2 số input vào.
int congHaiSoNguyen(int num1, int num2);

//Hàm in kết quả ra màn hình.
void printResult(int tongHaiSoNguyen);


int main(int argc, char const *argv[])
{
    int a, b;

    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int result = congHaiSoNguyen(a, b);

    printResult(result);
    return 0;
}

int congHaiSoNguyen(int num1, int num2)
{
    //Body của hàm
    //Dùng từ khóa return để trả về output của hàm
    int result = num1 + num2;
    return result;
}

void printResult(int tongHaiSoNguyen)
{
    printf("Ket qua: %d\n", tongHaiSoNguyen);
}