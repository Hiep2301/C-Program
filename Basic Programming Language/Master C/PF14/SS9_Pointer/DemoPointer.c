#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a = 2;
    int *pa; //Khai báo biến pa kiểu con trỏ

    //Sử dụng toán tử &, 
    //lấy địa chỉ vùng nhớ của biến a gán vào pa
    //Lúc này, ta gọi pa là con trỏ của a
    pa = &a; 

    printf("Dia chi vung nho cua bien a: %x\n", &a);
    printf("Dia chi vung nho cua bien a: %x\n", pa);

    printf("-------------------------------------------\n");

    printf("a = %d\n", a);
    printf("a = %d\n", *pa);
    
    a++;
    pa++;

    printf("pa = %x\n", pa);
    printf("Gia tri o vung nho pa = %d\n", *pa);
    return 0;
}
