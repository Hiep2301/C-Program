#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Khai bao mang
    int arr[5];
    double dou[10];

    //Khai bao va gan gia tri cho cac phan tu
    char chArr[] = {'a', 'b', 'c'};

    // arr[0] = 5;
    // arr[1] = 10;
    // arr[2] = 15;
    // arr[3] = 20;
    // arr[4] = 25;

    //Dung vong lap for de gan gia tri cho cac phan tu
    //cua mang
    for (int i = 0; i < 5; i++)
    {
        // arr[i] = i + 5;
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]); //Nhap gia tri tu ban phim
    }
    
    //Dung vong lap for de in gia tri cua cac phan tu
    //cua mang
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    // printf("%d", arr[0]);


    return 0;
}
