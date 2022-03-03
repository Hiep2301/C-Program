#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Khai báo biến
    int num1;
    float num2;
    printf("Nhap gia tri cho bien num1: ");

    //Nhập giá trị cho biến từ bàn phím:
    scanf("%d", &num1);

    printf("Nhap gia tri cho bien num2: ");

    //Nhập giá trị cho biến từ bàn phím:
    scanf("%f", &num2);

    //In ra giá trị của biến num1:
    printf("num1 = %d\n", num1);
    printf("num2 = %f\n", num2);
    return 0;
}
