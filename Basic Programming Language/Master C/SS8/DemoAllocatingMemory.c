//Cấp phát động

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int *pArr;
    int size;

    printf("Nhap kich thuoc mang ban muon khoi tao: ");
    scanf("%d", &size);

    //Cấp phát vùng nhớ cho biến con trỏ pArr 
    //để khởi tạo mảng.

    pArr = malloc(size * sizeof(int));

    //Nhập giá trị cho các phần tử của mảng vừa khởi tạo
    for (int i = 0; i < size; i++)
    {
        printf("pArr[%d] = ", i);
        scanf("%d", pArr + i);
    }
    
    //Hiển thị giá trị của các phần tử trong mảng.
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(pArr + i));
    }
    
    printf("\n--------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%x\n", pArr + i);
    }
    
    //Cấp phát thêm vùng nhớ để mở rộng mảng 
    pArr = realloc(pArr, 5 * sizeof(int));
    size += 5;

    printf("\n--------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%x\n", pArr + i);
    }

    //Giải phóng vùng nhớ đã cấp phát sau khi sử dụng xong
    free(pArr);
    size--;

    printf("\n--------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%x\n", pArr + i);
    }
    return 0;
}
