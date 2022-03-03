#include<stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    //Tim gia tri lon nhat trong ma
    int max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat trong mang: %d\n", max);
    
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if(max == arr[i])
        {
            count++;
        }
    }
    printf("So %d xuat hien %d lan trong mang.", max, count);
    
    return 0;
}
