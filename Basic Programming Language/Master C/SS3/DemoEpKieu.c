#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Chuyển đổi kiểu ngầm định
    // char ch = 'A';
    // int a = 10;

    // printf("%c", ch + 32);

    //Chuyển đổi kiểu chủ động
    int a = 5, b = 2;

    double c = (double)a / b;
    printf("c = %lf", c);
    
    return 0;
}
