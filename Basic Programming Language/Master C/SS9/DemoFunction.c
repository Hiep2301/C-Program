#include<stdio.h>
 

//Khai báo nguyên mẫu hàm (function prototype) cộng hai số nguyên.
int CongHaiSo(int num1, int num2);
int TruHaiSo(int num1, int num2);
int NhanHaiSo(int num1, int num2);
double ChiaHaiSo(int num1, int num2);

void printMenu();

int main(int argc, char const *argv[])
{
    int a, b, tong, hieu, tich;
    double thuong;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    
    while (1)
    {
        int choice;
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tong = CongHaiSo(a, b);
            printf("%d + %d = %d", a, b, tong);
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

//Định nghĩa hàm cộng hai số dựa trên nguyên mẫu đã khai báo.
int CongHaiSo(int num1, int num2)
{
  return num1 + num2;  
}

int TruHaiSo(int num1, int num2)
{
    return num1 - num2;
}
int NhanHaiSo(int num1, int num2)
{
    return num1 * num2;
}

double ChiaHaiSo(int num1, int num2)
{
    return (double)num1 / num2;
}

void printMenu()
{
    printf("\n-----MENU-----\n");
    printf("1. Cong hai so nguyen\n");
    printf("2. Tru hai so nguyen\n");
    printf("3. Nhan hai so nguyen\n");
    printf("4. Chia hai so nguyen\n");
    printf("0. Thoat chuong trinh\n");
    printf("-----------------------\n");
    printf("Moi nhap lua chon cua ban: ");
}
