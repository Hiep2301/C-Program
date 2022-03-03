#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* In dữ liệu ra màn hình */
    // printf("Demo output data\n");
    // printf("Demo output data");

    //In ra giá trị của biến.
    // int num1 = 10;
    // double num2 = 1.5;
    // printf("num1 = %d\nnum2 = %.1lf", num1, num2);

    // printf("%%");

    //Nhập giá trị cho biến từ bàn phím
    int num;
    printf("Nhap gia tri cho bien num: ");
    scanf("%d", &num);

    printf("num = %d", num);

    fflush(stdin); //Xóa bộ đệm
    // fseek(stdin, 0, SEEK_END); //On MacOS
    char ch;
    printf("\nNhap mot ki tu bat ki tu ban phim: ");
    scanf("%c", &ch);
    printf("Ki tu ban vua nhap la: %c", ch);
    return 0;
}


