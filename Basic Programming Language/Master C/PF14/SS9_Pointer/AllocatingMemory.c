#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    //Khai bao bien kieu con tro.
    int *arr;
    int size;

    printf("Nhap kich thuoc cua mang muon tao: ");
    scanf("%d", &size);

    //Cấp phát vùng nhớ khởi tạo ban đầu 
    arr = malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        printf("%p\n", &arr[i]);
    }
    
    //Cấp phát thêm
    arr = realloc(arr, 3 * sizeof(int));

    printf("Sau khi cap them 3 vung nho:\n");
    for (int i = 0; i < size + 3; i++)
    {
        printf("%p\n", &arr[i]);
    }

    //Giải phóng vùng nhớ
    free(arr);
    return 0;
}

