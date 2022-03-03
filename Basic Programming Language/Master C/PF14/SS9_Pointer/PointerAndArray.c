#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5];
    printf("Nhap mang: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", (arr + i));
    }

    printf("Mang sau khi nhap:\n");
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(arr + i));
    }
    
    return 0;
}
