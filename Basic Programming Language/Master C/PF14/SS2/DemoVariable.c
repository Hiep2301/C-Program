#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Demo khai bao bien: [kiểu_dữ_liệu] [tên_biến];
    //Khai bao bien kieu so nguyen:
    int number1;
    float number2;  //Biến kiểu số thực
    double number3; //Biến kiểu số thực
    char character; //Biến kiểu kí tự

    number1 = 10; //Gán giá trị cho biến number1
    number2 = 1.2;
    number3 = 69.96;
    character = 'A';

    //In giá trị của biến ra màn hình console
    printf("number1 = %d\n", number1);
    printf("number2 = %.1f\n", number2);
    printf("number3 = %.2lf\n", number3);
    printf("character: %c\n", character);
    return 0;
}
